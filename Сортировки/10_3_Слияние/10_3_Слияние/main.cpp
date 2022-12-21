#include <iostream>
#include <vector>
using namespace std;

void inputRandArr(vector<int> &A, int n)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
        A[i] = rand() % 1000;
}

void merge(vector<int> &A, size_t l, size_t r, size_t m)
{
    if (l >= r || m < l || m > r) return;
        if (r == l + 1 && A[l] > A[r]) {
            swap(A[l], A[r]);
            return;
        }
      
        vector<int> tmp(&A[l], &A[l] + (r + 1));
      
        for (size_t i = l, j = 0, k = m - l + 1; i <= r; ++i) {
            if (j > m - l) {
                A[i] = tmp[k++];
            } else if(k > r - l) {
                A[i] = tmp[j++];
            } else {
                A[i] = (tmp[j] < tmp[k]) ? tmp[j++] : tmp[k++];
            }
        }
}

void MergeSort(vector<int> &A, size_t l, size_t r)
{
    if(l >= r) return;
    
    size_t m = (l + r) / 2;
    
    MergeSort(A, l, m);
    MergeSort(A, m+1, r);
    merge(A, l, r, m);
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
    unsigned int srav = 0;
    //unsigned int count;
    cout << "Введите кол-во элементов массива: ";
    cin >> n;
    vector<int> A(n);
    inputRandArr(A, n);
  
    double start = clock();
    MergeSort(A, 1, n);
    double end = clock();
    double t = (end - start) / CLOCKS_PER_SEC;
    
    cout << "Для вычисления понадобилось: " << t * 60 << " (милисек) / " << t << " (сек)" << endl;
    cout << endl << "--ВЫВОД РЕЗУЛЬТАТОВ ТЕСТОВ--" << endl;
    cout << "Кол-во элементов массива: " << n << endl;
    cout << "Кол-во операций сранения: " << srav << endl;
    //cout << "Кол-во операций перемещения: " << count << endl;
    //cout << "Сумма: " << count + srav << endl;
    
    //outputArr(A, n);
    
    return 0;
}

