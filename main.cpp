#include <iostream> // Для вывода в консоль
#include <typeinfo> // Для определения типа переменной

    // Задание 2
    // Создать перечисление (enum) с возможными вариантами символов для игры в крестики-нолики
    enum Symbols{Empty, Cross, Zero};

    // Задание 4
    // Создать структуру (struct) данных «Поле для игры в крестики-нолики» и снабдить его всеми необходимыми свойствами (подумайте что может понадобиться)
    struct SField{
        Symbols aBuffer[9]{}; // Массив значений ячеек поля
        bool bFirstTurn : 1;  // 1 - если игрок хочет ходить первым при игре против компьютера
    };

    // Задание 5
    // Создать структуру (struct MyVariant) объединяющую: union MyData (int, float, char) и 3-и битовых поля (флага)
    // указывающими какого типа значение в данный момент содержится в объединении (isInt, isFloat, isChar).
    // Продемонстрировать пример использования в коде этой структуры 
    struct MyVariant{ 
        union Union_Data{
            int   nData;
            float fData;
            char  cData;
        } MyData;   
        bool bIsInt   : 1;
        bool bIsFloat : 1;
        bool bIsChar  : 1;
        void showType(){
            std::cout << "bIsInt: "   << bIsInt   << std::endl;
            std::cout << "bIsFloat: " << bIsFloat << std::endl;
            std::cout << "bIsChar: "  << bIsChar  << std::endl;
        }
        template <typename T>
        T value(){ //Возвращает значение данных хранящихся в структуре
            if(bIsInt)   {return MyData.nData;}
            if(bIsFloat) {return MyData.fData;}
            if(bIsChar)  {return MyData.cData;}
            return 0;
        }
        template <typename T>
        void operator= (T data){ //Оператор присваивания, коректно работает с int, float, char
            bIsInt = bIsFloat = bIsChar = 0;
            if(typeid(data).name() == typeid(0).name()){
                bIsInt = 1; MyData.nData = data;
            }
            if(typeid(data).name() == typeid(.0f).name()){
                bIsFloat = 1; MyData.fData = data;
            }
            if(typeid(data).name() == typeid('0').name()){
                bIsChar = 1; MyData.cData = data;
            }
        }
    };

int main(){
    // Задание 1
    // Создать и инициализировать переменные пройденных типов данных (short int, int, long long, char, bool, float, double)
    short int n_short_int = 0;
    const unsigned int uSize = 9U;
    long long l_long_long = 10'000'000LL;
    char cSymbol = 'A';
    bool bIsEmpty = true;
    float fPi = 3.1415f;
    double dwValue = 100.5;

    // Задание 3
    // Создать массив, способный содержать значения такого перечисления и инициализировать его
    Symbols aArray[uSize]{};

    // Демонстрация 5 задания
    // Можно например в переменную V записать код символа и потом преобразовать его в символ или наоборот
    MyVariant V;

    std::cout << "Enter int value: ";
    int nTest;
    std::cin >> nTest;
    V = nTest;
    V.showType();

    std::cout << "Enter float value: ";
    float fTest;
    std::cin >> fTest;
    V = fTest;
    V.showType();

    std::cout << "Enter char value: ";
    char cTest;
    std::cin >> cTest;
    V = cTest;
    V.showType();
    std::cout << "ID char symbol \'" << V.value<char>() << "\' - " << V.value<int>() << std::endl;

    return 0;
}