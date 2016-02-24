#include <iostream>
#include "header/node.h"
#include "header/avlFunctions.h"

using namespace std;

void showActions();

void executeAction(int optionSelected);

node *root = nullptr;

int main() {

    showActions();

    return 0;
}

void showActions() {

    int optionSelected;

    initialLog();

    cout << "1- Insert" << endl;
    cout << "2- Remove" << endl;
    cout << "3- Show Tree Pre Order" << endl;
    cout << "4- Show Tree In Order" << endl;
    cout << "5- Show Tree Post Order" << endl;
    cout << "6- Leave" << endl;
    cout << "\nChoose an option: ";

    cin >> optionSelected;

    executeAction(optionSelected);
}

void executeAction(int optionSelected) {

    const int insertOption = 1;
    const int removeOption = 2;
    const int showTreePreOrder = 3;
    const int showTreeInOrder = 4;
    const int showTreePostOrder = 5;
    const int leaveOption = 6;

    int value;

    switch (optionSelected) {

        case insertOption:

            cout << "Write value to insert: ";
            cin >> value;

            if (root == nullptr) {
                root = insert(value, nullptr);
            } else {
                insert(value, root);
            }
            break;

        case removeOption:

            cout << "Write value to remove: " << endl;
            cin >> value;

            remove(value, root);
            break;

        case showTreePreOrder:

            if (!isEmpty(root)) {
                preOrder(root);
            }

            break;

        case showTreeInOrder:

            if (!isEmpty(root)) {
                inOrder(root);
            }

            break;

        case showTreePostOrder:

            if (!isEmpty(root)) {
                postOrder(root);
            }

            break;

        case leaveOption:
            return;

        default:

            cout << "Invalid option! Please select a valid option." << endl;
            break;
    }

    showActions();
}