#include <iostream>
using namespace std;

struct Node
{
    int num;
        int day1;
        int time1;
        int time2;
 //-------------------//
        int day2;
        int time3;
        int time4;
    int price;
    Node *next;
    Node *prev;
};

typedef Node *node;

node createBus()
{
    node bus = new Node();
    cout << endl << "--ВВОД РАСПИСАНИЯ АВТОБУСА--" << endl << endl;
    cout << "Введите номер автобуса: ";
    cin >> bus->num;
    cout << "Введите первую дату отправок автобуса: ";
    cin >> bus->day1;
    cout << "Введите время первой отправки: ";
    cin >> bus->time1;
    cout << "Введите время второй отправки: ";
    cin >> bus->time2;
    cout << "Введите вторую дату отправок автобуса: ";
    cin >> bus->day2;
    cout << "Введите время третьей отправки: ";
    cin >> bus->time3;
    cout << "Введите время четвёртой отправки: ";
    cin >> bus->time4;
    cout << "Введите стоимость: ";
    cin >> bus->price;
    bus->next = NULL;

    return bus;
}

void addBusAfter (node &head, node &tail, node pos, node bus)
{
    if (!head)
    {
        bus->next = bus->prev = nullptr;
        head = tail = bus;
    }
    else if (!pos)
    {
        bus->next = nullptr;
        bus->prev = tail;
        tail = tail->next = bus;
    }
    else if (pos == head)
    {
        bus->prev = nullptr;
        bus->next = head;
        head = head->prev = bus;
    }
    else
    {
        bus->prev = pos->prev;
        bus->next = pos;
        pos->prev = pos->prev->next = bus;
    }
    cout << endl << endl;
}

void delBus (node &list, node &head, node &tail, node &current, int num)
{
    list = head;
    while(list)
    {
        if(list->num == num)
        {
            if(list == head)
            {
                head = head->next;
                if(head)
                    head->prev = NULL;
                else
                    tail = NULL;
                if(current == list)
                    current = head;
                delete list;
                break;
            }
            if (list == tail)
            {
                tail = tail->prev;
                if(tail)
                    tail->next = NULL;
                if(current == list)
                    current = tail;
                
                delete list;
                break;
            }
            list->prev->next = list->next;
            list->next->prev = list->prev;
            current = list->prev;
            
            delete list;
            break;
        }
        list = list->next;
    }
}

void countRaice (node &head, node pos, int &nun, int &count)
{
    int prove;
    cout << endl << "--ПОИСК КОЛ-ВО ПРОЙДЕННЫХ МАРШРУТОВ ЗА ОПРЕДЕЛЁННЫЙ ДЕНЬ--" << endl << endl;
    cout << "Введите дату: ";
    cin >> prove;
    cout << endl << "--РЕЗУЛЬТАТ--" << endl << endl;
    for (auto* pos = head; pos; pos = pos->next)
    {
        if (prove == pos->day1)
        {
            cout << "Номер автобуса: " << pos->num << endl;
            if (pos->time1 != nun)
                count++;
            if (pos->time2 != nun)
                count++;
            cout << "Всего за день пройдено маршрутов: " << count << endl << endl;
            count = 0;
        }
        
        else if (prove == pos->day2)
        {
            cout << "Номер автобуса: " << pos->num << endl;
            if (pos->time3 != nun)
                count++;
            if (pos->time4 != nun)
                count++;
            cout << "Всего за день пройдено маршрутов: " << count << endl << endl;
            count = 0;
        }
    }
    cout << endl;
}

void outputAllBus (node &head, node pos)
{
    cout << endl << "--ВЫВОД РАСПИСАНИЯ АВТОБУСОВ--" << endl << endl;
    for (auto* pos = head; pos; pos = pos->next)
    {
        cout << "Номер автобуса: " << pos->num << endl;
        cout << "Первая дата отправки автобуса: " << pos->day1 << endl;
        cout << "Время первой отправки: " << pos->time1 << endl;
        cout << "Время второй отправки: " << pos->time2 << endl;
        cout << "Вторая дата отправки автобуса: " << pos->day2 << endl;
        cout << "Время третьей отправки: " << pos->time3 << endl;
        cout << "Время четвёртой отправки: " << pos->time4 << endl;
        cout << "Стоимость: " << pos->price << endl;
        cout << endl;
    }
}

void outputAllBus2 (node &tail, node pos)
{
    cout << endl << "--ВЫВОД РАСПИСАНИЯ АВТОБУСОВ--" << endl << endl;
    pos = tail;
    while (pos->next != NULL)
        pos = pos->next;
    
    do
    {
        cout << "Номер автобуса: " << pos->num << endl;
        cout << "Первая дата отправки автобуса: " << pos->day1 << endl;
        cout << "Время первой отправки: " << pos->time1 << endl;
        cout << "Время второй отправки: " << pos->time2 << endl;
        cout << "Вторая дата отправки автобуса: " << pos->day2 << endl;
        cout << "Время третьей отправки: " << pos->time3 << endl;
        cout << "Время четвёртой отправки: " << pos->time4 << endl;
        cout << "Стоимость: " << pos->price << endl;
        pos = pos->prev;
        cout << endl;
    }
    while (pos != NULL);
}

void variation (node &head, node &tail, node pos, node &list, node &current, int &vvod, int &nun, int &count)
{
    int var;
    cout << "0 - Выход" << endl << "1 - Начать работу" << endl;
    cin >> var;
    if (var > 1 || var < 0)
    {
        cout << endl << "Такой функции нет!" << endl;
        exit(1);
    }
    cout << endl;

    while (var != 0)
    {
        cout << "0 - Выход" << endl
        << "1 - Создать расписание в конце списка" << endl
        << "2 - Удалить выбранный автобус" << endl
        << "3 - Нахождение кол-во пройденных маршрутов за определённый день" << endl
        << "4 - Вывод всех расписаний автобусов" << endl
        << "5 - Вывод всех расписаний автобусов в обратном порядке" << endl;
        cin >> var;
        if (var == 1)
            addBusAfter(head, tail, pos, createBus());
        
        if (var == 2)
        {
            cout << endl << "--УДАЛЕНИЕ АВТОБУСА ИЗ СПИСКА--" << endl << endl;
            cout << "Введите номер автобуса, который нужно удалить: ";
            cin >> vvod;
            delBus(list, head, tail, current, vvod);
            outputAllBus(head, pos);
            cout << endl;
        }
        if (var == 3)
            countRaice(head, pos, nun, count);
        
        if (var == 4)
        {
            outputAllBus(head, pos);
            cout << endl;
        }
        if (var == 5)
        {
            outputAllBus2(tail, pos);
            cout << endl;
        }
    }
}

int main() {
    node head = NULL;
    node tail = NULL;
    node pos = NULL;
    node list = NULL;
    node current = NULL;
    int vvod;
    int count = 0;
    int nun = 00;
    
    variation(head, tail, pos, list, current, vvod, nun, count);
    
    return 0;
}

