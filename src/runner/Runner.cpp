#include <iostream>
#include "Runner.h"

using namespace std;

void Runner::showActions() {

    int optionSelected;

    initialLog();

    cout << "1- Insert" << endl;
    cout << "2- Remove" << endl;
    cout << "3- Show Tree Pre Order" << endl;
    cout << "4- Show Tree In Order" << endl;
    cout << "5- Show Tree Post Order" << endl;
    cout << "6- Show Tree" << endl;
    cout << "7- Leave" << endl;
    cout << endl;
    cout << "Choose an option: ";

    cin >> optionSelected;

    executeAction(optionSelected);
}

void Runner::executeAction(int optionSelected) {

    const int insertOption = 1;
    const int removeOption = 2;
    const int showTreePreOrder = 3;
    const int showTreeInOrder = 4;
    const int showTreePostOrder = 5;
    const int showTree = 6;
    const int leaveOption = 7;

    int value;

    switch (optionSelected) {

        case insertOption:

            cleanConsole();

            cout << "Write value to insert: ";
            cin >> value;

            tree.insert(value, tree.getRoot());
            break;

        case removeOption:

            cleanConsole();

            cout << "Write value to remove: " << endl;
            cin >> value;

            tree.remove(value, false);
            break;

        case showTreePreOrder:

            cleanConsole();

            if (!isEmpty(tree.getRoot())) {
                tree.preOrder(tree.getRoot());
            }

            break;

        case showTreeInOrder:

            cleanConsole();

            if (!isEmpty(tree.getRoot())) {
                tree.inOrder(tree.getRoot());
            }

            break;

        case showTreePostOrder:

            cleanConsole();

            if (!isEmpty(tree.getRoot())) {
                tree.postOrder(tree.getRoot());
            }

            break;

        case showTree:

//            cleanConsole();
//            tree.showGraphic();

            tree.showAllTree(0, tree.getRoot());
            break;

        case leaveOption:
            return;

        default:

            cleanConsole();

            cout << "Invalid option! Please select a valid option." << endl;
            break;
    }

    showActions();
}

void Runner::cleanConsole() {
    system("clear");
}

bool Runner::isEmpty(Node *root) {
    return root == nullptr;
}

void Runner::initialLog() {

    cout << lineSeparator << endl;
    cout << logSeparator << endl;
    cout << avlFullName << endl;
    cout << logSeparator << endl;
}

void Runner::run() {
    showActions();
}