/**********************************************************
Program for creating the stack using the linked list.
Program performs all the operations such as push,pop and
display.It takes care of stack underflow condition. There can
	not be stack full condition in stack using linked list.
************************************************************/
#include <iostream.h>
#include <conio.h>
#include<stdlib.h>
//Declaration for data structure of linked stack
class Lstack
{
private:
    typedef struct stack
    {
        int data;
        struct stack *next;
    } node;
    node *top;
public:
    Lstack();
    ~Lstack();
    void create(),remove(),show();
    void Push(int, node **);
    void Display(node **);
    int Pop(node **);
    int Sempty(node *);
};
/*
------------------------------------------------------------------------------------------
The constructor defined
------------------------------------------------------------------------------------------
*/
Lstack::Lstack()
{
    top = NULL;
}
/*
------------------------------------------------------------------------------------------
The destructor defined
------------------------------------------------------------------------------------------
*/
Lstack::~Lstack()
{
    node *temp;
    temp=top;
    if(temp==NULL)
        delete temp;
    else
        {
            while(temp!=NULL)
                {
                    temp=temp ->next;
                    top=NULL;
                    top=temp;
                }
            delete temp;//de allocating memory
        }
}
/*
------------------------------------------------------------------------------------------
The create function
------------------------------------------------------------------------------------------
*/
void Lstack::create()
{
    int data;
    cout<<"\n Enter the data";
    cin>>data;
    Push(data,&top);
}
/*
------------------------------------------------------------------------------------------
The remove function
------------------------------------------------------------------------------------------
*/
void Lstack::remove()
{
    int item;
    if(Sempty(top))
        cout<<"\n stack underflow!";
    else
        {
            item = Pop(&top);
            cout<<"\n The popped node is  "<< item;
        }
}
/*
------------------------------------------------------------------------------------------
The show function
------------------------------------------------------------------------------------------
*/
void Lstack::show()
{
    Display(&top);
}

/*
------------------------------------------------------------------------------------------
The Push function
------------------------------------------------------------------------------------------
*/
void Lstack::Push(int Item, node **top)
{
    node *New;
    New = new node;
    New->next=NULL;
    New->data=Item;
    New -> next = *top;
    *top = New;
}
/*
------------------------------------------------------------------------------------------
The Sempty Function
------------------------------------------------------------------------------------------
*/
int Lstack::Sempty(node *temp)
{
    if(temp==NULL)
        return 1;
    else
        return 0;
}
/*
------------------------------------------------------------------------------------------
The Pop function
------------------------------------------------------------------------------------------
*/
int Lstack::Pop(node **top)
{
    int item;
    node *temp;
    item = (*top) ->data;
    temp = *top;
    *top = (*top) -> next;
    delete temp;
    return(item);
}
/*
------------------------------------------------------------------------------------------
The Display function
------------------------------------------------------------------------------------------
*/
void Lstack::Display(node **head )
{
    node *temp ;
    temp = *head;
    if(Sempty(temp))
        cout<<"\n The stack is empty!";
    else
        {
            while ( temp != NULL )
                {
                    cout<<"  "<<temp -> data;
                    temp = temp -> next;
                }
        }
    getch();
}
/*
------------------------------------------------------------------------------------------
The main function
------------------------------------------------------------------------------------------
*/
void main ( )
{
    int choice;
    char ans,ch;
    Lstack st;
    clrscr();
    cout<<"\n\t\t Stack Using Linked List";
    do
        {
            cout<<"\n\n The main menu";
            cout<<"\n1.Push\n2.Pop\n3.Display\n4.Exit";
            cout<<"\n Enter Your Choice";
            cin>>choice;
            switch(choice)
                {
                case 1:
                    st.create();
                    break;
                case 2:
                    st.remove();
                    break;
                case 3:
                    st.show();
                    break;
                case 4:
                    exit(0);
                }
            cout<<"\n Do you want to continue?";
            ans =getche();
            getch();
            clrscr();
        }
    while(ans ==’Y’ ||ans ==’y’);
    getch();
}


