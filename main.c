#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "httpServer.h"
#include "route.h"
#include "response.h"

int main() {
	HTTPServer httpServer;
	initServer(&httpServer, 3333);
	int socket;
	
	struct Route* route = initRoute("/", "index.html"); 

	return 0;
}