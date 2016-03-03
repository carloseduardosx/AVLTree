#include <iostream>
#include "Tree.h"

using namespace std;

Tree::Tree() {

    this->root = nullptr;
}

Node *Tree::getRoot() {
    return this->root;
}

void Tree::setRoot(Node *root) {
    this->root = root;
}

void Tree::preOrder(Node *root) {
    if (root != nullptr) {

        cout << " -> " << root->getValue();

        preOrder(root->getLeft());
        preOrder(root->getRight());
    }
}

void Tree::inOrder(Node *root) {
    if (root != nullptr) {

        inOrder(root->getLeft());

        cout << " -> " << root->getValue();

        inOrder(root->getRight());
    }
}

void Tree::postOrder(Node *root) {
    if (root != nullptr) {

        postOrder(root->getLeft());
        postOrder(root->getRight());

        cout << " -> " << root->getValue();
    }
}

Node *Tree::search(int value, Node *root) {

    if (root == nullptr) {
        return nullptr;
    }

    if (value == root->getValue()) {

        return root;
    } else if (root->getRight() != nullptr && value >= root->getValue()) {

        return search(value, root->getRight());
    } else if (root->getLeft() != nullptr) {

        return search(value, root->getLeft());
    } else {

        return nullptr;
    }
}

Node *Tree::major(Node *root) {

    Node *aux = root;

    if (aux->getRight() != nullptr) {
        return major(aux->getRight());
    } else {
        return aux;
    }
}

Node *Tree::minor(Node *root) {

    Node *aux = root;

    if (aux->getLeft() != nullptr) {
        return minor(aux->getLeft());
    } else {
        return aux;
    }
}

void Tree::remove(int value, bool wasCalledBefore) {

    Node *aux;
    Node *foundedNode = search(value, this->root);

    if (foundedNode == nullptr) {
        return;
    } else {

        if (foundedNode == this->root && foundedNode->getRight() == nullptr && foundedNode->getLeft() == nullptr) {

            delete foundedNode;

            this->root = nullptr;

            return;
        }

        if ((foundedNode->getRight() == nullptr && foundedNode->getLeft() == nullptr) || wasCalledBefore) {

            if (foundedNode->getRight() == nullptr && foundedNode->getLeft() == nullptr) {

                if (foundedNode->getFather()->getRight() == foundedNode) {
                    foundedNode->getFather()->setRight(nullptr);
                } else {
                    foundedNode->getFather()->setLeft(nullptr);
                }

                aux = foundedNode->getFather();

                delete foundedNode;

                recalculateBalanceFactorForAffectedNodes(aux);
                return;
            }

            if (wasCalledBefore && foundedNode == this->root) {

                if (foundedNode->getRight() != nullptr) {

                    foundedNode->setValue(foundedNode->getRight()->getValue());
                    foundedNode->setRight(foundedNode->getRight()->getRight());
                    foundedNode->setLeft(foundedNode->getRight()->getLeft());

                    aux = minor(foundedNode->getRight());

                    delete foundedNode->getRight();

                    if (aux != nullptr) {
                        recalculateBalanceFactorForAffectedNodes(aux);
                    }

                    return;
                } else {

                    foundedNode->setValue(foundedNode->getLeft()->getValue());
                    foundedNode->setRight(foundedNode->getLeft()->getRight());
                    foundedNode->setLeft(foundedNode->getLeft()->getLeft());

                    aux = major(foundedNode->getLeft());

                    delete foundedNode->getLeft();

                    if (aux != nullptr) {
                        recalculateBalanceFactorForAffectedNodes(aux);
                    }

                    return;
                }
            } else if (wasCalledBefore && foundedNode->getValue() >= this->root->getValue()) {

                foundedNode->getRight()->setFather(foundedNode->getFather());
                foundedNode->getFather()->setRight(foundedNode->getRight());
            } else if (wasCalledBefore && foundedNode->getValue() < this->root->getValue()) {

                foundedNode->getLeft()->setFather(foundedNode->getFather());
                foundedNode->getFather()->setLeft(foundedNode->getLeft());
            }

            aux = foundedNode->getFather();

            delete foundedNode;

            recalculateBalanceFactorForAffectedNodes(aux);
        } else {

            if (this->root != foundedNode && foundedNode->getValue() >= this->root->getValue()) {

                aux = minor(foundedNode);
            } else if (this->root != foundedNode && foundedNode->getValue() < this->root->getValue()) {

                aux = major(foundedNode);
            } else if (foundedNode == this->root) {

                aux = foundedNode->getRight() != nullptr ? minor(foundedNode->getRight())
                                                         : major(foundedNode->getLeft());
            } else {
                return;
            }

            int auxValue = aux->getValue();

            remove(aux->getValue(), true);

            foundedNode->setValue(auxValue);
        }
    }
}

