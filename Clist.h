#include <iostream>
using namespace std;

template <class t>
class Node
{
public:
    t elem;
    Node *next;
};

template <class t>
class CList
{
public:
    CList();
    bool empty(); // Checks if list is empty

    void addBack();            // Element that is referenced by the cursor   . We can say last Node
    void addFront();           // Element that is following the cursor . We can say First Node
    void insertAfterElement(); // Insert element after a specific element
    void removeFirst();        // Remove first element
    void removeLast();         // Remove last element
    void removeXelement();     // Remove any specific element
    void searchElement();      // Search any element
    void display();            // Displays the elements in the list

    void concatenate(); // Concatenates two list

    void secondListData();    // It takes all the details of the second list
    bool emptySecond();       // Checks if second list is empty
    void insertFrontSecond(); // insert element at the front of the second list
    void insertAfterSecond(); // insert element at the ith position of the list
    void insertEndSecond();   // insert element at the end of the list
    void displaySecond();     // Displays the element of the second list

    t front();
    t back();

private:
    Node<t> *cursor;  // Cursor of the first circular list
    Node<t> *cursor2; // Cursor of the second circular list
};

template <class t>
t CList<t>::front()
{

    return cursor->next->elem;
}

template <class t>
t CList<t>::back()
{

    return cursor->elem;
}

template <class t>
CList<t>::CList()
{
    cursor = NULL;
    cursor2 = NULL;
}

template <class t>
bool CList<t>::empty()
{
    if (cursor == NULL)
    {
        return true;
    }
    else
        return false;
}

template <class t>
void CList<t>::addBack()
{
    Node<t> *n = new Node<t>;
    cout << "Please enter the element " << endl;
    t ele;
    cin >> ele;
    if (empty())
    {
        n->elem = ele;
        n->next = n;
        cursor = n;
    }
    else
    {
        n->elem = ele;
        n->next = cursor->next;
        cursor->next = n;
        cursor = n;
    }
}

template <class t>

void CList<t>::addFront()
{
    t ele;
    cout << "Please enter the element . " << endl;
    cin >> ele;
    if (empty())
    {
        Node<t> *n = new Node<t>;
        n->elem = ele;

        n->next = n;
        cursor = n;
    }
    else
    {
        Node<t> *n = new Node<t>;
        n->elem = ele;
        n->next = cursor->next;
        cursor->next = n;
    }
}

template <class t>
void CList<t>::insertAfterElement()
{
    display();
    t old;
    t ele;
    cout << "Please enter the Y element . " << endl;
    cin >> old;
    cout << "Please enter the X element ." << endl;
    cin >> ele;
    Node<t> *n = new Node<t>;
    Node<t> *p = new Node<t>;
    n = cursor->next;
    while (n->elem != old)
    {
        n = n->next;
    }
    if (n == cursor)
    {
        p->next = n->next;
        n->next = p;
        p->elem = ele;
        cursor = p;
    }
    else
    {
        p->next = n->next;
        n->next = p;
        p->elem = ele;
    }
}

template <class t>
void CList<t>::removeFirst()
{
    if (empty() == true)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        Node<t> *n = new Node<t>;
        n = cursor->next;
        cursor->next = n->next;
        delete n;
    }
    cout << "Element deleted! " << endl;
}

template <class t>
void CList<t>::removeLast()
{
    if (empty() == true)
    {
        cout << "List is empty! " << endl;
    }
    else
    {
        Node<t> *n = new Node<t>;
        n = cursor->next;
        while (n->next != cursor)
        {
            n = n->next;
        }
        Node<t> *p = new Node<t>;
        p = n->next;
        n->next = p->next;
        cursor = n;
        delete p;
    }
    cout << "Element Deleted!" << endl;
}

template <class t>
void CList<t>::removeXelement()
{
    if (empty() == true)
    {
        cout << "List is empty! " << endl;
    }
    else
    {
        display();
        t ele;
        cout << "Please enter the element you want to delete:" << endl;
        cin >> ele;
        bool flag = false;
        if (cursor->elem == ele)
        {
            cursor = NULL;
            flag = true;
        }
        else
        {
            Node<t> *n = new Node<t>;
            n = cursor->next;

            if (n->elem == ele)
            {
                Node<t> *p = new Node<t>;
                p = cursor->next;
                cursor->next = p->next;
                delete p;
                flag = true;
            }
            else
            {
                while (n->next != cursor)
                {
                    if (n->next->elem == ele)
                    {
                        Node<t> *p = new Node<t>;
                        p = n->next;
                        n->next = p->next;
                        delete p;
                        flag = true;
                    }
                    n = n->next;
                }
            }
        }
        if (flag == true)
        {
            cout << "Element deleted! " << endl;
        }
        else
            cout << "Element not found! " << endl;
    }
}
template <class t>
void CList<t>::searchElement()
{

    if (empty() == true)
    {
        cout << "List is empty!" << endl;
    }
    else
    {

        t ele;
        cout << "Please enter the element you want to search. " << endl;
        cin >> ele;
        Node<t> *n = new Node<t>;
        n = cursor->next;
        int i = 1;
        bool flag = false;
        if (n->elem == ele)
        {

            cout << "Element is found at the place " << 1 << endl;
            cout << "It's pointer is " << cursor->next << endl;
            flag = true;
        }
        else
        {

            while (n->next != cursor->next)
            {
                ++i;
                if (n->next->elem == ele)
                {
                    cout << "Element is found at the place " << i << endl;
                    cout << "It's pointer is " << n->next << endl;
                    flag = true;
                }
                n = n->next;
            }
        }
        if (flag == false)
        {
            cout << ele << " not found in the list. " << endl;
        }
    }
}
template <class t>
bool CList<t>::emptySecond()
{
    if (cursor2 == NULL)
    {
        return true;
    }
    else
        return false;
}

