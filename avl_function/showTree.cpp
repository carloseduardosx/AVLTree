#include <iostream>
#include "../header/Node.h"

using namespace std;

void preOrder(Node *root) {
    if (root != nullptr) {

        cout << " -> " << root->value;

        preOrder(root->left);
        preOrder(root->right);
    }
};

void inOrder(Node *root) {
    if (root != nullptr) {

        inOrder(root->left);

        cout << " -> " << root->value;

        inOrder(root->right);
    }
};

void postOrder(Node *root) {
    if (root != nullptr) {

        postOrder(root->left);
        postOrder(root->right);

        cout << " -> " << root->value;
    }
};