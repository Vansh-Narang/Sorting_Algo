#include <bits./stdc++.h>
using namespace std;
void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}
int parition(int *arr, int s, int e)
{
    int cnt = 0;
    int pivot = arr[s];
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }
    int pivotIndex = s + cnt;
    swap(arr[s], arr[pivotIndex]);
    int i = s;
    int j = e;
    while (i < pivotIndex && j > pivotIndex) // comparing index with pivotindex only
    {
        while (arr[i] < pivot) // comparing values at indexes//value choti hai to move on
        {
            i++;
        }
        while (arr[j] > pivot) // value badi hai to move on
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) // check i not greater than j
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quicksort(int arr[], int s, int e)
{
    if (s <= e) // two elements hai agar
    {
        int p = parition(arr, s, e);
        quicksort(arr, s, p - 1);
        quicksort(arr, p + 1, e);
    }
}
void merge(int *a, int l, int mid, int r)
{
    int b[10000];
    int i = l;
    int j = mid + 1;
    int k = l;
    while (i <= mid && j <= r)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    if (i > mid)
    {
        while (j <= r)
        {
            b[k++] = a[j++];
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k++] = a[i++];
        }
    }
    for (int k = l; k <= r; k++)
    {
        a[k] = b[k];
    }
}
void mergesort(int *a, int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}
void InsertSort(int *arr, int n)
{
    int min, j;
    for (int i = 1; i < n; i++)
    {
        min = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > min)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = min;
    }
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}
void countSort(int *arr, int n)
{
    // first find the max in array
    int k = arr[0];
    for (int i = 0; i < n; i++)
    {
        k = max(k, arr[i]);
    }
    // create an array of size of maximum element
    int count[10000] = {0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }
    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    clock_t time_req;
    time_req = clock();
    int n;
    cout << "enter the size" << endl;
    cin >> n;
    int arr[10000];
    for (int i = 0; i < n; i++)
    {
        int no = rand() % 1000 + 1;
        arr[i] = no;
    }
    countSort(arr, n);
    print(arr, n);
    time_req = clock() - time_req;
    cout << "Processor time taken for multiplication: "
         << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;
}
