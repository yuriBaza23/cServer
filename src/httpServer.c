#include "httpServer.h"
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>

void initServer(HTTPServer *server, int port) {
  server->port = port;
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(port);
	server_address.sin_addr.s_addr = INADDR_ANY;

	bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

	listen(server_socket, 5);

	server->socket = server_socket;
	printf("[OK] Server in port %d\n", server->port);
}