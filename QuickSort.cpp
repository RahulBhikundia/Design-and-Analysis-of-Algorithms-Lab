#include <iostream>
#include <chrono>
using namespace std;

void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int arr[], int low, int high)
{
    int pi = low;
    int l = low, r = high + 1;
    while (l < r)
    {
        do
        {
            l++;
        } while (arr[l] < arr[pi]);
        do
        {
            r--;
        } while (arr[r] > arr[pi]);
        if (l < r)
            swap(arr, l, r);
    }
    swap(arr, pi, r);
    return r;
}

void QuickSort(int arr[], int first, int last)
{
    if (first < last)
    {
        int pi = partition(arr, first, last);
        QuickSort(arr, first, pi - 1);
        QuickSort(arr, pi + 1, last);
    }
}

int main()
{
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 10;
    }

    cout << "The random Numbers before sorting are:";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto start_time = chrono::high_resolution_clock::now();
    QuickSort(arr, 0, 9);
    auto end_time = chrono::high_resolution_clock::now();

    cout << "The random Numbers after sorting are:";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
    cout << "Runtime: " << duration.count() << " nanoseconds" << endl;

    return 0;
}