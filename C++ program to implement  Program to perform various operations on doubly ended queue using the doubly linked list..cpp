/*******************************************************************
 Demonstration Program to perform various operations on doubly ended
queue using the doubly linked list.
********************************************************************/

// List of include files
#include<iostream.h>
#include <conio.h>
// template class defination
template <class T>
class dll
{
private:
    struct node
    {
        T Data;
        struct	node  *next;
        struct	node  *prev;
    }*head;
public:
    dll()
    {
        head=NULL;
    }
    void create();
    void print();
    void insert_front();
    void insert_rear();
    void del_front();
    void del_rear();
};
/*
-----------------------------------------------------------------------
	The Create function
-----------------------------------------------------------------------
*/
template <class T>
void dll <T>:: create()
{
    // Local declarations here
    node  *n1,*last,*temp;
    char ans ='y';
    do
        {
            // allocate new node
            n1 = new node;
            cout<<"\nEnter the data :";
            cin>>n1->Data;
            n1 -> next = NULL;
            n1 -> prev = NULL;
            if (head==NULL) // Executed only for the first time
                {
                    head=n1;
                    last=n1;
                }
            else
                {
                    // last keeps track of the most recently
                    //	created node
                    last->next=n1;
                    n1->prev=last;
                    last=n1;
                }
            cout<<"\n\nEnter more?";
            ans = getche();
        }
    while(ans=='y'||ans=='Y');
    cout<<"\nThe List is created\n";
    getch();
}


/*
-----------------------------------------------------------------------
	The print function
	Output:None, Displays data
-----------------------------------------------------------------------
*/
template <class T>
void dll<T>::print()
{
    node *temp ;
    temp = head;
    if ( temp == NULL )
        {
            cout<<"\nThe list is empty\n";
            getch();
            return;
        }
    else
        {
            cout<<"\nThe list is:";
            while(temp != NULL)
                {
                    cout<<temp->Data<<"  ";
                    temp = temp -> next;
                }
        }
    getch();
}

/*--------------------------------------------------------------------
		Function to insert from rear end
-----------------------------------------------------------------------*/
template <class T>
void dll<T>::insert_rear()
{
    node *temp,*n1;
    int val,flag=0;
    cout<<"\nEnter the data of the new node to insert";
    cin>>val;
    temp=head;
    if(temp==NULL)
        flag=1;
    else
        {
            while(temp->next!=NULL)  // traverse till end
                temp=temp->next;
        }
// allocate new node
    n1 = new node;
    if ( n1 == NULL )
        cout<<"\nUnable to allocate memory\n";
    n1 -> Data  = val ;
    n1 -> next = NULL;
    n1 -> prev = NULL;
    if(flag==0)
        {
            temp->next=n1;  // attach at end
            n1->prev=temp;
        }
    else
        head=n1;       //if list empty make this node as head node
    cout<<"\nNode inserted";
}

/* -------------------------------------------------------------------
Function to insertion from front
----------------------------------------------------------------------*/
template <class T>
void dll<T>:: insert_front()
{
    node *temp,*n1;
    int data;
    cout<<"\nEnter the data of the new node to insert";
    cin>>data;
    /* allocate new node */
    n1 = new node;
    if ( n1 == NULL )
        cout<<"Unable to allocate memory\n";
    n1 -> Data  = data ;
    n1 -> next = NULL;
    n1 -> prev = NULL;
    if(head)
        {
            n1->next=head; //attach before head
            head->prev=n1;
        }
    head=n1; //make this node as head
    cout<<"\nNode inserted";
}

/*
-----------------------------------------------------------------------
	deletes an item from front of the list
-----------------------------------------------------------------------
*/
template <class T>
void dll<T>:: del_front()
{
    node *curr, *temp;
    curr=head;
    if(curr==NULL)
        cout<<"\nNode not found";
    else
        {
            if(head->next==NULL&&head->prev==NULL)//only one node in Q
                head=NULL;
            else
                {
                    head=curr->next;// first node
                    head->prev=NULL;
                }
        }
    cout<<"\n The item deleted";
    delete curr;
}
/*
-----------------------------------------------------------------------
	 deletes an item from rear of the list
-----------------------------------------------------------------------
*/
template <class T>
void dll<T>::del_rear()
{
    node *curr,*temp;
    curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    temp=curr->prev;
    temp->next=NULL;
    delete curr; //free memory
    cout<<"\nThe item is deleted\n";
}

/*
-----------------------------------------------------------------------
	The main function
	Input : None
	Output: None
	Parameter Passing Method : None
-----------------------------------------------------------------------
*/
void main()
{
    char ans = 'y';
    int ch;
    dll <int> d;
    dll <char> c;
    do
        {
            cout<<"\n"<<"MENU";
            cout<<"\n1.Create";
            cout<<"\n2.Display";
            cout<<"\n3.Insertion by front";
            cout<<" \n4.insertion by rear";
            cout<<"\n5.deletion by front";
            cout<<"\n6.deletion by rear";
            cout<<"\nEnter ur choice:";
            cin>>ch;
            switch(ch)
                {
                case 1:
                    d.create();
                    break;
                case 2:
                    d.print();
                    break;
                case 3:
                    d.print();
                    d.insert_front();
                    d.print();
                    break;
                case 4:
                    d.insert_rear();
                    d.print();
                    break;
                case 5:
                    d.print();
                    d.del_front();
                    d.print();
                    break;
                case 6:
                    d.print();
                    d.del_rear();
                    d.print();
                    break;
                default:
                    cout<<"\nInvalid choice";
                }
            cout<<"\n Do You Want To Continue?";
            ans=getch();
        }
    while(ans=='y'||ans=='Y');
    cout<<"\n\n\t Enter the characters in a Queue "<<endl;
    c.create();
    c.print();
    getch();
}
