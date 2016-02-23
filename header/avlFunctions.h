#ifndef AVL_TREE_AVLFUNCTIONS_H
#define AVL_TREE_AVLFUNCTIONS_H

#include "node.h"

node* minor(node* root);
node* major(node* root);
node* search(int value, node* root);
node* insert(int value, node* root);
void remove(int value, node* root);

#endif