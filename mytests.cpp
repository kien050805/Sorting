/*===========================================================================
Kien Le, Nguyen Nguyen, Bach Nguyen
12 October 2024
mytests.cpp
This file runs various tests on every sorting functions in sorting.hpp
===========================================================================*/

#include <iostream>
#include "sorting.hpp"
#include "sorting.cpp"

using namespace std;


int main()
{
    int A[4] = {4,3,2,1};
    int B[] = {};
    insertion_sort(A, 4);
    insertion_sort(B, 0);
    for (int i = 0; i < 4; i++)
    {
        cout << A[i] << ' ';
    };
    for (int i = 0; i < 0; i++)
    {
        cout << B[i] << ' ';
    };
    return 0;
};