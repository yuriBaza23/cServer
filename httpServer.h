#ifndef HTTPSERVER_H
#define HTTPSERVER_H

typedef struct HTTPServer {
  int port;
  int socket;
} HTTPServer;

void initServer(HTTPServer *server, int port);

#endif