Node *Tree::createNode(int value) {

    return new Node(value);
}

void Tree::insert(int value, Node *root) {

    if (this->root == nullptr) {

        setRoot(createNode(value));

        return;
    }

    if (value >= root->getValue()) {

        if (root->getRight() == nullptr) {

            Node *toAdd = createNode(value);

            toAdd->setFather(root);
            root->setRight(toAdd);

            recalculateBalanceFactorForAffectedNodes(root);
        } else {

            insert(value, root->getRight());
        }
    } else if (value < root->getValue()) {

        if (root->getLeft() == nullptr) {

            Node *toAdd = createNode(value);

            toAdd->setFather(root);
            root->setLeft(toAdd);

            recalculateBalanceFactorForAffectedNodes(root);
        } else {

            insert(value, root->getLeft());
        }
    }
}

void Tree::rightRotate(Node *root) {

    root->getLeft()->setFather(root->getFather());
    root->setFather(root->getLeft());

    if (root->getLeft()->getLeft() != nullptr) {
        root->getLeft()->getLeft()->setFather(root->getFather());
    }

    root->setLeft(root->getLeft()->getRight());
    root->getFather()->setRight(root);

    if (root->getFather()->getFather() != nullptr && root->getFather()->getFather()->getLeft() == root) {

        root->getFather()->getFather()->setLeft(root->getFather());
    } else if (root->getFather()->getFather() != nullptr) {
        root->getFather()->getFather()->setRight(root->getFather());
    }

    if (root == this->root) {
        this->root = root->getFather();
    }
}

void Tree::leftRotate(Node *root) {

    root->getRight()->setFather(root->getFather());
    root->setFather(root->getRight());

    if (root->getRight()->getRight() != nullptr) {
        root->getRight()->getRight()->setFather(root->getFather());
    }

    root->setRight(root->getRight()->getLeft());
    root->getFather()->setLeft(root);

    if (root->getFather()->getFather() != nullptr && root->getFather()->getFather()->getRight() == root) {

        root->getFather()->getFather()->setRight(root->getFather());
    } else if (root->getFather()->getFather() != nullptr) {

        root->getFather()->getFather()->setLeft(root->getFather());
    }

    if (root == this->root) {
        this->root = root->getFather();
    }
}

void Tree::rightLeftRotate(Node *root) {

    rightRotate(root->getRight());
    leftRotate(root);
}

void Tree::leftRightRotate(Node *root) {

    leftRotate(root->getLeft());
    rightRotate(root);
}

void Tree::recalculateBalanceFactorForAffectedNodes(Node *root) {

    Node *aux = root;

    do {

        int rightHeight = checkHeight(aux->getRight());
        int leftHeight = checkHeight(aux->getLeft());

        aux->setFb(rightHeight - leftHeight);

        if (aux->getFb() >= 2) {

            balance(aux, true);
            return;
        } else if (aux->getFb() <= -2) {

            balance(aux, false);
            return;
        }

        aux = aux->getFather();
    } while (aux != nullptr);
}

// FB: Altura do lado direito menos altura do lado esquerdo
// Distância: É o FB do nô desbalanceado menos o FB do nô filho que está para o lado pendente
// Distância: Se distância > 2 || < -2 então faremos rotação dupla.

/*
 * Deve-se tomar como base o sinal do fb para sabermos para onde iremos rotacionar
 * Se distância > 2 || <- 2 e o FB é posítivo então faremos rotação direita/esquerda
 * Se distância > 2 || <- 2 e o FB é negativo então faremos rotação esquerda/direita
 */
