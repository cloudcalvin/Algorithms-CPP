/**********************************************************************************
Implementation of circular queue ADT using an Array
**********************************************************************************/
#include<iostream.h>
#include<conio.h>
#define MAX 10
// Create a generic Queue class
template <class Type>
class Queue
{
    Type Que[MAX];
    int front,rear;
public:
    void init()
    {
        front=-1;
        rear=0;
    }
    void insert(Type ch);
    Type delet();
    void display();
};
/*
----------------------------------------------------
insert function
----------------------------------------------------
*/
template <class Type>
void Queue<Type>::insert(Type item)
{
    if (front==(rear+1)%MAX)
        {
            cout << "Circular Queue is full\n";
            return;
        }
    if(front==-1)
        {
            front=0;
            rear=0;
        }
    else
        rear=(rear+1)%MAX;
    Que[rear] = item;//inserting the item in the Que
}
/*
----------------------------------------------------
delet function
----------------------------------------------------
*/
template <class Type>
Type Queue<Type>::delet()
{
    Type val;
    if((front==-1)||(front>rear))
        {
            cout << "Circular Queue is empty\n";
            return 0; // return null on empty stack
        }
    val= Que[front];//item to be deleted
    if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%MAX;
    return val;
}
template <class Type>
void Queue<Type>::display()
{
    int i;
    if(front==-1)
        cout<<"\n Circular Queue is Empty";
    i=front;
    while(i!=rear)
        {
            cout<<"\n   "<<Que[i];
            i=(i+1)%MAX;
        }
    cout<<"\n   "<<Que[i];
    cout<<"\n";
}
/*
----------------------------------------------------
The main function
----------------------------------------------------
*/
void main()
{
    Queue <char> Q1;
    Queue <int> Q2;
    int i;
    clrscr();
    Q1.init();
    Q2.init();
    Q1.insert('p');
    Q1.insert('q');
    Q1.insert('r');
    cout<<"\n The Circular Queue of characters is ..."<<endl;
    Q1.display();
    Q2.insert(10);
    Q2.insert(20);
    Q2.insert(30);
    cout<<"\n The Circular Queue of integers is ..."<<endl;
    Q2.display();
    cout << "\n Delete from Queue of characters: "<<endl;
    for (i=0; i<3; i++)
        cout<<"  "<<Q1.delet() << "\n";
    cout << "Delete from Queue of integers: "<<endl;
    for (i=0; i<3; i++)
        cout<<"  "<<Q2.delet() << "\n";
// demonstrate double queue
    Queue <double> Q3;
    Q3.init();
    Q3.insert(1.1);
    Q3.insert(1.2);
    cout<<"\n The Circular Queue of doubles is ..."<<endl;
    Q3.display();
    cout << "Delete from Queue of doubles: "<<endl;
    for (i=0; i<2; i++)
        cout<<"  "<<Q3.delet() << "\n";
    getch();
}
