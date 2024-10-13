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