#include <dummycmake/blinker.hpp>
// #include <vector>
#include <iostream>
#include <random>


void add_offset(std::vector<int> &ints){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1,10); // inclusive

    if (ints.size() == 0) return;
    for (int i = 1; i<ints.size(); i++){
        ints[i] = ints[i] + dis(gen);
    }   
    ints[0] = ints[0] + ints[ints.size()-1];
}

