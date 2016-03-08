#ifndef AVL_TREE_NODE_H
#define AVL_TREE_NODE_H

#include <iostream>

using namespace std;

class Node {

private:

    int fb;
    int value;
    Node *father, *right, *left;

public:

    Node();

    Node(int value, int fb = 0, Node *father = nullptr, Node *right = nullptr, Node *left = nullptr);

    int getFb();

    void setFb(int fb);

    int getValue();

    void setValue(int value);

    Node *getFather();

    void setFather(Node *father);

    Node *getRight();

    void setRight(Node *right);

    Node *getLeft();

    void setLeft(Node *left);

    ~Node();
};

#endif