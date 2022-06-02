#include <bits/stdc++.h>

using namespace std;
struct Date
{
    int day, month, year;
};

struct Student
{
    char name[20];
    Date bDay;
    float math, physic, languages;
};

struct Node
{
    Student data;
    Node *next;
};

Node *input(Node *head, int n)
{
    Node *p, *last = NULL;
    last = head;
    if (head != NULL)
    {
        while (last->next != NULL)
        {
            last = last->next;
        }
    }
    for (int i = 0; i < n; i++)
    {
        p = new Node();
        p->next = NULL;
        cout << "name: ";
        cin >> p->data.name;
        cout << "day: ";
        cin >> p->data.bDay.day;
        cout << "month: ";
        cin >> p->data.bDay.month;
        cout << "year: ";
        cin >> p->data.bDay.year;
        cout << "math: ";
        cin >> p->data.math;
        cout << "physic: ";
        cin >> p->data.physic;
        cout << "languages: ";
        cin >> p->data.languages;
        if (head == NULL)
        {
            head = p;
            last = head;
        }
        else
        {
            last->next = p;
            last = p;
        }
    }
    return head;
}

void output(Node *head)
{
    cout << "--------output----------" << endl;
    Node *p = head;
    while (p != NULL)
    {
        cout << "Name: " << p->data.name << endl;
        cout << "bDay: " << p->data.bDay.day << " "
             << p->data.bDay.month << " "
             << p->data.bDay.year << endl;
        cout << " Math: " << p->data.math
             << " physic: " << p->data.physic
             << " languages: " << p->data.languages << endl;
        p = p->next;
    }
    cout << "--------output----------" << endl;
}
void append(Node *head)
{
    Node *p = new Node();

    Node *last = head;
    cout << "name: ";
    cin >> p->data.name;
    cout << "day: ";
    cin >> p->data.bDay.day;
    cout << "month: ";
    cin >> p->data.bDay.month;
    cout << "year: ";
    cin >> p->data.bDay.year;
    cout << "math: ";
    cin >> p->data.math;
    cout << "physic: ";
    cin >> p->data.physic;
    cout << "languages: ";
    cin >> p->data.languages;
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = p;
    return;
}

void count_students(Node *head, int date)
{
    Node *p = head;
    int c = 0;
    while (p != NULL)
    {
        if (date == (p->data.bDay.day))
        {
            c++;
        }

        p = p->next;
    }
    cout << "---------"
         << "count_students: have " << c << " students has same date" << endl;
}

Node *check_name(Node *head, char name[])
{
    Node *p = head;
    while (p != NULL)
    {
        if (strcmp(p->data.name, name) == 0) 
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

Node *delNode(Node *head, char name[])
{
    Node *THIS = check_name(head, name);
    if (THIS != NULL)
    {
        if (THIS == head)
        {
            head = head->next;
        }
        else
        {
            Node *pre = head;
            while (pre->next != THIS)
            {
                pre = pre->next;
            }
            pre->next = THIS->next;
        }
        delete THIS;
    }
    return head;
}

int main()
{
    Node *head = NULL;
    int n = 3;
    char name[30];
    head = input(head, n);
    output(head);
    append(head);
    output(head);

    count_students(head, 22);
    head = check_name(head, name);
    deleteNode(head, 2);
    head = delNode(head, name);

    return 0;
}
