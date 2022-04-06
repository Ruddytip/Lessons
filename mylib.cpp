#include "mylib.hpp"

void myArray::initArray(float* pArr, const size_t SIZE){
    for(size_t i = 0; i < SIZE; ++i)
        pArr[i] = static_cast<float>((rand() % 100) - 50);
}

void myArray::printArray(const float* pArr, const size_t SIZE){
    for(size_t i = 0; i < SIZE; ++i) std::cout << pArr[i] << ' ';
    std::cout << std::endl;
}

void myArray::countElements(const float* pArr, const size_t SIZE, size_t& positive, size_t& negative){
    for(size_t i = 0; i < SIZE; ++i)
        pArr[i] > 0 ? ++positive : ++negative;
}