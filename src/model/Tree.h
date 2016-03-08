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
    string breakLine = "\n";
    string rightBrace = "\\";
    string leftBrace = "/";
    string defaultSpaces = "  ";

    int max(int a, int b);

    int checkNumNodes(Node *root);

    void balance(Node *root, bool toRight);

    void recalculateBalanceFactorForAffectedNodes(Node *root);

    bool containsNode(Node *nodes[], int length);

public:

    Tree();

    Node *getRoot();

    void setRoot(Node *root);

    void showAllTree(int argsSize, Node *root, Node *nodes[], Node *lastNodes[]);

    void preOrder(Node *root);

    void inOrder(Node *root);

    void postOrder(Node *root);

    Node *search(int value, Node *root);

    Node *major(Node *root);

    Node *minor(Node *root);

    void remove(int value, bool wasCalledBefore);

    void removeAllNodes();

    Node *createNode(int value);

    void insert(int value, Node *root);

    void rightRotate(Node *root);

    void leftRotate(Node *root);

    void rightLeftRotate(Node *root);

    void leftRightRotate(Node *root);

    int checkHeight(Node *root);

    ~Tree();
};

#endif