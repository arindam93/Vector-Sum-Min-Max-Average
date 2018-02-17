#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <thread>
#include <future>
#include <iterator>

#include "e2.h"


//create shortcut
namespace sc = std::chrono;

int main() {

    std::vector<long> myVec (50000000);
    std::srand(0);

    //another, better option would be to use std::generate and a c++11ish random generator
    for(int i = 0; i < myVec.capacity(); ++i) {
        myVec[i] = std::rand() % 1000;
    }
    //http://en.cppreference.com/w/cpp/chrono
    auto start = sc::high_resolution_clock::now();

    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    long sum=0;
    double average;


    //todo:  insert code here to populate these values

    sum = parallel_sum(myVec.begin(), myVec.end());
    minVal = minimum_value(myVec.begin(), myVec.end());
    maxVal = maximum_value(myVec.begin(), myVec.end());
    average = sum/myVec.size();


    //       the final execution time must be faster
    //       than what can be achieved with a single thread
    //      bonus points will be rewarded for fastest times

    auto end = sc::high_resolution_clock::now();

    std::cout << "Min: " << minVal << std::endl;
    std::cout << "Max: " << maxVal << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Average: " << average << std::endl;

    std::cout << "Elapsed Time: " << sc::duration_cast<sc::milliseconds>(end - start).count() << "ms" << std::endl;
}