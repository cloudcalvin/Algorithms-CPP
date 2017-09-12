/****************************************************************
Implementation of recursive Binary Search algorithm
****************************************************************/
#include<stdio.h>
#include<conio.h>
#define SIZE 10
int n;
void main()
{
    int A[SIZE],KEY,i,flag,low,high;
    int BinSearch(int A[SIZE],int KEY,int low,int high);
    clrscr();
    printf("\n How Many elements in an array?");
    scanf("%d",&n);
    printf("\n Enter The Elements");
    for(i=0; i<n; i++)
        scanf("%d",&A[i]);
    printf("\n Enter the element which is to be searched");
    scanf("%d",&KEY);
    low=0;
    high=n-1;
    flag=BinSearch(A,KEY,low,high);
    printf("\n The element is at A[%d] location",flag);
    getch();
}
int BinSearch(int A[SIZE],int KEY,int low,int high)
{
    int m;
    m=(low+high)/2;	//mid of the array is obtained
    if(KEY==A[m])
        return m;
    else if(KEY<A[m])
        BinSearch(A,KEY,low,m-1);//search the left sub list
    else
        BinSearch(A,KEY,m+1,high);//search the right sub list
}


