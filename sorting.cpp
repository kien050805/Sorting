#include <iostream>
#include "sorting.hpp"

template <class T>
void quicksort(T *arr, long p = 1, long r)
{
    if (p < r)
    {
    long q = partition(arr, p, r);
    quicksort(arr, p, q -1);
    quicksort(arr, q+1, r);
    };
};

template <class T>
long partition(T *arr, long p, long r)
{
    T x = arr[r];
    long i = p - 1;
    for (long j = p, j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            i = i + 1;
            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        };
    T temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    };
    return i + 1;
};
