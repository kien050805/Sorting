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
#include <cassert>

using namespace std;
using namespace std::chrono;

const int max_val = INT_MAX;
const int min_val = INT_MIN;

bool insertion_sanity_check()
{
    bool check = true;

    int A[9] = {9, -8, 7, -6, 5, -4, 3, -2, 1};
    int B[0] = {};
    string C[5] = {"a", "b", "c", " ", "."};
    double D[5] = {3.14, .0, 1.14, 1.618, 2.71};
    int E[5] = {0, 0, 0, 0, 0};

    int expected_A[9] = {-8, -6, -4, -2, 1, 3, 5, 7, 9};
    string expected_C[5] = {" ", ".", "a", "b", "c"};
    double expected_D[5] = {.0, 1.14, 1.618, 2.71, 3.14};
    int expected_E[5] = {0, 0, 0, 0, 0};

    insertion_sort(A, 9);
    for (int i = 0; i < 9; i++)
    {
        if (A[i] != expected_A[i])
        {
            check = false;
        };
    };

    insertion_sort(B, 0);

    insertion_sort(C, 5);
    for (int i = 0; i < 5; i++)
    {
        if (C[i] != expected_C[i])
        {
            check = false;
        };
    };

    insertion_sort(D, 5);
    for (int i = 0; i < 5; i++)
    {
        if (D[i] != expected_D[i])
        {
            check = false;
        };
    };

    insertion_sort(E, 5);
    for (int i = 0; i < 5; i++)
    {
        if (E[i] != expected_E[i])
        {
            check = false;
        };
    };
    return check;
};

bool merge_sanity_check()
{
    bool check = true;

    int A[9] = {9, -8, 7, -6, 5, -4, 3, -2, 1};
    int B[0] = {};
    string C[5] = {"a", "b", "c", " ", "."};
    double D[5] = {3.14, .0, 1.14, 1.618, 2.71};
    int E[5] = {0, 0, 0, 0, 0};

    int expected_A[9] = {-8, -6, -4, -2, 1, 3, 5, 7, 9};
    string expected_C[5] = {" ", ".", "a", "b", "c"};
    double expected_D[5] = {.0, 1.14, 1.618, 2.71, 3.14};
    int expected_E[5] = {0, 0, 0, 0, 0};

    int *sorted_A = merge_sort(A, 9);
    for (int i = 0; i < 9; i++)
    {
        if (sorted_A[i] != expected_A[i])
        {
            check = false;
        };
    };

    int *sorted_B = merge_sort(B, 0);

    string *sorted_C = merge_sort(C, 5);
    for (int i = 0; i < 5; i++)
    {
        if (sorted_C[i] != expected_C[i])
        {
            check = false;
        };
    };

    double *sorted_D = merge_sort(D, 5);
    for (int i = 0; i < 5; i++)
    {
        if (sorted_D[i] != expected_D[i])
        {
            check = false;
        };
    };

    int *sorted_E = merge_sort(E, 5);
    for (int i = 0; i < 5; i++)
    {
        if (sorted_E[i] != expected_E[i])
        {
            check = false;
        };
    };
    return check;
};

bool quick_sanity_check()
{
    bool check = true;

    int A[9] = {9, -8, 7, -6, 5, -4, 3, -2, 1};
    int B[0] = {};
    string C[5] = {"a", "b", "c", " ", "."};
    double D[5] = {3.14, .0, 1.14, 1.618, 2.71};
    int E[5] = {0, 0, 0, 0, 0};

    int expected_A[9] = {-8, -6, -4, -2, 1, 3, 5, 7, 9};
    string expected_C[5] = {" ", ".", "a", "b", "c"};
    double expected_D[5] = {.0, 1.14, 1.618, 2.71, 3.14};
    int expected_E[5] = {0, 0, 0, 0, 0};

    quicksort(A, 9);
    for (int i = 0; i < 9; i++)
    {
        if (A[i] != expected_A[i])
        {
            check = false;
        };
    };

    quicksort(B, 0);

    quicksort(C, 5);
    for (int i = 0; i < 5; i++)
    {
        if (C[i] != expected_C[i])
        {
            check = false;
        };
    };

    quicksort(D, 5);
    for (int i = 0; i < 5; i++)
    {
        if (D[i] != expected_D[i])
        {
            check = false;
        };
    };

    quicksort(E, 5);
    for (int i = 0; i < 5; i++)
    {
        if (E[i] != expected_E[i])
        {
            check = false;
        };
    };
    return check;
};

