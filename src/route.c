#include "route.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Route* initRoute(char* key, char* value) {
  Route* route = malloc(sizeof(Route));

  route->key = key;
  route->value = value;

  route->left = route->right = NULL;
  return route;
}

Route* search(Route* root, char* key) {
  if (root == NULL) {
		return NULL;
	} 

	if (strcmp(key, root->key) == 0){
		return root;
	} else if (strcmp(key, root->key) > 0) {
		return search(root->right, key);
	} else if (strcmp(key, root->key) < 0) {
		return search(root->left, key);
	}  
}

void inorder(struct Route* root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%s -> %s \n", root->key, root->value);
    inorder(root->right);
  }
}