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
    insertion_sort(A, 0, 4);
    cout << A;
    return 0;
};