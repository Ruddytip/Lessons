#include <iostream> // Для вывода в консоль

// Написать функцию которая выводит массив double чисел на экран.
// Параметры функции это сам массив и его размер. Вызвать эту функцию из main.
// 
// Тут я немного нарушил требования ТЗ, так как указано именно массив double,
// но данная функция понадобилась и в других заданиях, поэтому я сделал её шаблонной
template<class T>
void printArray(const T* arr, const size_t SIZE){
    for(size_t i = 0; i < SIZE; ++i) std::cout << arr[i] << ' ';
    std::cout << std::endl;
}

// Задать целочисленный массив, состоящий из элементов 0 и 1.
// Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ].
// Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0.
// Выводить на экран массив до изменений и после.
void negativeArray(int* arr, const size_t SIZE){
    for(size_t i = 0; i < SIZE; ++i) arr[i] = (arr[i] == 0 ? 1 : 0);
}

// Задать пустой целочисленный массив размером 8.
// Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22.
// Вывести массив на экран.
void writeArrayPeriod3(int *arr, size_t SIZE){
    for(size_t i = 0; i < SIZE; ++i) arr[i] = i * 3 + 1;
}

// Структура элемента двусвязного списка
template<class T>
struct TNode{
    T data; // Значение элемента
    TNode* next; // Следующий элемент в списке
    TNode* prev; // Предыдущий элемент в списке
};

// * Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным),
// при этом метод должен циклически сместить все элементы массива на n позиций.
// 
// Мне показалось, что использовать двусторонний список в данной задаче - это оптимальное решение,
// так как колличество перезаписей ячеек массива всегда будет SIZE * 2 (не считая операций с указателями),
// не зависимо от размера массива и количества смещений
template<class T>
void rotateArray(T* arr, const size_t SIZE, int n){
    if(SIZE < 2) return; // Не имеет смысла проводить операции с пустым или единичным массивом
    bool flagSide = (n < 0); n = abs(n); // Флаг направления смещения
    if(n >= SIZE) n = n%SIZE; // Отсечение лишних смещений, так как не имеет смысла смещать элементы несколько раз по кругу
    if(n == 0) return; // Не имеет смысла проводить операции, если смещения приводят к исходному состоянию массива

    TNode<T> list[SIZE];
    TNode<T> *begin, *end, *iterator; // Указатели на начало, конец и итератор двустороннего списка
    for(size_t i = 0; i < SIZE; ++i){ // Инициализация двустороннего списка
        list[i].data = arr[i];
        if(i < SIZE - 1) list[i].next = &list[i + 1];
        if(i > 0)        list[i].prev = &list[i - 1];
    }

    begin = &list[0]; end = &list[SIZE - 1];
    begin->prev = end; end->next = begin; // Замыкание двустороннего списка в кольцо

    // Смещение начала двустороннего списка
    for(size_t i = 0; i < n; ++i) begin = (flagSide ? begin->next : begin->prev);

    iterator = begin;
    // Перезапись массива в соответствии с новым началом
    for(size_t i = 0; i < SIZE; ++i){
        arr[i]   = iterator->data;
        iterator = iterator->next;
    }
}

// ** Написать функцию, которой передается не пустой одномерный целочисленный массив,
// она должна вернуть истину если в массиве есть место, в котором сумма левой и правой части массива равны.
// Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false, checkBalance ([10, || 1, 2, 3, 4]) → true.
// Абстрактная граница показана символами ||, эти символы в массив не входят.
bool checkBalance(const int* arr, const size_t SIZE){
    // я не знаю, как трактовать массив с 1 элементом, поэтому в данной реализации подобный массив считается не сбалансированным
    if(SIZE < 2) return false;
    int summLeft { 0 }, summRight { 0 };
    for(size_t i = 0; i < SIZE - 1; ++i){ // количество проверок всегда на 1 меньше, чем элементов
        summLeft = summRight = 0;
        for(size_t j = 0; j <= i; ++j)       summLeft+= arr[j];
        for(size_t k = i + 1; k < SIZE; ++k) summRight+=arr[k];
        if(summLeft == summRight) return true;
    }
    return false;
}

int main(){
    // Задание 1
    const size_t SIZE1 = { 10 };
    double array1[SIZE1] { .0 };
    std::cout << "Task 1 result: ";
    printArray(array1, SIZE1);
    // ==================================================================================

    // Задание 2
    const size_t SIZE2 = { 10 };
    int array2[SIZE2] { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };
    std::cout << "Task 2:" << std::endl;
    std::cout << "\tarray before changes: "; printArray(array2, SIZE2);
    negativeArray(array2, SIZE2);
    std::cout << "\tarray after changes:  "; printArray(array2, SIZE2);
    // ==================================================================================

    // Задание 3
    const size_t SIZE3 { 8 };
    int array3[SIZE3] = { 0 };
    writeArrayPeriod3(array3, SIZE3);
    std::cout << "Task 3 result: ";
    printArray(array3, SIZE3);
    // ==================================================================================

    // Задание 4
    const size_t SIZE4 { 9 };
    int n { 0 };
    int array4[SIZE4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << "Task 4:" << std::endl;
    std::cout << "\tarray before changes: "; printArray(array4, SIZE4);
    std::cout << "\tenter number of shifts: "; std::cin >> n;
    // Если n положительное число, то смещение происходит в сторону увеличения индекса,
    // а если отрицательное, то в сторону уменьшения
    rotateArray(array4, SIZE4, n);
    std::cout << "\tarray after changes:  "; printArray(array4, SIZE4);
    // ==================================================================================

    // Задание 5
    const size_t SIZE5 { 5 };
    int array5[SIZE5] = {10, 1, 2, 3, 4};
    std::cout << "Task 4: array - "; printArray(array5, SIZE5);
    std::cout << "result balance - " << (checkBalance(array5, SIZE5) ? "true" : "false");
    std::cout << std::endl;
    // ==================================================================================

    return 0;
}