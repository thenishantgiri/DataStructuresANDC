#include <iostream>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

/* Function to Display an array */
void Display(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int m;
    cout << "Please enter the number of elements : ";
    cin >> m;
    int array[m];
    for (int i = 0; i < m; i++)
    {
        cout << "Please enter element " << i + 1 << " : ";
        cin >> array[i];
    }
    int n = sizeof(array) / sizeof(array[0]);
    bubbleSort(array, n);
    cout << "Sorted array: \n";
    Display(array, n);
    return 0;
}
