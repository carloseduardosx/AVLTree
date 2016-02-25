#ifndef AVL_TREE_NODE_H
#define AVL_TREE_NODE_H

class Node {

public:

    int value;
    Node *father;
    Node *right;
    Node *left;
};

#endif