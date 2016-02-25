#include "../header/Node.h"

Node *search(int value, Node *root) {

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

Node *major(Node *root) {

    if (root->right != nullptr) {
        return major(root->right);
    } else {
        return root;
    }
}

Node *minor(Node *root) {

    if (root->left != nullptr) {
        return minor(root->left);
    } else {
        return root;
    }
}