#include <iostream>
#include <vector>
using namespace std;

void inputRandArr(vector<int> &A, int n)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
        A[i] = rand() % 1000;
}

void sort(vector<int> &A, int n)
{
    int m;
    int srav = 0;
    unsigned int count = 0;
    double start = clock();

    for (int i = 0; i < n-1; i++)
    {
        count++;
        m = i;
        for (int j = i + 1; j < n; j++)
            if (A[j] > A[m])
            {
                srav++;
                m = j;
            }
        swap(A[m], A[i]);
    }
    
    double end = clock();
    double t = (end - start) / CLOCKS_PER_SEC;
    
    cout << endl << "--ВЫВОД РЕЗУЛЬТАТОВ ТЕСТОВ--" << endl;
    cout << "Для вычисления понадобилось: " << t * 60 << " (милисек) / " << t << " (сек)" << endl;
    cout << "Кол-во элементов массива: " << n << endl;
    cout << "Кол-во операций сранения: " << srav << endl;
    cout << "Кол-во операций перемещения: " << count << endl;
    cout << "Сумма: " << srav + count << endl;
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
    //outputArr(A, n);
    sort(A, n);
    //outputArr(A, n);

    return 0;
}
