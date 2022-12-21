#include <iostream>
#include <vector>
using namespace std;

const int N = 50;
const int cpok = 365;

struct Card
{
    char name [20];
    int invert;
    char autor [20];
    char book [20];
    int day1;
    int day2;
};

int zapis(vector<Card> &arr, int &num)
{
    do
    {
        cout << endl << "Введите количество взятых книг: ";
        cin >> num;
    }
    while (num < 0 || num > N);
    fflush(stdin);
    cout << endl << endl << "--ВВЕДИТЕ ДАННЫЕ КАРТОЧКИ--" << endl;
    for (int i = 0; i < 1; i++)
    {
        cout << "Имя пользователя: ";
        cin >> arr[i].name;
        cout << endl;
        for (int j = 0; j < num; j++)
        {
            cout << "--Данные карточки--" << endl;
            cout << "Инвентарный номер книги: ";
            cin >> arr[j].invert;
            cout << "Автор: ";
            cin >> arr[j].autor;
            cout << "Название: ";
            cin >> arr[j].book;
            cout << "Дата выдачи (номер дня в году): ";
            cin >> arr[j].day1;
            cout << "Дата возврата (номер дня в году): ";
            cin >> arr[j].day2;
            cout << endl;
        }
    }
    return num;
}

void deleteZapis(vector<Card> &arr, int *num3, int &num)
{
    *num3 = num--;
    int chislo;
    cout << endl << "--УДАЛЕНИЕ ЗАПИСИ--" << endl;
    cout << "Укажите дату возврата книги, по которой будет удалена запись: ";
    cin >> chislo;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].day2 == chislo)
            arr.erase(arr.begin() + i);
    }
    cout << endl << "--УДАЛЕНИЕ ПРОШЛО УСПЕШНО!--" << endl << endl;
}

void addZapis(vector<Card> &arr, int &num, int* num2)
{
    *num2 = num++;
    cout << endl << "--ВВЕДИТЕ ДАННЫЕ НОВОЙ КАРТОЧКИ--" << endl;
    cout << "Инвентарный номер книги: ";
    cin >> arr[*num2].invert;
    cout << "Автор: ";
    cin >> arr[*num2].autor;
    cout << "Название: ";
    cin >> arr[*num2].book;
    cout << "Дата выдачи (номер дня в году): ";
    cin >> arr[*num2].day1;
    cout << "Дата возврата (номер дня в году): ";
    cin >> arr[*num2].day2;
    cout << endl;
}

void outputZapis(vector<Card> arr, int num)
{
    cout << endl << "--ВЫВОД ВСЕХ ДЕЙСТВИТЕЛЬНЫХ ЗАПИСЕЙ--" << endl;
    for (int i = 0; i < 1; i++)
    {
        cout << "Имя пользователя: ";
        cout << arr[i].name << endl;
        for (int j = 0; j < num; j++)
        {
            cout << endl << "--Данные карточки--";
            cout << endl << "Инвентарный номер книги: ";
            cout << arr[j].invert;
            cout << endl << "Автор: ";
            cout << arr[j].autor;
            cout << endl << "Название: ";
            cout << arr[j].book;
            cout << endl << "Дата выдачи (номер дня в году): ";
            cout << arr[j].day1;
            cout << endl << "Дата возврата (номер дня в году): ";
            cout << arr[j].day2;
            cout << endl;
        }
    }
    cout << endl;
}

void countPros(vector<Card> arr, int &flag, int num)
{
    cout << endl << "--ОПРЕДЕЛЕНИЕ КОЛИЧЕСТВА ПРОСРОЧЕК--" << endl;
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (arr[j].day1 + cpok < arr[j].day2)
                flag++;
        }
    }
    cout << "Количество просрочек: " << flag << endl << endl;
    flag = 0;
}

int main()
{
    int clients = 0;
    int flag = 0;
    int num = 0;
    int num2;
    int num3;
    int var;
    cout << "0 - Выход" << endl << "1 - Начать работу" << endl;
    cin >> var;
    if (var > 1 || var < 0)
    {
        cout << endl << "Такой функции нет!" << endl;
        exit(1);
    }
    cout << endl;
    vector<Card> card(N);
    
    while (var != 0)
    {
        cout << "0 - Выход" << endl
        << "1 - Создать запись" << endl
        << "2 - Удалить запись по дате возврата" << endl
        << "3 - Добавить запись" << endl
        << "4 - Определить количетво просрочек" << endl
        << "5 - Вывод всех действительных записей" << endl;
        cin >> var;
        if (var == 1)
            num = zapis(card, clients);
        if (var == 2)
            deleteZapis(card, &num3, num);
        if (var == 3)
            addZapis(card, num, &num2);
        if (var == 4)
            countPros(card ,flag, num);
        if (var == 5)
            outputZapis(card, num);
        else if (var > 5 || var < 0)
            cout << endl << "Такой функции нет!" << endl << endl;
    }
    
    return 0;
}

