#ifndef Func_hpp
#define Func_hpp

#include "Prefix.hpp"

void Push(Oper*& headSym, Oper*& tailSym);
int EmptyOper(Oper*& headSym);
void PushOut(Oper*& headSym, Oper*& tailSym);
void ReturnSym(Oper*& headSym);
void EmptySym(Oper*& headSym);

#endif
