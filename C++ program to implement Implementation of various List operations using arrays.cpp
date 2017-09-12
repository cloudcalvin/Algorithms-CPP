/******************************************************************
Implementation of various List operations using arrays
*******************************************************************/
#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
class ARR_LST
{
    /*data structure for list using array*/
private:
    struct node
    {
        int data;
        int next;
    } a[10];
public:
    int head;
    ARR_LST();
    int Create();
    void Display(int);
    void Insert();
    void Delete();
    void Search();
};
ARR_LST::ARR_LST()
{
    for(int i=0; i<10; i++)
        {
            a[i].data=-1;
        }
}

int ARR_LST::Create()
{
    int head,i;
    cout<<"\n Enter the index for first node ";
    cin>>i;
    head=i;
    while(i!=-1)
        {
            cout<<"\n Enter the data and index of the first element ";
            cin>>a[i].data;
            cout<<"  ";
            cin>>a[i].next;
            i=a[i].next;
        }
    return head;
}
void ARR_LST::Display(int i)
{
    while(i!=-1)
        {
            if(a[i].data==-1)
                cout<<"  ";
            else
                {
                    cout<<a[i].data<<"->";
                }
            i=a[i].next;
        }
    cout<<"NULL";
}
void ARR_LST::Insert()
{
    int i,new_data,temp;
    cout<<"\n Enter the new data which is to be inserted ";
    cin>>new_data;
    cout<<"\n Enter the data after which you want to insert ";
    cin>>temp;
    for(i=0; i<10; i++)
        {
            if(a[i].data==temp)
                break;
        }
    if(a[i+1].data==-1)/*next location is empty*/
        {
            a[i+1].next=a[i].next;
            a[i].next=i+1;
            a[i+1].data=new_data;
        }
}
void ARR_LST::Delete()
{
    int i,temp,current,new_next;
    cout<<"\n Enter The node to be deleted ";
    cin>>temp;
    for(i=0; i<10; i++)
        {
            if(a[i].data==temp)
                {
                    if(a[i].next==-1)
                        {
                            a[i].data=-1;/*writing -1 means deleting the element*/
                        }
                    current=i;/*marking the index of an array at which
						 record is placed*/
                    new_next=a[i].next;/*storing the next pointer value at
that index*/
                }
        }
    for(i=0; i<10; i++)
        {
            if(a[i].next==current)
                {
                    a[i].next=new_next;
                    a[current].data=-1;
                }
        }
}
void ARR_LST::Search()
{
    int i,temp,flag=0;
    cout<<"\n Enter the node to be searched ";
    cin>>temp;
    for(i=0; i<10; i++)
        {
            if(a[i].data==temp)
                {
                    flag=1;          /*flag 1 means the element is present*/
                    break;
                }
        }
    if(flag==1)
        cout<<"\n The "<<temp<<"  node is present in the list";
    else
        cout<<"\n The node is not present ";
}
void main()
{
    char ans;
    int choice;
    ARR_LST obj;
    do
        {
            //clrscr();
            cout<<"\t\t Program for implementing List using Array ";
            cout<<"\n  Main Menu";
            cout<<"\n1. Creation";
            cout<<"\n2. Display";
            cout<<"\n3. Insertion of element in the list";
            cout<<"\n4. Deletion of element from the list";
            cout<<"\n5. Searching of element from the list";
            cout<<"\n6. Exit";
            cout<<"\n Enter Your choice ";
            cin>>choice;
            switch(choice)
                {
                case 1:
                    obj.head=obj.Create();
                    break;
                case 2:
                    obj.Display(obj.head);
                    break;
                case 3:
                    obj.Insert();
                    break;
                case 4:
                    obj.Delete();
                    break;
                case 5:
                    obj.Search();
                    break;
                case 6:
                    exit(0);
                }
            cout<<"\n Do you Wish to go to Main Menu? ";
            ans=getch();
        }
    while(ans=='y'||ans=='Y');
    getch();
}

