#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << " ]" << endl;
}

void seletionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i; j < size; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int didswap = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                didswap = true;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (!didswap)
        {
            cout << "Array is already sorted" << endl;
            break;
        }
    }
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (arr[j - 1] > arr[j] && j > 0)
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

void merge(int arr[], int start, int mid, int end)
{
    int lptr = start;
    int rptr = mid + 1;
    int temp[end - start + 1];
    int temp_ptr = 0;
    while (lptr <= mid && rptr <= end)
    {
        if (arr[lptr] < arr[rptr])
        {
            temp[temp_ptr] = arr[lptr];
            lptr++;
            temp_ptr++;
        }
        else
        {
            temp[temp_ptr] = arr[rptr];
            rptr++;
            temp_ptr++;
        }
    }

    while (lptr <= mid)
    {
        temp[temp_ptr] = arr[lptr];
        lptr++;
        temp_ptr++;
    }

    while (rptr <= end)
    {
        temp[temp_ptr] = arr[rptr];
        rptr++;
        temp_ptr++;
    }

    for(int i=0;i<end-start+1;i++){
        arr[start+i]=temp[i];
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2; // 1
    mergeSort(arr, start, mid); //[1,2]
    mergeSort(arr, mid + 1, end);//[3]
    merge(arr, start, mid, end);
}

int partition(int arr[],int start,int end){
    int pivot=arr[start];
    int i =start+1;
    int j=end;
    while(i<=j){
        while(i<=end&&arr[i]<=pivot){
            i++;
        }
        while(j>=start&&arr[j]>pivot){
            j--;
        }
        if(i<=j){
            int temp =arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp =arr[start];
    arr[start]=arr[j];
    arr[j]=temp;

    return j;
}

void quickSort(int arr[],int start , int end){
    if(start>=end){
        return;
    }
    int pivot=partition(arr,start,end);
    quickSort(arr,start,pivot);
    quickSort(arr,pivot+1,end);
}

int main()
{
    int size;
    cout << "Enter the size of array : ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Array element: ";
        cin >> arr[i];
    }

    cout << "Before Sorting " << endl;
    printArray(arr, size);
    cout << "After Sorting " << endl;
    quickSort(arr, 0,size-1);
    printArray(arr, size);
}