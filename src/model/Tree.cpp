#include "Tree.h"

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

            setRoot(nullptr);

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

                aux = foundedNode->getRight() != nullptr ? minor(foundedNode->getRight()) : major(foundedNode->getLeft());
            } else {
                return;
            }

            int auxValue = aux->getValue();

            remove(aux->getValue(), true);

            foundedNode->setValue(auxValue);
        }
    }
}

void Tree::removeAllNodes() {

    Node* aux = this->root;

    if (aux == nullptr) {
        return;
    }

    do {
        remove(aux->getValue(), false);
        aux = this->root;
    } while (aux != nullptr);
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

int Tree::min(int a, int b) {
    return a < b ? a : b;
}

int Tree::checkNumNodes(Node *root) {

    if (root == nullptr) {
        return 0;
    }

    int leftNodes = checkNumNodes(root->getLeft());
    int rightNodes = checkNumNodes(root->getRight());

    return leftNodes + rightNodes + 1;
}

bool Tree::containsNode(Node *nodes[], int length) {

    for (int i = 0; i < length; i++) {

        if (nodes[i] != nullptr) {
            return true;
        }
    }

    return false;
}

void Tree::showAllTree(int argsSize, Node *root, Node *nodes[], Node *lastNodes[]) {

    if (root != nullptr) {

        string rootSpaces;
        string auxSpaces;
        int rootHeight = checkHeight(root);
        int leftNodes = checkNumNodes(root->getLeft());
        int rightNodes = checkNumNodes(root->getRight());

        for (int i = 0; i < (rootHeight + leftNodes + rightNodes); i++) {
            rootSpaces.append(" ");
        }

        if (rootHeight > 2) {

            if ((max(leftNodes, rightNodes) - min(leftNodes, rightNodes) > 0)) {
                for (int i = 0; i < (max(leftNodes, rightNodes) - min(leftNodes, rightNodes)); i++) {
                    auxSpaces += " ";
                }
            } else {
                for (int i = 0; i < rootHeight; i++) {
                    auxSpaces += " ";
                }
            }
        }

        cout << auxSpaces << rootSpaces << root->getValue() << endl;

        rootSpaces.resize(rootSpaces.size() - rootHeight + 1);
        this->rootSpaces = rootSpaces;

        Node **children = new Node *[2];

        children[0] = root->getLeft();
        children[1] = root->getRight();

        showAllTree(2, nullptr, children, nullptr);
    } else {

        bool isFirstLoop = true;
        int nodeCursor = 0;
        int nodeQuantityByLevel = 2 * argsSize;
        int midArgsSize = (argsSize / 2) - 1;
        string valuesByLevel = "";
        Node **children = new Node *[nodeQuantityByLevel];

        for (int i = 0; i < argsSize; i++) {

            Node *node = nodes[i];

            int height = checkHeight(node);
            int leftNodesFromFather = node == nullptr ? 0 : checkNumNodes(node->getFather()->getLeft());
            int rightNodesFromFather = node == nullptr ? 0 : checkNumNodes(node->getFather()->getRight());

            if (node != nullptr) {

                if (isFirstLoop) {

                    valuesByLevel += rootSpaces + to_string(node->getValue());
                    rootSpaces.resize(rootSpaces.size() - height + 1);
                    isFirstLoop = false;
                } else {

                    for (int j = 0; j < (leftNodesFromFather + rightNodesFromFather); j++) {

                        valuesByLevel += " ";
                    }

                    valuesByLevel += to_string(node->getValue());
                }

                if (i == midArgsSize) {
                    valuesByLevel += this->defaultSpaces + " ";
                }

                children[nodeCursor++] = node->getLeft();
                children[nodeCursor++] = node->getRight();
            } else {

                if (isFirstLoop) {

                    valuesByLevel += rootSpaces + " ";
                    rootSpaces.resize(rootSpaces.size() - height + 1);
                    isFirstLoop = false;
                } else {

                    if (lastNodes != nullptr) {
                        Node *lastNode = lastNodes[i];

                        int heightFromLastNode = lastNode == nullptr ? 1 : checkHeight(lastNode);
                        int heightFromLeftLastNode = lastNode == nullptr ? 1 : checkHeight(lastNode->getLeft());
                        int heightFromRightLastNode = lastNode == nullptr ? 1 : checkHeight(lastNode->getRight());

                        if (((heightFromLeftLastNode + rightNodesFromFather) - heightFromLastNode) <= 0) {
                            valuesByLevel += defaultSpaces;
                        }

                        for (int j = 0; j < (max(heightFromLeftLastNode, heightFromRightLastNode) +
                                min(heightFromLeftLastNode, heightFromRightLastNode)) - heightFromLastNode; j++) {

                            valuesByLevel += " ";
                        }
                    } else {
                        valuesByLevel += " ";
                    }

                    if (i == midArgsSize) {
                        valuesByLevel += defaultSpaces;
                    }
                }

                children[nodeCursor++] = nullptr;
                children[nodeCursor++] = nullptr;
            }
        }

        cout << valuesByLevel << endl;

        if (containsNode(children, nodeQuantityByLevel)) {

            Node **futureLastNodes = new Node *[nodeQuantityByLevel];

            for (int o = 0; o < argsSize; o++) {

                for (int j = 0; j <= nodeQuantityByLevel; j++) {

                    futureLastNodes[j] = nodes[o];
                    futureLastNodes[++j] = nodes[o];
                    o++;

                    if (o == argsSize) {
                        break;
                    }
                }
            }
            showAllTree(nodeQuantityByLevel, nullptr, children, futureLastNodes);
        }
    }
}

Tree::~Tree() {

    if (this->root != nullptr) {
        remove(root->getValue(), false);
    }
}

void Tree::showRoot() {

    if (this->root != nullptr) {
        cout << "Root: " << this->root->getValue() << endl;
    }
}
