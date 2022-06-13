#include <iostream>

using namespace std;

typedef string object;
typedef struct node *tree_pointer;
typedef struct  node
{   object  data;
    tree_pointer   left;
    tree_pointer   right;
};
node * newNode(object x)
{
    node * p;
    p= new node;
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
node * createtree(node * p,node * t1, node * t2)
{
    p->left=t1;
    p->right=t2;
    return p;
}
node * createtree(object x,node * t1, node * t2)
{   node * p;
    p=newNode(x);
    p->left=t1;
    p->right=t2;
    return p;
}
void inorder(tree_pointer t)
{
    if(t)
    {
        inorder(t->left);
        cout<<t->data<<" ";
        inorder(t->right);
    }
}
void preorder(tree_pointer t)
{
    if(t)
    {
        cout<<t->data<<" ";
        inorder(t->left);
        inorder(t->right);
    }
}
void postorder(tree_pointer t)
{
    if(t)
    {

        inorder(t->left);
        inorder(t->right);
           cout<<t->data<<" ";
    }
}


int main()
{
    string s="((8-5)*((4+2)/3))";
    node * t;
    t=createtree("*",createtree("-",newNode("8"),newNode("5")),createtree("/",createtree("+",newNode("4"),newNode("2")),newNode("3")));


    inorder(t);

    cout<<"\n";
    preorder(t);
    cout<<"\n";
    postorder(t);

    return 0;
}