#include <iostream>
#include "../header/node.h"

using namespace std;

void preOrder(node *root) {
    if (root != nullptr) {

        cout << " -> " << root->value;

        preOrder(root->left);
        preOrder(root->right);
    }
};

void inOrder(node *root) {
    if (root != nullptr) {

        inOrder(root->left);

        cout << " -> " << root->value;

        inOrder(root->right);
    }
};

void postOrder(node *root) {
    if (root != nullptr) {

        postOrder(root->left);
        postOrder(root->right);

        cout << " -> " << root->value;
    }
};