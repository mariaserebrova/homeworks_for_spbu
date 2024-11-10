
#include <iostream>

using namespace std;



void heapify(int arr[], int n, int root)
{
    int biggest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;


    if (left < n && arr[left] > arr[biggest])
        biggest = left;


    if (right < n && arr[right] > arr[biggest])
        biggest = right;


    if (biggest != root)
    {
        swap(arr[root], arr[biggest]);

        heapify(arr, n, biggest);
    }
}


void heapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);


    for (int i = n - 1; i >= 0; i--)
    {

        swap(arr[0], arr[i]);


        heapify(arr, i, 0);
    }
}


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}


int main()
{
    int arr[] = { 3, 6, 9, 12333, 67 };
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "sorted array is \n";
    printArray(arr, n);
};
