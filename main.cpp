#include <iostream> // Для вывода в консоль

// Написать программу, проверяющую что сумма двух (введенных с клавиатуры) чисел лежит в пределах от 10 до 20 (включительно),
// если да – вывести строку "true", в противном случае – "false".
// ===============================================================
// Предполагается что пользователь всегда вводит корректные данные
void task1(){
    const int rangeBegin{ 10 }, rangeEnd{ 20 };
    int firstNubmer{ 0 }, secondNumber{ 0 }, summ{ 0 };
    std::cout << "Enter firts number: ";  std::cin >> firstNubmer;
    std::cout << "Enter second number: "; std::cin >> secondNumber;
    summ = firstNubmer + secondNumber;
    if(summ >= rangeBegin && summ <= rangeEnd){
        std::cout << "true" << std::endl;
    }else{
        std::cout << "false" << std::endl;
    }
}

// Написать программу, выводящую на экран строку “true”, если две целочисленные константы,
// объявленные в её начале либо обе равны десяти сами по себе, либо их сумма равна десяти. Иначе "false".
void task2(){
    const int VAR1{ 10 }, VAR2{ 10 };
    const int CONST_VAR{ 10 };
    if(VAR1 == CONST_VAR && VAR2 == CONST_VAR){
        std::cout << "true" << std::endl;
    }else if((VAR1 + VAR2) == CONST_VAR){
        std::cout << "true" << std::endl;
    }else{
        std::cout << "false" << std::endl;
    }
}

// Написать программу которая выводит на экран список всех нечетных чисел он 1 до 50.
// Например: "Your numbers: 1 3 5 7 9 11 13 …". Для решения используйте любой С++ цикл.
void task3(){
    const size_t rangeBegin{ 1 }, rangeEnd{ 50 };
    std::cout << "Your numbers: " << std::endl;
    for(size_t i = rangeBegin; i <= rangeEnd; ++i){
        if(i%2 != 0) std::cout << i << ' ';
    }
    std::cout << std::endl;
}

// Возвращает true, если число number простое
bool simpleNumber(unsigned int number);
// Со звёздочкой. Написать программу, проверяющую, является ли некоторое число - простым.
// Простое число — это целое положительное число, которое делится без остатка только на единицу и себя само.
// =======================================================================
// Предполагается что пользователь всегда вводит целое положительное число
void task4(){
    unsigned int number{ 0 };
    std::cout << "Enter number: "; std::cin >> number;
    std::cout << "Number " << number << (simpleNumber(number) ? " is simple." : " is`n simple.") << std::endl;
}

bool simpleNumber(unsigned int number){
    if(number == 0) return false; // Ноль не простое число   <-|
    if(number == 1) return true;  // Единица простое число   <-| числа, которые необходимо обработать отдельно 
    if(number == 2) return false; // Двойка не простое число <-|
    const size_t rangeBegin{ 2 }, rangeEnd{ number - 1 }; // Проверять числа меньше двух и само число не имеет смысла
    for(size_t i = rangeBegin; i <= rangeEnd; ++i){
        if(number%i == 0) return false;
    }
    return true;
}

// Со звёздочкой. Пользователь вводит с клавиатуры число (год): от 1 до 3000.
// Написать программу, которая определяет является ли этот год високосным.
// Каждый 4-й год является високосным, кроме каждого 100-го, при этом каждый 400-й – високосный.
// Вывести результаты работы программы в консоль.
// ===============================================================
// Предполагается что пользователь всегда вводит корректные данные
void task5(){
    unsigned int year{ 0 };
    std::cout << "Enter year: "; std::cin >> year;
    bool four = (year%4 == 0); // Год кратен 4
    bool hundred = (year%100 == 0); // Год кратен 100
    bool fourHundred = (year%400 == 0); // Год кратен 400
    bool bissextile = (four && !hundred) || fourHundred;
    std::cout << "Year " << year << (bissextile ? " is bissextile." : " is`n bissextile.") << std::endl;
}

int main(){
    // task1();
    // task2();
    // task3();
    // task4();
    // task5();
    return 0;
}