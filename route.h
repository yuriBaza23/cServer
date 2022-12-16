#include <stdlib.h>
#include <stdio.h>

typedef struct Route {
  char* key;
  char* value;
  struct Route *next, *prev; 
} Route;

Route* initRoute(char* key, char* value);