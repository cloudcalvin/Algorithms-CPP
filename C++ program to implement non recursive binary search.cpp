/****************************************************************
Implementation of non recursive Binary Search algorithm
****************************************************************/
#include<stdio.h>
#include<conio.h>
#define SIZE 10
int n;
void main()
{
    int A[SIZE],KEY,i,flag;
    int BinSearch(int A[SIZE],int KEY);
    clrscr();
    printf("\n How Many elements in an array?");
    scanf("%d",&n);
    printf("\n Enter The Elements");
    for(i=0; i<n; i++)
        scanf("%d",&A[i]);
    printf("\n Enter the element which is to be searched");
    scanf("%d",&KEY);
    flag=BinSearch(A,KEY);
    if(flag==-1)
        printf("\n The Element is not present");
    else
        printf("\n The element is at A[%d] location",flag);
    getch();
}
int BinSearch(int A[SIZE],int KEY)
{
    int low,high,m;
    low=0;
    high=n-1;
    while(low<=high)
        {
            m=(low+high)/2;	//mid of the array is obtained
            if(KEY==A[m])
                return m;
            else if(KEY<A[m])
                high=m-1;		//search the left sub list
            else
                low=m+1;		//search the right sub list
        }
    return -1; //if element is not present in the list
}


