#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

// client structure + global variables
typedef struct s_client {
	int		id;
	char	msg[1024];
} t_client;

t_client clients[4096];

char	buff_read[4096 * 42];
char	buff_write[4096 * 42 + 42];
int		fd_max;
int		id_i = 0;
fd_set	r_set, w_set, mem_set;

// function to send message to all clients
void	ft_send_to_all(int sender) {
	for (int fd_i = 0; fd_i <= fd_max; fd_i++) {
		if (FD_ISSET(fd_i, &r_set) && fd_i != sender) {
			send(fd_i, buff_write, strlen(buff_write), 0);
		}
	}
}

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}


int main(int ac, char **av) {
	// argument check
	if (ac != 2) {
		write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
		return (1);
	}

	// socket setup
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd < 0) { 
		write(2, "Fatal error\n", strlen("Fatal error\n"));
		return(1); 
	} 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		write(2, "Fatal error\n", strlen("Fatal error\n"));
		return(1);
	} 
	if (listen(sockfd, 128) != 0) {
		write(2, "Fatal error\n", strlen("Fatal error\n"));
		return(1); 
	}
	// initialization
	len = sizeof(cli);
	fd_max = sockfd;
	FD_ZERO(&mem_set);
	FD_ISSET(sockfd, &mem_set);
	bzero(clients, sizeof(clients));
	// main loop
	while (42) {
		// initilization
		r_set = mem_set;
		w_set = mem_set;
		if (select(fd_max + 1, &r_set, &w_set, NULL, NULL) < 0) {
			continue ;
		}
		// handling readable fds
		for (int fd_i = 0; fd_i <= fd_max; fd_i++) {
			if (FD_ISSET(fd_i, &r_set)) {
				if (fd_i == sockfd) {
					connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
					if (connfd < 0) {
						continue;
					} 
					clients[connfd].id = id_i++;
					FD_SET(connfd, &mem_set);
					if (connfd > fd_max) {
						fd_max = connfd;
					}
					sprintf(buff_write, "server: client %d just arrived\n", clients[connfd].id);
					ft_send_to_all(connfd); 
				} else {
					int rec = recv(fd_i, buff_read, 65536, 0);
					if (rec < 0) {
						sprintf(buff_write, "server: client %d just left\n", clients[connfd].id);
						ft_send_to_all(fd_i);
						FD_CLR(fd_i, &mem_set);
						close(fd_i);
					} else {
						int j = strlen(clients[fd_i].msg);
						for (int i = 0; i < rec; i++) {
							clients[fd_i].msg[j] = buff_read[i];
							if (clients[fd_i].msg[j] == '\n') {
								clients[fd_i].msg[j] = '\0';
								sprintf(buff_write, "client %d: %s\n", clients[fd_i].id, clients[fd_i].msg);
								ft_send_to_all(fd_i);
								bzero(clients[fd_i].msg, strlen(clients[fd_i].msg));
								j = -1;
							} j++;
						}
					}
				}
			}
		}
	}
}
