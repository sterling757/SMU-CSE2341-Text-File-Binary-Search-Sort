#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include <dsstring.h>

struct Algorithms {
public:
    //find effective pivot
    int medianOfThree(const dsString**&, int, int);

    void insertionSort(dsString**&, int, int);

    //Sort strings by length
    void sortLength(dsString**&, int, int);
    //Sort alphabetically
    void sortString(dsString**&, int, int);

    //test to see if arr portion is sorted
    bool isSorted_Length(dsString **, int, int);
    bool isSorted(dsString**, int, int);

    template <class T>
    inline void swap(T* a, T* b){
        T temp = *a;
        *a = *b;
        *b = temp;
    }

private:
    //quickSort by length
    void quickSort_Length(dsString**&, int, int);
    void dualPivot_Length(dsString**&, int, int, int&, int&);

    //quickSort alphabetically using a 3 qay partition
    void quickSort_String(dsString**&, int, int, int);
    void dualPivot_alph(dsString**&, int, int, int&, int&, int);
};

#endif // ALGORITHMS_H
