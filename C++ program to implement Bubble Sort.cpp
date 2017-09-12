#include<iostream.h>
#include<conio.h>
class Sort
{
private:
    int n;
    int A[10];
public:
    void get_data();
    void bubble();
};
void Sort::get_data()
{
    cout<<"\n How many elements are there?";
    cin>>n;
    cout<<"\n Enter the elements\n";
    for(int i=0; i<n; i++)
        cin>>A[i];
}
void Sort::bubble()
{
    int  temp;
    for(int i=0; i<=n-2; i++)
        {
            for(int j=0; j<=n-2-i; j++)
                {
                    if(A[j]>A[j+1])
                        {
                            temp=A[j];
                            A[j]=A[j+1];
                            A[j+1]=temp;
                        }
                }
        }
    cout<<"\n The sorted List is ...\n";
    for(i=0; i<n; i++)
        cout<<"         "<<A[i];
}

void main()
{
    Sort obj;
    clrscr( );
    cout<<"\n\t\t Bubble Sort\n";
    obj.get_data();
    obj.bubble();
    getch( );
}
