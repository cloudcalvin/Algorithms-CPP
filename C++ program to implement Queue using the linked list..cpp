/**********************************************************
Program For implementing the Queue using the linked list.
The queue full condition will never occur in this program.
************************************************************/
#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
//Declaration of Linked Queue data structure
class Lqueue
{
private:
    typedef struct node
    {
        int data;
        struct node *next;
    } Q;
    Q *front,*rear;
public:
    Lqueue();
    ~Lqueue();
    void create(),remove(),show();
    void insert();
    Q *delet();
    void display(Q *);
};

/*
------------------------------------------------------------
The constructor defined
------------------------------------------------------------*/
Lqueue::Lqueue()
{
    front=NULL;
    rear= NULL;
}
/*
------------------------------------------------------------
The create function
-----------------------------------------------------------*/
void Lqueue::create()
{
    insert();
}
/*
------------------------------------------------------------
The remove function
------------------------------------------------------------*/
void Lqueue::remove()
{
    front =delet();
}
/*
------------------------------------------------------------
The show function
------------------------------------------------------------*/
void Lqueue::show()
{
    display(front);
}

/*
------------------------------------------------------------
 The insert Function
------------------------------------------------------------
*/
void Lqueue::insert()
{
    char ch;
    Q *temp;
    clrscr();
    temp =new Q;//allocates memory for temp node
    temp->next=NULL;
    cout<<"\n\n\n\tInsert the element in the Queue\n";
    cin>>temp->data;
    if(front == NULL)//creating first node
        {
            front= temp;
            rear=temp;
        }
    else                 //attaching other nodes
        {
            rear->next=temp;
            rear=rear->next;
        }
}

/*
------------------------------------------------------------
The QEmpty Function
------------------------------------------------------------*/
int Qempty(Q *front)
{
    if(front ==NULL)
        return 1;
    else
        return 0;
}
/*
------------------------------------------------------------
The delet Function
------------------------------------------------------------
*/
Q *Lqueue::delet()
{
    Q *temp;
    temp=front;
    if(Qempty(front))
        {
            cout<<"\n\n\t\tSorry!The Queue Is Empty\n";
            cout<<"\n Can not delete the element";
        }
    else
        {
            cout<<"\n\tThe deleted Element Is  "<<temp->data;
            front=front->next;
            temp->next=NULL;
            delete temp;
        }
    return front;
}
/*
------------------------------------------------------------
 The display Function
------------------------------------------------------------
*/
void Lqueue::display(Q *front)
{
    if(Qempty(front))
        cout<<"\n The Queue Is Empty\n";
    else
        {
            cout<<"\n\t The Display Of Queue Is \n ";
            for(; front !=rear->next; front=front->next)
                cout<<"  "<<front->data;
        }
    getch();
}
/*
------------------------------------------------------------
The destructor defined
------------------------------------------------------------
*/
Lqueue::~Lqueue()
{
    if((front!=NULL)&&(rear!=NULL))
        {
            front=NULL;
            rear=NULL;
            delete front;
            delete rear;
        }
}

/*
------------------------------------------------------------
The main Function
Calls:create,remove,show
Called By:O.S.
------------------------------------------------------------
*/
void main(void)
{
    char ans;
    int choice;
    Lqueue Que;
    do
        {
            clrscr();
            cout<<"\n\tProgram For Queue Using Linked List\n";
            cout<<"\n            Main Menu";
            cout<<"\n1.Insert\n2.Delete \n3.Display";
            cout<<"\n Enter Your Choice";
            cin>>choice;
            switch(choice)
                {
                case 1 :
                    Que.create();
                    break;
                case 2 :
                    Que.remove();
                    break;
                case 3 :
                    Que.show();
                    break;
                default:
                    cout<<"\nYou have entered Wrong Choice"<<endl;
                    break;
                }
            cout<<"\nDo You Want To See Main Menu?(y/n)"<<endl;
            ans = getch();
        }
    while(ans == ‘y’ || ans == ‘Y’);
    getch();
}


