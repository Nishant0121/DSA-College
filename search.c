#include <stdio.h>

void linearSearch(int array[], int size, int target);
void binarySearch(int array[], int size, int target);
void interpolationSearch(int array[], int size, int target);
void sortArray(int array[], int size);

int main()
{
    int array[100];
    int size, target, choice;
    int flag = 1;

    while (flag == 1)
    {
        printf("\n1) Linear Search\n2) Binary Search\n3) Interpolation Search\n4) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4)
        {
            printf("Exiting...\n");
            break;
        }

        printf("Enter the Size of array: ");
        scanf("%d", &size);
        printf("Enter the Elements of array: ");
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &array[i]);
        }

        printf("Enter the Target Element: ");
        scanf("%d", &target);

        if (choice != 1)
        {
            sortArray(array, size);
            printf("Sorted Array: ");
            for (int i = 0; i < size; i++)
            {
                printf("%d ", array[i]);
            }
            printf("\n");
        }

        switch (choice)
        {
        case 1:
            linearSearch(array, size, target);
            break;
        case 2:
            binarySearch(array, size, target);
            break;
        case 3:
            interpolationSearch(array, size, target);
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }

    return 0;
}

void linearSearch(int array[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == target)
        {
            printf("Element %d found at index %d\n", target, i);
            return;
        }
    }
    printf("Element not found\n");
}

void binarySearch(int array[], int size, int target)
{
    int low = 0, high = size - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid] == target)
        {
            printf("Element %d found at index %d\n", target, mid);
            return;
        }
        else if (array[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    printf("Element not found\n");
}

void interpolationSearch(int array[], int size, int target)
{
    int low = 0, high = size - 1, pos;
    while (low <= high && target >= array[low] && target <= array[high])
    {
        if (low == high)
        {
            if (array[low] == target)
                printf("Element %d found at index %d\n", target, low);
            else
                printf("Element not found\n");
            return;
        }
        pos = low + ((target - array[low]) * (high - low)) / (array[high] - array[low]);
        if (array[pos] == target)
        {
            printf("Element %d found at index %d\n", target, pos);
            return;
        }
        else if (array[pos] < target)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }
    printf("Element not found\n");
}

void sortArray(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
