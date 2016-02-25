#include <iostream>
#include "../header/Node.h"

using namespace std;

string lineSeparator = "\n";
string logSeparator = "---------------------------------------------------------";
string avlFullName = "Georgy Adelson-Velsky and Evgenii Landis' Tree";

bool isEmpty(Node *root) {
    return root == nullptr;
}

void initialLog() {

    cout << lineSeparator << endl;
    cout << logSeparator << endl;
    cout << avlFullName << endl;
    cout << logSeparator << endl;
}