/*===========================================================================
Kien Le, Nguyen Nguyen, Bach Nguyen
12 October 2024
sorting.cpp
This file contains the implementations of the sorting functions in sorting.hpp
===========================================================================*/

#include <iostream>
#include <random>
#include "sorting.hpp"

/*===========================================================================
merge function
Merge the left and right array into one array for merge_sort
Parameters: left array, right array, length of original array
Return: the ordered array after merge
===========================================================================*/
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
partition function
Divide the array for quicksort by the larger part and lower part of the pivot
Parameters: the array to be divided, length of the array
Return: Number of items larger then the pivot
===========================================================================*/
template <class T>
long partition(T *arr, long n)
{
    // Choose pivot as last item
    T x = arr[n - 1];
    long i = -1;
    for (long j = 0; j < n - 1; j++)
    {
        if (arr[j] >= x)
        {
            i = i + 1;
            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    };
    T temp = arr[i + 1];
    arr[i + 1] = arr[n - 1];
    arr[n - 1] = temp;
    return i + 1;
};

/*===========================================================================
rearrange function
Rearrange the array for quicksort depending on the pivot
Parameters: the array to be rearranged, the pivot point, the length of the array
Return: None
===========================================================================*/
template <class T>
void rearrange(T *arr, long q, long n)
{
    if (n < 2)
    {
        return;
    }

    T temp[n];
    for (long i = 0; i < n; i++)
    {
        temp[i] = arr[i];
    }

    for (long i = q + 1; i < n; i++)
    {
        arr[i - q - 1] = temp[i];
    }

    arr[n - q - 1] = temp[q];

    for (long i = 0; i < q; i++)
    {
        arr[n - q + i] = temp[i];
    }
}

/*===========================================================================
randomized_partition function
Rearrange the array for quicksort depending on the randomized pivot
Parameters: the array to be divided, length of the array
Return: Number of items larger then the pivot
===========================================================================*/
template <class T>
long randomized_partition(T *arr, long n)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distri(0, n - 1);
    long k = distri(gen);
    T temp = arr[n - 1];
    arr[n - 1] = arr[k];
    arr[k] = temp;

    T x = arr[n - 1];
    long i = -1;
    for (long j = 0; j < n - 1; j++)
    {
        if (arr[j] >= x)
        {
            i = i + 1;
            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    };
    temp = arr[i + 1];
    arr[i + 1] = arr[n - 1];
    arr[n - 1] = temp;
    return i + 1;
};

/*===========================================================================
pick_median function
Pick the median of arr[a], arr[b] and arr[c] for improved quick_sort
Parameters: the array, first iterm, middle item, last item
Return: the median of arr[a], arr[b] and arr[c] the array
===========================================================================*/
template <class T>
long pick_median(T *arr, long a, long b, long c)
{
    if ((arr[a] >= arr[b] && arr[a] <= arr[c]) || (arr[a] >= arr[c] && arr[a] <= arr[b]))
    {
        return a;
    }
    else if ((arr[b] >= arr[a] && arr[b] <= arr[c]) || (arr[b] >= arr[c] && arr[b] <= arr[a]))
    {
        return b;
    }
    else
    {
        return c;
    }
};

/*===========================================================================
improved_partition function
Rearrange the array for quicksort depending on the pivot (the median of arr[0], 
arr[mid] and arr[n])
Parameters: the array to be divided, length of the array
Return: Number of items larger then the pivot
===========================================================================*/
template <class T>
long improved_partition(T *arr, long n)
{
    long mid = n / 2;
    long k = pick_median(arr, 0, mid, n);
    T temp = arr[n - 1];
    arr[n - 1] = arr[k];
    arr[k] = temp;

    T x = arr[n - 1];
    long i = -1;
    for (long j = 0; j < n - 1; j++)
    {
        if (arr[j] >= x)
        {
            i = i + 1;
            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    };
    temp = arr[i + 1];
    arr[i + 1] = arr[n - 1];
    arr[n - 1] = temp;
    return i + 1;
};

/*===========================================================================
Insertion Sort
The function goes through the unsorted list and insert each element of the
unsorted portion into its correct position in the sorted portion of the list.
Parameters: the array to be sorted, length of array
Return: None
===========================================================================*/
template <class T>
void insertion_sort(T *arr, long n)
{
    // Iterate through the array starting from index 1
    for (long i = 1; i < n; i++)
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

/*===========================================================================
Merge Sort
This function divide the unsorted array in halfs until it can no longer be
divided and recursively sort each array individually and merge back together
in sorted order.
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

/*===========================================================================
Quick Sort
This function recursively selects the last item in the array as a pivot
and then sort the array.
Parameters: the array to be sorted, length of array
Return: None
===========================================================================*/
template <class T>
void quicksort(T *arr, long n)
{
    if (n > 1)
    {
        long q = partition(arr, n);
        quicksort(arr, q);
        rearrange(arr, q, n);
        quicksort(arr, n - q - 1);
    };
};

/*===========================================================================
Randomized Quick Sort
This function recursively selects a random item as a pivot and then
sort the array.
Parameters: the array to be sorted, length of array
Return: None
===========================================================================*/
template <class T>
void randomized_quicksort(T *arr, long n)
{
    if (n > 1)
    {
        long q = randomized_partition(arr, n);
        randomized_quicksort(arr, q);
        rearrange(arr, q, n);
        randomized_quicksort(arr, n - q - 1);
    };
};

/*===========================================================================
Improved Quick Sort
This function recursively selects the median of arr[0], arr[mid] and arr[n] as a pivot and then
sort the array.
Parameters: the array to be sorted, length of array
Return: None
===========================================================================*/
template <class T>
void improved_quicksort(T *arr, long n)
{
    if (n > 1)
    {
        long q = improved_partition(arr, n);
        improved_quicksort(arr, q);
        rearrange(arr, q, n);
        improved_quicksort(arr, n - q - 1);
    };
};