#include "Func.hpp"
#include "Prefix.hpp"

void Push(Oper*& headSym, Oper*& tailSym)
{
    char c;
    cout << "--ВВЕДИТЕ ВТАЛКИВАЕМЫЙ ЭЛЕМЕНТ--" << endl;
    cin >> c;
    AddOper(c,headSym, tailSym);
    Oper* symbol = headSym;
    cout << endl << "--ИТОГ--" << endl;
    while (symbol)
    {
        cout << symbol->data;
        symbol = symbol->next;
    }
    cout << endl << endl;
}

void PushOut(Oper*& headSym, Oper*& tailSym)
{
    cout << "Вытолкнутый элемент: " << tailSym->data << endl;
    Oper* symbol = headSym;
    if (headSym != tailSym)
    {
        cout << "Итог: ";
        while (symbol != tailSym)
        {
            cout << symbol->data;
            symbol = symbol->next;
        }
        delete (tailSym);
    }
    else
        cout << "ОЧЕРЕДЬ ПУСТА";
    cout << endl << endl;
}

int EmptyOper(Oper*& headSym)
{
    if (headSym == nullptr)
    {
        cout << "ОЧЕРЕДЬ ПУСТА" << endl << endl;
        return 1;
    }
    else
    {
        cout << "ОЧЕРЕДЬ НЕ ПУСТА" << endl << endl;
        return 0;
    }
}

void EmptySym(Oper*& headSym)
{
    Oper* symbol = headSym;
    Oper* del;
    while (symbol)
    {
        del = symbol;
        symbol = symbol->next;
        headSym = symbol;
        delete(del);
    }
    EmptyOper(headSym);
}

void ReturnSym(Oper*& headSym)
{
    cout << "Итог: " << headSym->data << endl << endl;
}
