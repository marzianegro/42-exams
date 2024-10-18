#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

// to-do: client structure + global variables
typedef struct s_client {
	int	id;
	char msg[1024];
} t_client;

t_client clients[4096];

char 	buff_read[4096 * 42];
char 	buff_write[4096 * 42 + 42];
int		fd_max;
int		id_i = 0;
fd_set	r_set, w_set, mem_set;

// to-do: function to send msg to all clients
void	ft_send_to_all(int sender) {
	for (int fd_i = 0; fd_i <= fd_max; fd_i++) {
		if (FD_ISSET(fd_i, &w_set) && fd_i != sender) {
			send(fd_i, buff_write, strlen(buff_write), 0);
		}
	}
}

// note: don't need
// int extract_message(char **buf, char **msg)
// {
// 	char	*newbuf;
// 	int	i;

// 	*msg = 0;
// 	if (*buf == 0)
// 		return (0);
// 	i = 0;
// 	while ((*buf)[i])
// 	{
// 		if ((*buf)[i] == '\n')
// 		{
// 			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
// 			if (newbuf == 0)
// 				return (-1);
// 			strcpy(newbuf, *buf + i + 1);
// 			*msg = *buf;
// 			(*msg)[i + 1] = 0;
// 			*buf = newbuf;
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// note: don't need
// char *str_join(char *buf, char *add)
// {
// 	char	*newbuf;
// 	int		len;

// 	if (buf == 0)
// 		len = 0;
// 	else
// 		len = strlen(buf);
// 	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
// 	if (newbuf == 0)
// 		return (0);
// 	newbuf[0] = 0;
// 	if (buf != 0)
// 		strcat(newbuf, buf);
// 	free(buf);
// 	strcat(newbuf, add);
// 	return (newbuf);
// }


int main(int ac, char **av) {
	// to-do: argument check
	if (ac != 2) {
		write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
		return (1);
	}

	// to-do: socket setup
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd < 0) { 
		write(2, "Fatal error\n", strlen("Fatal error\n"));
		return (1);
	}
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		write(2, "Fatal error\n", strlen("Fatal error\n"));
		return (1);
	} 
	if (listen(sockfd, 128) != 0) {
		write(2, "Fatal error\n", strlen("Fatal error\n"));
		return (1);
	}

	// to-do: initialization
	len = sizeof(cli);
	fd_max = sockfd;
	FD_ZERO(&mem_set); // review: forgot
	FD_SET(sockfd, &mem_set); // review: forgot
	bzero(&servaddr, sizeof(servaddr)); 

	// to-do: main loop
	while (42) {
		// to-do: initialization
		r_set = mem_set;
		w_set = mem_set;
		if (select(fd_max + 1, &r_set, &w_set, NULL, NULL)) {
			continue; // review: skipping to next iteration in the while loop
		}
		// to-do: handling readable fds
		for (int fd_i = 0; fd_i <= fd_max; fd_i++) {
			// to-do: new connection
			if (FD_ISSET(fd_i, &r_set)) {
				if (fd_i == sockfd) { // review: new connection!
					connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
					if (connfd < 0) { 
						// review: WRONG
						// write(2, "Fatal error\n", strlen("Fatal error\n"));
						// return (1);
						continue;
					}
					clients[connfd].id = id_i++;
					FD_SET(connfd, &mem_set);
					if (connfd > fd_max) { // review: forgot
						fd_max = connfd;
					}
					sprintf(buff_write, "server: client %d just arrived\n", clients[connfd].id); // review: forgot
					ft_send_to_all(connfd);
				}
			// to-do: already existing client
			} else {
				int rec = recv(fd_i, buff_read, 65536, 0); // review: put strlen(buff_read) instead of 65536
				if (rec < 0) {
					sprintf(buff_write, "server: client %d just left\n", clients[fd_i].id); // review: forgot
					ft_send_to_all(fd_i);
					FD_CLR(fd_i, &mem_set);
					close(fd_i);
				} else {
					int j = strlen(clients[fd_i].msg);
					for (int i = 0; i < rec; i++) { // review: forgot loop
						clients[fd_i].msg[j] = buff_read[i]; // review: put buff_write instead of buff_read
						if (clients[fd_i].msg[j] == '\n') {
							clients[fd_i].msg[j] = '\0';
							sprintf(buff_write, "client %d: %s\n", clients[fd_i].id, clients[fd_i].msg);
							ft_send_to_all(fd_i);
							bzero(&clients[fd_i].msg, sizeof(clients[fd_i].msg)); // review: forgot &
							j = -1;
						} j++;
					}
				}
			} break;
		}
	}
}
