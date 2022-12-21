#include <iostream>
#include <vector>
using namespace std;

void inputRandArr(vector<int> &A, int n)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
        A[i] = rand() % 1000;
}

void bubleSort(vector<int> &A, int n)
{
    unsigned int srav;
    unsigned int count = 0;
    double start = clock();
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (A[j] < A[j + 1])
            {
                count++;
                swap(A[j + 1], A[j]);
            }
        }
    }

    double end = clock();
    double t = (end - start) / CLOCKS_PER_SEC;
    
    cout << "Для вычисления понадобилось: " << t * 60 << " (милисек) / " << t << " (сек)" << endl;
    srav = ((n * n) - n) / 2;
    cout << endl << "--ВЫВОД РЕЗУЛЬТАТОВ ТЕСТОВ--" << endl;
    cout << "Кол-во элементов массива: " << n << endl;
    cout << "Кол-во операций сранения: " << srav << endl;
    cout << "Кол-во операций перемещения: " << count << endl;
    cout << "Сумма: " << count + srav << endl;
}

void outputArr(vector<int> A, int n)
{
    cout << endl << "--Вывод отсортированного массива--" << endl;
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl << endl;
}

int main()
{
    int n;
    cout << "Введите кол-во элементов массива: ";
    cin >> n;
    vector<int> A(n);
    inputRandArr(A, n);
    outputArr(A, n);
    bubleSort(A, n);
    outputArr(A, n);
    
    return 0;
}
