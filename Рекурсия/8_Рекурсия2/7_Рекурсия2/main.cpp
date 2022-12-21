#include <iostream>
using namespace std;

struct Stack
{
    int data;
    Stack *next;
};

int createStack(Stack **top, int &i, int &n, int &count1)
{
    count1++;
    int d;
    if (i == n) return 0;
    Stack *q = new Stack[n];
    cin >> d;
    q->data = d;
    
    if (top == NULL)
        *top = q;
    else
    {
        q->next = *top;
        *top = q;
    }
    i++;
    
    return createStack(top, i, n, count1);
}

void printStack(Stack *top, int &count2)
{
    count2++;
    if (top)
    {
        printStack(top->next, count2);
        cout << top->data << " ";
    }
}

int main()
{
    int n;
    int i = 0;
    static int count1 = -1;
    static int count2 = -1;
    Stack *top = NULL;
    cout << "Введите количество элементов стека: ";
    cin >> n;
    
    cout << endl << "--ВВОД ДАННЫХ--" << endl;
    createStack(&top, i, n, count1);
    cout << "Глубина рекурсии createStack: " << count1 << endl;
    cout << endl << "--ВЫВОД ДАННЫХ--" << endl;
    printStack(top, count2);
    cout << endl << "Глубина рекурсии printStack: " << count2 << endl;
    cout << endl << endl;
    
    return 0;
}