template <class t>
void CList<t>::insertFrontSecond()
{
    t ele;
    cout << "Please enter the element :" << endl;
    cin >> ele;
    if (emptySecond())
    {
        Node<t> *n = new Node<t>;
        n->elem = ele;

        n->next = n;
        cursor2 = n;
    }
    else
    {
        Node<t> *n = new Node<t>;
        n->elem = ele;
        n->next = cursor2->next;
        cursor2->next = n;
    }
}

template <class t>
void CList<t>::insertAfterSecond()
{
    displaySecond();
    t old;
    t ele;
    cout << "Please enter the Y element. " << endl;
    cin >> old;
    cout << "Please enter the X element." << endl;
    cin >> ele;
    Node<t> *n = new Node<t>;
    Node<t> *p = new Node<t>;
    n = cursor2->next;
    while (n->elem != old)
    {
        n = n->next;
    }
    if (n == cursor2)
    {
        p->next = n->next;
        n->next = p;
        p->elem = ele;
        cursor2 = p;
    }
    else
    {
        p->next = n->next;
        n->next = p;
        p->elem = ele;
    }
}

template <class t>
void CList<t>::insertEndSecond()
{
    Node<t> *n = new Node<t>;
    cout << "Please enter the element :" << endl;
    t ele;
    cin >> ele;
    if (emptySecond())
    {
        n->elem = ele;
        n->next = n;
        cursor2 = n;
    }
    else
    {
        n->elem = ele;
        n->next = cursor2->next;
        cursor2->next = n;
        cursor2 = n;
    }
}

template <class t>
void CList<t>::displaySecond()
{
    if (emptySecond() == true)
    {
        cout << "List is empty! " << endl;
    }
    else
    {
        cout << "Elements in the second list :- ";
        Node<t> *n = new Node<t>;
        n = cursor2->next;
        cout << n->elem << " ";
        while (n->next != cursor2->next)
        {
            n = n->next;
            cout << n->elem << " ";
        }
    }
    cout << endl;
}
template <class t>
void CList<t>::display()
{
    if (empty() == true)
    {
        cout << "List is empty! " << endl;
    }
    else
    {
        cout << "Elements in the first list :- ";
        Node<t> *n = new Node<t>;
        n = cursor->next;
        cout << n->elem << " ";
        while (n->next != cursor->next)
        {
            n = n->next;
            cout << n->elem << " ";
        }
    }
    cout << endl;
}

template <class t>
void CList<t>::secondListData()
{
    int choice;
    char repeat;
    do
    {
        cout << "----------------------------------------------------------------------" << endl;
        cout << "Enter 1: To insert an element X at the front of the second list. " << endl;
        cout << "Enter 2: To insert element X at the end of the second  List . " << endl;
        cout << "Enter 3: To display the elements of the second list ." << endl;
        cout << "Enter 4: To insert element X after an  element Y of the second list  ." << endl;
        cout << "----------------------------------------------------------------------" << endl;

        cin >> choice;
        switch (choice)
        {
        case 1:
            insertFrontSecond();
            break;
        case 2:
            insertEndSecond();
            break;
        case 3:
            displaySecond();
            break;
        case 4:
            insertAfterSecond();
            break;
        default:
            cout << "Inavalid Choice . " << endl;
            break;
        }
        cout << "Want to repeat in the SECOND LIST ? Y / N ? " << endl;
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');
}

template <class t>
void CList<t>::concatenate()
{
    Node<t> *p = new Node<t>;
    if (empty() == true)
    {
        cout << "First list is empty " << endl;
    }
    else if (emptySecond() == true)
    {
        cout << "Second List is empty . " << endl;
    }
    else
    {
        p = cursor->next;
        while (p->next != cursor2->next)
        {
            if (p->next == cursor->next)
            {
                p->next = cursor2->next;
            }
            cout << p->elem << " ";
            p = p->next;
        }
        cout << p->elem << " ";
    }
    cout << endl;
}
