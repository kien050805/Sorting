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
#include <climits>

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

long long insertion_sort_run_time(long n)
{
    // Sort array length n
    int* arr = rand_arr(n);
    auto start = high_resolution_clock::now();
    insertion_sort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    long long run_time = duration.count();

    return run_time;
};

long long merge_sort_run_time(long n)
{
    // Sort array length n
    int* arr = rand_arr(n);
    auto start = high_resolution_clock::now();
    int* arr_2 = merge_sort(arr, n);
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

    int len[5] = {10, 100, 1000, 10000, 100000};

    int insertion_runtime[5] = {};
    int merge_runtime[5] = {};

    for (int i = 0; i < 5; i++)
    {
        insertion_runtime[i] = insertion_sort_run_time(len[i]);
        merge_runtime[i] = merge_sort_run_time(len[i]);
    }

    cout << "Insertion sort runtime in microseconds: ";
    for (int i = 0; i < 5; i++)
    {
        cout << insertion_runtime[i] << ' ';
    };
    cout << endl;

    cout << "Merge sort runtime in microseconds: ";
    for (int i = 0; i < 5; i++)
    {
        cout << merge_runtime[i] << ' ';
    };
    cout << endl;

    int insertion_10[5] = {};
    for (int i = 0; i < 5; i++)
    {
        int current_time = 0;
        for (int j = 0; j < 10; j++){
            current_time += insertion_sort_run_time(len[i]);
        }
        current_time = current_time / 10;
        insertion_10[i] = current_time;
    }

    cout << "Average insertion sort runtime over sample of 10 in microseconds: ";
    for (int i = 0; i < 5; i++)
    {
        cout << insertion_10[i] << ' ';
    };
    cout << endl;

    int merge_10[5] = {};
    for (int i = 0; i < 5; i++)
    {
        int current_time = 0;
        for (int j = 0; j < 10; j++){
            current_time += merge_sort_run_time(len[i]);
        }
        current_time = current_time / 10;
        merge_10[i] = current_time;
    }

    cout << "Average merge sort runtime over sample of 10 in microseconds: ";
    for (int i = 0; i < 5; i++)
    {
        cout << merge_10[i] << ' ';
    };
    cout << endl;
};