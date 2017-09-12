/******************************************************************
    Program for implementing the sequential search
*******************************************************************/
#include<iostream.h>
#include<conio.h>
class Search
{
private:
    int a[10],n,key;
public:
    void get_data();
    void Seq_Search(int);
};
void Search::Seq_Search(int key)
{
    int flag=0,mark;
    for(int i=0; i<n; i++)
        {
            //searching element from beginning of array
            if(a[i]==key)
                {
                    flag=1;//setting the flag if element found
                    mark=i;//marking the location of key element
                    break;
                }
        }
    if(flag==1)//flag=1 means element is found
        cout<<"\n The element is present at location: "<<mark+1;
    else
        cout<<"\n The element is not present in the array";
}
void Search::get_data()
{
    cout<<"\n How Many Elements are there in an array? ";
    cin>>n;
    cout<<"\n Enter the elements ";
    for(int i=0; i<n; i++)
        cin>>a[i];
}

void main( )
{
    int k;
    Search obj;
    clrscr();
    obj.get_data();
    cout<<"\n\t Enter the element which is to be searched ";
    cin>>k;
    obj.Seq_Search(k);
    getch( );
}

