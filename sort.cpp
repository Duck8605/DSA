#include <iostream>
using namespace std;

//Insertion Sort
void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//Selection Sort
void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int MIN = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[MIN])
                MIN = j;
        }
        swap(arr[MIN],arr[i]);
    }
}

//Merge Sort
void Merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 +j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else 
            arr[k++] = R[j++];
    } 
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void MergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
    }
}

//Bubble Sort
void BubbleSort(int arr[], int n)
{
    for (int i= 0; i < n - 1; i++) {
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) 
                swap(arr[j], arr[j + 1]);
        }
    }
}

//Interchange Sort
void InterchangeSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[i])
                swap(arr[i], arr[j]);
}

//Heap Sort
void Heapify(int a[], int n, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < n && a[l] > a[i])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        Heapify(a, n, largest);
    }
}

void HeapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(a[i], a[0]);
        Heapify(a, i, 0);
    }
}

//Quick Sort
int Partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    i++;
    swap(arr[i], arr[r]);
    return i;
}

void QuickSort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int p = Partition(arr, l, r);
    QuickSort(arr, l, p - 1);
    QuickSort(arr, p + 1, r);
}