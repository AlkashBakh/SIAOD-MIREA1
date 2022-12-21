#ifndef Prefix_hpp
#define Prefix_hpp

#include <iostream>
#include <string>
using namespace std;

struct Oper
{
    string data;
    struct Oper* next;
};

struct MatOper
{
    string data;
    struct MatOper* next;
};

int Empty(MatOper*& headZnak);
void Swap(int a, MatOper*& headZnak, MatOper*& tailZnak, Oper*&headSym, bool error);
void AddZnak(char c, MatOper*& headZnak, MatOper*& tailZnak, Oper*& headSym, bool error);
void AddOper(char c, Oper*& headSym, Oper*& tailSym);
void PrintHead(Oper*& headSym);

#endif
