#include <iostream>
#include <vector>
using namespace std;

// insertion sort template function
// to sort array in ascending order
// n is the size of array
template <class T>
void InsertionSort(T arr[], int n)
{
    int i, j;
    T temp;

    for (int i = 1; i < n; ++i)
    {

        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = temp;
    }
}

// template function to print array
// n: size of array
template <class T>
void PrintArray(T arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 2, 6, 3, 4, 55, 22, 1, 44};
    int n = sizeof(arr) / sizeof(int);

    cout << "Integer Array Before Sort: ";
    PrintArray(arr, n);

    InsertionSort(arr, n);

    cout << "Integer Array After Sort: ";
    PrintArray(arr, n);
}
