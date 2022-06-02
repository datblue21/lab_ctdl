#include <iostream>
#include <string.h>
using namespace std;

typedef char item[5];

struct Node
{
    item data;
    Node *next;
};

typedef Node *Stack;

Node *push(Stack &s, item x)
{
    Node *p = new Node;
    if (p != NULL)
    {
        strcpy(p->data, x);
        p->next = s;
        s = p;
    }
    return s;
}
Stack pop(Stack &s, item &x)
{
    if (s != NULL)
    {
        Node *p = s;
        s = s->next;
        strcpy(x, p->data);
        delete p;
    }
    return s;
}

int empty(Stack s)
{
    return (s == NULL);
}

void InfixToPostfix(int n, item infix[20], int &j, item postfix[20])
{
    Stack s = NULL;
    item x;
    j = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(infix[i], "(") == 0)
        {
            s = push(s, infix[i]);
        }
        else if ((strcmp(infix[i], "+") == 0) || (strcmp(infix[i], "-") == 0) || (strcmp(infix[i], "*") == 0) || (strcmp(infix[i], "/") == 0))
        {
            s = push(s, infix[i]);
        }
        else if (strcmp(infix[i], ")") == 0)
        {
            while (strcmp(s->data, "(") != 0)
            {
                s = pop(s, x);
                strcpy(postfix[j++], x);
            }
            s = pop(s, x);
        }
        else
        {
            strcpy(postfix[j++], infix[i]);
        }
    }
}
double evaluate(int m, item postfix[20])
{

    Stack s = NULL;
    item x;
    double result = 0, a, b;
    for (int i = 0; i < m; i++)
    {
        if (strcmp(postfix[i], "+") == 0)
        {
            s = pop(s, x);
            b = atof(x);
            s = pop(s, x);
            a = atof(x);
            result = a + b;
            sprintf(x, "%.2f", result);
            s = push(s, x);
        }
        else if (strcmp(postfix[i], "-") == 0)
        {
            s = pop(s, x);
            b = atof(x);
            s = pop(s, x);
            a = atof(x);
            result = a - b;
            sprintf(x, "%.2f", result);
            s = push(s, x);
        }
        else if (strcmp(postfix[i], "*") == 0)
        {
            s = pop(s, x);
            b = atof(x);
            s = pop(s, x);
            a = atof(x);
            result = a * b;
            sprintf(x, "%.2f", result);
            s = push(s, x);
        }
        else if (strcmp(postfix[i], "/") == 0)
        {
            s = pop(s, x);
            b = atof(x);
            s = pop(s, x);
            a = atof(x);
            result = a / b;
            sprintf(x, "%.2f", result);
            s = push(s, x);
        }
        else
        {
            s = push(s, postfix[i]);
        }
    }
    /*
    */
    s = pop(s, x);
    result = atof(x);
    return result;
}
int main()
{
    Stack s;
    item x;
    // ((5+10) - (3*2)) => 5 10 + 3 2 * -

    // ((3*2) + (2+4))  =>  3 2 * 2 4 + +

    item exp[20], postfix[20];
    int n = 13, m;
    int j;
    strcpy(exp[0], "(");
    strcpy(exp[1], "(");
    strcpy(exp[2], "3");
    strcpy(exp[3], "*");
    strcpy(exp[4], "2");
    strcpy(exp[5], ")");
    strcpy(exp[6], "+");
    strcpy(exp[7], "(");
    strcpy(exp[8], "2");
    strcpy(exp[9], "+");
    strcpy(exp[10], "4");
    strcpy(exp[11], ")");
    strcpy(exp[12], ")");
    // for(int i = 0; i <n; i++){
    //     s = push(s, exp[i]);
    // }
    // while (!empty(s))
    // {
    //     s = pop(s,x);
    //     cout << x ;
    // }
    InfixToPostfix(n, exp, j, postfix);

    // while (!empty(s))
    // {
    //     s = pop(s, x);
    //     cout << x;
    // }
    for (int i = 0; i < j; i++)
    {
        cout << postfix[i];
    }
    cout << "\n-------- --------\n";
    cout << "evaluation : " << evaluate(j, postfix);
}