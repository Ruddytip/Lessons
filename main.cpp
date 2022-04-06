#include <iostream> // Для вывода в консоль
#include "mylib.hpp" // Для выполнения первого(пятого) задания
#include <fstream>

// Описать макрокоманду (через директиву define), проверяющую, входит ли переданное ей число
// (введенное с клавиатуры) в диапазон от нуля (включительно) до переданного ей второго аргумента
// (исключительно) и возвращает true или false, вывести на экран «true» или «false».
#define IN_RANGE(n, range) ((n >= 0 && n < range)? true : false)

// Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define. 
// Инициализируйте его через ввод с клавиатуры. Напишите для него свою функцию сортировки (например Пузырьком).
// Реализуйте перестановку элементов как макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки.
#define SIZE_INT 10

void printIntArray(const int* pArr, const size_t SIZE){
    for(size_t i = 0; i < SIZE; ++i) std::cout << pArr[i] << ' ';
    std::cout << std::endl;
}

#define SwapINT(a, b) std::swap(a, b)

void sortBubble(int* array){
    for(size_t i = 0; i < SIZE_INT; ++i)
        for(size_t j = 0; j < SIZE_INT; ++j)
            if(array[i] < array[j]) SwapINT(array[i], array[j]);
}

// * Объявить структуру Сотрудник с различными полезными полями.
// Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack.
// Выделите динамически переменную этого типа. Инициализируйте ее.
// Выведите ее на экран и ее размер с помощью sizeof. Сохраните эту структуру в текстовый файл.
#pragma pack(push, 1)
struct TEemployee{
    std::string name; // ФИО
    std::string post; // Должность
    size_t age;       // Возраст
    size_t salary;    // Зарплата
    size_t office;    // Номер кабинета
    bool retired;     // Находиться в отставке
};
#pragma pop

// Выводит значения полей emp в поток out
template<class T>
void writeStream(T& out, const TEemployee* emp){
    out << "Struct sizeof - " << sizeof(*emp) << std::endl;
    out << "Name - "          << emp->name    << std::endl;
    out << "Post - "          << emp->post    << std::endl;
    out << "Age - "           << emp->age     << std::endl;
    out << "Salary - "        << emp->salary  << std::endl;
    out << "Office - "        << emp->office  << std::endl;
    out << "Retired - "       << emp->retired << std::endl;
}

int main(){
    // Задание 1 и 5
    std::cout << "Task1:" << std::endl;
    const size_t SIZE { 10 };
    size_t positive { 0 }, negative { 0 };
    float array[SIZE];
    myArray::initArray(array, SIZE);
    std::cout << "Arrary: ";
    myArray::printArray(array, SIZE);
    myArray::countElements(array, SIZE, positive, negative);
    std::cout << "Positive count - " << positive << std::endl;
    std::cout << "Negative count - " << negative << std::endl;
    // =======================

    // Задание 2
    size_t in { 0 }, range { 10 };
    std::cout << "Task2:" << std::endl;
    std::cout << "Range = " << range << ". ";
    std::cout << "Enter number: ";
    std::cin >> in;
    std::cout << "Number lies in the range - ";
    std::cout << (IN_RANGE(in, range) ? "true" : "false") << std::endl;
    // =======================

    // Задание 3
    std::cout << "Task3:" << std::endl;
    int intArray[SIZE_INT];
    for(size_t i = 0; i < SIZE_INT; ++i){
        std::cout << "Enter number for " << i + 1 << " element: ";
        std::cin >> intArray[i];
    }
    std::cout << "Array before sort: ";
    printIntArray(intArray, SIZE_INT);
    sortBubble(intArray);
    std::cout << "Array after sort:  ";
    printIntArray(intArray, SIZE_INT);
    // =======================

    // Задание 4
    std::cout << "Task4:" << std::endl;
    TEemployee* emp = new TEemployee{"Joe", "master", 50, 100'000, 10, false};
    writeStream(std::cout, emp);
    std::ofstream fout("Task4.txt", std::ios_base::trunc);
    if(fout.is_open()){
        writeStream(fout, emp);
    }else{
        std::cerr << "Some error file!" << std::endl;
    }
    delete emp;
    // =======================

    return 0;
}