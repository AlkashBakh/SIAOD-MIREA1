#include <iostream>
#include <ctime>
using namespace std;

void variat(int*);
void inputN(int*);
void inputM(int*);
void createArr(int, int, int**);
void variation(int, int, int**, int);
void inputArray(int, int, int**);
void inputRandArray(int, int, int**);
void outputArray(int, int, int**);
void findSedNum(int, int, int**);
void deleteArray(int, int, int**);

int main()
{
    int n;
    int m;
    int var;
    variat(&var);
    cout << endl << "--Введите параметры прямоугольного двумерного массива--" << endl;
    inputN(&n);
    inputM(&m);
    if (m == n)
    {
        cout << endl << "Двумерный массив квадратный!" << endl;
        exit(1);
    }
    int **arr = new int* [n];
    createArr(m, n, arr);
    variation(m, n, arr, var);
    outputArray(m, n, arr);
    findSedNum(m, n, arr);
    deleteArray(m, n, arr);
    
    return 0;
}

void variat(int* var)
{
    cout << "0 - Выход из программы" << endl << "1 - Ввод массива вручную" << endl << "2 - Ввод массива случайными числами" << endl;
    cin >> *var;
    int vvod;
    vvod = *var;
    if (*var == 0)
        exit(1);
    if((vvod == 0) || (*var != 0 && *var != 1 && *var != 2))
    {
        cout << endl;
        cout << "Неправильное введённое значение!" << endl;
        exit(1);
    }
}

void inputN(int* n)
{
    cout << "Введите количество строк динамического массива (от 2 до 50): ";
    cin >> *n;
    int vvod;
    vvod = *n;
    if(vvod == 0 || *n < 2 || *n > 50)
    {
        cout << "Неправильное введённое значение!" << endl << endl;
        exit(1);
    }
}

void inputM(int* m)
{
    cout << "Введите количество столбцов динамического массива (от 2 до 50): ";
    cin >> *m;
    int vvod;
    vvod = *m;
    if(vvod == 0 || *m < 2 || *m > 50)
    {
        cout << endl;
        cout << "Неправильное введённое значение!" << endl;
        exit(1);
    }
}

void createArr(int m, int n, int** arr)
{
    for (int i = 0; i < n; i++)
        arr[i] = new int[m];
}

void variation(int m, int n, int** arr, int var)
{
    if (var == 1)
        inputArray(m, n, arr);
    if (var == 2)
        inputRandArray(m, n, arr);
}

void inputArray(int m, int n, int** arr)
{
    cout << endl << "--Ввод двумерного массива--" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Введите элемент масива [" << i << "] [" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}

void inputRandArray(int m, int n, int** arr)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            arr[i][j] = rand() % 100;
    }
}

void outputArray(int m, int n, int** arr)
{
    cout << endl << "--Вывод двумерного массива--" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
}

void findSedNum(int m, int n, int** arr)
{
    cout << endl << "--Результаты--" << endl;
    int flag = 0;
    int max;
    int min;
    int imax = 1;
    int jmin = 1;
    for (int i = 0; i < n; i++)
    {
        max = arr[i][1];
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] >= max)
            {
                max = arr[i][j];
                jmin = j;
            }
        }
        min = arr[1][jmin];
        for (int k = 0; k < n; k++)
        {
            if (arr[k][jmin] <= min)
            {
                min = arr[k][jmin];
                imax = i;
            }
        }
        if (min == max)
        {
            cout << "Седловая точка: " << arr[imax][jmin] << endl;
            int index[3] = {imax, jmin};
            cout << "Индексы седловой точки: ";
            for(int g = 0; g < 2; g++)
                cout << index[g] << " ";
            flag++;
        }
    }
    if (flag == 0)
        cout << "Седловая точка не найдена!" << endl;
}

void deleteArray(int m, int n, int** arr)
{
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    
    delete[] arr;
    cout << endl;
}
