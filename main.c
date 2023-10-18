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
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = array[low + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = array[mid + 1 + j];
    }


    i = 0;
    j = 0;
    k = low;

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

        int mid = low + (high - low) / 2;

        mergeSortSub(array, low, mid);
        mergeSortSub(array, mid + 1, high);

        merge(array, low, mid, high);
    }
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {

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
        int pi = partition(array, low, high);

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
int getMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}
void countingSort(int array[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(array[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        array[i] = output[i];
    }
}
void radixSort()
{
    printf("\n\t\tRadix Sort \n");
    int array[Max_Size];
    int n;
    printf("\n\tEnter the Size of your array:");
    scanf("%d",&n);

    printf("\nEnter Your unsorted Number :\n");
    for(int i=0 ; i<n ; i++)
    {
        scanf("\t\t%d",&array[i]);
    }
	int m = getMax(array, n);

	for (int exp = 1; m/exp > 0; exp *= 10){
        countingSort(array, n, exp);
	}

    printf("\n\tYour sorted Array :");
    printarray(array,n);
    close();

}
void heapify(int array[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
      {
          largest = left;
      }

    if (right < n && array[right] > array[largest])
      {
          largest = right;
      }

    if (largest != i) {
      swap(&array[i], &array[largest]);
      heapify(array, n, largest);
    }
  }
void heapSort()
{
    printf("\n\t\tHeap Sort \n");
    int array[Max_Size];
    int n;
    printf("\n\tEnter the Size of your array:");
    scanf("%d",&n);

    printf("\nEnter Your unsorted Number :\n");
    for(int i=0 ; i<n ; i++)
    {
        scanf("\t\t%d",&array[i]);
    }


	for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(array, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
      swap(&array[0], &array[i]);
      heapify(array, i, 0);
    }

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
    printf("\n \t 6. Radix Sort");
    printf("\n \t 7. Heap Sort");
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
            radixSort();
            break;
        case 7:
            system("cls");
            heapSort();
            break;
        default:
            system("cls");
            printf("\n\n\n\t\tError! operator is not correct\n\n");
            close();
    }
    return 0;
}
