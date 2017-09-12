/*******************************************************************
 Demonstration Program to perform various operations on
 singly link lists.
********************************************************************/

// List of include files

#include<iostream.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0
// class defination


class sll
{
private:
    struct node
    {
        int data;
        struct	node  *next;
    }*head;
public:
    sll();
    void create();
    void display();
    void search(int key);
    void insert_head();
    void insert_after();
    void insert_last();
    void dele();
    ~sll();
};

/*
--------------------------------------------------------------------------
The  Constructor defined
--------------------------------------------------------------------------
*/
sll::sll()
{
    head=NULL;//initialize head to NULL
}
/*
--------------------------------------------------------------------------
	The Destructor defined
--------------------------------------------------------------------------
*/
sll::~sll()
{
    node *temp,*temp1;
    temp=head->next;
    delete head;
    while(temp!=NULL) //free the memory allocated
        {
            temp1=temp->next;
            delete temp;
            temp=temp1;
        }
}
/*
-------------------------------------------------------------------------
	The Create function
-------------------------------------------------------------------------
*/
void sll :: create()
{
    node *temp, *New;
    int val,flag;
    char ans ='y';
    flag=TRUE;
    do
        {
            cout<<"\nEnter the data :";
            cin>>val;
            // allocate memory to new node
            New = new node;
            if ( New == NULL )
                cout<<"Unable to allocate memory\n";
            New-> data  = val ;
            New-> next = NULL;
            if( flag==TRUE ) // Executed only for the first time
                {
                    head=New;
                    temp = head;
                    flag=FALSE;
                }
            else
                {
                    /*temp last keeps track of the most recently
                      created node*/
                    temp->next = New;
                    temp = New;
                }
            cout<<"\n Do you want to enter more elements?(y/n)";
            ans = getche();
        }
    while(ans=='y'||ans=='Y');
    cout<<"\nThe Singly Linked List is created\n";
    getch();
    clrscr();
}

/*
-------------------------------------------------------------------------
	The display function
------------------------------------------------------------------------
*/
void sll ::display()
{
    node *temp ;
    temp = head;
    if ( temp == NULL )
        {
            cout<<"\nThe list is empty\n";
            getch();
            clrscr();
            return;
        }
    while ( temp != NULL )
        {
            cout<<temp->data<<"  ";
            temp = temp -> next;
        }
    getch();
}

void sll::search(int key)
{
    node *temp;
    int found;
    temp = head;
    if ( temp == NULL )
        {
            cout<<"The Linked List is empty\n";
            getch();
            clrscr();
        }
    found = FALSE;
    while ( temp != NULL && found==FALSE)
        {
            if ( temp->data != key)
                temp = temp -> next;
            else
                found = TRUE;
        }
    if ( found==TRUE )
        {
            cout<<"\nThe Element is present in the list\n";
            getch();
        }
    else
        {
            cout<<"The Element is not present in the list\n";
            getch();
        }
}



/*
-------------------------------------------------------------------------
	The dele function
-------------------------------------------------------------------------
*/

void sll:: dele()
{
    node *temp, *prev ;
    int  key;
    temp=head;
    clrscr();
    cout<<"\nEnter the data of the node you want to delete: ";
    cin>>key;
    while(temp!=NULL)
        {
            if(temp->data==key)//traverse till required node to delete
                break;              //is found
            prev=temp;
            temp=temp->next;
        }
    if(temp==NULL)
        cout<<"\nNode not found";
    else
        {
            if(temp==head) //first node
                head=temp->next;
            else
                prev->next=temp->next;  //intermediate or end node
            delete temp;
            cout<<"\nThe Element is deleted\n";
        }
    getch();
}

/*
-------------------------------------------------------------------------
	  Function to insert at end
-------------------------------------------------------------------------
*/
void sll::insert_last()
{
    node *New,*temp;
    cout<<"\nEnter The element which you want to insert";
    cin>>New->data;
    if(head==NULL)
        head=New;
    else
        {
            temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=New;
            New->next=NULL;
        }
}


/*
--------------------------------------------------------------------------
	  Function to insert after a node
--------------------------------------------------------------------------
*/
void sll:: insert_after()
{
    int key;
    node  *temp,*New;
    New= new node;
    cout<<"\n Enter The element which you want to insert";
    cin>>New->data;
    if(head==NULL)
        {
            head=New;
        }
    else
        {
            cout<<"\n Enter The element after which you want to insert the node";
            cin>>key;
            temp=head;
            do
                {
                    if(temp->data==key)
                        {
                            New->next=temp->next;
                            temp->next=New;
                            break;
                        }
                    else
                        temp=temp->next;
                }
            while(temp!=NULL);
        }
}
/*
-------------------------------------------------------------------------
Function to insert at the beginning
-------------------------------------------------------------------------
*/

void sll:: insert_head()
{
    node *New,*temp;
    New=new node;
    cout<<"\n Enter The element which you want to insert";
    cin>>New->data;
    if(head==NULL)
        head=New;
    else
        {
            temp=head;
            New->next=temp;
            head=New;
        }
}
/*
------------------------------------------------------------------------
	The main function
	Input : None
	Output: None
	Parameter Passing Method : None
-------------------------------------------------------------------------
*/
void main()
{
    sll s;
    int choice,val,ch1;
    char ans = 'y';
    do
        {
            clrscr();
            cout<<"\nProgram to Perform Various operations on Linked List";
            cout<<"\n1.Create";
            cout<<"\n2.Display";
            cout<<"\n3.Search";
            cout<<"\n4.Insert an element in a list";
            cout<<"\n5.Delete an element from list";
            cout<<"\n6.Quit";
            cout<<"\nEnter Your Choice ( 1-6) ";
            cin>>choice;
            switch( choice)
                {
                case 1:
                    s.create();
                    break;
                case 2:
                    s.display();
                    break;
                case 3:
                    cout<<"Enter the element you want to search";
                    cin>>val;
                    s.search(val);
                    break;
                case 4:
                    clrscr();
                    cout<<"\nThe list is:\n";
                    s.display();
                    cout<<"\nMenu";
                    cout<<"\n1.Insert at beginning\n2.Insert after";
                    cout<<"\n3.Insert at end";
                    cout<<"\nEnter your choice";
                    cin>>ch1;
                    switch(ch1)
                        {
                        case 1:
                            s.insert_head();
                            break;
                        case 2:
                            s.insert_after();
                            break;
                        case 3:
                            s.insert_last();
                            break;
                        default:
                            cout<<"\nInvalid choice";
                        }
                    break;
                case 5:
                    s.dele();
                    break;
                default:
                    cout<<"\nInvalid choice";
                }
            cout<<"\nContinue?";
            cin>>ans;
        }
    while(ans=='y'||ans=='Y');
    getch();
    return;
}




