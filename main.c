#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Max_Size 100

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void printarray(int array[] ,int n)
{
    for(int i=0 ; i<n ; i++)
    {
        printf(" %d, ",array[i]);
    }
}
void close()
{
    int inMain ;
    printf("\n\nselect 1 to go main 0 to close terminal :");
    scanf("%d",&inMain);

    switch(inMain)
    {
        case 1:
            system("cls");
            main();
            break;

        case 0:
            system("cls");
            break;
        default:
            system("cls");
            printf("\n\n\n\t\tError! operator is not correct\n\n");
            close();
    }
}
void merge(int array[], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1; // Size of the left subarray
    int n2 = high - mid;     // Size of the right subarray

    // Create temporary arrays to hold the data
    int L[n1], R[n2];

    // Copy data from the original array to the temporary arrays
    for (i = 0; i < n1; i++) {
        L[i] = array[low + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = array[mid + 1 + j];
    }

    // Merge the two subarrays back into the original array
    i = 0; // Initial index of the left subarray
    j = 0; // Initial index of the right subarray
    k = low; // Initial index of the merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from L[] and R[] if there are any
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}
void mergeSortSub(int array[], int low , int high)
{
    if (low < high) {
        // Same as (l+r)/2, but avoids
        // overflow for large l and h
        int mid = low + (high - low) / 2;

        // Sort first and second halves
        mergeSortSub(array, low, mid);
        mergeSortSub(array, mid + 1, high);

        merge(array, low, mid, high);
    }
}
//partition
int partition(int array[], int low, int high)
{
    // Choosing the pivot
    int pivot = array[high];

    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than the pivot
        if (array[j] < pivot) {

            // Increment index of smaller element
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}
void quickSortSub(int array[], int low, int high)
{
    if (low < high) {

        // pi is partitioning index, arr[p]
        // is now at right place
        int pi = partition(array, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSortSub(array, low, pi - 1);
        quickSortSub(array, pi + 1, high);
    }
}
void Selection_Sort()
{
    printf("\n\t\tSelection Sort \n");
    int array[Max_Size];
    int n;
    printf("\n\tEnter the Size of your array:");
    scanf("%d",&n);

    printf("\nEnter Your unsorted Number :\n");
    for(int i=0 ; i<n ; i++)
    {
        scanf("\t\t%d",&array[i]);
    }
    printf("\n\tYour sorted Array :");
    int i , j , min_index;
    for( i = 0 ; i<n ; i++)
    {
        min_index=i;
        for(j=i+1 ; j<n ; j++)
        {
            if(array[j]<array[min_index])
            {
                min_index=j;
            }
        }
        if(min_index != i)
        {
            swap(&array[min_index], &array[i]);
        }
    }
    printarray(array,n);
    close();
}
void Bubble_Sort()
{
    printf("\n\t\tBubble Sort \n");
    int array[Max_Size];
    int n;
    printf("\n\tEnter the Size of your array:");
    scanf("%d",&n);

    printf("\nEnter Your unsorted Number :\n");
    for(int i=0 ; i<n ; i++)
    {
        scanf("\t\t%d",&array[i]);
    }
    printf("\n\tYour sorted Array :");

    int i , j ;
    bool is_Swaped;

    for( i = 0 ; i<n-1 ; i++)
    {
        is_Swaped=false;
        for(j=0 ; j<n-i-1 ; j++)
        {
            if(array[j]>array[j+1])
            {
                swap(&array[j], &array[j+1]);
                is_Swaped=true;
            }
        }
        if(is_Swaped==false)
        {
            break;
        }
    }
    printarray(array,n);
    close();
}

void Insertion_Sort()
{
    printf("\n\t\tInsertion Sort \n");
    int array[Max_Size];
    int n;
    printf("\n\tEnter the Size of your array:");
    scanf("%d",&n);

    printf("\nEnter Your unsorted Number :\n");
    for(int i=0 ; i<n ; i++)
    {
        scanf("\t\t%d",&array[i]);
    }
    printf("\n\tYour sorted Array :");

    int i , j ;
    int key;

    for( i = 1 ; i<n ; i++)
    {
        key = array[i];
        j= i-1;
        while(array[j]> key && j>=0)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
    printarray(array,n);
    close();
}
void mergeSort()
{
    printf("\n\t\tMerge Sort \n");
    int array[Max_Size];
    int n;
    printf("\n\tEnter the Size of your array:");
    scanf("%d",&n);

    printf("\nEnter Your unsorted Number :\n");
    for(int i=0 ; i<n ; i++)
    {
        scanf("\t\t%d",&array[i]);
    }
    int low = 0 ;
    int high = n;

    mergeSortSub(array, low , high);
    printf("\n\tYour sorted Array :");

    printarray(array,n);
    close();
}
void quickSort()
{
    printf("\n\t\tQuick Sort \n");
    int array[Max_Size];
    int n;
    printf("\n\tEnter the Size of your array:");
    scanf("%d",&n);

    printf("\nEnter Your unsorted Number :\n");
    for(int i=0 ; i<n ; i++)
    {
        scanf("\t\t%d",&array[i]);
    }
    int low = 0 ;
    int high = n;

    quickSortSub(array, low , high);
    printf("\n\tYour sorted Array :");

    printarray(array,n);
    close();
}


int main()
{
    int input ;
    printf("\n\n\t\t List Of Sorting Algorithom :");
    printf("\n\n \t 1. Selection Sort");
    printf("\n \t 2. Bubble Sort");
    printf("\n \t 3. Insertion Sort");
    printf("\n \t 4. Marge Sort");
    printf("\n \t 5. Quick Sort");
    printf("\n \t 6. Insertion Sort");
    printf("\n \t 7. Insertion Sort");
    printf("\n\n\t Enter a number to select any Sorting Algorithom :");
    scanf("%d",&input);
    switch(input)
    {
        case 1:
            system("cls");
            Selection_Sort();
            break;

        case 2:
            system("cls");
            Bubble_Sort();
            break;

        case 3:
            system("cls");
            Insertion_Sort("3");
            break;

        case 4:
            system("cls");
            mergeSort();
            break;
        case 5:
            system("cls");
            quickSort();
            break;
        case 6:
            system("cls");
            printf("6");
            break;
        case 7:
            system("cls");
            printf("7");
            break;
        default:
            system("cls");
            printf("\n\n\n\t\tError! operator is not correct\n\n");
            close();
    }
    return 0;
}
