#include <stdio.h>

void main()
{
    int A[100], n, k, i, mid, low, high;

    printf("Enter the 1.Binary search 2.linear search 3.interpolation: ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("The binary search:\n ");
        int A[100], n, k, i, mid, low, high;
        printf("Enter the length of array \n ");
        scanf("%d", &n);
        printf("enter the number to found ");
        scanf("%d", &k);
        printf("Enter the array:\n ");
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &A[i]);
        }
        low = 0;
        high = n - 1;
        mid = (high + low) / 2;
        while (high >= low)
        {
            if (A[mid] == k)
            {
                printf("%d is found at %d", k, mid);
                break;
            }
            if (k < A[mid])
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
            mid = (high + low) / 2;
        }
        if (high < low)
            printf("%d is not found", k);
        break;
    case 2:
        printf("The linear search:\n ");
        printf("enter the length of array:\n ");
        scanf("%d", &n);
        printf("enter the number to found");
        scanf("%d", &k);
        printf("enter the element of array:\n ");
        int ans;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (A[i] == k)
            {
                ans = i;
                break;
            }
        }
        if (ans == -1)
        {
            printf("Element not found");
        }
        else
        {
            printf("Element found at %d", ans);
        }
        break;
    case 3:
        printf("Interpolation search:\n");
        printf("Enter the length of the array: ");
        scanf("%d", &n);
        printf("Enter the number to find: ");
        scanf("%d", &k);
        printf("Enter the array elements:\n");
        for (i = 0; i < n; ++i)
        {
            scanf("%d", &A[i]);
        }
        low = 0;
        high = n - 1;
        while (low <= high && k >= A[low] && k <= A[high])
        {
            int pos = low + (((double)(high - low) / (A[high] - A[low])) * (k - A[low]));
            if (A[pos] == k)
            {
                ans = pos;
                break;
            }
            if (A[pos] < k)
            {
                low = pos + 1;
            }
            else
            {
                high = pos - 1;
            }
        }
        if (ans != -1)
        {
            printf("Element found at position %d\n", ans);
        }
        else
        {
            printf("Element not found\n");
        }
        break;
    case 4:
        printf("exit");
        break;
    default:
        printf("Invalid choice");
        break;
    }
}