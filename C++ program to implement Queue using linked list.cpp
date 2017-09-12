/**********************************************************
  Program For implementing the Queue using the linked list.
 **************************************************************/
#include<iostream.h>
#include<conio.h>


//Declaration of Linked Queue data structure
template <class T>
class Lqueue
{
private:
    typedef struct node
    {
        T data;
        struct node *next;
    } Q;
    Q *front,*rear,*temp;
public:
    Lqueue()
    {
        front=NULL;
        rear=NULL;
    }
    void create(),remove(),show();
    void insert();
    void delet(Q **front);
    void display(Q *);
};

template <class T>
void Lqueue<T>::create()
{
    insert();
}

template <class T>
void Lqueue <T>::remove()
{
    delet(&front);//reference to front is passed
}

template <class T>
void Lqueue <T>::show()
{
    display(front);
}
/*

--------------------------------------------------------------------------
 The insert Function
--------------------------------------------------------------------------
*/
template <class T>
void Lqueue <T>::insert()
{
    temp =new Q;//allocates memory for temp node
    temp->next=NULL;
    cout<<"\n\tInsert the element in the Queue\n";
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

--------------------------------------------------------------------------
 The delet Function
--------------------------------------------------------------------------
*/
template <class T>
void Lqueue <T>::delet(Q **front)
{
    temp=*front;
    if(*front==NULL)
        {
            cout<<"\n\n\t\tSorry!The Queue Is Empty\n";
            cout<<"\n Can not delete the element";
        }
    else
        {
            cout<<"\n\tThe deleted Element Is  "<<temp->data;
            *front=(*front)->next;//front's address is restored
            temp->next=NULL;
            delete temp;
        }
}

/*
--------------------------------------------------------------------------
 The display Function
--------------------------------------------------------------------------
*/
template <class T>
void Lqueue <T>::display(Q *front)
{
    if(front==NULL)
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
--------------------------------------------------------------------------
The main Function
Calls:create,remove,show
Called By:O.S.
--------------------------------------------------------------------------
*/
void main(void)
{
    char ans;
    int choice;
    Lqueue <int> IQue;//object for int type
    Lqueue <char> CQue;//object for char type
    do
        {
            cout<<"\n\tProgram For Queue Using Linked List\n";
            cout<<"\n            Main Menu";
            cout<<"\n1.Insert\n2.Delete \n3.Display";
            cout<<"\n Enter Your Choice";
            cin>>choice;
            switch(choice)
                {
                case 1 :
                    IQue.create();
                    break;
                case 2 :
                    IQue.remove();
                    break;
                case 3 :
                    IQue.show();
                    break;
                default:
                    cout<<"\nYou have entered Wrong Choice"<<endl;
                    break;
                }
            cout<<"\nDo You Want To See Main Menu?(y/n)"<<endl;
            ans = getch();
        }
    while(ans == 'y' || ans == 'Y');
    cout<<" \n\t\tQueue created for storing 5 letteres"<<endl;
    for(int i=1; i<=5; i++)
        CQue.create();
    cout<<"\n";
    CQue.show();
    cout<<"\n";
}
