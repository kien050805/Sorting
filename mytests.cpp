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


int *rand_arr(long length)
{
    int *arr = new int[length];

    // Random number generation setup
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distri(min_val, max_val);

    // Populate the array with random numbers
    for (long i = 0; i < length; i++)
    {
        arr[i] = distri(gen);
    };

    // Return the pointer to the array
    return arr;
};

long long sorting_run_time(long n)
{
    // Sort array length n
    int *arr = rand_arr(n);
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
    int *arr = rand_arr(n);
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
    int *arr = rand_arr(n);
    auto start = high_resolution_clock::now();
    int *arr_2 = merge_sort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    long long run_time = duration.count();

    return run_time;
};

long long quick_sort_run_time(long n)
{
    // Sort array length n
    int *arr = rand_arr(n);
    auto start = high_resolution_clock::now();
    quicksort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    long long run_time = duration.count();

    return run_time;
};

long long improved_quick_sort_run_time(long n)
{
    // Sort array length n
    int *arr = rand_arr(n);
    auto start = high_resolution_clock::now();
    improved_quicksort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    long long run_time = duration.count();

    return run_time;
};

long long ran_quick_sort_run_time(long n)
{
    // Sort array length n
    int *arr = rand_arr(n);
    auto start = high_resolution_clock::now();
    randomized_quicksort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    long long run_time = duration.count();

    return run_time;
};

long long cpp_sort_run_time(long n)
{
    // Sort array length n
    int *arr = rand_arr(n);
    auto start = high_resolution_clock::now();
    sort(arr, arr + n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    long long run_time = duration.count();

    return run_time;
};

int main()
{
    // Array for testing array lengths
    int len[5] = {10, 100, 1000, 10000, 100000};

    // Initial array runtime testing
    int insertion_runtime[5] = {};
    int merge_runtime[5] = {};
    int quick_runtime[5] = {};
    int improved_quick_runtime[5] = {};
    int randomized_quick_runtime[5] = {};
    int cpp_runtime[5] = {};

    for (int i = 0; i < 5; i++)
    {
        insertion_runtime[i] = insertion_sort_run_time(len[i]);
        merge_runtime[i] = merge_sort_run_time(len[i]);
        quick_runtime[i] = quick_sort_run_time(len[i]);
        improved_quick_runtime[i] = improved_quick_sort_run_time(len[i]);
        randomized_quick_runtime[i] = ran_quick_sort_run_time(len[i]);
        cpp_runtime[i] = cpp_sort_run_time(len[i]);
    }

    // Printing out insertion sort runtime
    cout << "Insertion sort runtime in microseconds: ";
    for (int i = 0; i < 5; i++)
    {
        cout << insertion_runtime[i] << ' ';
    };
    cout << endl;

    // Printing out merge sort runtime
    cout << "Merge sort runtime in microseconds: ";
    for (int i = 0; i < 5; i++)
    {
        cout << merge_runtime[i] << ' ';
    };
    cout << endl;

    // Printing out quick sort runtime
    cout << "Quick sort runtime in microseconds: ";
    for (int i = 0; i < 5; i++)
    {
        cout << quick_runtime[i] << ' ';
    };
    cout << endl;

    // Printing out improved quick sort runtime
    cout << "Improved quick sort runtime in microseconds: ";
    for (int i = 0; i < 5; i++)
    {
        cout << improved_quick_runtime[i] << ' ';
    };
    cout << endl;

    // Printing out randomized quick sort runtime
    cout << "Randomized quick sort runtime in microseconds: ";
    for (int i = 0; i < 5; i++)
    {
        cout << randomized_quick_runtime[i] << ' ';
    };
    cout << endl;

    // Printing out C++ sort runtime
    cout << "C++ sort runtime in microseconds: ";
    for (int i = 0; i < 5; i++)
    {
        cout << cpp_runtime[i] << ' ';
    };
    cout << endl;

    // Calculating insertion sort average sampling
    int insertion_10[5] = {};
    for (int i = 0; i < 5; i++)
    {
        int current_time = 0;
        for (int j = 0; j < 10; j++)
        {
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

    // Calculating merge sort average sampling
    int merge_10[5] = {};
    for (int i = 0; i < 5; i++)
    {
        int current_time = 0;
        for (int j = 0; j < 10; j++)
        {
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

    // Calculating quick sort average sampling
    int quick_10[5] = {};
    for (int i = 0; i < 5; i++)
    {
        int current_time = 0;
        for (int j = 0; j < 10; j++)
        {
            current_time += quick_sort_run_time(len[i]);
        }
        current_time = current_time / 10;
        quick_10[i] = current_time;
    }

    cout << "Average quick sort runtime over sample of 10 in microseconds: ";
    for (int i = 0; i < 5; i++)
    {
        cout << quick_10[i] << ' ';
    };
    cout << endl;

    // Calculating improved quick sort average sampling
    int improved_quick_10[5] = {};
    for (int i = 0; i < 5; i++)
    {
        int current_time = 0;
        for (int j = 0; j < 10; j++)
        {
            current_time += improved_quick_sort_run_time(len[i]);
        }
        current_time = current_time / 10;
        improved_quick_10[i] = current_time;
    }

    cout << "Average improved quick sort runtime over sample of 10 in microseconds: ";
    for (int i = 0; i < 5; i++)
    {
        cout << improved_quick_10[i] << ' ';
    };
    cout << endl;

    // Calculating randomized quick sort average sampling
    int randomized_quick_10[5] = {};
    for (int i = 0; i < 5; i++)
    {
        int current_time = 0;
        for (int j = 0; j < 10; j++)
        {
            current_time += ran_quick_sort_run_time(len[i]);
        }
        current_time = current_time / 10;
        randomized_quick_10[i] = current_time;
    }

    cout << "Average randomized quick sort runtime over sample of 10 in microseconds: ";
    for (int i = 0; i < 5; i++)
    {
        cout << randomized_quick_10[i] << ' ';
    };
    cout << endl;

    // Calculating C++ sort average sampling
    int cpp_sort_10[5] = {};
    for (int i = 0; i < 5; i++)
    {
        int current_time = 0;
        for (int j = 0; j < 10; j++)
        {
            current_time += cpp_sort_run_time(len[i]);
        }
        current_time = current_time / 10;
        cpp_sort_10[i] = current_time;
    }

    cout << "Average C++ sort runtime over sample of 10 in microseconds: ";
    for (int i = 0; i < 5; i++)
    {
        cout << cpp_sort_10[i] << ' ';
    };
    cout << endl;
};