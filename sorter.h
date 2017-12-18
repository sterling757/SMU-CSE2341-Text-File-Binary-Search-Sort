#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include <fstream>

#include "dsstring.h"
#include "algorithms.h"

class Sorter{
public:
    Sorter();

    //sorts the file by length and alphabetically
    void sort();

    //Reads in file from argv[1]
    void readInput(char*);
    //Writes out to output file to argv[2]
    void writeOutput(char*);

    ~Sorter();
private:
    Algorithms alg;
    dsString** s_ptr;
    int totalWords;
    int wordsToSort;
};

#endif // SORTER_H
