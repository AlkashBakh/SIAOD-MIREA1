#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

void variat(int* var);
void variation(vector<int> lol, int size, int var);
void inputArray(vector<int> lol, int size);
void inputRandArray(vector<int> lol, int size);
void outputVector(vector<int> lol, int size);
void swap(int* a, int* b);
void inputSize(int* size);
void findMax(vector<int> lol, int size, int* max);

int main()
{
    int size;
    int max = -1;
    int var;
    variat(&var);
    inputSize(&size);
    vector<int> lol(size);
    variation(lol, size, var);
    outputVector(lol, size);
    cout << endl;
    findMax(lol, size, &max);
    int NewNum;
    cout << endl << "Введите число которое будет стоять после максимального элемента: ";
    cin >> NewNum;
    swap(lol[max], lol[max - 1]);
    lol[max] = NewNum;
    outputVector(lol, size);
    
    return 0;
}

void variat(int* var)
{
    metka:
    cout << "0 - Выход из программы" << endl << "1 - Ввод массива вручную" << endl << "2 - Ввод массива случайными числами" << endl;
    int vvod;
    cin >> *var;
    vvod = *var;
    if (*var == 0)
        exit(1);
    if((vvod == 0) || (*var != 0 && *var != 1 && *var != 2))
    {
        cout << endl;
        cout << "Неправильное введённое значение!" << endl;
        goto metka;
    }
}

void inputSize(int* size)
{
    cout << "Введите количество элементов вектора: ";
    cin >> *size;
    if (*size < 2)
    {
        cout << endl << "Неправильное введённое значение!" << endl;
        exit(1);
    }
}

void variation(vector<int> lol, int size, int var)
{
    if (var == 1)
        inputArray(lol, size);
    if (var == 2)
        inputRandArray(lol, size);
}

void inputArray(vector<int> lol, int size)
{
    cout << endl;
    cout << "--Ввод массива--" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Введите элемент массива " << i << ": ";
        cin >> lol[i];
    }
    
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if(lol[i] % 2 != 0)
            flag++;
    }
    
    if (flag == size)
    {
        cout << endl;
        cout << "Не введено ни одного чётного числа!" << endl;
        exit(1);
    }
}

void inputRandArray(vector<int> lol, int size)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < size; i++)
        lol[i] = rand() % 100;
}

void outputVector(vector<int> lol, int size)
{
    cout << endl << "--Вывод массива--" << endl;
    for(int i = 0; i < size; i++)
        cout << lol[i] << " ";
    cout << endl;
}

void findMax(vector<int> lol, int size, int* max)
{
    for (int i = 0; i < size; i++)
    {
        if (lol[i] % 2 == 0)
        {
                if (*max == -1)
                    *max = i;
                else if (lol[i] > lol[*max])
                    *max = i;
        }
    }
    cout << "Максимальный индекс чётного элемента: " << *max;
}

void swap(int* a, int* b)
{
    int peremen = *a;
    *a = *b;
    *b = peremen;
}
