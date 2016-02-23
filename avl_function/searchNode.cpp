#include "../header/node.h"

node* search(int value, node* root) {

    if (root == nullptr) {
        return nullptr;
    }

    if (value == root->value) {
        return root;
    } else if (root->left != nullptr && value >= root->value) {
        search(value, root->left);
    } else if (root->right != nullptr && value < root->value) {
        search(value, root->right);
    }

    return root;
}

node* major(node* root) {

    if (root->left != nullptr) {
        major(root->left);
    }

    return root;
}

node* minor(node* root) {

    if (root->right != nullptr) {
        minor(root->right);
    }

    return root;
}