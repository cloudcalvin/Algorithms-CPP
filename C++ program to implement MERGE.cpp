
/************************************************************
This program is for performing Merge Sort.
*************************************************************/
# include<conio.h>
# include<stdio.h>
# include<stdlib.h>
int n;
void main()
{
    int i,low,high;
    int A[10];
    void MergeSort(int A[10],int low,int high);
    void Display(int A[10]);
    clrscr();
    printf("\n\t\t Merge Sort \n");
    printf("\n Enter the length of list :");
    scanf("%d",&n);
    printf("\n Enter list elements :");
    for(i=0; i<n; i++)
        scanf("%d",&A[i]);
    low=0;
    high=n-1;
    MergeSort(A,low,high);
    Display(A);
    getch();
}
/*
 This function is to split the list into sublists
*/
void MergeSort(int A[10],int low,int high)
{
    int mid;
    void Combine(int A[10],int low,int mid,int high);
    if(low < high)
        {
            mid = (low+high)/2;//split the list at mid
            MergeSort(A,low,mid);//first sublist
            MergeSort(A,mid+1,high);//second sublist
            Combine(A,low,mid,high);//merging of two sublists
        }
}
/* This function is for merging the two sublists
*/
void Combine(int A[10],int low,int mid,int high)
{
    int i,j,k;
    int temp[10];
    k=low;
    i=low;
    j=mid+1;
    while(i <= mid && j <= high)
        {
            if(A[i]<=A[j])
                {
                    temp[k]=A[i];
                    i++;
                    k++;
                }
            else
                {
                    temp[k]=A[j];
                    j++;
                    k++;
                }
        }
    while(i<=mid)
        {
            temp[k]=A[i];
            i++;
            k++;
        }
    while(j<=high)
        {
            temp[k]=A[j];
            j++;
            k++;
        }
    //copy the elements from temp array to A
    for(k=low; k<=high; k++)
        A[k]=temp[k];
}
/* function to display sorted array */
void Display(int A[10])
{
    int i;
    printf("\n\n The Sorted Array Is ...\n");
    for(i=0; i<n; i++)
        printf("%d\t",A[i]);
}

