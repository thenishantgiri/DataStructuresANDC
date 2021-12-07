#include <iostream>
#include "DLinked.h"
using namespace std;

// Defining QueueEmpty exception
class QueueEmpty : public exception
{
public:
    const char *what() const throw()
    {
        return "Exception caught : Queue is empty. \n";
    }
};
template <class t>
class Deque
{
public:
    int n;
    Deque();
    void EnqueueFront();
    void EnqueueBack();
    void DequeueFront();
    void DequeueBack();
    int size();
    void front();
    void back();
    bool empty();

    void menuDriven(Deque<t> khan);

private:
    List<t> c;
};

template <class t>
Deque<t>::Deque()
{
    n = 0;
}

template <class t>
void Deque<t>::EnqueueFront()
{
    c.addFront();
    n++;
}

template <class t>
void Deque<t>::EnqueueBack()
{
    c.addBack();
    n++;
}

template <class t>
void Deque<t>::DequeueBack()
{
    if (empty())
    {
        QueueEmpty s;
        throw s;
    }
    else
    {
        c.removeBack();
        n--;
    }
}
template <class t>
void Deque<t>::DequeueFront()
{
    if (empty())
    {
        QueueEmpty s;
        throw s;
    }
    else
    {
        c.removeFront();
        n--;
    }
}

template <class t>
void Deque<t>::front()
{
    if (empty())
    {
        QueueEmpty s;
        throw s;
    }
    else
    {
        c.front();
    }
}

template <class t>
void Deque<t>::back()
{
    if (empty())
    {
        QueueEmpty s;
        throw s;
    }
    else
    {
        c.back();
    }
}

template <class t>
int Deque<t>::size()
{
    return n;
}

template <class t>
bool Deque<t>::empty()
{
    if (n == 0)
    {
        return true;
    }
    else
        return false;
}
template <class t>
void Deque<t>::menuDriven(Deque<t> k)
{
    int choice;
    char repeat;
    do
    {
        cout << "Enter 1:  Enqueue front." << endl;
        cout << "Enter 2:  Enqueue back. " << endl;
        cout << "Enter 3:  Dequqe front ." << endl;
        cout << "Enter 4:  Dequeue back." << endl;
        cout << "Enter 5:  Get Front. " << endl;
        cout << "Enter 6:  Get Back." << endl;
        cout << "Enter 7:  Get size. " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            k.EnqueueFront();
            break;
        case 2:
            k.EnqueueBack();
            break;
        case 3:
            k.DequeueFront();
            break;
        case 4:
            k.DequeueBack();
            break;
        case 5:
            try
            {
                k.front();
            }
            catch (QueueEmpty s)
            {
                cout << s.what();
            }
            break;
        case 6:
            try
            {
                k.back();
            }
            catch (QueueEmpty s)
            {
                cout << s.what();
            }
            break;
        case 7:
            cout << "Elements in the Queue :- " << k.size() << endl;
            break;
        default:
            cout << "Invalid Choice. " << endl;
            break;
        }
        cout << "Do you want to repeat ? [Y]/[N]? " << endl;
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');
}
int main()
{
    cout << "Enter 1: Integer Operations. " << endl;
    cout << "Enter 2: String Operations. " << endl;
    cout << "Enter 3: Char operations . " << endl;
    int type;
    cin >> type;
    if (type == 1)
    {
        Deque<int> k;
        k.menuDriven(k);
    }
    else if (type == 2)
    {
        Deque<string> k;
        k.menuDriven(k);
    }
    else if (type == 3)
    {
        Deque<char> k;
        k.menuDriven(k);
    }
    else
        cout << "Invalid Choice." << endl;
    return 0;
}