#include <iostream>
#include <ctime>
#include "Function.h"
#include "Time.h"
using namespace std;

int BinarySearch(int* array, int size_of_array, int search) {
    int mid_index = size_of_array / 2; //index of the middle element
    int left_pointer = 0; //pointer on left element of array
    int right_pointer = size_of_array - 1; //pointer on right element of array

    while (left_pointer <= right_pointer) {
        if (array[mid_index] == search)
            return mid_index;
        else {
            if (array[mid_index] > search)
                right_pointer = mid_index - 1;
            else
                left_pointer = mid_index + 1;
        }

        mid_index = (left_pointer + right_pointer) / 2;
    }

    return -1; //index can be onli positive number, so the function returns "-1" if there is no correct number
}

void QuickSort(int* array, int size_of_array) {
    int mid = array[size_of_array / 2]; //finding the central element relatively to which array will be sorted
    int left_pointer = 0;
    int right_pointer = size_of_array - 1;

    do { //soting array while left pointer and right pointer are equal
        while (array[left_pointer] < mid) { //skippimg all elements on the left side which are less than middle element
            left_pointer++;
        }

        while (array[right_pointer] > mid) { //skipping all elements on the right side which are more than middle element
            right_pointer--;
        }

        if (left_pointer <= right_pointer) {
            int tmp = array[left_pointer];
            array[left_pointer] = array[right_pointer];
            array[right_pointer] = tmp;
            right_pointer--;
        }
    } while (left_pointer < right_pointer);

    if (size_of_array == 2) return; //there are two elements and they are sorted, so the function is over

    if (right_pointer > 0) //sorting right side of array if it's not sorted yet
        QuickSort(array, right_pointer + 1);

    if (left_pointer < size_of_array) //sorting left side of array if it's not sorted yet
        QuickSort(&array[left_pointer + 1], size_of_array - 1 - left_pointer);
}

void BubleSort(int* array, int size_of_array) {
    int tmp;
    for (int i = 0; i < size_of_array - 1; i++) {
        for (int j = 0; j < size_of_array - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

bool isSorted(int* array, int size_of_array) {
    while (--size_of_array >= 1) {
        if (array[size_of_array] < array[size_of_array - 1]) {
            return 0;
        }
    }
    return 1;
}

void BogoSort(int* array, int size_of_array) {
    while (!isSorted(array, size_of_array)) {
        int tmp;
        int swap; //index for element which value will be swaped with current element
        for (int i = 0; i < size_of_array; i++) {
            tmp = array[i];
            swap = rand() % size_of_array;
            array[i] = array[swap];
            array[swap] = tmp;
        }
    }
}

void CountingSort(char* array, int size_of_array) {
    int max = array[0], min = array[0];
    for (int i = 0; i < size_of_array; i++) {
        if (array[i] > max) max = array[i];
        if (array[i] < min) min = array[i];
    }

    int size_of_new_array = max - min;
    int* new_array = new int[size_of_new_array + 1];

    for (int i = 0; i < size_of_new_array + 1; i++) {
        new_array[i] = 0;
    }
    for (int i = 0; i < size_of_array; i++) {
        new_array[(int)array[i] - min]++;
    }

    int counter = 0;
    if (new_array) {
        for (int i = 0; i < size_of_new_array + 1; i++) {
            for (int j = 0; j < new_array[i]; j++) {
                array[counter] = (char)i + min;
                counter++;
            }
        }
    }
}