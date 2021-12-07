#include <iostream>
using namespace std;

template <class t>
class BST
{
public:
    BST<t> *left;
    BST<t> *right;
    t ele;
};
template <class t>
class tree
{
public:
    tree();
    BST<t> *createNode();        // Takes data and return a node
    void insert(BST<t> *p);      // Takes node and position it in BST
    void preorder(BST<t> *root); // Recursive function for preorder

    void postOrder(BST<t> *root); // Rcursive function for postorder
    void inOrder(BST<t> *root);   // Recursive function for Inorder
    void deleteNode(BST<t> *&p);  // Takes a referance of the node to be deleted
    void searchAndDelete();       // searches the node then delete it
    void searchNreplace();        // searches the node and replace it
    void menuDrive(tree<t> k);    // Menu Driver
private:
    BST<t> *root;
};
template <class t>
tree<t>::tree() // Constructor to intialize the root with Zero
{
    root = 0;
}
template <class t>
BST<t> *tree<t>::createNode() // Create new node and return it
{
    cout << "Please enter the value of the new node:" << endl;
    t data;
    cin >> data;
    BST<t> *p = new BST<t>;
    p->ele = data;
    p->left = 0;
    p->right = 0;

    return p;
}
// takes new node then fix it at correct position
template <class t>
void tree<t>::insert(BST<t> *n)
{
    BST<t> *p = root;
    BST<t> *prev = 0;
    while (p != 0)
    {
        prev = p;
        if (n->ele < p->ele)
        {
            p = p->left;
        }
        else
            p = p->right;
    }
    if (root == 0)
    {
        root = n;
    }
    else if (n->ele < prev->ele)
    {
        prev->left = n;
    }
    else if (n->ele >= prev->ele)
    {
        prev->right = n;
    }
}
template <class t>
void tree<t>::preorder(BST<t> *p)
{ // Recursive function for Preorder

    if (p != 0)
    {
        cout << p->ele << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

template <class t>
void tree<t>::postOrder(BST<t> *p)
{ // recursive function for PostOrder

    if (p != 0)
    {
        postOrder(p->left);
        postOrder(p->right);
        cout << p->ele << " ";
    }
}

template <class t>
void tree<t>::inOrder(BST<t> *p)
{ // Recursive function for Inorder

    if (p != 0)
    {
        inOrder(p->left);
        cout << p->ele << " ";
        inOrder(p->right);
    }
}
// search for the node and call delete function to delete it
template <class t>
void tree<t>::searchAndDelete()
{
    bool flag = false;
    BST<t> *p = root, *prev = 0;
    if (root == 0)
        cout << "Tree is empty. " << endl;
    else
    {
        cout << "Please enter the value to delete. " << endl;
        t data;
        cin >> data;

        while (p != 0)
        {
            if (p->ele == data)
            {
                flag = true;
                break;
            }
            prev = p;
            if (p->ele < data)
                p = p->right;
            else
                p = p->left;
        }

        if (p != 0 && p->ele == data)
        {
            if (p == root)
                deleteNode(root);

            else if (prev->left == p)
                deleteNode(prev->left);
            else
                deleteNode(prev->right);
        }
        else
            cout << "Element not found!" << endl;
    }
}
// takes the node and delete it
template <class t>
void tree<t>::deleteNode(BST<t> *&p)
{

    BST<t> *tmp = p;

    // bool flag = false;
    if (p->right == 0)
    {
        p = p->left;
    }
    else if (p->left == 0)
    {
        p = p->right;
    }
    else
    {
        tmp = p->left;
        while (tmp->right != 0)
        {
            tmp = tmp->right;
        }
        tmp->right = p->right;

        tmp = p;
        p = p->left;
    }
    delete tmp;
}
// search for the node,delete it , replace with new node and fix it at correct position
template <class t>
void tree<t>::searchNreplace()
{
    bool flag = false;
    BST<t> *p = root, *prev = 0;
    if (root == 0)
        cout << "Tree is empty! " << endl;
    else
    {
        cout << "Please enter the value to be deleted :" << endl;
        t data;
        cin >> data;

        while (p != 0)
        {
            if (p->ele == data)
            {
                flag = true;
                break;
            }
            prev = p;
            if (p->ele < data)
                p = p->right;
            else
                p = p->left;
        }

        if (p != 0 && p->ele == data)
        {
            if (p == root)
            {
                deleteNode(root);
                insert(createNode());
            }

            else if (prev->left == p)
            {
                deleteNode(prev->left);
                insert(createNode());
            }
            else
            {
                deleteNode(prev->right);
                insert(createNode());
            }
        }
        else
            cout << "Element not found!" << endl;
    }
}

template <class t>
void tree<t>::menuDrive(tree<t> k)
{
    int choice;
    char repeat;
    do
    {
        cout << "Enter 1: Insert new Node ." << endl;
        cout << "Enter 2: Delete Node. " << endl;
        cout << "Enter 3: Search And Replace ." << endl;
        cout << "Enter 4: Print in PreOrder,PostOrder,Inorder. " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            insert(createNode());
            break;
        case 2:
            searchAndDelete();
            break;
        case 3:
            searchNreplace();
            break;
        case 4:
            if (root != 0)
            {
                cout << "PreOrder :- ";
                preorder(root);
                cout << "\nPostOrder :- ";
                postOrder(root);
                cout << "\nInOrder :- ";
                inOrder(root);
            }
            else
                cout << "Tree is empty! " << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
            break;
        }
        cout << "\n\nWant to Repeat ? [Y][N]?" << endl;
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');
}
int main()
{
    // Asks user for their preferred type of tree and perform desired tasks
    int type;
    cout << "Enter 1: Integer Operations. " << endl;
    cout << "Enter 2: String Operations. " << endl;
    cout << "Enter 3: Char Operations. " << endl;
    cout << "Enter 4: Float operations. " << endl;
    cin >> type;
    if (type == 1)
    {
        tree<int> k;
        k.menuDrive(k);
    }
    else if (type == 2)
    {
        tree<string> k;
        k.menuDrive(k);
    }
    else if (type == 3)
    {
        tree<char> k;
        k.menuDrive(k);
    }
    else if (type == 4)
    {
        tree<float> k;
        k.menuDrive(k);
    }
    else
        cout << "Invalid Choice!" << endl;

    return 0;
}
