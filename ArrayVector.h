//
// Created by peter on 9/16/20.
//

#ifndef PROJECT2SETUP_ARRAYVECTOR_H
#define PROJECT2SETUP_ARRAYVECTOR_H


#include <cstdlib>

class ArrayVector {
public:
    ArrayVector(size_t av_size);
    ArrayVector(size_t other_sz, int* other_array);
    void AddArray(size_t arg_size, int* other_array);
    ~ArrayVector();
    void PushBack(int val);
    void Remove(int val);
    int Pop();
    void Insert(size_t index, int val);
    int Get(size_t index);
    void PrintVector();
    int Sum();
    int Max();
    int Min();
    double Average();
    //int getTotalElements();
    //int getCurrentElements();
private:
    void AddSpace();
    void AddSpace(size_t s);
    size_t total_elements;
    size_t current_elements;
    int* array_for_vector;
};

#endif //PROJECT2SETUP_ARRAYVECTOR_H
