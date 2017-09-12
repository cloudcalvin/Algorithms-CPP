/***************************************************************
Program to sort the elements in ascending order using Quick Sort.
***************************************************************/
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>

#define SIZE 10
void Quick(int A[SIZE],int,int);
int Partition(int A[SIZE],int,int);
void swap(int A[SIZE],int *,int *);
int n;
int main()
{
    int i;
    int A[SIZE];
    printf("\n\t\t Quick Sort Method \n");
    printf("\n Generating the list using the random numbers");
    srand(10000);
    n=10;
    for (i = 0; i < n; i++)
        {
            int val = n * ((float)rand() / ((float)RAND_MAX +(float) 1));
            A[i] = val;
        }
    printf("\n The Original List is\n");
    for (i = 0; i < n; i++)
        printf(" %d",A[i]);
    Quick(A,0,n-1);
    printf("\n\n\t Sorted Array Is: \n");
    for(i=0; i<n; i++)
        printf(" %d",A[i]);
    return 0;
}

/*
This function is to sort the elements in a sublist
*/
void Quick(int A[SIZE],int low,int high)
{
    int m,i;
    if(low<high)
        {
            m=Partition(A,low,high);//setting pivot element
            Quick(A,low,m-1);//splitting of list
            Quick(A,m+1,high);//splitting  of list
        }
}
/*
This function is to partition a list and decide the pivot element
*/
int Partition(int A[SIZE],int low,int high)
{
    int pivot=A[low],i=low,j=high;
    while(i<=j)
        {
            while(A[i]<=pivot)
                i++;
            while(A[j]>pivot)
                j--;
            if(i<j)
                swap(A,&i,&j);
        }
    swap(A,&low,&j);
    return j;
}

void swap(int A[SIZE],int *i,int *j)
{
    int temp;
    temp=A[*i];
    A[*i]=A[*j];
    A[*j]=temp;
}
