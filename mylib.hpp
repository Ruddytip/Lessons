#pragma once
#include <iostream>

// Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h)
// во втором модуле mylib объявить 3 функции: для инициализации массива (типа float),
// печати его на экран и подсчета количества отрицательных и положительных элементов. 
// Вызывайте эти 3-и функции из main для работы с массивом.

// * Сделайте задание 1 добавив свой неймспейс во втором модуле (первое задание тогда можно не делать).

namespace myArray{
    void initArray(float* pArr, const size_t SIZE);
    void printArray(const float* pArr, const size_t SIZE);
    // Записывает в переменную positive количество положительных элементов в массиве
    // Записывает в переменную negative количество отрицательных элементов в массиве
    void countElements(const float* pArr, const size_t SIZE, size_t& positive, size_t& negative);
};