// INCLUDES AND DEFINITIONS
#include <netdb.h> // definitions for network db operations
#include <netinet/in.h> // constants and structures for internet domain addresses
#include <stdio.h> // standard input/output
#include <stdlib.h> // memory allocation, process control, conversions, etc.
#include <string.h> // string handling functions
#include <sys/socket.h> // definitions for sockets
#include <unistd.h> // access to POSIX oeprating system API

// note: STEPS
// 1. client structure and global variables
// 2. function to send message to all clients
// 3. argument check
// 4. socket setup
// 5. initialization
// 6. main loop
	// 6.1. initialization
	// 6.2. handling readable FDs
		// 6.2.1. handling new clients
		// 6.2.2. handling data from existing clients
			// 6.2.2.1 client has disconnected
			// 6.2.2.2 process retrieved data

typedef struct s_client {
	int		id;
	char	msg[1024];
} t_client;

t_client	clients[4096];
char		buff_read[4096 * 42];
char		buff_write[4096 * 42 + 42];
int			fd_max = 0;
int			id_i = 0;
fd_set 		w_set, r_set, mem_set;

void	ft_send_to_all(int sender) {
	for (int fd_i = 0; fd_i <= fd_max; fd_i++) {
		if (FD_ISSET(fd_i, &w_set) && fd_i != sender) {
			send(fd_i, buff_write, strlen(buff_write), 0);
		}
	}
}

int	main(int ac, char **av) {
	if (ac != 2) {
		write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
		return (1);
	}

	int fd_sock, fd_conn, len;
	struct sockaddr_in servaddr, cliaddr;

	bzero(&servaddr, sizeof(servaddr));
	fd_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (fd_sock < 0) {
		write(2, "Fatal error\n", strlen("Fatal error\n"));
		return (1);
	}

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	servaddr.sin_port = hton(atoi(av[1]));

	if (bind(fd_sock, (const struct sockaddr *)&servaddr, sizeof(servaddr))) {
		write(2, "Fatal error\n", strlen("Fatal error\n"));
		return (1);
	}
	if (listen(fd_sock, 128)) {
		write(2, "Fatal error\n", strlen("Fatal error\n"));
		return (1);
	}

	len = sizeof(cliaddr);
	fd_max = fd_sock;
	FD_ZERO(&mem_set);
	FD_SET(fd_sock, &mem_set);
	bzero(clients, sizeof(clients));

	while (42) {
		w_set = mem_set;
		r_set = mem_set;
		if (select(fd_max + 1, &r_set, &w_set, NULL, NULL) < 0) {
			continue ;
		}
		for (int fd_i = 0; fd_i <= fd_max; fd_i++) {
			if (FD_ISSET(fd_i, &r_set)) {
				if (fd_i == fd_sock) {
					fd_conn = accept(fd_i, (struct sockaddr *)&cliaddr, (socklen_t *)&len);
					if (fd_conn < 0) {
						continue ;
					}
					clients[fd_conn].id = id_i++;
					FD_SET(fd_conn, &mem_set);
					if (fd_conn > fd_max) {
						fd_max = fd_conn;
					}
					sprintf(buff_write, "server: client %d just arrived\n", clients[fd_conn].id);
					ft_send_to_all(fd_conn);
				}
			} else {
				int rec = recv(fd_i, buff_read, 65536, 0);
				if (rec <= 0) {
					sprintf(buff_write, "server: client %d just left\n", clients[fd_i].id);
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
							bzero(&clients[fd_i].msg, sizeof(clients[fd_i].msg));
							j = -1;
						} j++;
					}
				}
			} break;
		}
	}
}
