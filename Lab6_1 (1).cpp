//  binary search tree
#include <iostream>
using namespace std;
 int n=1;
 int k=0;
// BST node
struct Node {
    int key;
    struct Node *left, *right;
};
 
// Utility function to create a new node
Node* newNode(int data)
{
    Node* temp = new Node;
 
    temp->key = data;
 
    temp->left = NULL;
    temp->right = NULL;
 
    return temp;
}
 
// A utility function to insert a new
// Node with given key in BST
Node* insert(Node* root, int key)
{
    // Create a new Node containing
    // the new element
    Node* newnode = newNode(key);
 
    // Pointer to start traversing from root and
    // traverses downward path to search
    // where the new node to be inserted
    Node* x = root;
 
    // Pointer y maintains the trailing
    // pointer of x
    Node* y = NULL;
 
    while (x != NULL) {
        y = x;
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }
 
    // If the root is NULL i.e the tree is empty
    // The new node is the root node
    if (y == NULL)
        y = newnode;
 
    // If the new key is less then the leaf node key
    // Assign the new node to be its left child
    else if (key < y->key)
        y->left = newnode;
 
    // else assign the new node its right child
    else
        y->right = newnode;
 
    // Returns the pointer where the
    // new node is inserted
    return y;
}
 
void pre(Node* root)
{
    if (root == NULL) {
        return;
    }
    else
    {
        cout<<root->key<<" ";
        pre(root->left);
        pre(root->right);
    }
}

void Inorder(Node* root)
{
    if (root == NULL)
        return;
    else {
        Inorder(root->left);
        cout << root->key << " ";
        Inorder(root->right);
    }
}
 void postr(Node* root)
{
    if (root == NULL) {
        return;
    }
    else {
        postr(root->left);
        postr(root->right);
        cout<<root->key<<" ";
    }
}

Node* searchMin(Node* T )
{
	if( T == NULL ) 
		return NULL;
	else if( T->left == NULL ) 
		return(T);
	else 
		return(searchMin ( T->left ));
}
Node* searchMax( Node* T )
{
	if( T != NULL )
	while( T->right != NULL ) 
		T = T->right;
	return T;
}

void Search(Node *root, int key) 
{
   int depth = 0;
   Node *temp = new Node;
   temp = root;
   while(temp != NULL) {
      depth++;
      if(temp->key == key) {
         cout<<" Item found at depth: "<<depth;
         return;
      } else if(temp->key > key)
         temp = temp->left;
         else
            temp = temp->right;
   }
   cout<<" Item not found";
   return;
}
int CountNodes(Node*root)
{
	if(root==NULL)
		return 0;
	if(root->left!=NULL)
	{
		n=n+1;
		n=CountNodes(root->left);
	}
	if(root->right!=NULL)
	{
		n=n+1;
		n=CountNodes(root->right);
	}
	return n;
}
int internalnodes(struct Node* root)
{
    // Base cases.
    if (root == NULL || (root->left == NULL &&
                         root->right == NULL))
        return 0;
 
    // If root is Not NULL and its one of its
    // child is also not NULL
    return 1 + internalnodes(root->left) +internalnodes(root->right);
}
// Find height of a tree, defined by the root node
int tree_height(Node* root) 
{
    // Get the height of the tree
    if (!root)
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
 Node* deleteNode(Node* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else 
	{
        // node has no child
        if (root->left==NULL and root->right==NULL)
            return NULL;
       
        // node with only one child or no child
        else if (root->left == NULL) {
             Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
 		 
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        Node* temp = searchMin(root->right);
 
        // Copy the inorder successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
 

int main()
{
    /* Let us create following BST
             8
          /     \
       3         10
    /   \       /   \
  1     6    9      14 
     /   \          /
    4	  7      13	    */
 
    Node* root = NULL;
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 1);
    insert(root, 6);
    insert(root, 4);
    insert(root, 7);
    insert(root, 10);
    insert(root, 9);
    insert(root, 14);
    insert(root, 13);
 
 
    cout<<"Traverse the tree in pre-order \n";pre(root);
    cout<<"\n";
   	cout<<"Traverse the tree in in-order \n";Inorder(root);
  	cout<<"\n";
   	cout<<"Traverse the tree in post-order \n";postr(root);
    cout<<"\n";
    cout<<"Find the smallest element: ";
   	cout<<searchMin(root)->key;
	cout<<"\n";
    cout<<"Find the largest element: ";
   	cout<<searchMax(root)->key;
  	Search(root,1);
   	cout<<"\n";
	cout<<"Count the number of nodes: "<<CountNodes(root)<<endl;
	cout<<"Count the number of internal nodes: "<<internalnodes(root)<<endl;
	cout<<"Determine the height of the tree: "<<tree_height(root)<<endl;
	cout<<"Delete a node pre-order from the tree: ";
	root=deleteNode(root,3);
	pre(root);
	cout<<"\n";
	cout<<"Delete a node in-order from the tree: ";
	root=deleteNode(root,3);
	Inorder(root);
	cout<<"\n";
	cout<<"Delete a node post-order from the tree: ";
	root=deleteNode(root,3);
	postr(root);
    return 0;
}




