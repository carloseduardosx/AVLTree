#ifndef AVL_TREE_NODE_H
#define AVL_TREE_NODE_H

struct node {
    int value;
    node * father;
    node * right;
    node * left;
};

#endif