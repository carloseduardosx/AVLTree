#include "../header/avlFunctions.h"

void remove(int value, Node *root) {

    Node *aux;
    Node *foundedNode = search(value, root);

    if (foundedNode == nullptr) {
        return;
    } else {

        if (foundedNode->right == nullptr && foundedNode->left == nullptr) {

            delete foundedNode;
        } else {

            if (root != foundedNode && foundedNode->value >= root->value) {
                aux = minor(foundedNode);
            } else if (root != foundedNode && foundedNode->value < root->value) {
                aux = major(foundedNode);
            } else {

                if (foundedNode->right != nullptr) {
                    aux = minor(foundedNode->right);
                } else {
                    aux = major(foundedNode->left);
                }
            }

            foundedNode->value = aux->value;
            remove(aux->value, aux);
        }
    }
}