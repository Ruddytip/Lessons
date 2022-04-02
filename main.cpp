#include <iostream> // Для вывода в консоль
#include <cmath>    // Для функции возведения в квадрат pow(a, b)
#include <ctime>    // Для функции time(0)
#include <fstream>  // Для работы с файлами

// Выделить в памяти динамический одномерный массив типа int. Размер массива запросить у пользователя.
// Инициализировать его числами степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128 ... Вывести массив на экран.
// Не забыть освободить память. =) Разбить программу на функции.
namespace task1{
    size_t enterSize(){
        size_t size { 0 };
        std::cout << "Enter the number of items: ";
        std::cin >> size;
        return size;
    }
    void initArrayDegree(size_t* array, const size_t SIZE){
        for(size_t i = 0; i < SIZE; ++i) array[i] = pow(2, i);
    }
    void printArray(size_t* array, const size_t SIZE){
        for(size_t i = 0; i < SIZE; ++i) std::cout << array[i] << ' ';
        std::cout << std::endl;
    }
    size_t* createArray(const size_t SIZE){
        return new size_t[SIZE];
    }
    void deleteArray(size_t* array){
        delete[] array;
        array = nullptr;
    }
};

// Динамически выделить матрицу 4х4 типа int. Инициализировать ее псевдослучайными числами через функцию rand.
// Вывести на экран. Разбейте вашу программу на функции которые вызываются из main.
namespace task2{
    size_t SIZE { 0 };
    // Заполняет матрицу случайными значениями
    void initMatrix(int** matrix){
        srand(time(0));
        for(size_t i = 0; i < SIZE; ++i){
            for(size_t j = 0; j < SIZE; ++j){
                matrix[j][i] = rand() % 10;
            }
        }
    }
    void printMatrix(int** matrix){
        for(size_t i = 0; i < SIZE; ++i){
            std::cout << "\t\t";
            for(size_t j = 0; j < SIZE; ++j){
                std::cout << matrix[j][i] << ' ';
            }
            std::cout << std::endl;
        }
    }
    int** createMatrix(){
        int** matrix = new int*[SIZE];
        for(size_t i = 0; i < SIZE; ++i) matrix[i] = new int[SIZE];
        return matrix;
    }
    void deleteMatrix(int** matrix){
        for(size_t i = 0; i < SIZE; ++i) delete[] matrix[i];
        delete[] matrix;
        matrix = nullptr;
    }
};

// Написать программу, которая создаст два текстовых файла (*.txt),
// примерно по 50-100 символов в каждом (особого значения не имеет с каким именно содержимым).
// Имена файлов запросить у польлзователя.
namespace task3{
    std::string enterNameFile(){
        std::string name("");
        std::cout << "Enter the file name: ";
        std::cin >> name;
        return name + ".txt";
    }
    bool writeFileRand(std::string name){
        srand(time(0));
        size_t countRow = rand() % 20 + 10; // Случайное количество строк от 10 до 29
        std::string buff("");
        std::ofstream fout(name, std::ios_base::trunc);
        if(!fout.is_open()) return false;

        for(size_t i = 0; i < countRow; ++i){
            // Случайное количество символов от 5 до 54
            buff = std::string(rand() % 50 + 5, '0' + rand() % 10);
            fout << buff << '\n';
        }

        fout.close();
        return true;
    }
};

// * Написать функцию, «склеивающую» эти файлы в третий текстовый файл (имя файлов спросить у пользователя).
namespace task4{
    std::string glueFiles(std::string name1, std::string name2){
        std::string nameNewFile(task3::enterNameFile());
        std::string buff(""); // Буфер для построчного копирования
        std::ifstream fin1, fin2;
        std::ofstream fout;

        fout.open(nameNewFile, std::ios_base::trunc);
        if(fout.is_open()){
            fin1.open(name1);
            if(fin1.is_open()){
                while(!fin1.eof()){
                    buff = "";
                    std::getline(fin1, buff);
                    fout << buff << '\n';
                }
            fin1.close();
            }else{
                std::cerr << "An error occurred when opening the \"" << name1 << "\" file!" << std::endl;
                return "";
            }

            fin2.open(name2);
            if(fin2.is_open()){
                while(!fin2.eof()){
                    buff = "";
                    std::getline(fin2, buff);
                    fout << buff << '\n';
                }
            fin2.close();
            }else{
                std::cerr << "An error occurred when opening the \"" << name2 << "\" file!" << std::endl;
                return "";
            }
        fout.close();
        }else{
            std::cerr << "An error occurred when creating the \"" << nameNewFile << "\" file!" << std::endl;
            return "";
        }
        return nameNewFile;
    }
};

// * Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово
// в указанном пользователем файле (для простоты работаем только с латиницей). Используем функцию find которая есть в строках std::string.
namespace task5{
    bool find(std::string fileName, std::string str){
        std::ifstream fin(fileName);
        if(!fin.is_open()){
            std::cerr << "An error occurred when opening the \"" << fileName << "\" file!" << std::endl;
            return false;
        }
        while(!fin.eof()){
            std::string buff("");
            std::getline(fin, buff);
            if(buff.find(str) != std::string::npos){
                fin.close();
                return true;
            }
        }

        fin.close();
        return false;
    }
};

int main(){
    // Задание 1
    size_t size = task1::enterSize();
    size_t* array = task1::createArray(size);
    task1::initArrayDegree(array, size);
    std::cout << "Task 1 result: ";
    task1::printArray(array, size);
    task1::deleteArray(array);
    // =====================================================================================================

    // Задание 2
    task2::SIZE = 4; // Размер матрицы
    int** matrix = task2::createMatrix();
    task2::initMatrix(matrix);
    std::cout << "Task 2 result:" << std::endl;
    task2::printMatrix(matrix);
    task2::deleteMatrix(matrix);
    // =====================================================================================================

    // Задание 3
    const size_t coutFiles { 2 };
    std::string name[coutFiles];
    std::cout << "Task 3:" << std::endl;
    for(size_t i = 0; i < coutFiles; ++i){
        name[i] = task3::enterNameFile();
        if(task3::writeFileRand(name[i])){
            std::cout << "The \"" << name[i] << "\" file has been successfully created!" << std::endl;
        }else{
            std::cout << "An error occurred when creating the \"" << name[i] << "\" file!" << std::endl;
        }
    }
    // =====================================================================================================

    // Задание 4
    std::cout << "Task 4: ";
    std::string nameNewFile = task4::glueFiles(name[0], name[1]);
    if(!nameNewFile.empty()){
        std::cout << "the new \"" << nameNewFile << "\" file has been successfully created!" << std::endl;
    }else{
        std::cout << "an error occurred while creating or writing a new file!" << std::endl;
    }
    // =====================================================================================================

    // Задание 5
    const std::string fileName("test.txt"), strFind("manor");
    std::cout << "Task 5 result: the file \"" << fileName << "\" contains the line \"" << strFind << "\" - ";
    std::cout << (task5::find(fileName, strFind) ? "true" : "false") << std::endl;
    // =====================================================================================================

    return 0;
}