#include <iostream>
using namespace std;
template <class X>
class Node
{
public:
    int data;
    Node<X> *next;
    Node<X> *prev;
    Node()
    {
        next = 0;
        prev = 0;
    }
    Node(int d, Node *n = 0, Node *p = 0)
    {
        data = d;
        next = n;
        prev = p;
    }
};
template <class X>
class Doublylist
{
public:
    Node<X> *head;
    Node<X> *head1;
    Node<X> *tail;
    Node<X> *tail1;
    Doublylist();
    bool IsEmpty();
    void InsertAthead(X e);
    void InsertAttail(X e);
    int Removefromhead();
    void RemoveAtlocation(X e);
    int Removefromtail();
    bool search(X e);
    void insertAtlocation(X e, int pos);
    void List2();
    void Concatenate();
    bool ifempty(Node<X> *p);
    void display();
};

template <class X>
Doublylist<X>::Doublylist()
{
    head = tail = 0;
}

template <class X>
bool Doublylist<X>::IsEmpty()
{
    if (head == 0)
        return 1;
    else
        return 0;
}

template <class X>
void Doublylist<X>::InsertAthead(X e)
{
    Node<X> *p = new Node<X>(e); //creating node
    if (IsEmpty())
    {
        head = tail = p;
    }
    else
    {
        p->next = head;
        head->prev = p;
        head = p;
    }
}

template <class X>
void Doublylist<X>::InsertAttail(X e)
{
    Node<X> *p = new Node<X>(e); //creating node
    if (IsEmpty())
    {
        head = tail = p;
    }
    else
    {
        tail->next = p;
        p->prev = tail;
        tail = p;
    }
}

