/*****************************************************************************
Program to find the kth smallest element
*****************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 9
int partition(int A[],int low,int high);

void main( )
{
    int A[]= {10,55,9,4,234,30,40,22,34};
    int select(int A[],int low,int high,int i);
    int low,m,high;
    clrscr( );
    int i=7;
    low=0;
    high=8;
    printf(" The element is %d ",select(A,low,high,i));
    getch( );
}
int select(int A[size],int low,int high,int i)
{
    int m,key;
    if(low==high)
        return A[low];
    m=partition(A,low,high);
    key=m-low+1;
    if(i==key)
        return A[m];
    else if(i<key)
        return select(A,low,m-1,i);
    else return select(A,m+1,high,i-key);
}
int partition(int A[size],int low,int high)
{
    int x,i,j,temp;
    x=A[high];
    i=low-1;
    for(j=low; j<=high-1; j++) //selecting the random number
        {
            //from low to high
            if(A[j]<=x)
                {
                    i=i+1;
                    temp=A[i];
                    A[i]=A[j];
                    A[j]=temp;
                }
        }
    temp=A[i+1];
    A[i+1]=A[high];
    A[high]=temp;
    return i+1;
}