void Tree::balance(Node *root, bool toRight) {

    int distance;
    Node *aux = root;

    if (toRight) {

        distance = aux->getFb() - aux->getRight()->getFb();

        distance > 2 || distance < -2 ? rightLeftRotate(aux) : leftRotate(aux);
    } else {

        distance = aux->getFb() - aux->getLeft()->getFb();

        distance > 2 || distance < -2 ? leftRightRotate(aux) : rightRotate(aux);
    }

    recalculateBalanceFactorForAffectedNodes(aux);
}

int Tree::checkHeight(Node *root) {

    if (root == nullptr) {
        return 0;
    }

    int heightLeft = checkHeight(root->getLeft());
    int heightRight = checkHeight(root->getRight());

    return this->max(heightLeft, heightRight) + 1;
}

int Tree::max(int a, int b) {
    return a > b ? a : b;
}

int Tree::checkNumNodes(Node *root) {

    if (root == nullptr) {
        return 0;
    }

    int leftNodes = checkNumNodes(root->getLeft());
    int rightNodes = checkNumNodes(root->getRight());

    return leftNodes + rightNodes + 1;
}

void Tree::cleanGraphicData() {

    leftIndex = 0;
    rightIndex = 0;

    leftSubTree->clear();
    rightSubTree->clear();
}

void Tree::showGraphic() {

    showRootAndStoreSubTrees(this->root, false, false);
    buildAndShowSubTrees();
    cleanGraphicData();
}

void Tree::buildAndShowSubTrees() {

    string lineNodeValues = "";
    unsigned long rightSubTreeLength = rightSubTree->length();

    for (int i = 0; i < rightSubTreeLength; i++) {

        if (leftSubTree[i].empty() && rightSubTree[i].empty()) {

            break;
        } else if (!leftSubTree[i].empty() && !rightSubTree[i].empty()) {

            cout << leftSubTree[i].append(rightSubTree[i]) << endl;
        } else {

            if (!leftSubTree[i].empty()) {
                lineNodeValues.append(leftSubTree[i]);
            }

            if (!rightSubTree[i].empty()) {
                lineNodeValues.append(rightSubTree[i]);
            }

            cout << lineNodeValues << endl;
        }
    }
}

void Tree::showRootAndStoreSubTrees(Node *root, bool toRight, bool isRightBrace) {

    int height = checkHeight(root);
    int leftNodes = root == nullptr ? 1 : checkNumNodes(root->getLeft());
    int rightNodes = root == nullptr ? 1 : checkNumNodes(root->getRight());

    if (height > 0 && root != nullptr) {

        if (root == this->root) {

            string spaces = "";
            int spacesToShowRoot = height * leftNodes == 0 ? 1 : leftNodes;

            for (int i = 0; i < spacesToShowRoot; i++) {
                spaces.append(" ");
            }

            cout << spaces << root->getValue() << endl;

            showRootAndStoreSubTrees(root->getLeft(), false, false);
            showRootAndStoreSubTrees(root->getRight(), true, true);
        } else if (toRight) {

            string spaces = "";
            int spacesToShowRoot = (height * leftNodes == 0 ? 1 : leftNodes)
                                   + (height * rightNodes == 0 ? 1 : rightNodes);

            for (int i = 0; i < spacesToShowRoot; i++) {
                spaces.append(" ");
            }

            if (isRightBrace) {
                rightSubTree[rightIndex++] = spaces.append(to_string(root->getValue()));
            } else {
                leftSubTree[leftIndex++] = spaces.append(to_string(root->getValue()));
            }

            showRootAndStoreSubTrees(root->getLeft(), false, isRightBrace);
            showRootAndStoreSubTrees(root->getRight(), true, isRightBrace);
        } else {

            string spaces = "";
            int spacesToShowNode = height * leftNodes;

            for (int i = 0; i < spacesToShowNode; i++) {
                spaces.append(" ");
            }

            if (isRightBrace) {
                rightSubTree[rightIndex++] = spaces.append(to_string(root->getValue()));
            } else {
                leftSubTree[leftIndex++] = spaces.append(to_string(root->getValue()));
            }

            showRootAndStoreSubTrees(root->getLeft(), false, isRightBrace);
            showRootAndStoreSubTrees(root->getRight(), true, isRightBrace);
        }
    }
}

Tree::~Tree() {

    if (this->root != nullptr) {
        remove(root->getValue(), false);
    }
}