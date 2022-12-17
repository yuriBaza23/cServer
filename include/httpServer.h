#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

typedef struct HTTPServer {
  int socket;
  int port;
} HTTPServer;

void initServer(HTTPServer *server, int port);

#endif