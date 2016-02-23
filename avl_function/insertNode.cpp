#include "../header/node.h"
#include "../header/avlFunctions.h"

node* insert(int value, node* root) {

    node* toAdd = new node();

    toAdd->value = value;

    if (root == nullptr) {
        return toAdd;
    }

    node* foundedNode = search(value, root);

    if (value >= foundedNode->value) {

        toAdd->father = foundedNode;
        foundedNode->left = toAdd;
    } else {

        toAdd->father = foundedNode;
        foundedNode->right = toAdd;
    }
}