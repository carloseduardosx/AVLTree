#include "../header/node.h"

static int leftHeight = 0;
static int rightHeight = 0;

// FB: Altura do lado esquerdo menos altura do lado direito
// Distância: É o FB do nô desbalanceado menos o FB do nô filho que está para o lado que está pendendo
// Distância: Se distância >2 || <-2 então faremos rotação dupla.

/*
 * Deve-se tomar como base o sinal do fb para sabermos para onde iremos rotacionar
 * Se distância >2 || <-2 e o FB é posítivo então faremos rotação direita/esquerda
 * Se distância >2 || <-2 e o FB é negativo então faremos rotação esquerda/direita
 */


void cleanFields() {
    leftHeight = 0;
    rightHeight = 0;
}

void rightRotate(node *root) {

    root->left->father = root->father;
    root->father = root->left;

    if (root->left->right != nullptr) {
        root->left->right->father = root;
    }

    root->left = root->left->right;
    root->father->right = root;

    if (root->father->father != nullptr && root->father->father->left == root) {

        root->father->father->left = root->father;
    } else if (root->father->father != nullptr) {
        root->father->father->right = root->father;
    }
}

void leftRotate(node *root) {

    root->right->father = root->father;
    root->father = root->right;

    if (root->right->right != nullptr) {
        root->right->right->father = root;
    }

    root->right = root->right->right;
    root->father->left = root;

    if (root->father->father != nullptr && root->father->father->right == root) {

        root->father->father->right = root->father;
    } else if (root->father->father != nullptr) {

        root->father->father->left = root->father;
    }
}

void rightLeftRotate(node *root) {

    rightRotate(root->right);
    leftRotate(root);
}

void leftRightRotate(node *root) {

    leftRotate(root->left);
    rightRotate(root);
}

void checkHeight(node *root) {

    if (root != nullptr) {

        if (root->right != nullptr) {

            rightHeight++;
            checkHeight(root->right);
        } else if (root->left != nullptr) {

            leftHeight++;
            checkHeight(root->left);
        }
    }
}

void checkBalancing(node *root) {

    checkHeight(root);

    int fb = rightHeight - leftHeight;

    if (fb > 1) {

        cleanFields();
        checkHeight(root->right);

        int fbChild = rightHeight - leftHeight;
        int distance = fb - fbChild;

        if (distance > 2 || distance < -2) {

            rightLeftRotate(root);
        } else {

            leftRotate(root);
        }

    } else if (fb < -1) {

        cleanFields();
        checkHeight(root->left);

        int fbChild = rightHeight - leftHeight;
        int distance = fb - fbChild;

        if (distance > 2 || distance < -2) {

            leftRightRotate(root);
        } else {

            rightRotate(root);
        }
    }
}