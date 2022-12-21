#include <iostream>
#include <ctime>
using namespace std;

void variat(int*);
void inputN(int*);
void inputM(int*);
void variation(int, int, int[], int);
void inputArray(int, int, int[]);
void inputRandArray(int, int, int[]);
void outputArray(int, int, int[]);
void findSedNum(int, int, int[]);

int main() {
    int n;
    int m;
    int var;
    variat(&var);
    metka2:
    cout << endl << "--Введите параметры прямоугольного двумерного массива--" << endl;
    inputN(&n);
    inputM(&m);
    if (m == n)
    {
        cout << endl << "Двумерный массив квадратный!" << endl;
        goto metka2;
    }
    int arr[n * m];
    variation(m, n, arr, var);
    outputArray(m, n, arr);
    findSedNum(m, n, arr);
    
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

void inputN(int* n) {
    metkaN:
    cout << "Введите количество строк динамического массива (от 2 до 50): ";
    int vvod;
    cin >> *n;
    vvod = *n;
    if(vvod == 0 || *n < 2 || *n > 50) {
        cout << "Неправильное введённое значение!" << endl << endl;
        goto metkaN;
    }
}

void inputM(int* m) {
    metkaM:
    cout << "Введите количество столбцов динамического массива (от 2 до 50): ";
    int vvod;
    cin >> *m;
    vvod = *m;
    if(vvod == 0 || *m < 2 || *m > 50) {
        cout << "Неправильное введённое значение!" << endl << endl;
        goto metkaM;
    }
}

void variation(int m, int n, int arr[], int var)
{
    if (var == 1)
        inputArray(m, n, arr);
    if (var == 2)
        inputRandArray(m, n, arr);
}

void inputArray(int m, int n, int arr[])
{
    cout << endl << "--Ввод двумерного массива--" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Введите элемент масива [" << i << "] [" << j << "]: ";
            cin >> arr[i * m + j];
        }
    }
}

void inputRandArray(int m, int n, int arr[])
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            arr[i * m + j] = rand() % 100;
    }
}

void outputArray(int m, int n, int arr[])
{
    cout << endl << "--Вывод двумерного массива--" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i * m + j] << "\t";
        cout << endl;
    }
}

void findSedNum(int m, int n, int arr[])
{
    cout << endl << "--Результат--" << endl;
    int flag = 0;
    int max;
    int min;
    int imax = 1;
    int jmin = 1;
    for (int i = 0; i < n; i++)
    {
        max = arr[i * m + 1];
        for (int j = 0; j < m; j++)
        {
            if (arr[i * m + j] >= max)
            {
                max = arr[i * m + j];
                jmin = j;
            }
        }
        min = arr[1 * m + jmin];
        for (int k = 0; k < n; k++)
        {
            if (arr[k * m + jmin] <= min)
            {
                min = arr[k * m + jmin];
                imax = i;
            }
        }
        if (min == max)
        {
            cout << "Седловая точка: " << arr[imax * m + jmin] << endl;
            int index[3] = {imax, jmin};
            cout << "Индексы седловой точки: ";
            for(int g = 0; g < 2; g++)
                cout << index[g] << " ";
            flag++;
            cout << endl;
        }
    }
    if (flag == 0)
        cout << "Седловая точка не найдена!" << endl;
}
