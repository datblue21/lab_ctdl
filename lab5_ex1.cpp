#include <iostream>
#include <string.h>

using namespace std;
typedef char ItemType[5];

// Stack
struct Node
{

    ItemType data;
    Node *next;
};

typedef Node *Stack;

struct TreeNode
{

    ItemType data;
    TreeNode *left;
    TreeNode *right;
};
typedef TreeNode *Tree;

Stack push(Stack &s, ItemType x)
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
Stack pop(Stack &s, ItemType &x)
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

// TRee

Tree NewNode(ItemType x)
{
    Tree p;
    p = new TreeNode;
    strcpy(p->data, x);
    p->left = NULL;
    p->right = NULL;
    return p;
}

Tree CreateTree(ItemType x, Tree t1, Tree t2)
{
    Tree root;
    root = NewNode(x);
    root->left = t1;
    root->right = t2;
    return root;
}

void LVR(Tree t)
{
    if (t != NULL)
    {
        LVR(t->left);
        cout << t->data;
        LVR(t->right);
    }
}

void VLR(Tree t)
{
    if (t != NULL)
    {
        cout << t->data;
        LVR(t->left);
        LVR(t->right);
    }
}

void LRV(Tree t, int &m, ItemType posfix[])
{
    if (t != NULL)
    {
        LRV(t->left, m, posfix);
        LRV(t->right, m, posfix);
        strcpy(posfix[m++], t->data);
    }
}

float evaluate(int m, ItemType posfix[])
{
    Stack s = NULL;
    //
    ItemType x;

    float result = 0;
    float a, b;
    for (int i = 0; i < m; i++)
    {
        if (strcmp(posfix[i], "+") == 0)
        {
            s = pop(s, x);
            b = atof(x);
            s = pop(s, x);
            a = atof(x);
            result = a + b;
            sprintf(x, "%.2f", result);
            s = push(s, x);
        }
        else if (strcmp(posfix[i], "-") == 0)
        {
            s = pop(s, x);
            b = atof(x);
            s = pop(s, x);
            a = atof(x);
            result = a - b;
            sprintf(x, "%.2f", result);
            s = push(s, x);
        }
        else if (strcmp(posfix[i], "*") == 0)
        {
            s = pop(s, x);
            b = atof(x);
            s = pop(s, x);
            a = atof(x);
            result = a * b;
            sprintf(x, "%.2f", result);
            s = push(s, x);
        }
        else if (strcmp(posfix[i], "/") == 0)
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
            s = push(s, posfix[i]);
        }
    }
    s = pop(s, x);
    result = atof(x);
    return result;
}
int main()
{
    Tree t;
    int m = 0;
    Stack s;
    ItemType posfix[20];

    float result;
    // t = CreateTree("*",
    //                CreateTree("-", CreateTree("8", NULL, NULL), CreateTree("5", NULL, NULL)),
    //                CreateTree("/",
    //                           CreateTree("+", CreateTree("4", NULL, NULL), CreateTree("2", NULL, NULL)),
    //                           CreateTree("3", NULL, NULL)));
    //

    // (8-3) * (4/2) = 10

    t = CreateTree("*", CreateTree("-", CreateTree("8", NULL, NULL), CreateTree("3", NULL, NULL)),
                   CreateTree("/", CreateTree("4", NULL, NULL), CreateTree("2", NULL, NULL)));

    cout << "--------------------LVR--------------------\n";

    VLR(t);
    cout << "\n";

    cout << "--------------------LVR--------------------\n";

    LVR(t);
    cout << "\n";

    cout << "--------------------LRV---------------------\n";
    LRV(t, m, posfix);
    for (int i = 0; i < m; i++)
    {
        cout << posfix[i] << " ";
    }
    cout << "\n";

    result = evaluate(m, posfix);
    cout << "result: " << result << endl;
    return 0;
}