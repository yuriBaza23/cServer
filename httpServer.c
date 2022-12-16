#include "httpServer.h"
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>

void initServer(HTTPServer *server, int port) {
  server->port = port;
  int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(port);
	serverAddress.sin_addr.s_addr = INADDR_ANY;

	bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));

	listen(serverSocket, 5);

	server->socket = serverSocket;
	printf("[OK] Server in port %d\n", server->port);
}