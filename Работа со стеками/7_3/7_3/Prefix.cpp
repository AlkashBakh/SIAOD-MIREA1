#include "Prefix.hpp"
#include "Func.hpp"

struct Oper;
struct MatOper;

int Empty(MatOper*& headZnak)
{
    if (headZnak == nullptr)
        return 1;
    else
        return 0;
}

void Swap(int a, MatOper*& headZnak, MatOper*& tailZnak, Oper*& headSym, bool error)
{
    switch (a)
    {
        case  1:
        {
            Oper* symbol = headSym;
            MatOper* znak = headZnak->next;
            symbol->next->data = znak->data + symbol->next->data + symbol->data;
            symbol->next->next->data = znak->next->data + symbol->next->next->data + symbol->next->data;
            headSym = symbol->next->next;
            
            if (znak->next->next)
                headZnak->next = znak->next->next;
            else
            {
                headZnak->next = nullptr;
                tailZnak = headZnak;
            }
            
            delete (symbol->next);
            delete (symbol);
            delete (znak->next);
            delete (znak);
            return;
        }
                
        case 2:
        {
            Oper* symbol = headSym;
            MatOper* znak = headZnak->next;
            symbol->next->data = znak->data + symbol->next->data + symbol->data;
            headSym = symbol->next;
            
            if (znak->next)
                headZnak->next = znak->next;
            else
            {
                headZnak->next = nullptr;
                tailZnak = headZnak;
            }
            
            delete (symbol);
            delete (znak);
            return;
        }
                
        case 3:
        {
            Oper* symbol = headSym;
            MatOper* znak = headZnak->next;
            MatOper* delznak;
            Oper* delsymbol;
            
            while (znak->data != "(")
            {
                symbol->next->data = znak->data + symbol->next->data + symbol->data;
                headSym = symbol->next;
                delsymbol = symbol;
                delznak = znak;
                symbol = symbol->next;
                
                if (znak->next)
                    znak = znak->next;
                else
                {
                    cout << "ОШИБКА! Закрывающая скобка нигде не была открыта!";
                    error = true;
                    return;
                }
                delete (delsymbol);
                delete (delznak);
            }
            
            delete (headZnak);
            if (znak->next)
                headZnak = znak->next;
            else
            {
                headZnak = nullptr;
                tailZnak = nullptr;
            }
            
            delete (znak);
            return;
        }
                
        case 4:
        {
            Oper* symbol = headSym;
            MatOper* znak = headZnak;
            
            if ((headZnak->data == "(") ||
                ((headZnak->next != nullptr) && (headZnak->next->data == "(")) ||
                ((headZnak->next != nullptr) && (headZnak->next->next != nullptr) && (headZnak->next->next->data == "(")))
            {
                cout << "ОШИБКА! Скобка не закрыта!";
                headSym = nullptr;
                return;
            }
            else
            {
                while (znak)
                {
                    symbol->next->data = znak->data + symbol->next->data + symbol->data;
                    symbol = symbol->next;
                    znak = znak->next;
                    delete (headSym);
                    headSym = symbol;
                    delete(headZnak);
                    headZnak = znak;
                }
                return;
            }
        }
        default:
            break;
    }
}

void AddZnak(char c, MatOper*& headZnak, MatOper*& tailZnak, Oper*& headSym, bool error)
{
    if (headZnak == nullptr)
    {
        MatOper* znak = new MatOper;
        znak->data = c;
        znak->next = nullptr;
        headZnak = znak;
        tailZnak = znak;
    }
    else
    {
        MatOper* znak = new MatOper;
        znak->data = c;
        znak->next = headZnak;
        headZnak = znak;
        
        if ((znak->data == "+" || znak->data == "-") && (znak->next->data != "("))
        {

            if (znak->next->next != nullptr && (znak->next->data == "/" || znak->next->data == "*") && ((znak->next->next->data != "(")))
                Swap(1, headZnak, tailZnak, headSym, error);
            else
                Swap(2, headZnak, tailZnak, headSym, error);
            return;
        }
        
        if ((znak->data == "*" || znak->data == "/") && (znak->next->data == "*" || znak->next->data == "/"))
        {
            Swap(2, headZnak, tailZnak, headSym, error);
            return;
        }
        
        if (znak->data == ")")
            Swap(3, headZnak, tailZnak, headSym, error);
    }
}

void AddOper(char c, Oper*& headSym, Oper*& tailSym)
{
    if (headSym == nullptr)
    {
        Oper* symbol = new Oper;
        symbol->data = c;
        symbol->next = nullptr;
        headSym = symbol;
        tailSym = symbol;
    }
    else
    {
        Oper* symbol = new Oper;
        symbol->data = c;
        symbol->next = headSym;
        headSym = symbol;
    }
}

void PrintHead(Oper*& headSym)
{
    cout << "Итог: " << headSym->data << endl << endl;
    delete (headSym);
}

