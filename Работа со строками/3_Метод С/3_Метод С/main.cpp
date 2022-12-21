#include <stdlib.h>
#include <stdio.h>

const int SIZE = 80;
void form(char*, char*);
 
int main()
{
    char buf[SIZE], outbuf[SIZE] = {' '};
    printf("Введите предложение: ");
    fgets(buf, SIZE, stdin);
    form(buf, outbuf);
    printf("Результат: %s\n\n", outbuf);
    
    return 0;
}

void form(char *a, char *out)
{
    char *first = a, *end = a;
    *out = '\0';
    int flag = 0;
    int flag2 = 1;
    
    while (*first != '\0')
    {
        flag = 1;
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
            flag2 = 1;
            char *w = first;
            while (w != t)
            {
                if (*w == *t)
                {
                    flag2 = 0;
                    break;
                }
                w++;
            }
            if (flag2 == 0)
                break;
            t++;
        }
        
//--ПРОВЕРКА НА УПОРЯДОЧЕННОСТЬ БУКВ СЛОВА ПО АЛФАВИТУ--
        while (first != (end-1) && *first)
        {
            if (*first > *(first+1))
            {
                flag = 0;
                break;
            }
            first++;
        }
        
//--НАХОЖДЕНИЕ НУЖНОГО СЛОВА--
        if (flag == 1 && flag2 == 1)
        {
            while (p != end)
                *out++ = *p++;
            *out++ = ' ';
            *out = '\0';
            first++;
        }
        else first = end;
    }
}
