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

int main()
{
    int input ;
    printf("\n\n\t\t List Of Sorting Algorithom :");
    printf("\n\n \t 1. Selection Sort");
    printf("\n \t 2. Bubble Sort");
    printf("\n \t 3. Insertion Sort");
    printf("\n \t 4. Insertion Sort");
    printf("\n \t 5. Insertion Sort");
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
            printf("4");
            break;
        case 5:
            system("cls");
            printf("5");
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
