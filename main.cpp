#include <iostream>
#include "sorter.h"

using namespace std;

int main(int argc, char *argv[]) {
    Sorter sorter;

    sorter.readInput(argv[1]);
    sorter.sort();
    sorter.writeOutput(argv[2]);
}
