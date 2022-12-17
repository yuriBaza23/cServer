#include <stdlib.h>
#include <stdio.h>

typedef struct Route {
  char* key;
  char* value;
  struct Route *right, *left; 
} Route;

Route* initRoute(char* key, char* value);
void inorder(Route* root);
Route* search(Route * root, char* key);