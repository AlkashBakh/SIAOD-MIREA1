#include <iostream>
#include <vector>
using namespace std;

void inputRandArr(vector<int> &A, int n)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
        A[i] = rand() % 1000;
}

void inputArr(vector<int> &A, int n)
{
    cout << endl << "--ВВОД МАССИВА--" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
}

void sort(vector<int> &A, int n)
{
    unsigned int srav;
    unsigned int count = 0;
    double start = clock();
    
    for (int i = 1; i < n; i++)
        for (int j = i; j > 0 && A[j-1] > A[j]; j--)
        {
            count++;
            swap(A[j-1], A[j]);
        }
    
    double end = clock();
    double t = (end - start) / CLOCKS_PER_SEC;
    
    srav = n * (n-1) / 2;
    cout << endl << "--ВЫВОД РЕЗУЛЬТАТОВ ТЕСТОВ--" << endl;
    cout << "Для сортировки понадобилось: " << t * 60 << " (милисек) / " << t << " (сек)" << endl;
    cout << "Кол-во элементов массива: " << n << endl;
    cout << "Кол-во операций сранения: " << srav << endl;
    cout << "Кол-во операций перемещения: " << count << endl;
    cout << "Сумма: " << srav + count << endl;
}

void outputArr(vector<int> A, int n)
{
    cout << endl << "--ВЫВОД МАССИВА--" << endl;
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
    //inputArr(A, n);
    sort(A, n);
    outputArr(A, n);
    
    return 0;
}
