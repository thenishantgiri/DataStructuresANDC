#include <iostream>
using namespace std;
class Node
{
public:
    int info;
    Node *next;
    Node()
    {
        next = 0;
    }
    Node(int x, Node *n = 0)
    {
        info = x;
        next = n;
    }
};
class Slist
{
private:
    Node *head, *tail;

public:
    Slist()
    {
        head = tail = 0;
    }
    int isempty();
    void addtohead(int);
    void addtotail(int);
    int deletefromhead();
    void deletenode(int e);
    bool isinlist(int);
    void display();
    ~Slist();
    void addnode(int e, int pos);
};
int Slist::isempty()
{
    if (head == 0)
        return 1;
    else
        return 0;
}
void Slist::addtohead(int x)
{
    Node *p = new Node(x); //node with info part x is created
    if (isempty())
    {
        head = tail = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
}
void Slist::addtotail(int x)
{
    Node *p = new Node(x);
    if (isempty())
    {
        head = tail = p;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
}
int Slist::deletefromhead()
{
    int x = head->info;
    if (head == tail)
    {
        delete head;
        head = tail = 0;
    }
    else
    {
        Node *temp;
        temp = head;
        head = head->next;
        delete temp;
    }
    return x;
}

bool Slist::isinlist(int e)
{
    Node *temp = head;
    while (temp != 0 && temp->info != e)
        temp = temp->next;
    if (temp == 0)
        return false;
    else
        return true;
}
void Slist::deletenode(int e)
{
    if (head->info == e && head == tail)
    {
        delete head;
        head = tail = 0;
    }
    else if (head->info == e)
    {
        deletefromhead();
    }
    else
    {
        Node *prev, *p;
        p = head->next;
        while (p != 0 && p->info != e)
        {
            prev = p;
            p = p->next;
        }
        if (p != 0)
        {
            prev->next = p->next;
            if (p == tail)
            {
                prev->next = 0;
                tail = prev;
                delete p;
            }
        }
        else
            cout << "\n Element not found! \n";
    }
}
void Slist::display()
{
    Node *temp = head;
    while (temp != 0)
    {
        cout << temp->info << " -> ";
        temp = temp->next;
    }
}
Slist::~Slist()
{
    Node *temp = head;
    while (temp != 0)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}
void Slist::addnode(int e, int pos)
{
    Node *temp = head;
    int count = 1;
    while (temp != tail)
    {
        count++;
        temp = temp->next;
    }
    if (pos > count || pos < 0)
        cout << "Invalid position!";
    else
    {

        Node *p = new Node(e);
        if (pos == 1)
        {
            p->next = head;
            head = p;
        }
        else
        {
            int i;
            Node *temp1 = head;
            Node *temp2 = head;
            for (i = 2; i <= pos; i++)
            {
                temp1 = temp2;
                temp2 = temp1->next;
            }
            p->next = temp2;
            temp1->next = p;
        }
    }
}
int main()
{
    Slist s;
    int t;
    int x;
    cout << "Please enter the number of elements: ";
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Please enter element at position " << i + 1 << " : ";
        cin >> x;
        s.addtotail(x);
    }
    do
    {

        cout << "\n\n********************** Please enter your choice ********************\n";
        int n;

        cout << "1.Insert an element x at the beginning of the singly linked list\n\n";
        cout << "2.Insert an element x at position in the singly linked list \n\n";
        cout << "3.Remove an element from the beginning of the singly linked list\n\n";
        cout << "4.Remove an element from position in the singly linked list. \n\n";
        cout << "5.Search for an element x in the singly linked list and return its pointer\n\n";
        cout << "6.Display the list\n\n";

        cout << "Your choice : ";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            cout << endl
                 << "*********************************************************************" << endl;
            cout << "\nPlease enter element you want to enter : ";
            int x;
            cin >> x;
            s.addtohead(x);
            cout << "\nList so formed\n";
            s.display();
            cout << endl
                 << "*********************************************************************" << endl;
            break;
        }
        case 2:
        {
            int e, p = 0;
            cout << "\n*********************************************************************" << endl;
            cout << "\nPlease enter the element : ";
            cin >> e;
            cout << "Please enter the position : ";
            cin >> p;
            s.addnode(e, p);
            cout << "\nList is formed!\n";
            s.display();
            cout << "\n*********************************************************************" << endl;
            break;
        }

        case 3:
        {
            cout << "\n*********************************************************************" << endl;
            if (s.isempty())
            {
                cout << "\nList is empty! ";
            }
            else
            {
                int x = s.deletefromhead();
                cout << "\nThe deleted element is = " << x << endl;
            }
            cout << "\n*********************************************************************" << endl;
            break;
        }

        case 4:
        {
            cout << "\n*********************************************************************" << endl;
            if (s.isempty())
            {
                cout << "\nList is empty! \n";
            }
            else
            {
                int x;
                cout << "\nPlease enter element you want to delete : ";
                cin >> x;
                s.deletenode(x);
            }
            cout << "\n*********************************************************************" << endl;
            break;
        }
        case 5:
        {
            cout << "\n*********************************************************************" << endl;
            if (s.isempty())
            {
                cout << "\nList is empty! \n";
            }
            else
            {
                int x;
                cout << "\nPlease enter the element to be searched \n";
                cin >> x;
                if (s.isinlist(x))
                {
                    cout << "\nElement is present! \n";
                }
                else
                    cout << "\nElement not present! \n";
            }
            cout << "\n*********************************************************************" << endl;
            break;
        }

        case 6:
        {
            s.display();
            break;
        }
        }
        cout << "\nPlease enter 1 if you want to continue : ";
        cin >> t;
    } while (t == 1);
    return 0;
}
