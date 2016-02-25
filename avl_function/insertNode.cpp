#include "../header/avlFunctions.h"

Node *createNodeWithValue(int value) {

    Node *node = new Node();

    node->value = value;

    return node;
}

Node *insert(int value, Node *root) {

    if (root == nullptr) {

        Node *toAdd = createNodeWithValue(value);

        return toAdd;
    }

    if (value >= root->value) {

        if (root->right == nullptr) {

            Node *toAdd = createNodeWithValue(value);

            toAdd->father = root;
            root->right = toAdd;

            return toAdd;
        } else {

            insert(value, root->right);
        }
    } else if (value < root->value) {

        if (root->left == nullptr) {

            Node *toAdd = createNodeWithValue(value);

            toAdd->father = root;
            root->left = toAdd;

            return toAdd;
        } else {

            insert(value, root->left);
        }
    }
}