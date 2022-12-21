#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

const int SIZE = 80;
void form(char*, char*);
 
int main()
{
    char buf[SIZE], outbuf[SIZE] = {' '};
    cout << "Введите предложение: ";
    cin.getline(buf, SIZE);
    form(buf, outbuf);
    cout << "Результат: " << outbuf << endl << endl;
    
    return 0;
}

void form(char *a, char *out)
{
    char *first = a, *end = a;
    *out = '\0';
    bool flag = false;
    bool flag2 = true;
    
    while (*first != '\0')
    {
        flag = true;
        while (*first == ' ' && *first != '\0')
            first++;
        end = first;
 
        while (*end != ' ' && *end)
            end++;
 
        char *p = first;
        char *t = first;
        
//--ПРОВЕРКА НА ПОВТОРЯЮЩИЕСЯ БУКВЫ--
        while (t != end)
        {
            flag2 = true;
            char *w = first;
            while (w != t)
            {
                if (*w == *t)
                {
                    flag2 = false;
                    break;
                }
                w++;
            }
            if (flag2 == false)
                break;
            t++;
        }
        
//--ПРОВЕРКА НА УПОРЯДОЧЕННОСТЬ БУКВ СЛОВА ПО АЛФАВИТУ--
        while (first != (end-1) && *first)
        {
            if (*first > *(first+1))
            {
                flag = false;
                break;
            }
            first++;
        }
        
//--НАХОЖДЕНИЕ НУЖНОГО СЛОВА--
        if (flag == true && flag2 == true)
        {
            while (p != end)
                *out++ = *p++;
            *out++ = ' ';
            *out = '\0';
            first++;
        }
        else
            first = end;
    }
}
