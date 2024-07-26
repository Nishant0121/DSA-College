#include <stdio.h> // Include the standard input/output library for using printf

// Function to print an array
void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {                        // Loop through each element of the array
        printf("%d ", a[i]); // Print the current element
    }
}

// Function to partition the array for quicksort
int partition(int a[], int low, int high)
{
    int pivot = a[low]; // Choose the first element as the pivot
    int i = low + 1;    // Initialize i to the element right after pivot
    int j = high;       // Initialize j to the last element
    int temp;           // Temporary variable for swapping

    do
    {
        while (a[i] <= pivot)
        { // Increment i until an element larger than pivot is found
            i++;
        }
        while (a[j] > pivot)
        { // Decrement j until an element smaller than or equal to pivot is found
            j--;
        }
        if (i < j)
        { // If i is still less than j, swap the elements at i and j
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j); // Repeat the process until i is not less than j

    // Swap the pivot element with the element at j
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    // Return the partition index
    return j;
}

// Function to implement quicksort
void quickSort(int a[], int low, int high)
{
    int partitionIndex;
    if (low < high)
    {                                             // Check if there are at least two elements to sort
        partitionIndex = partition(a, low, high); // Partition the array and get the partition index
        quickSort(a, low, partitionIndex - 1);    // Recursively sort the left subarray
        quickSort(a, partitionIndex + 1, high);   // Recursively sort the right subarray
    }
}

// Main function
void main()
{
    int a[] = {5, 2, 9, 4, 8, 56}; // Initialize the array to be sorted
    int size = 6;                  // Size of the array
    printArray(a, size);           // Print the array before sorting
    quickSort(a, 0, size - 1);     // Call quickSort to sort the array
    printf("\n");                  // Print a new line
    printArray(a, size);           // Print the sorted array
}
