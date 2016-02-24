#ifndef AVL_TREE_AVLFUNCTIONS_H
#define AVL_TREE_AVLFUNCTIONS_H

#include "node.h"

// Principal
node* search(int value, node* root);
node* minor(node* root);
node* major(node* root);
node* insert(int value, node* root);
void remove(int value, node* root);

// Show Tree
void preOrder(node *root);
void inOrder(node *root);
void postOrder(node *root);

// Util
void initialLog();
bool isEmpty(node *root);

#endif