/*===========================================================================
Kien Le, Nguyen Nguyen, Bach Nguyen
12 October 2024
sorting.cpp
This file contains the implementations of the sorting functions in sorting.hpp
===========================================================================*/

#include <iostream>
#include "sorting.hpp"

/*===========================================================================
Insertion Sort
The function goes through the unsorted list and insert each element of the
unsorted portion into its correct position in the sorted portion of the list.
Parameters: the array to be sorted, length of array
Return: void
===========================================================================*/
template <class T>
void insertion_sort(T *arr, long n)
{
    // Iterate through the array starting from index 1
    for (int i = 1; i < n; i++)
    {
        T val = arr[i];
        T j = i - 1;
        // While the element next to be sorted is smaller
        // than the max in the sorted, move it back
        while (j >= 0 && arr[j] > val)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = val;
    }
}
