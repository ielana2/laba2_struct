#include <iostream>
#include <ctime> 
#include "Function.h"
#include "Time.h"
using namespace std;

int main()
{
    srand(time(NULL));

    int size; //size of array
    int key; //an element that needs to be found in Binary Search
    int* sorting_array; //pointer on array of int type, on which sorting algoritms will work
    char* counting_sort_array; //pointer on array of type char, on which counting search will work

    float average_time = 0; //for counting averige time of algoritms

    cout << "Enter the size of array" << endl;
    cin >> size;

    while (size <= 1) { //check for right input
        cout << "Array for sorting algoritms must contain at least two elements. Please, enter size of array again";
        cin >> size;
    }

    sorting_array = new int[size]; //creating arrays of given size

    for (int i = 0; i < 10; i++) { //cycle to time functions ten times

        //cout << "Before sorting: ";
        for (int i = 0; i < size; i++) { //filling arrays with random values
            sorting_array[i] = rand();
            //cout << sorting_array[i] << " ";
        }

        Time t; //class for timing function
        //QuickSort(sorting_array, size);
        BubleSort(sorting_array, size); 
        cout << endl << "Working time: " << t.elapsed() << endl; //getting results of timing
        average_time += t.elapsed();

        /*cout << "After sorting: ";
        for (int i = 0; i < size; i++) {
            cout << sorting_array[i] << " ";
        }
        cout << endl;*/

    }

    delete[] sorting_array;

    cout << "Average time: " << average_time / 10 << endl;
}
