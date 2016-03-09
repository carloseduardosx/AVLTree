#ifndef AVL_TREE_TREE_H
#define AVL_TREE_TREE_H

#include <iostream>
#include <math.h>
#include "Node.h"

using namespace std;

class Tree {

private:

    Node *root;

    string rootSpaces = "";
    string defaultSpaces = "  ";

    int max(int a, int b);

    int min(int a, int b);

    int checkHeight(Node *root);

    int checkNumNodes(Node *root);

    void balance(Node *root, bool toRight);

    void recalculateBalanceFactorForAffectedNodes(Node *root);

    bool containsNode(Node *nodes[], int length);

    void rightRotate(Node *root);

    void leftRotate(Node *root);

    void rightLeftRotate(Node *root);

    void leftRightRotate(Node *root);

    Node *search(int value, Node *root);

    Node *major(Node *root);

    Node *minor(Node *root);

    Node *createNode(int value);

public:

    Tree();

    Node *getRoot();

    void setRoot(Node *root);

    void showRoot();

    void showAllTree(int argsSize, Node *root, Node *nodes[], Node *lastNodes[]);

    void preOrder(Node *root);

    void inOrder(Node *root);

    void postOrder(Node *root);

    void remove(int value, bool wasCalledBefore);

    void removeAllNodes();

    void insert(int value, Node *root);

    ~Tree();
};

#endif