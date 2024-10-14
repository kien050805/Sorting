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

/*===========================================================================
insertion_sanity_check()
Run a series of predefined test cases to ensure that the insertion sort
algorithm is functioning correctly.
Parameters: None
Return: boolean value depending on if the function pass the test cases
===========================================================================*/
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

    // Test with regular unsorted list
    insertion_sort(A, 9);
    for (int i = 0; i < 9; i++)
    {
        if (A[i] != expected_A[i])
        {
            check = false;
        };
    };

    // Test with list of no items
    insertion_sort(B, 0);

    // Test with list of strings
    insertion_sort(C, 5);
    for (int i = 0; i < 5; i++)
    {
        if (C[i] != expected_C[i])
        {
            check = false;
        };
    };

    // Test with list of doubles
    insertion_sort(D, 5);
    for (int i = 0; i < 5; i++)
    {
        if (D[i] != expected_D[i])
        {
            check = false;
        };
    };

    // Test with list of the same items
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

/*===========================================================================
merge_sanity_check()
Run a series of predefined test cases to ensure that the merge sort
algorithm is functioning correctly.
Parameters: None
Return: boolean value depending on if the function pass the test cases
===========================================================================*/
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

    // Test with regular unsorted list
    int *sorted_A = merge_sort(A, 9);
    for (int i = 0; i < 9; i++)
    {
        if (sorted_A[i] != expected_A[i])
        {
            check = false;
        };
    };

    // Test with list of no items
    int *sorted_B = merge_sort(B, 0);

    // Test with list of strings
    string *sorted_C = merge_sort(C, 5);
    for (int i = 0; i < 5; i++)
    {
        if (sorted_C[i] != expected_C[i])
        {
            check = false;
        };
    };

    // Test with list of doubles
    double *sorted_D = merge_sort(D, 5);
    for (int i = 0; i < 5; i++)
    {
        if (sorted_D[i] != expected_D[i])
        {
            check = false;
        };
    };

    // Test with list of the same item
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

/*===========================================================================
quick_sanity_check()
Run a series of predefined test cases to ensure that the quick sort
algorithm is functioning correctly.
Parameters: None
Return: boolean value depending on if the function pass the test cases
===========================================================================*/
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

    // Test with regular unsorted list
    quicksort(A, 9);
    for (int i = 0; i < 9; i++)
    {
        if (A[i] != expected_A[i])
        {
            check = false;
        };
    };

    // Test with list of no items
    quicksort(B, 0);

    // Test with list of strings
    quicksort(C, 5);
    for (int i = 0; i < 5; i++)
    {
        if (C[i] != expected_C[i])
        {
            check = false;
        };
    };

    // Test with list of doubles
    quicksort(D, 5);
    for (int i = 0; i < 5; i++)
    {
        if (D[i] != expected_D[i])
        {
            check = false;
        };
    };

    // Test with list of the same item
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

/*===========================================================================
ran_quick_sanity_check()
Run a series of predefined test cases to ensure that the randomized merge sort
algorithm is functioning correctly.
Parameters: None
Return: boolean value depending on if the function pass the test cases
===========================================================================*/
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

    // Test with regular unsorted list
    randomized_quicksort(A, 9);
    for (int i = 0; i < 9; i++)
    {
        if (A[i] != expected_A[i])
        {
            check = false;
        };
    };

    // Test with list of no items
    randomized_quicksort(B, 0);

    // Test with list of strings
    randomized_quicksort(C, 5);
    for (int i = 0; i < 5; i++)
    {
        if (C[i] != expected_C[i])
        {
            check = false;
        };
    };

    // Test with list of doubles
    randomized_quicksort(D, 5);
    for (int i = 0; i < 5; i++)
    {
        if (D[i] != expected_D[i])
        {
            check = false;
        };
    };

    // Test with list of the same item
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

/*===========================================================================
improved_merge_sanity_check()
Run a series of predefined test cases to ensure that the improved merge sort
algorithm is functioning correctly.
Parameters: None
Return: boolean value depending on if the function pass the test cases
===========================================================================*/
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

    // Test with regular unsorted list
    improved_quicksort(A, 9);
    for (int i = 0; i < 9; i++)
    {
        if (A[i] != expected_A[i])
        {
            check = false;
        };
    };

    // Test with list of items
    improved_quicksort(B, 0);

    // Test with list of strings
    improved_quicksort(C, 5);
    for (int i = 0; i < 5; i++)
    {
        if (C[i] != expected_C[i])
        {
            check = false;
        };
    };

    // Test with list of doubles
    improved_quicksort(D, 5);
    for (int i = 0; i < 5; i++)
    {
        if (D[i] != expected_D[i])
        {
            check = false;
        };
    };

    // Test with list of the same item
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

/*===========================================================================
rand_arr()
Generate an array of random integers of the desired length.
Parameters: length of the array to be generated
Return: array of random integers
===========================================================================*/
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

/*===========================================================================
insertion_sort_run_time()
Calculates the run time of insertion sort based on the input length
Parameters: length of array to be sorted
Return: the run time of insertion_sort() in microseconds
===========================================================================*/
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

/*===========================================================================
merge_sort_run_time()
Calculates the run time of merge sort based on the input length
Parameters: length of array to be sorted
Return: the run time of merge_sort() in microseconds
===========================================================================*/
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

/*===========================================================================
quick_sort_run_time()
Calculates the run time of quick sort based on the input length
Parameters: length of array to be sorted
Return: the run time of quicksort() in microseconds
===========================================================================*/
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

/*===========================================================================
improved_quick_sort_run_time()
Calculates the run time of improved quick sort based on the input length
Parameters: length of array to be sorted
Return: the run time of improved_quicksort() in microseconds
===========================================================================*/
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

/*===========================================================================
ran_quick_sort_run_time()
Calculates the run time of randomized quick sort based on the input length
Parameters: length of array to be sorted
Return: the run time of randomized_quicksort() in microseconds
===========================================================================*/
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

/*===========================================================================
cpp_sort_run_time()
Calculates the run time of C++ sort function based on the input length
Parameters: length of array to be sorted
Return: the run time of sort() in microseconds
===========================================================================*/
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

/*===========================================================================
all_run_time()
Runs all of the run time functions over arrays of size 10, 100, 1000, 10000, 
100000, and calculates the average run time of 10 times for each sorting 
algorithm and then print to terminal.
Parameters: None
Return: None
===========================================================================*/
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

/*===========================================================================
main()
Run and throw exceptions for all of the sanity check functions and run 
all_run_time()
===========================================================================*/
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

    all_run_time();
};