#include "../header/node.h"

node* search(int value, node* root) {

    if (root == nullptr) {
        return nullptr;
    }

    if (value == root->value) {
        return root;
    } else if (root->right != nullptr && value >= root->value) {
        search(value, root->right);
    } else if (root->left != nullptr && value < root->value) {
        search(value, root->left);
    }

    return root;
}

node* major(node* root) {

    if (root->right != nullptr) {
        return major(root->right);
    } else {
        return root;
    }
}

node* minor(node* root) {

    if (root->left != nullptr) {
        return minor(root->left);
    } else {
        return root;
    }
}