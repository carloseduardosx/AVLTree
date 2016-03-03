#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(int value, int fb, Node *father, Node *right, Node *left) {

    this->fb = fb;
    this->value = value;
    this->father = father;
    this->right = right;
    this->left = left;
}

int Node::getFb() {
    return this->fb;
}

void Node::setFb(int fb) {
    this->fb = fb;
}

int Node::getValue() {
    return this->value;
}

void Node::setValue(int value) {
    this->value = value;
}

bool Node::getSavedToPrint() {
    return this->savedToPrint;
}

void Node::setSavedToPrint(bool savedToPrint) {
    this->savedToPrint = savedToPrint;
}

Node *Node::getFather() {
    return this->father;
}

void Node::setFather(Node *father) {
    this->father = father;
}

Node *Node::getRight() {
    return this->right;
}

void Node::setRight(Node *right) {
    this->right = right;
}

Node *Node::getLeft() {
    return this->left;
}

void Node::setLeft(Node *left) {
    this->left = left;
}

Node::~Node() {
}