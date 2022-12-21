#include "Func.hpp"
#include "Staple.hpp"

bool error = false;
Oper* headSym = nullptr;
Oper* tailSym = nullptr;
MatOper* headZnak = nullptr;
MatOper* tailZnak = nullptr;

int main()
{
    char a[256];
    int k = 0, b = 0;
    cout << "--ВВЕДИТЕ ВЫРАЖЕНИЕ--" << endl;
    scanf("%255[^\n]", a);
    cout << endl << "1 - Операции над очередью" << endl
    << "2 - Перевести инфикс в префикс" << endl
    << "3 - Определить позиции скобок" << endl;
    cin >> k;
    cout << endl;
    
    switch (k)
    {
        case 1:
        {
            for (int i = 0; a[i]; i++)
            {
                AddOper(a[i], headSym, tailSym);
            }
            cout << "--ВЫБЕРИТЕ ФУНКЦИЮ--" << endl
            << "1 - Втолкнуть элемент" << endl
            << "2 - Вытолкнуть элемент" << endl
            << "3 - Вернуть значение в вершине очереди" << endl
            << "4 - Сделать очередь пустой" << endl
            << "5 - Определить, пуста ли очередь" << endl;
            cin >> b;
            cout << endl;
            
            switch (b)
            {
                case 1:
                {
                    Push(headSym, tailSym);
                    break;
                }
                case 2:
                {
                    PushOut(headSym,tailSym);
                    break;
                }
                case 3:
                {
                    ReturnSym(headSym);
                    break;
                }
                case 4:
                {
                    EmptySym(headSym);
                    break;
                }
                case 5:
                {
                    EmptyOper(headSym);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case 2:
        {
            for (int i = 0; a[i]; i++)
            {
                if ((a[i] == '+') ||
                    (a[i] == '-') ||
                    (a[i] == '*') ||
                    (a[i] == '/') ||
                    (a[i] == '(') ||
                    (a[i] == ')'))
                {
                    AddZnak(a[i], headZnak, tailZnak,headSym, error);
                }
                else
                    AddOper(a[i], headSym, tailSym);
                if (error)
                    return 1;
            }
            
            if (Empty(headZnak) == 0)
                Swap(4, headZnak,  tailZnak,  headSym, error);
            if (headSym)
                PrintHead(headSym);
            else
                return 1;
            break;
        }
        case 3:
        {
            int i;
            i = 0;
            while (a[i])
                i++;
            for (; i >= 0; i--)
            {
                AddOper(a[i], headSym, tailSym);
            }
            cout << "--ВЫБЕРИТЕ ТИП СКОБОК--" << endl
            << "1 - Закрывающие" << endl
            << "2 - Открывающие" << endl;
            cin >> b;
            cout << endl;
            
            switch (b)
            {
                case 1:
                {
                    Open(headSym);
                    break;
                }
                case 2:
                {
                    Close(headSym);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
    return 0;
}
