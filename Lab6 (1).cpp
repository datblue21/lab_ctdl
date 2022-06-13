#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

typedef Node *Tree;

Tree newNode(int data)
{
    Tree temp = new Node;

    temp->data = data;

    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Tree insert1(Tree root, int data)
{
    Tree newnode = newNode(data);

    Tree x = root;
    Tree y = NULL;

    while (x != NULL)
    {
        if (x->data == data)
        {
            return NULL;
        }
        else if (x->data < data)
        {
            x = x->right;
        }
        else
            x = x->left;
    }
    if (y == NULL)
        y = newnode;

    else if (data < y->data)
        y->left = newnode;

    else
        y->right = newnode;

    return y;
}

Tree insert(Tree root, int val)
{

    if (root == NULL)
        return newNode(val);

    if (root->data < val)
        root->right = insert(root->right, val);

    else if (root->data > val)
        root->left = insert(root->left, val);

    return root;
}

Tree insert3( Tree T, int x)
{
    if (T == NULL)
    {
        T = (Tree)malloc(sizeof(Tree));
        if (T == NULL)
        {

            fprintf(stderr, "the memory is full.\n");
            exit(1);
        }
        else
        {
            T->data = x;
            T->left = T->right = NULL;
        }
    }
    else if (x < T->data)
        T->left = insert3(T->left, x);
    else if (x > T->data)
        T->right = insert3(T->right, x );
    return T;
}

// 1.b traverse the tree
void pre(Tree root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << root->data << " ";
        pre(root->left);
        pre(root->right);
    }
}

void Inorder(Tree root)
{
    if (root == NULL)
        return;
    else
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}
void postr(Tree root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postr(root->left);
        postr(root->right);
        cout << root->data << " ";
    }
}
// 1 c search Min , Max

Tree searchMin(Tree T)
{
    if (T == NULL)
        return NULL;
    else if (T->left == NULL)
        return (T);
    else
        return (searchMin(T->left));
}

Tree searchMax(Tree T)
{
    if (T != NULL)
        while (T->right != NULL)
            T = T->right;
    return T;
}

// 1d search given valuas
Tree reSearch(int data, Tree T)
{
    if (T == NULL)
        return NULL;
    if (data < T->data)
        return reSearch(data, T->left);
    else if (data > T->data)
        return reSearch(data, T->right);
    else
        return T;
}

// 1 d FInd given value
void Search(Node *root, int key)
{
    int depth = 0;
    Node *temp = new Node;
    temp = root;
    while (temp != NULL)
    {
        depth++;
        if (temp->data == key)
        {
            cout << " Item found at depth: " << depth;
            return;
        }
        else if (temp->data > key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    cout << " Item not found";
}

// 1e countNodes
int CountNodes(Tree root, int &n)
{

    if (root == NULL)
        return 0;
    if (root->left != NULL)
    {
        n = n + 1;
        n = CountNodes(root->left, n);
    }
    if (root->right != NULL)
    {
        n = n + 1;
        n = CountNodes(root->right, n);
    }
    return n;
}

// 1f count number internal nodes
int internalnodes(struct Node *root)
{
    // Base cases.
    if (root == NULL || (root->left == NULL &&
                         root->right == NULL))
        return 0;

    // If root is Not NULL and its one of its
    // child is also not NULL
    return 1 + internalnodes(root->left) + internalnodes(root->right);
}

// 1g tree height
int tree_height(Tree root)
{
    // Get the height of the tree
    if (root == NULL)
        return 0;
    else
    {
        // Find the height of both subtrees
        // and use the larger one
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

// 1h deleteNode
Tree deleteNode(int x, Tree T)
{
    Tree tmp;
    if (T == NULL)
    {
        fprintf(stderr, "Element not found in tree");
        exit(1);
    }
    else if (x < T->data)
        T->left = deleteNode(x, T->left);
    else if (x > T->data)
        T->right = deleteNode(x, T->right);
    else if (T->left && T->right)
    {
        tmp = searchMin(T->right);
        T->data = tmp->data;
        T->right = deleteNode(T->data, T->right);
    }
    else
    {
        tmp = T;
        if (T->left == NULL)
            T = T->right;
        else if (T->right == NULL)
            T = T->left;
        free(tmp);
    }
    return T;
}

int main()
{
    Tree root = NULL;
    int n = 1;
    root = insert1(root, 8);
    insert3(root, 3);
    insert3(root, 1);
    insert3(root, 6);
    insert3(root, 4);
    insert3(root, 7);
    insert3(root, 10);
    insert3(root, 9);
    insert3(root, 14);
    insert3(root, 13);

    cout << "Traverse the tree in pre-order \n";
    pre(root);
    cout << "\n";
    cout << "Traverse the tree in in-order \n";
    Inorder(root);
    cout << "\n";
    cout << "Traverse the tree in post-order \n";
    postr(root);
    cout << "\n";
    cout << "Find the smallest element: ";
    cout << searchMin(root)->data;
    cout << "\n";
    cout << "Find the largest element: ";
    cout << searchMax(root)->data;
    Search(root, 1);
    cout << "\n";
    cout << "Count the number of nodes: " << CountNodes(root, n) << endl;
    cout << "Count the number of internal nodes: " << internalnodes(root) << endl;
    cout << "Determine the height of the tree: " << tree_height(root) << endl;
    cout << "Delete a node pre-order from the tree: ";
    root = deleteNode(3, root);
    pre(root);
    return 0;
}