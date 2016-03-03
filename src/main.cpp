#include <iostream>
#include "runner/Runner.h"

using namespace std;

int main() {

    Runner *runner = new Runner();

    runner->run();

    return EXIT_SUCCESS;
}