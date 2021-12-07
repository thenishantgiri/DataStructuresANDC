#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node()
    {
        this->next = NULL;
    }
};

template <typename T>
class cList
{
private:
    Node<T> *head;

public:
    cList()
    {
        this->head = NULL;
    }

    void add(T item)
    {
        Node<T> *node = new Node<T>[1];
        node->data = item;
        if (head == NULL)
        {
            head = node;
            head->next = node;

            return;
        }
        Node<T> *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = node;
        node->next = head;
    }

    void addFront(T item)
    {
        Node<T> *node = new Node<T>[1];
        node->data = item;
        if (head == NULL)
        {
            head = node;
            node->next = head;

            return;
        }
        node->next = head;
        Node<T> *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = node;
        head = node;
    }

    void add(int index, T item)
    {
        if (index > length() || index < 0)
        {
            cout << "Index out of bound!" << endl;
            return;
        }
        Node<T> *node = new Node<T>[1];
        node->data = item;
        int count = 0;
        Node<T> *temp = head;
        while (count < index)
        {
            if (count == index - 1)
            {
                node->next = temp->next != head ? temp->next : head;
                temp->next = node;
                cout << "new node added at index " << index << " !" << endl;
                break;
            }
            count++;
            temp = temp->next;
        }
    }

    int length()
    {
        if (head == NULL)
            return 0;
        int len = 1;
        Node<int> *temp = head;
        while (temp->next != head)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    Node<T> *gethead()
    {
        return head;
    }
    void displayAll()
    {
        if (head == NULL)
        {
            cout << "Clinked list is empty" << endl;
            return;
        }
        cout << endl
             << "---------Circular linked list items---------" << endl;
        Node<T> *temp = head;
        while (true)
        {
            cout << temp->data << " | ";
            temp = temp->next;
            if (temp == head)
                break;
        }
        cout << endl
             << "---------------------------------------------" << endl;
    }

    void remove()
    {
        if (head == NULL)
        {
            cout << "Circular linked list is empty!" << endl;
            return;
        }

        if (length() == 1)
        {
            removeFront();
            return;
        }

        Node<T> *temp = head;
        while (temp->next != head)
        {
            if (temp->next->next == head)
            {
                temp->next = head;
                cout << "last item removed" << endl;
                break;
            }
            temp = temp->next;
        }
    }

    void remove(int index)
    {
        if (head == NULL)
        {
            cout << "Circular linked list is empty!" << endl;
            return;
        }
        if (index >= length() || index < 0)
        {
            cout << "Index out of bound!" << endl;
            return;
        }
        if (index == 0)
        {
            removeFront();
            return;
        }
        int count = 0;
        Node<T> *temp = head;
        while (temp->next != head)
        {
            if (count == index - 1)
            {
                temp->next = temp->next->next;
                cout << "Item removed at index " << index << endl;
                break;
            }
            count++;
            temp = temp->next;
        }
    }

    void removeFront()
    {
        if (head == NULL)
        {
            cout << "Circular linked list is empty!" << endl;
            return;
        }
        if (length() == 1)
        {
            head = NULL;
            cout << "First item removed!" << endl;
            return;
        }
        Node<T> *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
        cout << "Front item removed!" << endl;
    }

    T get(int index)
    {
        if (head == NULL)
        {
            cout << "Circular linked list is empty!" << endl;
            return -9999;
        }
        if (index >= length() || index < 0)
        {
            cout << "Index out of bound!" << endl;
            return -9999;
        }
        if (index == 0)
        {
            return head->data;
        }
        int count = 0;
        T res;
        Node<T> *temp = head;
        while (true)
        {
            if (count++ == index)
            {
                res = temp->data;
                break;
            }
            temp = temp->next;
            if (temp == head)
                break;
        }
        return res;
    }

    void concatenate(Node<T> *a, Node<T> *b)
    {
        Node<T> *ptr;
        if (a == NULL)
        {
            a = b;
            return;
        }
        if (b == NULL)
        {
            a = a;
            return;
        }
        ptr = a;

        while (a->next != b)
        {
            if (a->next != ptr)
            {

                cout << a->data << "->";
                a = a->next;
            }
            else
            {
                a->next = b;
                cout << a->data << "->";
                a = a->next;
            }
        }
        a->next = ptr;
        cout << a->data << "->" << endl;
    }
};

int main()
{
    cList<int> list, list2;
    int ch, item, index;
    int t, x;
    bool quit = false;
    cout << "Please enter the number of elements you would like to enter : ";
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Please enter element at position " << i + 1 << " : ";
        cin >> x;
        list.add(x);
    }
    do
    {
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
        cout << "select option :" << endl;
        cout << "1: insert back" << endl;
        cout << "2: insert front" << endl;
        cout << "3: insert at index" << endl;
        cout << "4: display items" << endl;
        cout << "5: get item at index" << endl;
        cout << "6: delete back" << endl;
        cout << "7: delete front" << endl;
        cout << "8: delete at index" << endl;
        cout << "9: concatenate two clist" << endl;
        cout << "10: exit" << endl;
        cin >> ch;
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
        switch (ch)
        {
        case 1:
            cout << "Please enter item to be inserted:" << endl;
            cin >> item;
            list.add(item);
            break;
        case 2:
            cout << "Please enter item to be inserted:" << endl;
            cin >> item;
            list.addFront(item);
            break;
        case 3:
            cout << "Please enter item to be inserted:" << endl;
            cin >> item;
            cout << "Please enter the index:" << endl;
            cin >> index;
            list.add(index, item);
            break;
        case 4:
            list.displayAll();
            break;

        case 5:
            cout << "Please enter index:" << endl;
            cin >> index;
            cout << "Item at index " << index << ": " << list.get(index) << endl;
            break;
        case 6:
            list.remove();
            break;
        case 7:
            list.removeFront();
            break;
        case 8:
            cout << "enter index:" << endl;
            cin >> index;
            list.remove(index);
            break;

        case 9:
            cout << "Please enter the number of elements you would like to enter in second Clinkedlist : ";
            cin >> t;
            for (int i = 0; i < t; i++)
            {
                cout << "Please enter element at position " << i + 1 << " : ";
                cin >> x;
                list2.add(x);
            }

            list.concatenate(list.gethead(), list2.gethead());
            break;

        case 10:
            quit = true;
            break;
        default:
            cout << "Invalid selection!" << endl;
            break;
        }
    } while (!quit);
    return 0;
}
