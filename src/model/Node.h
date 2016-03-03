#ifndef AVL_TREE_NODE_H
#define AVL_TREE_NODE_H

#include <iostream>

using namespace std;

class Node {

private:

    int fb;
    int value;
    bool savedToPrint;
    Node *father, *right, *left;

public:

    Node(int value, int fb = 0, Node *father = nullptr, Node *right = nullptr, Node *left = nullptr);

    int getFb();

    void setFb(int fb);

    int getValue();

    void setValue(int value);

    bool getSavedToPrint();

    void setSavedToPrint(bool savedToPrint);

    Node *getFather();

    void setFather(Node *father);

    Node *getRight();

    void setRight(Node *right);

    Node *getLeft();

    void setLeft(Node *left);

    ~Node();
};

#endif