bool ran_quick_sanity_check()
{
    bool check = true;

    int A[9] = {9, -8, 7, -6, 5, -4, 3, -2, 1};
    int B[0] = {};
    string C[5] = {"a", "b", "c", " ", "."};
    double D[5] = {3.14, .0, 1.14, 1.618, 2.71};
    int E[5] = {0, 0, 0, 0, 0};

    int expected_A[9] = {-8, -6, -4, -2, 1, 3, 5, 7, 9};
    string expected_C[5] = {" ", ".", "a", "b", "c"};
    double expected_D[5] = {.0, 1.14, 1.618, 2.71, 3.14};
    int expected_E[5] = {0, 0, 0, 0, 0};

    randomized_quicksort(A, 9);
    for (int i = 0; i < 9; i++)
    {
        if (A[i] != expected_A[i])
        {
            check = false;
        };
    };

    randomized_quicksort(B, 0);

    randomized_quicksort(C, 5);
    for (int i = 0; i < 5; i++)
    {
        if (C[i] != expected_C[i])
        {
            check = false;
        };
    };

    randomized_quicksort(D, 5);
    for (int i = 0; i < 5; i++)
    {
        if (D[i] != expected_D[i])
        {
            check = false;
        };
    };

    randomized_quicksort(E, 5);
    for (int i = 0; i < 5; i++)
    {
        if (E[i] != expected_E[i])
        {
            check = false;
        };
    };

    return check;
};

bool improved_quick_sanity_check()
{
    bool check = true;

    int A[9] = {9, -8, 7, -6, 5, -4, 3, -2, 1};
    int B[0] = {};
    string C[5] = {"a", "b", "c", " ", "."};
    double D[5] = {3.14, .0, 1.14, 1.618, 2.71};
    int E[5] = {0, 0, 0, 0, 0};

    int expected_A[9] = {-8, -6, -4, -2, 1, 3, 5, 7, 9};
    string expected_C[5] = {" ", ".", "a", "b", "c"};
    double expected_D[5] = {.0, 1.14, 1.618, 2.71, 3.14};
    int expected_E[5] = {0, 0, 0, 0, 0};

    improved_quicksort(A, 9);
    for (int i = 0; i < 9; i++)
    {
        if (A[i] != expected_A[i])
        {
            check = false;
        };
    };

    improved_quicksort(B, 0);

    improved_quicksort(C, 5);
    for (int i = 0; i < 5; i++)
    {
        if (C[i] != expected_C[i])
        {
            check = false;
        };
    };

    improved_quicksort(D, 5);
    for (int i = 0; i < 5; i++)
    {
        if (D[i] != expected_D[i])
        {
            check = false;
        };
    };

    improved_quicksort(E, 5);
    for (int i = 0; i < 5; i++)
    {
        if (E[i] != expected_E[i])
        {
            check = false;
        };
    };
    return check;
};

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

void all_run_time()
{
    // Array for testing array lengths
    int len[5] = {10, 100, 1000, 10000, 100000};

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

    cout << "Average insertion sort runtime over test case of 10/100/1000/10000/100000 in microseconds: ";
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

    cout << "Average merge sort runtime over test case of 10/100/1000/10000/100000 in microseconds: ";
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

    cout << "Average quick sort runtime over test case of 10/100/1000/10000/100000 in microseconds: ";
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

    cout << "Average improved quick sort runtime over test case of 10/100/1000/10000/100000 in microseconds: ";
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

    cout << "Average randomized quick sort runtime over test case of 10/100/1000/10000/100000 in microseconds: ";
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

    cout << "Average C++ sort runtime over test case of 10/100/1000/10000/100000 in microseconds: ";
    for (int i = 0; i < 5; i++)
    {
        cout << cpp_sort_10[i] << ' ';
    };
    cout << endl;
};


int main()
{
    int count = 0;
    try
    {
        if (insertion_sanity_check())
        {
            count++;
        }
        else
        {
            throw count;
        };
        if (merge_sanity_check())
        {
            count++;
        }
        else
        {
            throw count;
        };
        if (quick_sanity_check())
        {
            count++;
        }
        else
        {
            throw count;
        };
        if (ran_quick_sanity_check())
        {
            count++;
        }
        else
        {
            throw count;
        };
        if (improved_quick_sanity_check())
        {
            count++;
        }
        else
        {
            throw count;
        };
    }
    catch (int count)
    {
        cout << count << "/5 test cases passed!" << endl;
    };
    cout << "All test cases passed!" << endl;

    // all_run_time();
};