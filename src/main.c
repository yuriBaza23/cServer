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
	initServer(&httpServer, 9999);
	int clientSocket;
	
	Route* route = initRoute("/", "index.html"); 
  inorder(route);

  while(1) {
    char msg[90096] = "";
    clientSocket = accept(httpServer.socket, NULL, NULL);
    read(clientSocket, msg, 90095);
    printf("%s\n", msg);

    char* method = "";
    char* path = "";
    char* clientHeader = strtok(msg, "\n");
    char* header_token = strtok(clientHeader, " ");

    int parseCounter = 0;
    while(header_token != NULL) {
      if (parseCounter == 0) {
        method = header_token;
      } else if (parseCounter == 1) {
        path = header_token;
      }
      header_token = strtok(NULL, " ");
      parseCounter++;
    }

    char temp[90000] = "";
    if (strstr(path, "/static/") != NULL) {
			strcat(temp, "static/index.css");
      // ADD STATIC FILE METHOD HERE
		} else {
      Route* destination = search(route, path);
      strcat(temp, "pages/");
      if(destination != NULL) {
        strcat(temp, destination->value);
      } else {
        strcat(temp, "404.html");
      }
    }

    char* data = render(temp);
    char httpHeader[90096] = "HTTP/1.1 200 OK\r\n\r\n";
    strcat(httpHeader, data);
    strcat(httpHeader, "\r\n\r\n");
    send(clientSocket, httpHeader, sizeof(httpHeader), 0);
    close(clientSocket);
    free(data);
  }

	return 0;
}