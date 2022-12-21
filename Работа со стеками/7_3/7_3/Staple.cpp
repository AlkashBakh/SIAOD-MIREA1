#include "Staple.hpp"
#include "Prefix.hpp"

void Open(Oper*& headSym)
{
    Oper* symbol = headSym;
    Oper* symboldel = nullptr;
    int i = 1;
    int imax = 0;
    cout << "Итог: ";
    while (1)
    {
        symbol = headSym;
        i = 1;
        while (symbol)
        {
            if (symbol->data == "(")
            {
                imax = i;
                symboldel = symbol;
            }
            if (symbol->data == ")")
            {
                cout << imax << " " << i << "; ";
                symboldel->data = "0";
                symbol->data = "0";
                break;
            }
            i++;
            symbol = symbol->next;
        }
        if (symbol == nullptr)
            break;
    }
    cout << endl << endl;
}

void Close(Oper*& headSym)
{
    Oper* symbolotkr = headSym;
    Oper* symbolzakr;
    int imax = 0;
    int i = 1, k = 0, count = 0;
    cout << "Итог: ";
    while (symbolotkr)
    {
        if (symbolotkr->data == "(")
        {
            symbolzakr = symbolotkr->next;
            k = i;
            while (symbolzakr)
            {
                if (symbolzakr->data == "(")
                    count++;
                if (symbolzakr->data == ")")
                {
                    if (count == 0)
                    {
                        imax = k + 1;
                        break;
                    }
                    else
                        count--;
                }
                k++;
                symbolzakr = symbolzakr->next;
            }
        }
        if (imax != 0)
        {
            cout << i << " " << imax << "; ";
            imax = 0;
        }
        i++;
        symbolotkr = symbolotkr->next;
    }
    cout << endl << endl;
}
