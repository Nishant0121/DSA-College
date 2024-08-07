#include <stdio.h>

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void merge(int arr[], int si, int mid, int ei)
{
    int temp[ei - si + 1];
    int i = si;      // idx for first sorted part
    int j = mid + 1; // idx for second sorted part
    int k = 0;       // idx for temp

    while (i <= mid && j <= ei)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    // for leftover elements of first part
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    // for leftover elements of second part
    while (j <= ei)
    {
        temp[k++] = arr[j++];
    }

    for (k = 0, i = si; k < ei - si + 1; k++, i++)
    {
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int mid = si + (ei - si) / 2; // or = (si+ei)/2
    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);

    merge(arr, si, mid, ei);
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i + 1] and arr[high] (or pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n, choice;

    do
    {
        printf("Select sorting algorithm:\n");
        printf("1. Bubble Sort\n");
        printf("2. Merge Sort\n");
        printf("3. Quick Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4)
        {
            printf("Exiting...\n");
            break;
        }
        printf("Enter the size of the array: ");
        scanf("%d", &n);

        int arr[n];
        printf("Enter the elements of the array: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        switch (choice)
        {
        case 1:
            bubbleSort(arr, n);
            break;
        case 2:
            mergeSort(arr, 0, n - 1);
            break;
        case 3:
            quickSort(arr, 0, n - 1);
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
            continue;
        }

        printf("Sorted array: ");
        printArr(arr, n);

    } while (choice != 4);

    return 0;
}