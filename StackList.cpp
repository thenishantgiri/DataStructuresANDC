#include <iostream>
#include <exception>
using namespace std;

class StackEmpty : public exception
{
public:
    const char *what() const throw()
    {
        return "Exception Caught : Stack is Empty!\n";
    }
};

template <class t>
class Node
{
public:
    t elem;
    Node *next;
};

template <class t>
class Slist
{
public:
    Slist();
    bool empty();
    int size();
    void push();
    void pop();
    void top();
    void display();

private:
    Node<t> *head;
    int T;
};

template <class t>
Slist<t>::Slist()
{
    T = -1;
    head = NULL;
}

template <class t>
bool Slist<t>::empty()
{
    if (head == NULL)
    {
        return true;
    }
    else
        return false;
}

template <class t>
void Slist<t>::push()
{

    T = T + 1;
    Node<t> *n = new Node<t>;
    cout << "Please enter the element : " << endl;
    t ele;
    cin >> ele;
    n->elem = ele;
    n->next = head;
    head = n;
}

template <class t>
void Slist<t>::pop()
{
    if (empty())
    {
        StackEmpty s;
        throw s;
    }
    else
    {
        cout << "POPPED element is : " << head->elem << endl;
        Node<t> *n = new Node<t>;
        n = head;
        head = n->next;
        delete n;
        T--;
    }
}

template <class t>
int Slist<t>::size()
{
    if (empty())
    {
        StackEmpty s;
        throw s;
    }
    else
    {
        return T + 1;
    }
}

template <class t>
void Slist<t>::top()
{
    if (empty())
    {
        StackEmpty s;
        throw s;
    }
    else
    {
        cout << "Top element : " << head->elem << " \n";
    }
}

template <class t>
void Slist<t>::display()
{
    if (empty())
    {
        StackEmpty s;
        throw s;
    }
    else
    {
        Node<t> *n = new Node<t>;
        n = head;
        cout << "Elements in the stack : ";

        while (n->next != NULL)
        {
            cout << n->elem << " ";
            n = n->next;
        }
        cout << n->elem;

        cout << endl;
    }
}
int main()
{
    cout << "Enter 1: String Operations : " << endl;
    cout << "Enter 2: Integer Operations : " << endl;
    int type;
    cin >> type;
    int choice;
    char repeat;
    if (type == 2)
    {
        Slist<int> s;
        do
        {
            cout << "1: Push. " << endl;
            cout << "2: Pop. " << endl;
            cout << "3: Get the top element. " << endl;
            cout << "4: Number of elements in the stack. " << endl;
            cout << "5: Check if stack is empty. " << endl;
            cout << "6: Display the elements of the stack. " << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:

                s.push();

                break;
            case 2:
                try
                {
                    s.pop();
                }
                catch (StackEmpty s)
                {
                    cout << s.what();
                }
                break;
            case 3:
                try
                {
                    s.top();
                }
                catch (StackEmpty s)
                {
                    cout << s.what();
                }
                break;
            case 4:
                try
                {
                    cout << "Number of elements : " << s.size() << " \n";
                }
                catch (StackEmpty s)
                {
                    cout << s.what();
                }
                break;
            case 5:
                cout << s.empty() << " \n";
                break;
            case 6:
                try
                {
                    s.display();
                }
                catch (StackEmpty s)
                {
                    cout << s.what();
                }
                break;
            default:
                cout << "Invalid Choice! " << endl;
                break;
            }
            cout << "\nWant to repeat ? Y/ N ? " << endl;
            cin >> repeat;
        } while (repeat == 'y' || repeat == 'Y');
    }
    else if (type == 1)
    {
        Slist<string> s;
        do
        {
            cout << "1: Push. " << endl;
            cout << "2: Pop. " << endl;
            cout << "3: Get the top element. " << endl;
            cout << "4: Number of elements in the stack. " << endl;
            cout << "5: Check if stack is empty. " << endl;
            cout << "6: Display the elements of the stack. " << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:

                s.push();

                break;
            case 2:
                try
                {
                    s.pop();
                }
                catch (StackEmpty s)
                {
                    cout << s.what();
                }
                break;
            case 3:
                try
                {
                    s.top();
                }
                catch (StackEmpty s)
                {
                    cout << s.what();
                }
                break;
            case 4:
                try
                {
                    cout << "Number of elements : " << s.size() << " \n";
                }
                catch (StackEmpty s)
                {
                    cout << s.what();
                }
                break;
            case 5:
                cout << s.empty() << " \n";
                break;
            case 6:
                try
                {
                    s.display();
                }
                catch (StackEmpty s)
                {
                    cout << s.what();
                }
                break;
            default:
                cout << "Invalid Choice! " << endl;
                break;
            }
            cout << "\nWant to repeat ? Y/ N ? " << endl;
            cin >> repeat;
        } while (repeat == 'y' || repeat == 'Y');
    }
    else
        cout << "Invalid choice! " << endl;
    return 0;
}
