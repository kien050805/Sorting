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
    };
};


// merge function
// Merges two arrays back into one for merge_sort
// Parameters: left array, right array, length of original array
// Return: Merged array
template <class T>
T *merge(T *left, T *right, long n)
{
    long mid = n / 2;
    T *res_arr = new T[n];
    long res_counter = 0, left_counter = 0, right_counter = 0;

    // Merge two sorted subarrays
    while (left_counter < mid && right_counter < (n - mid))
    {
        if (left[left_counter] <= right[right_counter])
        {
            res_arr[res_counter++] = left[left_counter++];
        }
        else
        {
            res_arr[res_counter++] = right[right_counter++];
        }
    }

    // Copy remaining elements from left array
    while (left_counter < mid)
    {
        res_arr[res_counter++] = left[left_counter++];
    }

    // Copy remaining elements from right array
    while (right_counter < (n - mid))
    {
        res_arr[res_counter++] = right[right_counter++];
    }

    return res_arr;
}


/*===========================================================================
Merge Sort
This function partitions the unsorted array in halfs until it can no longer
be divided and recursively sort each array individually and merged back
together in sorted order.
Parameters: the array to be sorted, length of array
Return: the sorted array
===========================================================================*/
template <class T>
T *merge_sort(T *arr, long n)
{
    if (n <= 1)
    {
        return arr;
    };

    long mid = n / 2;
    T left[mid];
    T right[n - mid];

    for (long i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    };
    for (long i = mid; i < n; i++)
    {
        right[i - mid] = arr[i];
    };
    T *temp = merge_sort(left, mid);
    for (long i = 0; i < mid; i++)
    {
        left[i] = temp[i];
    }
    temp = merge_sort(right, n - mid);
    for (long i = mid; i < n; i++)
    {
        right[i - mid] = temp[i - mid];
    };

    T *ordered_arr = merge(left, right, n);

    return ordered_arr;
};

template <class T>
long partition(T *arr, long p, long r)
{
    T x = arr[r - 1];
    long i = p - 1;
    for (int j = p; j < r - 1; j++)
    {
        if (arr[j] <= x)
        {
            i = i + 1;
            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    };
    T temp = arr[i + 1];
    arr[i + 1] = arr[r - 1];
    arr[r - 1] = temp;
    return i + 1;
};

template <class T>
void quicksort(T *arr, long r, long p)
{
    if (p < r)
    {
        long q = partition(arr, p, r);
        quicksort(arr, q - 1, p);
        quicksort(arr, r, q + 1);
    };
};
