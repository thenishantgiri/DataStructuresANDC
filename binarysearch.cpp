#include <iostream>
using namespace std;

class Bsearch
{

public:
    int search(int A[], int size, int to_be_searched);
};

int Bsearch::search(int A[], int size, int to_be_searched)
{

    int flag = 0;
    int low = 0, high = size - 1, mid;

    while (low < high)
    {
        mid = (low + high) / 2;

        if (A[mid] == to_be_searched)
            return mid;

        if (A[low] <= A[mid])
            high = mid;

        if (A[high] >= mid)
            low = mid;
    }

    return -1;
}

int main()
{

    int size;
    cout << "Please enter the size of Array \n";
    cin >> size;

    int A[size];
    cout << "Please enter the Array elements: \n";
    for (int i = 0; i < size; ++i)
        cin >> A[i];

    int to_be_searched;
    cout << "Please enter the element to be searched \n";
    cin >> to_be_searched;

    Bsearch obj;
    int result = obj.search(A, size, to_be_searched);

    if (result == -1)
    {
        cout << "Element not found!";
    }
    else
    {
        cout << "Element found at " << result;
    }

    return 0;
}
