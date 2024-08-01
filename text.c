#include <stdio.h>

void print(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int division(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (i <= high && a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quick(int a[], int low, int high)
{
    int divide;
    if (low < high)
    {
        divide = division(a, low, high);
        quick(a, low, divide - 1);
        quick(a, divide + 1, high);
    }
}

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = a[low + i];
    for (j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void bubbleSort(int a[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void main()
{
    int a[100];
    int size;
    int choice;
    int count = 0;
    while (count == 0)
    {
        printf("1) Merge Sort\n2) Quick Sort\n3) Bubble Sort\n4)Exit\n");
        scanf("%d", &choice);

        if (choice == 4)
        {
            count++;
            break;
        }

        printf("Enter The Number Of Array elements: ");
        scanf("%d", &size);
        printf("Enter the array Elements:\n");
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &a[i]);
        }

        switch (choice)
        {
        case 1:
            mergeSort(a, 0, size - 1);
            break;
        case 2:
            quick(a, 0, size - 1);
            break;
        case 3:
            bubbleSort(a, size);
            break;
        default:
            printf("Invalid choice\n");
            return;
        }

        printf("Sorted array:\n");
        print(a, size);
    }
}
