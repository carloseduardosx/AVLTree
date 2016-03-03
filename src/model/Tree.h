#ifndef AVL_TREE_TREE_H
#define AVL_TREE_TREE_H

#include "Node.h"

class Tree {

private:

    Node *root;

    int leftIndex = 0;
    int rightIndex = 0;

    string breakLine = "\n";
    string rightBrace = "\\";
    string leftBrace = "/";

    string leftSubTree[100];
    string rightSubTree[100];

    int max(int a, int b);

    int checkNumNodes(Node *root);

    void balance(Node *root, bool toRight);

    void recalculateBalanceFactorForAffectedNodes(Node *root);

    void showRootAndStoreSubTrees(Node *root, bool toRight, bool isRightBrace);

    void buildAndShowSubTrees();

    void cleanGraphicData();

public:

    Tree();

    Node *getRoot();

    void showGraphic();

    void setRoot(Node *root);

    void preOrder(Node *root);

    void inOrder(Node *root);

    void postOrder(Node *root);

    Node *search(int value, Node *root);

    Node *major(Node *root);

    Node *minor(Node *root);

    void remove(int value, bool wasCalledBefore);

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