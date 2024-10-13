/*===========================================================================
Kien Le, Nguyen Nguyen, Bach Nguyen
12 October 2024
sorting.hpp
This file contains the definitions of the sorting functions. 
===========================================================================*/

using namespace std;

#ifndef SORTING
#define SORTING

template <class T>
void insertion_sort(T *arr, long n);

template <class T>
T* merge_sort(T *arr, long n);

template <class T>
void quicksort(T *arr,long r, long p = 0);

template <class T>
void improved_quicksort(T * arr, long n);

template <class T>
void randomized_quicksort(T *arr, long n);

#endif