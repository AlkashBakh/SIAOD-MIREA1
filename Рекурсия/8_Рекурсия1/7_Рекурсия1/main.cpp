#include <iostream>
#include <vector>
using namespace std;

void inputArr(vector<double> &lol, int n)
{
    for(int i = 0; i < n; i++)
        cin >> lol[i];
    cout << endl;
}

double aver(vector<double> kek, int len, int &count)
{
    count++;
    if (len == 1) return kek[len-1];
    
    return ((len-1) * aver(kek, len-1, count) + kek[len-1]) / len;
}

int main() {
    int n;
    static int count = 0;
    cout << "Введите количество элементов массива: ";
    cin >> n;
    cout << endl;
    vector<double> lol(n);
    
    cout << "--ВВОД ДАННЫХ--" << endl;
    inputArr(lol, n);
    cout << "--ИТОГ--" << endl;
    cout << "Средняя арифметическая элементов массива: " << aver(lol, n, count) << endl;
    cout << "Глубина рекурсии: " << count << endl << endl;
    
    return 0;
}
