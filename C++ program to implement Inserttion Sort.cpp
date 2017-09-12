
/**********************************************************
Implementation of insertion sort
**********************************************************/
#include<iostream.h>
#include<conio.h>
class Sort
{
private:
    int A[10];
    int n;
public:
    void get_data();
    void Insert_sort();
    void display();
};
void Sort::Insert_sort()
{
    int i,j,temp;
    for(i=1; i<=n-1; i++)
        {
            temp=A[i];
            j=i-1;
            while( (j>=0)&&(A[j]>temp))
                {
                    A[j+1]=A[j];
                    j=j-1;
                }
            A[j+1]=temp;
        }
}
void Sort::get_data()
{
    cout<<"\n How many elements are there?";
    cin>>n;
    cout<<"\n Enter the elements\n";
    for(int i=0; i<n; i++)
        cin>>A[i];
}
void Sort::display()
{
    cout<<"\n The sorted list of elements is...\n";
    for(int i=0; i<n; i++)
        cout<<"\n    "<<A[i];
}
void main( )
{
    Sort obj;
    clrscr( );
    cout<<"\n\t\t Insertion Sort";
    obj.get_data();
    obj.Insert_sort();
    obj.display();
    getch();
}
