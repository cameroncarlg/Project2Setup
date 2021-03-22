//Cameron Guilbeau
//c00251326
//I certify that this code is entirely my own besides code
//given by the instructor or code that contains standard practices.

#include <iostream>
#include <fstream>
#include <random>
#include "ArrayVector.h"
#include <string>

int main() {
    int score;
    std::fstream grades_input_file("grades.txt");
    auto grade_vector = ArrayVector(5);
    while (grades_input_file >> score){
        grade_vector.PushBack(score);
    }
    std::cout << "The worst grade is: " << grade_vector.Min() << std::endl;
    std::cout << "The best grade is: " << grade_vector.Max() << std::endl;
    std::cout << "The average grade is: " << grade_vector.Average() << std::endl;

    //Test Code
    /*
    size_t sample_size = 3;
    //int sample_array[]{ 1, 2, 3};
    //auto go = ArrayVector(sample_size, sample_array);
    auto go = ArrayVector(sample_size);
    //go.PrintVector();

    go.Insert(0, 1);
    go.Insert(1, 2);
    go.Insert(2, 3);
    go.PrintVector();
    std::cout << "Inserting a 4 at the end of the vector" << std::endl;
    go.PushBack(4);
    go.PrintVector();
    std::cout << "Popping off the back end of the element" << std::endl;
    std::cout << go.Pop() << std::endl;
    go.PrintVector();
    std::cout << "Removing the first occurrence of the element 2 in the vector" << std::endl;
    go.Remove(2);
    go.PrintVector();
    std::cout << "Inserting a 2 between 1 and 3 at slot 1: " << std::endl;
    go.Insert(1, 2);
    go.PrintVector();
    std::cout << "Getting element at slot 2" << std::endl;
    std::cout << go.Get(2) << std::endl;
    go.PrintVector();
    std::cout << "Pushing 4 to the end of the vector" << std::endl;
    go.PushBack(4);
    go.PrintVector();
    std::cout << "Pushing 4 to the end of the vector" << std::endl;
    go.PushBack(4);
    go.PrintVector();
    std::cout << "Removing the first occurence of the value 1 in the vector" << std::endl;
    go.Remove(1);
    go.PrintVector();
    int addedArray[] = { 10, 20, 30, 40,};
    go.AddArray(4, addedArray);
    std::cout << "After adding an array to our array" << std::endl;
    go.PrintVector();
    std::cout << "After popping last element\n";
    std::cout << go.Pop() << std::endl;
    go.PrintVector();
     */

    return 0;
}
