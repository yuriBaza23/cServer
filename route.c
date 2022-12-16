#include "route.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Route* initRoute(char* key, char* value) {
  Route* route = malloc(sizeof(Route));

  route->key = key;
  route->value = value;

  route->next = NULL;
  route->prev = NULL;
  return route;
}