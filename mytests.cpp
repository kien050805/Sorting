/*===========================================================================
Kien Le, Nguyen Nguyen, Bach Nguyen
12 October 2024
mytests.cpp
This file runs various tests on every sorting functions in sorting.hpp
===========================================================================*/

#include <iostream>
#include "sorting.cpp"
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

const int max_val = INT_MAX;
const int min_val = INT_MIN;

int* rand_arr(long length){
    int* arr = new int[length];

    // Random number generation setup
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distri(min_val, max_val);

    // Populate the array with random numbers
    for (long i = 0; i < length; i++) {
        arr[i] = distri(gen);
    };

    // Return the pointer to the array
    return arr;
};


long long sorting_run_time(long n)
{
    // Sort array length n
    int* arr = rand_arr(n);
    auto start = high_resolution_clock::now();
    // _sort(arr, 10)
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    long long run_time = duration.count();

    return run_time;
};





int main()
{
    // int A[8] = {2,8,7,1,3,5,6,4};
    // int B[0] = {};
    // string C[5] = {"a", "d", "b", "f", "."};
    // int *E = merge_sort(A, 8);
    // int *F = merge_sort(B, 0);
    // string *G = merge_sort(C, 5);
    // for (int i = 0; i < 8; i++)
    // {
    //     cout << E[i] << ' ';
    // };
    // cout << endl;
    // for (int i = 0; i < 0; i++)
    // {
    //     cout << F[i] << ' ';
    // };
    // cout << F;
    // cout << endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << G[i] << ' ';
    // };
    // return 0;
};