template <class X>
bool Doublylist<X>::ifempty(Node<X> *p)
{
    if (p == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class X>
void Doublylist<X>::List2()
{
    X x;
    int n;
    Node<X> *t;
    cout << "\nCreating 2 doubly linked list" << endl;
    cout << "Enter number to element to create Doubly Linked List 2 : ";
    cin >> n;

    head1 = new Node<X>;
    if (ifempty(head1))
    {
        cout << "\nUnable to allocate memory.";
    }
    else
    {
        cout << "Enter element at position 1: ";
        cin >> x;
        head1->data = x;
        head1->prev = head1->next = NULL;
        tail1 = head1;

        for (int i = 2; i <= n; i++)
        {

            t = new Node<X>;

            if (ifempty(t))
            {
                cout << "\nUnable to allocate memory.";
                break;
            }
            else
            {
                cout << "Enter element at position " << i << ": ";
                cin >> x;

                t->data = x;
                t->next = NULL;
                t->prev = tail1;
                tail1->next = t;
                tail1 = t;
            }
        }
        cout << "List 2 created sucessfully !!!" << endl;
    }
}

template <class X>
void Doublylist<X>::insertAtlocation(X e, int pos)
{
    Node<X> *temp = head;
    int count = 1;
    while (temp != tail)
    {
        count++;
        temp = temp->next;
    }
    if (pos > count || pos < 0)
        cout << "Invalid position";
    else
    {

        Node<X> *p = new Node<X>(e);
        if (pos == 1)
        {
            p->next = head;
            p->prev = NULL;
            head->prev = p;
            head = p;
        }
        else
        {
            int i;
            Node<X> *temp1 = head;
            Node<X> *temp2 = head;
            for (i = 2; i <= pos; i++)
            {
                temp1 = temp2;
                temp2 = temp1->next;
            }
            p->next = temp2;
            p->prev = temp1;
            temp1->next = p;
            temp2->prev = p;
        }
    }
}

template <class X>
int Doublylist<X>::Removefromhead()
{
    int x = head->data;
    if (head == tail)
    {
        delete head;
        head = tail = 0;
    }
    else
    {
        Node<X> *p = head->next;
        p->prev = 0;
        delete head;
        head = p;
    }
    return x;
}

template <class X>
void Doublylist<X>::RemoveAtlocation(X e)
{
    if (head->data == e && head == tail)
    {
        delete head;
        head = tail = 0;
    }
    else if (head->data == e)
    {
        Removefromhead();
    }
    else if (tail->data == e)
    {
        Removefromtail();
    }
    else
    {
        Node<X> *p = head->next;
        while (p != NULL && p->data != e)
        {
            p = p->next;
        }
        if (p->data == e)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
        }
        else
            cout << "\n\nNode not found\n\n";
    }
}

template <class X>
int Doublylist<X>::Removefromtail()
{
    int x = tail->data;
    if (head == tail)
    {
        delete head;
        head = tail = 0;
    }
    else
    {
        Node<X> *p = tail->prev;
        p->next = 0;
        delete tail;
        tail = p;
    }
    return x;
}

template <class X>
bool Doublylist<X>::search(X e)
{
    Node<X> *temp = head;
    while (temp != 0 && temp->data != e)
        temp = temp->next;
    if (temp == 0)
        return false;
    else
        return true;
}

template <class X>
void Doublylist<X>::Concatenate()
{
    Node<X> *p = tail, *q = head1;

    p->next = q;
    q->prev = p;
    tail = tail1;
    head1 = head;
    cout << "\nList 1 is Concatenated to List 2 ";
}

template <class X>
void Doublylist<X>::display()
{
    Node<X> *temp = head;
    while (temp != 0)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl
         << endl;
}

int main()
{
    Doublylist<int> a;
    int t, x, opt, ch;
    int e;
    cout << "Enter the number of elements you would like to enter : ";
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Enter element at position " << i + 1 << " : ";
        cin >> x;
        a.InsertAttail(x);
    }
    a.display();
    do
    {
        cout << "MENU " << endl;
        cout << "1.Insert an element x at the beginning " << endl;
        cout << "2.Insert an element x at any location" << endl;
        cout << "3.Insert an element x at the end " << endl;
        cout << "4.Remove an element from the beginning " << endl;
        cout << "5.Remove an element from any location" << endl;
        cout << "6.Remove an element from the end " << endl;
        cout << "7.Search for an element " << endl;
        cout << "8.Concatenate two doubly linked lists " << endl;
        cout << "Enter your choice : ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "\nEnter the element you want to enter in the begining : ";
            cin >> e;
            a.InsertAthead(e);
            a.display();
            break;

        case 2:
            int e, p;
            cout << "\nEnter the element you would like to enter : ";
            cin >> e;
            cout << "Enter the position where you want to enter the element : ";
            cin >> p;
            a.insertAtlocation(e, p);
            cout << "\nList so formed\n";
            a.display();
            break;

        case 3:
            cout << "\nEnter the element you want to enter in the end : ";
            cin >> e;
            a.InsertAttail(e);
            a.display();
            break;

        case 4:
            cout << "Removing from the begining " << endl;
            a.Removefromhead();
            a.display();
            break;

        case 5:
            if (a.IsEmpty())
            {
                cout << "\nList is empty \n";
            }
            else
            {
                int x;
                cout << "\nEnter info part of the node u like to delete \n";
                cin >> x;
                a.RemoveAtlocation(x);
                cout << "\nThe new list\n ";
                a.display();
            }
            break;

        case 6:
            cout << "Removing from the end " << endl;
            a.Removefromtail();
            a.display();
            break;

        case 7:
            cout << "\nEnter the element you want to search : ";
            cin >> e;
            if (a.search(e))
            {
                cout << "Element is present in the list ";
            }
            else
            {
                cout << "Element is not present in the list";
            }
            break;

        case 8:
            a.List2();
            a.Concatenate();
            cout << "\nAfter concatenation list is : ";
            a.display();
            break;

        default:
            cout << "INVALID CHOICE!";
        }
        cout << "\nEnter 1 if you want to continue : ";
        cin >> ch;
    } while (ch == 1);
    return 0;
}
