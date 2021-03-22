//
// Created by peter on 9/16/20.
//

#include "ArrayVector.h"
#include <algorithm>
#include <iostream>


// Constructor with single size argument.
ArrayVector::ArrayVector(size_t av_size) {
    total_elements = av_size;
    int *temp = new int[av_size];
    array_for_vector = temp;
    current_elements = 0;
}

// Constructor a size and array pointer argument
ArrayVector::ArrayVector(size_t other_sz, int *other_array) {
    total_elements = other_sz;
    array_for_vector = new int[other_sz];
    for (int i = 0; i < total_elements; i++) {
        array_for_vector[i] = other_array[i];
    }
    current_elements = other_sz;
}

// This function assumes we have elements in _total_elements and passed a size
// and array pointer argument. We copy the current _total_elements, create an temp
// array, copy elements from original array into temp. If i >= to the initial
// size of the array, add elements from passed array. Delete old memory location,
// assign pointer to new memory location. Updates the current # of elements.
void ArrayVector::AddArray(size_t arg_size, int *other_array) {
    int pastTotalElements = total_elements;
    total_elements += arg_size;
    int counter = 0;
    int* temp = new int[total_elements];
    for (int i = 0; i < total_elements; i++) {
        if (i >= pastTotalElements) {
            temp[i] = other_array[i-pastTotalElements];
            counter++;
        } else {
            temp[i] = array_for_vector[i];
            counter++;
        }
    }
    delete[] array_for_vector;
    array_for_vector = temp;
    current_elements = counter;
}

// Gets the index of the array
int ArrayVector::Get(size_t index) {
    return array_for_vector[index];
}

// Returns the last element of the array and
// deletes/updates array.
int ArrayVector::Pop() {
    int poppedValue = array_for_vector[total_elements - 1];
    total_elements--;
    current_elements--;
    int* tempPop = new int[total_elements];
    for (int i = 0; i < total_elements; i++) {
        tempPop[i] = array_for_vector[i];
    }
    delete[] array_for_vector;
    array_for_vector = tempPop;
    return poppedValue;
}

// Adds a single space to our array.
void ArrayVector::AddSpace() {
    int *temp = new int[total_elements + 1];
    for (unsigned i = 0; i < total_elements; i++) {
        temp[i] = array_for_vector[i];
    }
    delete[] array_for_vector;
    array_for_vector = temp;
    total_elements++;
}

// Adds a space of size _s to our array.
void ArrayVector::AddSpace(size_t s) {
    int *temp = new int[total_elements + s];
    for (unsigned i = 0; i < total_elements; i++) {
        temp[i] = array_for_vector[i];
    }
    delete[] array_for_vector;
    array_for_vector = temp;
    total_elements++;
}

// Checks if the array is full, if it is, adds a space of 1
// to the array else it pushes val into the back.
void ArrayVector::PushBack(int val) {
    if (current_elements >= total_elements) {
        AddSpace();
    }
    array_for_vector[current_elements] = val;
    current_elements++;
}

// Inserts a given value a given index.
void ArrayVector::Insert(size_t index, int val) {
    if (current_elements >= total_elements) {
        AddSpace();
    }
    int tempOldNum = array_for_vector[index];
    int *temp = new int[total_elements];
    int tempCounter = 0;
    for (unsigned int i = 0; i < total_elements; i++) {
        if (i == index) {
            temp[i] = val;
        } else {
            temp[i] = array_for_vector[tempCounter];
            tempCounter++;
        }
    }
    delete[] array_for_vector;
    array_for_vector = temp;
    current_elements++;
}

// Removes the given value from the array. Does nothing
// If value is not present.
void ArrayVector::Remove(int val) {
    bool valuePresent = false;
    unsigned position;
    for (unsigned i = 0; i < total_elements; i++) {
        if (array_for_vector[i] == val) {
            valuePresent = true;
            position = i;
        }
    }
    if (valuePresent) {
        total_elements--;
        current_elements--;
        int *temp = new int[total_elements];
        for (unsigned int i = 0; i < total_elements; i++) {
            if (i >= position) {
                temp[i] = array_for_vector[i+1];
            } else {
                temp[i] = array_for_vector[i];
            }
        }
        delete[] array_for_vector;
        array_for_vector = temp;
    }
}

/*
int ArrayVector::getTotalElements(){
    return total_elements;
}

int ArrayVector::getCurrentElements(){
    return current_elements;
}
 */

// Returns the sum of the array.
int ArrayVector::Sum() {
    int sum = 0;
    for (int i = 0; i < total_elements; i++) {
        sum += array_for_vector[i];
    }
    return sum;
}

// Returns the maximum value in the array.
int ArrayVector::Max() {
    int max = array_for_vector[0];
    for (int i = 0; i < total_elements; i++) {
        if (array_for_vector[i] > max) {
            max = array_for_vector[i];
        }
    }
    return max;
}

// Returns the minimum value in the array.
int ArrayVector::Min() {
    int min = array_for_vector[0];
    for (int i = 0; i < total_elements; i++) {
        if (array_for_vector[i] < min) {
            min = array_for_vector[i];
        }
    }
    return min;
}

// Returns the average values of the array.
double ArrayVector::Average() {
    int sum = 0;
    for (int i = 0; i < total_elements; i++) {
        sum += array_for_vector[i];
    }
    return sum * 1.0 / current_elements;
}

// Destructor
ArrayVector::~ArrayVector() {
    delete [] array_for_vector;
}

// Prints the array with borders for ~clean~ println.
void ArrayVector::PrintVector() {
    std::cout << "------------------" << std::endl;
    for (int i = 0; i < total_elements; i++) {
        std::cout << array_for_vector[i] << std::endl;
    }
    std::cout << "------------------" << std::endl;
}
