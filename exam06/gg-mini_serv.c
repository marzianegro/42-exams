// INCLUDES AND DEFINITIONS
#include <netdb.h> // definitions for network db operations
#include <netinet/in.h> // constants and structures for internet domain addresses
#include <stdio.h> // standard input/output
#include <stdlib.h> // memory allocation, process control, conversions, etc.
#include <string.h> // string handling functions
#include <sys/socket.h> // definitions for sockets
#include <unistd.h> // access to POSIX oeprating system API

// CLIENT STRUCTURE AND GLOBAL VARIABLES
typedef struct s_client {
    int     id;
    char    msg[1024];
}   t_client;

t_client clients[4096];

char buff_read[4096 * 42];
char buff_write[4096 * 42 + 42];
int fd_max = 0; // maximum fd value
int id_i = 0; // counter for assigning unique IDs to clients
// fd sets for select() to monitor multiple file descriptors
fd_set w_set, r_set, mem_set;

// FUNCTION TO SEND MESSAGES TO ALL CLIENTS
void    ft_send_to_all(int sender) {
    for (int fd_i = 0; fd_i <= fd_max; fd_i++) {
        if (FD_ISSET(fd_i, &w_set) && fd_i != sender) { // check if fd is in write set
            send(fd_i, buff_write, strlen(buff_write), 0);
        }
    }
}

int main(int ac, char **av){
    // ARGUMENT CHECK
    if (ac != 2) {
        write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
        return (1);
    }
    
    // SOCKET SETUP
    int sockfd, connfd, len; // socket fd, connection fd, client address struct length
    struct sockaddr_in servaddr, cliaddr; // server address structure, client address structure

    bzero(&servaddr, sizeof(servaddr));
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    // System Call returns an error before the program starts accepting connections
    if (sockfd < 0) {
        write(2, "Fatal error\n", strlen("Fatal error\n"));
        return (1);
    }

    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // 127.0.0.1
    servaddr.sin_port = htons(atoi(av[1])); 
    
    if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)))) { 
        write(2, "Fatal error\n", strlen("Fatal error\n"));
        return (1);
    }
    if (listen(sockfd, 128)) {
        write(2, "Fatal error\n", strlen("Fatal error\n"));
        return (1);
    }

    // INITIALIZATION
    len = sizeof(cliaddr);
    fd_max = sockfd;
    FD_ZERO(&mem_set); // initialize memory fd set
    FD_SET(sockfd, &mem_set); // add server socket to mem_set
    bzero(clients, sizeof(clients));
    // MAIN LOOP
    while (42) {
        w_set = mem_set; // monitoring writable fds
        r_set = mem_set; // monitoring readable fds
        if (select(fd_max + 1, &r_set, &w_set, NULL, NULL) < 0) // monitor multiple fds for readability and writability
            continue ; // on failure
        for (int fd_i = 0; fd_i <= fd_max; fd_i++) {
            if (FD_ISSET(fd_i, &r_set)) { // check if fd is in read set
                if (fd_i == sockfd) {
                    connfd = accept(fd_i, (struct sockaddr *)&cliaddr, (socklen_t *)&len);
                    if (connfd < 0)
                        continue; // on failure
                    clients[connfd].id = id_i++;
                    FD_SET(connfd, &mem_set); // add new client socket to memory set
                    if (connfd > fd_max)
                        fd_max = connfd;
                    sprintf(buff_write, "server: client %d just arrived\n", clients[connfd].id);
                    ft_send_to_all(connfd);
                    // bzero(&cliaddr, sizeof(cliaddr));
                }
                else { // handle data from existing client
                    int rec = recv(fd_i, buff_read, 65536, 0);
                    if (rec <= 0) { // client has disconnected
                        sprintf(buff_write, "server: client %d just left\n", clients[fd_i].id);
                        ft_send_to_all(fd_i);
                        FD_CLR(fd_i, &mem_set); // remove client socket from memory
                        close(fd_i);
                    }
                    else { // process retrieved data
                        int j = strlen(clients[fd_i].msg); // buffer index
                        for (int i = 0; i < rec; i++) {
                            clients[fd_i].msg[j] = buff_read[i];
                            if (clients[fd_i].msg[j] == '\n') {
                                clients[fd_i].msg[j] = '\0'; // terminate message
                                sprintf(buff_write, "client %d: %s\n", clients[fd_i].id, clients[fd_i].msg);
                                ft_send_to_all(fd_i);
                                bzero(&clients[fd_i].msg, sizeof(clients[fd_i].msg)); // clear buffer
                                j = -1; // reset
                            }
                            j++;
                        }
                    }
                }
                break ;
            }
        }
    }
}
