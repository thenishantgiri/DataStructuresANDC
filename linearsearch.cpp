#include <iostream>
using namespace std;

class linear
{
public:
    int n, a;
    void linearsearch(int x[], int n, int a);
};

void linear ::linearsearch(int x[], int n, int a)
{
    int i, j, flag = 0;

    for (i = 0; i < n; i++)
    {
        if (x[i] == a)
        {
            flag = 1;
            j = i + 1;
            break;
        }
    }
    s if (flag == 1)
    {
        cout << "\n the element is found at" << j << "th indexs";
    }
    else
    {
        cout << "\n Element not found!";
    }
}

int main()
{
    linear l;
    int n, b;
    cout << "\n Please enter the size: ";
    cin >> n;
    int x[n];
    cout << "\n Please enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> x[i];
    cout << "\n Please enter the element to be searched: ";
    cin >> b;
    l.linearsearch(x, n, b);
    return (0);
}
