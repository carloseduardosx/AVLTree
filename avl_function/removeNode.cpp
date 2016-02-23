#include "../header/node.h"
#include "../header/avlFunctions.h"

void remove(int value, node* root) {

    node* aux;
    node* foundedNode = search(value, root);

    if (foundedNode == nullptr) {
        return;
    } else {

        if (foundedNode->right == nullptr && foundedNode->left == nullptr) {

            delete foundedNode;
        } else {

            if (foundedNode->right != nullptr) {
                aux = minor(root->right);
            } else {
                aux = major(root->left);
            }

            foundedNode->value = aux->value;
            remove(aux->value, aux);
        }
    }
}