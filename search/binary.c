#include <stdio.h>

int linear(int a[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == target)
        {
            return i;
            break;
        }
    }
}
int binary(int a[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    int mid;

    while (low < high)
    {
        mid = (low + high) / 2;
        if (a[low] == target)
        {
            return low;
        }
        if (a[high] == target)
        {
            return high;
        }
        if (a[mid] == target)
        {
            return mid;
        }
        else if (a[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
}

void sort(int a[], int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void main()
{
    int a[] = {3, 6, 2, 8, 4, 7};
    int size = 6;
    int target = 4;
    sort(a, size);
    int index = binary(a, size, target);
    printf("Element Found At %d", index);
}