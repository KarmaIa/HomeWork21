#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//Задание 1. Определить существует ли треугольник. Если существует определить
// является ли он прямоугольником.

//Задание 2. Найти сумму всех чисел меньше N которые делятся на 3 и 5

//Задание 3. Найти медиану массива

//Задание 4. Зашифровать строку с помощью шифра Цезаря. "//Потом" Строку считываем из файла. 
// Записываем в новый файл зашифрованную

void Encryption(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = str[i] + 5;
    }
}

void ReadFile(const char* filename, char* str, int& count)
{
    ifstream inFile("file.txt");
    if (inFile.is_open())
    {
        inFile.read(str, strlen(str));
        count = inFile.gcount();
        str[count] = '\0';
        inFile.close();
    }
    else
    {
        cout << "Не удалось открыть файл" << endl;
        count = 0;
        str[0] = '\0';
    }
}

void WriteToNewFile(const char* filename, char* str, int& count)
{
    ofstream outFile("NewFile.txt");
    if (outFile.is_open())
    {
        outFile.write(str, strlen(str));
        outFile.close();
    }
}

//Задание 5. Написать функцию удаляющую столбец двумерного массива по указанному номеру

void fillTwoDimensionalArray(int** arr, int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }
}

void printTwoDimensionalArray(int** arr, int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void removeColInTwoDimensionalArray(int** arr, int& col, int row, int choice)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = choice - 1; j < col; j++)
        {
            swap(arr[i][j], arr[i][j + 1]);
        }
    }
    col--;
}

//Задание 6. Разместить код на Github


int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(0));

    //Задание 1
    int a = 60;
    int b = 100;
    int c = 55;
    if (a + b > c && a + c > b && b + c > a)
    {
        cout << "Треугольник существует" << endl;
        if ((pow(a, 2) < pow(b, 2) + pow(c, 2)) || (pow(b, 2) + pow(c, 2) == pow(a, 2)) || (pow(a, 2) > pow(b, 2) + pow(c, 2)))
        {
            cout << "Треугольник прямоугольный" << endl;
        }
        else 
        {
            cout << "Треугольник не прямоугольный" << endl;
        }
    }
    else
    {
        cout << "Треугольник не существует" << endl;
    }

    //Задание 2
    /*int sum = 0;
    int N = 10;
    for (int i = 0; i < N; i++)
    {
        if (i % 3 == 0)
        {
            sum += i;
        }
        else if (i % 5 == 0)
        {
            sum += i;
        }
    }
    cout << "Сумма всех чисел меньше N: " << sum << endl;*/

    //Задание 3.
    /*const int size = 5;
    int arr[size] = { 3,7,12,16,19 };
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int median;
    if (size % 2 == 0)
    {
        median = (arr[size / 2 - 1] + arr[size / 2]) / 2;
        cout << "Медиан: " << median << endl;
    }
    else if (size % 2 != 0)
    {
        median = arr[size / 2];
        cout << "Медиан: " << median << endl;
    }*/

    //Задание 4.
    /*char str[1024];
    int countSymbol = 0;
    
    ReadFile("file.txt", str, countSymbol);
    Encryption(str);
    WriteToNewFile("NewFile.txt", str, countSymbol);*/
    
    //Задание 5.
    /*int row = 4;
    int col = 4;
    int **array = new int* [row];
    for (int i = 0; i < row; i++)
    {
        array[i] = new int[col];
    }
    fillTwoDimensionalArray(array, col, row);

    cout << "До удаления столбца:" << endl;
    printTwoDimensionalArray(array, col, row);
    cout << "После удаления столбца:" << endl;
    removeColInTwoDimensionalArray(array, col, row, 2);
    printTwoDimensionalArray(array, col, row);
    delete[] array;*/
}
