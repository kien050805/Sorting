/*===========================================================================
Kien Le, Nguyen Nguyen, Bach Nguyen
12 October 2024
mytests.cpp
This file runs various tests on every sorting functions in sorting.hpp
===========================================================================*/

#include <iostream>
#include "sorting.cpp"

using namespace std;


int main()
{
    int A[8] = {2,8,7,1,3,5,6,4};
    int B[0] = {};
    string C[5] = {"a", "d", "b", "f", "."};
    quicksort(A, 8);
    quicksort(B, 0);
    quicksort(C, 5);
    for (int i = 0; i < 8; i++)
    {
        cout << A[i] << ' ';
    };
    cout << endl;
    for (int i = 0; i < 0; i++)
    {
        cout << B[i] << ' ';
    };
    cout << B;
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << C[i] << ' ';
    };
    return 0;
};