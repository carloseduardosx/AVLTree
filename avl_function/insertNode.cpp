#include "../header/node.h"
#include "../header/avlFunctions.h"

node *createNodeWithValue(int value) {

    node *node = new struct node();

    node->value = value;

    return node;
}

node *insert(int value, node *root) {

    if (root == nullptr) {

        node *toAdd = createNodeWithValue(value);

        return toAdd;
    }

    if (value >= root->value) {

        if (root->right == nullptr) {

            node *toAdd = createNodeWithValue(value);

            toAdd->father = root;
            root->right = toAdd;

            return toAdd;
        } else {

            insert(value, root->right);
        }
    } else if (value < root->value) {

        if (root->left == nullptr) {

            node *toAdd = createNodeWithValue(value);

            toAdd->father = root;
            root->left = toAdd;

            return toAdd;
        } else {

            insert(value, root->left);
        }
    }
}