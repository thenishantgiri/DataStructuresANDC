#include <iostream>
#include <exception>
using namespace std;

class StackEmpty : public exception // StackEmpty exception class
{
public:
    const char *what() const throw()
    {
        return "Exception Caught : Stack is empty! ";
    }
};

class StackFull : public exception // StackFull exception class
{
public:
    const char *what() const throw()
    {
        return "Exception Caught : Stack is full!";
    }
};

template <class t>
class ArrayStack
{
private:
    int T = -1;
    int n;
    t arr[10];

public:
    void input();   // Get the size of the stack/ Array
    bool empty();   // Check if stack is empty
    void display(); // Display the elements of the stack

    void pop();  // Pop the top element of the stack
    void push(); // Push an element on stack
    void top();  // Displays the top element of the stack
    int size();  // Number of current items in the stack
};

template <class t>
void ArrayStack<t>::input()
{
    cout << "Please enter the size of the stack: " << endl;
    cin >> n;
}

template <class t>
bool ArrayStack<t>::empty()
{
    if (T < 0)
    {
        return true;
    }
    else
        return false;
}

template <class t>
void ArrayStack<t>::pop()
{
    if (empty())
    {
        StackEmpty s;
        throw s;
    }
    else
    {
        --T;
        cout << "Element popped! " << endl;
    }
}

template <class t>
void ArrayStack<t>::push()
{
    if (T == n - 1)
    {
        StackFull s;
        throw s;
    }
    else
    {
        cout << "Please enter the element : " << endl;
        T = T + 1;
        cin >> arr[T];
    }
}

template <class t>
void ArrayStack<t>::top()
{
    if (empty())
    {
        StackEmpty s;
        throw s;
    }
    else
    {
        cout << arr[T] << " \n";
    }
}

template <class t>
void ArrayStack<t>::display()
{
    if (empty())
    {
        StackEmpty s;
        throw s;
    }
    else
    {
        cout << "Elements in the stack : " << endl;
        for (int i = 0; i <= T; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

template <class t>
int ArrayStack<t>::size()
{
    if (empty())
    {
        StackEmpty s;
        throw s;
    }
    else
        return T + 1;
}
int main()
{
    int choice;
    char repeat;
    cout << "Enter 1: For string operations. " << endl;
    cout << "Enter 2: For integer operations . " << endl;
    int type;
    cin >> type;
    if (type == 2)
    {
        ArrayStack<int> A;
        A.input();
        do
        {
            cout << "1.Push." << endl;
            cout << "2.Pop. " << endl;
            cout << "3.Display. " << endl;
            cout << "4.Get the top element . " << endl;
            cout << "5.Number of elements in the stack ." << endl;
            cout << "6.Check if Stack is empty. " << endl;
            cin >> choice;
            switch (choice)
            {

            case 1:
                try
                {
                    A.push();
                }
                catch (StackFull e)
                {
                    cout << e.what() << endl;
                }
                break;
            case 2:
                try
                {
                    A.pop();
                }
                catch (StackEmpty e)
                {
                    cout << e.what() << endl;
                }
                break;
            case 3:
                try
                {
                    A.display();
                }
                catch (StackEmpty e)
                {
                    cout << e.what();
                }
                break;
            case 4:
                try
                {
                    A.top();
                }
                catch (StackEmpty e)
                {
                    cout << e.what() << endl;
                }
                break;
            case 5:
                try
                {
                    cout << "Number of current elements : " << A.size() << " \n";
                }
                catch (StackEmpty s)
                {
                    cout << s.what();
                }
                break;
            case 6:
                cout << A.empty() << " \n";
                break;
            default:
                cout << "Invalid Choice . " << endl;
                break;
            }
            cout << "\nWant to repeat ? Y or N ? " << endl;
            cin >> repeat;
        } while (repeat == 'y' || repeat == 'Y');
    }
    else if (type == 1)
    {
        ArrayStack<string> A;
        A.input();
        do
        {
            cout << "Enter 1: Push an element ." << endl;
            cout << "Enter 2: Pop an element . " << endl;
            cout << "Enter 3: Display the elements . " << endl;
            cout << "Enter 4: Get the top element . " << endl;
            cout << "Enter 5: Number of elements in the stack ." << endl;
            cout << "Enter 6: Check if Stack is empty . " << endl;
            cin >> choice;
            switch (choice)
            {

            case 1:
                try
                {
                    A.push();
                }
                catch (StackFull e)
                {
                    cout << e.what() << endl;
                }
                break;
            case 2:
                try
                {
                    A.pop();
                }
                catch (StackEmpty e)
                {
                    cout << e.what() << endl;
                }
                break;
            case 3:
                try
                {
                    A.display();
                }
                catch (StackEmpty e)
                {
                    cout << e.what();
                }
                break;
            case 4:
                try
                {
                    A.top();
                }
                catch (StackEmpty e)
                {
                    cout << e.what() << endl;
                }
                break;
            case 5:
                try
                {
                    cout << "Number of current elements : " << A.size() << " \n";
                }
                catch (StackEmpty s)
                {
                    cout << s.what();
                }
                break;
            case 6:
                cout << A.empty() << " \n";
                break;

            default:
                cout << "Invalid Choice! " << endl;
                break;
            }
            cout << "\nWant to repeat ? Y or N ? " << endl;
            cin >> repeat;
        } while (repeat == 'y' || repeat == 'Y');
    }
    return 0;
}
