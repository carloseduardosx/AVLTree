#include <iostream>
#include "../header/node.h"

using namespace std;

string lineSeparator = "\n";
string logSeparator = "---------------------------------------------------------";
string avlFullName = "Georgy Adelson-Velsky and Evgenii Landis' Tree";

bool isEmpty(node *root) {
    return root == nullptr;
}

void initialLog() {

    cout << lineSeparator << endl;
    cout << logSeparator << endl;
    cout << avlFullName << endl;
    cout << logSeparator << endl;
}