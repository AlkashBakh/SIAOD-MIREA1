#include <iostream>
using namespace std;

struct Node
{
    double data;
    Node *next;
};

void pushBack(Node **head, Node **last, double data)
{
    Node* node = new Node();
    node->data = data;
    node->next = NULL;
    
    if (*last != NULL)
        (*last)->next = node;
    
    *last = node;
    if (*head == NULL)
        *head = *last;
}

void reverse(Node **head_ref)
{
    Node *temp = NULL;
    Node *prev = NULL;
    Node *current = (*head_ref);
    
    while(current != NULL)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head_ref) = prev;
}

void add (Node **head_ref, double data)
{
    Node* node = new Node();
    node->data = data;
    
    if ((*head_ref) == NULL)
    {
        node->next = NULL;
        (*head_ref) = node;
    }
    else
    {
        node->next = (*head_ref)->next;
        (*head_ref)->next = node;
    }
}

void del (Node **head_ref)
{
    Node* del = (*head_ref)->next;
    if (!del) return;
    (*head_ref)->next = del->next;
    delete del;
}

void delFirstNeg (Node *&head)
{
    if (!head) return;
    Node* tmp = head;
    if (head->data < 0)
    {
        head = head->next;
        delete tmp;
        return;
    }
    while(tmp->next)
    {
        if(tmp->next->data < 0)
        {
            del(&tmp);
            return;
        }
        tmp = tmp->next;
    }
}

double findMax (Node *&head)
{
    double maximum = INT_MIN;
    Node* ptr = head;
    
    while (ptr != NULL)
    {
        maximum = max(maximum, ptr->data);
        ptr = ptr->next;
    }
    
    return maximum;
}

void delMax (Node *&head, double m)
{
    if (!head) return;
    Node* tmp = head;
    if (head->data == m)
    {
        head = head->next;
        delete tmp;
        return;
    }
    while(tmp->next)
    {
        if(tmp->next->data == m)
        {
            del(&tmp);
            return;
        }
        tmp = tmp->next;
    }
}

void comeBackMax (Node **head, Node **last, double m)
{
    Node *node = new Node;
    node->next = NULL;
    node->data = m;
     
    if (*last != NULL)
        (*last)->next = node;
    
    *last = node;
    if (*head == NULL)
        *head = *last;
}

void printNodes (Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void addNodes (Node *head)
{
    reverse(&head);
    add(&head, 99.09);
    add(&head, 100.54);
    reverse(&head);
}

void pushBackMax (Node *head, Node *last, double &m)
{
    m = findMax(head);
    delMax(head, m);
    comeBackMax(&head, &last, m);
}

int main()
{
    double m = 0;
    Node *head = NULL;
    Node *last = NULL;
    
    cout << "Исходные данные" << endl;
    pushBack(&head, &last, 28.34);
    pushBack(&head, &last, 21.2);
    pushBack(&head, &last, 14.76);
    pushBack(&head, &last, 7.4);
    printNodes(head);
    cout << endl << endl;
    
    cout << "Функция addNodes" << endl;
    addNodes(head);
    printNodes(head);
    cout << endl << endl;
    
    cout << "Функция delFirstNeg" << endl;
    delFirstNeg(head);
    printNodes(head);
    cout << endl << endl;
    
    cout << "Функция pushBackMax" << endl;
    pushBackMax(head, last, m);
    printNodes(head);
    cout << endl << endl;
    
    return 0;
}
