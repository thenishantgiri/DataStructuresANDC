#include <iostream>
#include <exception>
using namespace std;

//  Defining QueueFull exception
class QueueFull : public exception
{
public:
    const char *what() const throw()
    {
        return " Exception caught: Queue is full. \n";
    }
};

// Defining QueueEmpty exception
class QueueEmpty : public exception
{
public:
    const char *what() const throw()
    {
        return "Exception caught : Queue is empty. \n";
    }
};

// main class
template <class t> // Using template class
class CircularArray
{
public:
    int num, f, r, n;
    t Q[20];
    CircularArray();
    void input();
    int size();
    bool empty();
    void enqueue();
    void dequeue();
    void front();
    void back();

    void menuDrive(CircularArray<t> k);
};

template <class t>
CircularArray<t>::CircularArray()
{
    n = 0;
    f = 0;
    r = 0;
}

template <class t>
int CircularArray<t>::size()
{
    return n;
}

template <class t>
void CircularArray<t>::input()
{
    cout << "Please enter the size of the queue: " << endl;
    cin >> num;
}

template <class t>
bool CircularArray<t>::empty()
{
    if (n == 0)
    {
        return true;
    }
    else
        return false;
}

template <class t>
void CircularArray<t>::enqueue()
{
    if (size() == num)
    {
        QueueFull s;
        throw s;
    }
    else
    {

        cout << "Please enter the element : " << endl;
        cin >> Q[r];
        n++;
        r = (r + 1) % num;
    }
}

template <class t>
void CircularArray<t>::dequeue()
{
    if (empty())
    {
        QueueEmpty s;
        throw s;
    }
    else
    {
        f = (f + 1) % num;
        n--;
    }
}

template <class t>
void CircularArray<t>::front()
{
    if (empty())
    {
        QueueEmpty s;
        throw s;
    }
    else
    {
        cout << "Front element is : " << Q[f];
    }
}

template <class t>
void CircularArray<t>::back()
{
    if (empty())
    {
        QueueEmpty s;
        throw s;
    }
    else
    {
        int b = (r - 1) % num;
        if (b == -1)
            b = num - 1;
        cout << "Back element is : " << Q[b];
    }
}

template <class t>
void CircularArray<t>::menuDrive(CircularArray<t> k)
{
    k.input();
    int choice;
    char repeat;
    do
    {

        cout << "Enter 1: To Enqueue. " << endl;
        cout << "Enter 2: To Dequeue. " << endl;
        cout << "Enter 3: Get the front element. " << endl;
        cout << "Enter 4: Get the back element. " << endl;
        cout << "Enter 5: Get the current number of elements. " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            try
            {
                k.enqueue();
            }
            catch (QueueFull s)
            {
                cout << s.what();
            }
            break;
        case 2:
            try
            {
                k.dequeue();
            }
            catch (QueueEmpty s)
            {
                cout << s.what();
            }
            break;
        case 3:
            try
            {
                k.front();
            }
            catch (QueueEmpty s)
            {
                cout << s.what();
            }
            break;
        case 4:
            try
            {
                k.back();
            }
            catch (QueueEmpty s)
            {
                cout << s.what();
            }
            break;
        case 5:
            cout << "Current no. of elements: " << k.size();
            break;

        default:
            cout << "Invalid choice! " << endl;
            break;
        }
        cout << "\nWant to repeat ? Y/N ?" << endl;
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');
}

// Main
int main()
{
    int choice;
    char repeat;

    cout << "Enter 1: For integer operations : " << endl;
    cout << "Enete 2: For string operations : " << endl;
    cout << "Enter 3: Char Operations. " << endl;
    int type;
    cin >> type;
    if (type == 1)
    {
        CircularArray<int> k;
        k.menuDrive(k);
    }
    else if (type == 2)
    {
        CircularArray<string> k;
        k.menuDrive(k);
    }
    else if (type == 3)
    {
        CircularArray<char> k;
        k.menuDrive(k);
    }
    else
        cout << "Invalid Choice! " << endl;

    return 0;
}