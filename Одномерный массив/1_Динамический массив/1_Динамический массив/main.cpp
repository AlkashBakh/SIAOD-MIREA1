#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void variat(int*);
void inputSize(int*);
int* allocateArray(int);
void variation(int, int*, int);
void inputArray(int*, int);
void inputRandArray(int, int*);
void outputArray(int*, int);
void freeArray(int*);
int findIndex(int*, int);
void swap(int*, int*);

int main()
{
    int size;
    int var;
    variat(&var);
    cout << "Введите размер динамического массива: ";
    inputSize(&size);
    int* arr = allocateArray(size);
    variation(size, arr, var);
    outputArray(arr, size);
    int MaxIndex =findIndex(arr, size);
    cout << endl << "Индекс максимального чётного элемента: " << MaxIndex;
    int NewValue;
    cout << endl << "Введите число которое будет стоять после максимального элемента: ";
    inputSize(&NewValue);
    swap((arr + MaxIndex), (arr + MaxIndex - 1));
    *(arr + MaxIndex) = NewValue;
    outputArray(arr, size);
    freeArray(arr);
    cout << endl;

    return 0;
}

int* allocateArray(int size)
{
    return (int*)malloc (size * sizeof(int));
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
    int vvod;
    cin >> *size;
    vvod = *size;
    if(vvod == 0 || *size < 1) {
        cout << endl;
        cout << "Неправильное введённое значение!" << endl;
        exit(1);
    }
}

void variation(int size, int* arr, int var)
{
    if (var == 1)
        inputArray(arr, size);
    if (var == 2)
        inputRandArray(size, arr);
}

void inputArray(int* arr, int size)
{
    cout << endl;
    cout << "--Ввод массива--" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Введите элемент массива " << i << ": ";
        cin >> *(arr + i);
    }
    
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if(*(arr + i) % 2 != 0)
            flag++;
    }
    
    if (flag == size) {
        cout << endl;
        cout << "Не введено ни одного чётного числа!" << endl;
        exit(1);
    }
}

void inputRandArray(int size, int* arr)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100;
}

void outputArray(int* arr, int size)
{
    cout << endl << "--Вывод массива--" << endl;
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int findIndex(int* arr, int size)
{
    int max = 0;
    for(int i = 0; i < size; i++)
    {
        if(max < *(arr + i)  && arr[i] % 2 == 0)
            max = *(arr + i);
    }
    int index = 0;
    for(int i = 0; i < size; i++)
    {
        if(*(arr + i) == max)
            index = i;
    }
    return index;
}

void swap(int* a, int* b)
{
    int peremen = *a;
    *a = *b;
    *b = peremen;
}

void freeArray(int* arr)
{
    free(arr);
}
