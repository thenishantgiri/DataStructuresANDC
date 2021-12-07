#include <iostream>
#include "Clist.h"
using namespace std;

class QueueEmpty : public exception
{
public:
    const char *what() const throw()
    {
        return " Exception Caught: Queue is empty. \n";
    }
};
template <class t>
class Qlist
{
public:
    Qlist();
    void enqueue();
    void dequeue();
    void front();
    void back();
    int size();
    bool empty();

    void menuDrive(Qlist<t> obj);

private:
    int n;
    CList<t> c;
};

template <class t>
Qlist<t>::Qlist()
{
    n = 0;
}
template <class t>
bool Qlist<t>::empty()
{
    if (n == 0)
        return true;
    else
        return false;
}

template <class t>
int Qlist<t>::size()
{
    return n;
}

template <class t>
void Qlist<t>::enqueue()
{
    c.addBack();
    n++;
}

template <class t>
void Qlist<t>::dequeue()
{
    if (empty())
    {
        QueueEmpty s;
        throw s;
    }
    else
    {
        c.removeFirst();
        n--;
    }
}

template <class t>
void Qlist<t>::front()
{
    if (empty())
    {
        QueueEmpty s;
        throw s;
    }
    else
        cout << "Front element is :-" << c.front() << endl;
}

template <class t>
void Qlist<t>::back()
{
    if (empty())
    {
        QueueEmpty s;
        throw s;
    }
    else
        cout << "Back element is :- " << c.back() << endl;
}

template <class t>
void Qlist<t>::menuDrive(Qlist<t> obj)
{
    int choice;
    char repeat;
    do
    {
        cout << "Enter 1: Enquque. " << endl;
        cout << "Enter 2: Dequeue. " << endl;
        cout << "Enter 3:Front " << endl;
        cout << "Enter 4 : Back " << endl;
        cout << "Enter 5 : Size ." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.enqueue();
            break;
        case 2:
            try
            {
                obj.dequeue();
            }
            catch (QueueEmpty a)
            {
                cout << a.what();
            }
            break;
        case 3:
            try
            {
                obj.front();
            }
            catch (QueueEmpty s)
            {
                cout << s.what();
            }
            break;
        case 4:
            try
            {
                obj.back();
            }
            catch (QueueEmpty s)
            {
                cout << s.what();
            }
            break;
        case 5:
            cout << "Current no. of elements ." << obj.size() << endl;
            break;
        default:
            cout << "Invalid Choice. " << endl;
            break;
        }
        cout << "Want to repeat ? [Y]/[N]? " << endl;
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');
}
int main()
{
    int type;
    cout << "Enter 1 : Integer Operations ." << endl;
    cout << "Enter 2: String Operations ." << endl;
    cout << "Enter 3: Char Operations . " << endl;
    cin >> type;
    if (type == 1)
    {
        Qlist<int> k;
        k.menuDrive(k);
    }
    else if (type == 2)
    {
        Qlist<string> k;
        k.menuDrive(k);
    }
    else if (type == 3)
    {
        Qlist<char> k;
        k.menuDrive(k);
    }
    else
        cout << "Invalid Choice. " << endl;
    return 0;
}