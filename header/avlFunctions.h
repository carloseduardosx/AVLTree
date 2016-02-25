#ifndef AVL_TREE_AVLFUNCTIONS_H
#define AVL_TREE_AVLFUNCTIONS_H

#include "Node.h"

// Principal
Node *search(int value, Node *root);

Node *minor(Node *root);

Node *major(Node *root);

Node *insert(int value, Node *root);

void remove(int value, Node *root);

// Show Tree
void preOrder(Node *root);

void inOrder(Node *root);

void postOrder(Node *root);

// Util
void initialLog();

bool isEmpty(Node *root);

#endif