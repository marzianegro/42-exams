#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

// to-do: client structure + global variables
typedef struct s_client {
	int		id;
	char	msg[1024];
} t_client;
t_client	clients[4096];

char	buff_read[4096 * 42];
char	buff_write[4096 * 42 + 42];
int		fd_max = 0;
int		id_i = 0;
fd_set	r_set, w_set, mem_set;

// to-do: function to send message to all clients
void	ft_send_to_all(int sender) {
	for (int fd_i = 0; fd_i <= fd_max; fd_i++) {
		if (FD_ISSET(fd_i, &w_set) && fd_i != sender) {
			send(fd_i, buff_write, strlen(buff_write), 0);
		}
	}
}

int main(int ac, char **av) {
	// to-do: argument check
	if (ac != 2) {
		write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
		exit(1);
	}

	// to-do: socket setup
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		write(2, "Fatal error\n", strlen("Fatal error\n"));
		exit(1);
	} 
	bzero(&servaddr, sizeof(servaddr)); 

	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); 
  
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		write(2, "Fatal error\n", strlen("Fatal error\n"));
		exit(1); 
	} 
	if (listen(sockfd, 128) != 0) {
		write(2, "Fatal error\n", strlen("Fatal error\n"));
		exit(1);
	}

	// to-do: initialization
	len = sizeof(cli);
	bzero(&cli, sizeof(cli));
	fd_max = sockfd;
	FD_ZERO(&mem_set);
	FD_SET(sockfd, &mem_set);
	// to-do: main loop
	while (42) {
		// to-do: initialization
		r_set = mem_set;
		w_set = mem_set;
		if (select(fd_max + 1, &r_set, &w_set, 0, 0) == -1) {
			continue;
		}
		// to-do: handling readable fds
		for (int fd_i = 0; fd_i <= fd_max; fd_i++) {
			if (FD_ISSET(fd_i, &r_set)) {
				if (fd_i == sockfd) { // to-do: new client
					connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
					if (connfd < 0) { 
						continue;
					}
					clients[connfd].id = id_i++;
					FD_SET(connfd, &mem_set);
					if (connfd > fd_max) {
						fd_max = connfd;
					}
					sprintf(buff_write, "server: client %djust arrived\n", clients[connfd].id);
					ft_send_to_all(connfd);
				} else { // to-do: existing client 66536
					int rec = recv(fd_i, buff_read, 66536, 0);
					if (rec < 0) { // to-do: client has disconnected
						sprintf(buff_write, "server: client %d just left\n", clients[fd_i].id);
						ft_send_to_all(connfd);
						FD_CLR(fd_i, &mem_set);
						close(fd_i);
					} else { // to-do: process received data
						int j = strlen(clients[fd_i].msg);
						for (int i = 0; i < rec; i++) {
							clients[fd_i].msg[j] = buff_read[i];
							if (clients[fd_i].msg[j] == '\n') {
								clients[fd_i].msg[j] = '\0';
								sprintf(buff_write, "client %d: %s\n", clients[fd_i].id, clients[fd_i].msg);
								ft_send_to_all(fd_i);
								bzero(&clients[fd_i].msg, sizeof(clients[fd_i].msg));
								j = -1;
							} j++;
						}
					}
				}		
			}
		}
	}
}
