#ifndef AVL_TREE_RUNNER_H
#define AVL_TREE_RUNNER_H

#include "../model/Node.h"
#include "../model/Tree.h"

class Runner {

private:

    Tree tree;

    string lineSeparator = "\n";
    string logSeparator = "---------------------------------------------------------";
    string avlFullName = "Georgy Adelson-Velsky and Evgenii Landis' Tree";

    void showActions();

    void executeAction(int optionSelected);

    bool isEmpty(Node *root);

    void initialLog();

    void cleanConsole();

public:

    void run();
};

#endif