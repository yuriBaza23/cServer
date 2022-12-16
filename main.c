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
	
	Route* route = initRoute("/", "index.html"); 

  while(1) {
    char msg[4096] = "";
    socket = accept(httpServer.socket, NULL, NULL);
    read(socket, msg, 4095);
    printf("%s\n", msg);

    char* method = "";
    char* path = "";
    char* clientHeader = strtok(msg, "\n");
    char* tokenHeader = strtok(clientHeader, " ");

    int parseCounter = 0;
    while(tokenHeader != NULL) {
      if (parseCounter == 0) {
        method = tokenHeader;
      } else if (parseCounter == 1) {
        path = tokenHeader;
      }
      tokenHeader = strtok(NULL, " ");
      parseCounter++;
    }

    char temp[4096] = "";
    if (strstr(path, "/") != NULL) {
			strcat(temp, "index.css");
		}

    char* data = render(temp);
    char httpHeader[4096] = "HTTP/1.1 200 OK\r\n\r\n";
    strcat(httpHeader, data);
    strcat(httpHeader, "\r\n\r\n");
    send(socket, httpHeader, sizeof(httpHeader), 0);
    close(socket);
    free(data);
  }

	return 0;
}