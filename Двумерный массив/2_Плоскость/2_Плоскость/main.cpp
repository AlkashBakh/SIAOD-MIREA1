#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void variation(int* var)
{
    cout << "0 - Выход из программы" << endl << "1 - Ручной ввод" << endl << "2 - Ввод случайными числами" << endl;
    cin >> *var;
    int vvod;
    vvod = *var;
    if (*var == 0)
        exit(1);
    if ((vvod == 0) || (*var != 0 && *var != 1 && *var != 2))
    {
        cout << "Неправильное введённое значение!" << endl << endl;
        exit(1);
    }
    cout << endl;
}

void inputN(int* n)
{
    cout << "Введите размер множества A: ";
    cin >> *n;
    int vvod;
    vvod = *n;
    if(vvod == 0 || *n < 2)
    {
        cout << "Неправильное введённое значение!" << endl;
        cout << endl;
        exit(1);
    }
}

void inputArr(int m, int n, vector<vector<int>> &lol)
{
    cout << endl << "--Введите координаты [x,y] точек множества A--" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cout << "Введите элемент множества " << i+1 << " [" << j << "]: ";
            cin >> lol[i][j];
        }
    cout << endl;
}

void inputRandArr(int m, int n, vector<vector<int>> &lol)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            lol[i][j] = rand() % 100;
    }
}

void variant(int m, int n, vector<vector<int>> &lol, int var)
{
    if (var == 1)
        inputArr(m, n, lol);
    if (var == 2)
        inputRandArr(m, n, lol);
}

void outputArr(vector<vector<int>> &lol)
{
    cout << "--Вывод координат множеств--" << endl;
    for (int i = 0; i < lol.size(); i++)
    {
        for (int j = 0; j < lol[i].size(); j++)
            cout << lol[i][j] << " ";
        cout << endl;
    }
}

void koordD(int n, vector<int> &d, vector<vector<int>> &lol)
{
    cout << endl << "--Введите координаты точки d--" << endl;
    cout << "Координата Х: ";
    cin >> d[0];
    cout << "Координата У: ";
    cin >> d[1];
    cout << endl << "--Вывод координат точки d--" << endl;
    
    for (int i = 0; i < n; i++)
    {
        if (lol[i][0] == d[0])
        {
            if (lol[i][1] == d[1])
            {
                cout << "Координаты точки d попадают во множество A!" << endl;
                exit(1);
            }
        }
    }
    for (int i = 0; i < d.size(); i++)
        cout << d[i] << " ";
    cout << endl;
}

void findParalel(int count, int n, vector<int> &d, vector<vector<int>> &lol)
{
    cout << endl << "--Результат--";
    int st1x, st1y, st2x, st2y, st3x, st3y, st4x, st4y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if ((lol[i][0] == lol[j][0]) && (lol[i][1] == lol[j][1]))
                    continue;
                if ((lol[k][0] == lol[j][0]) && (lol[k][1] == lol[j][1]))
                    continue;
                if ((lol[i][0] == lol[k][0]) && (lol[i][1] == lol[k][1]))
                    continue;
                st1x = lol[i][0] - d[0];
                st1y = lol[i][1] - d[1];
                st2x = lol[j][0] - lol[k][0];
                st2y = lol[j][1] - lol[k][1];
                st3x = lol[i][0] - lol[j][0];
                st3y = lol[i][1] - lol[j][1];
                st4x = d[0] - lol[k][0];
                st4y = d[1] - lol[k][1];
                if ((st1x == st2x) && (st1y == st2y) && (st3x == st4x) && (st3y == st4y))
                    count++;
            }
        }
    }
    if (count != 0)
        cout << endl << "Всего найдено параллелограммов: " << count/2 << endl;
    else
        cout << endl << "Параллелограммов не найдено :(" << endl;
    cout << endl;
}

int main()
{
    int n;
    int m = 2;
    int count = 0;
    int var;
    variation(&var);
    inputN(&n);
    vector<int> d(m);
    vector<vector<int>> lol(n, vector <int> (m));
    variant(m, n, lol, var);
    outputArr(lol);
    koordD(n, d, lol);
    findParalel(count, n, d, lol);
    
    return 0;
}

