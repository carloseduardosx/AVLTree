#ifndef AVL_TREE_TREE_H
#define AVL_TREE_TREE_H

#include "Node.h"

class Tree {

private:

    int rightHeight = 0;
    int leftHeight = 0;
    Node *root;

    int max(int a, int b);

    void balance(Node *root, bool toRight);

    void recalculateBalanceFactorForAffectedNodes(Node *root);

public:

    Tree();

    Node *getRoot();

    void setRoot(Node *root);

    void preOrder(Node *root);

    void inOrder(Node *root);

    void postOrder(Node *root);

    Node *search(int value, Node *root);

    Node *major(Node *root);

    Node *minor(Node *root);

    void remove(int value);

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