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
        front=rear=-1;
    }
    void insert(Type ch);
    Type delet();
};
/*
---------------------------------------------------------------
insert function
---------------------------------------------------------------
*/
template <class Type>void Queue<Type>::insert(Type item)
{
    if (rear>=MAX)
        {
            cout << "Queue is full\n";
            return;
        }
    if(front==-1)
        front++;
    Que[++rear] = item;//inserting the item in the Que
}
/*
---------------------------------------------------------------
delet function
---------------------------------------------------------------
*/
template <class Type>Type Queue<Type>::delet()
{
    Type val;
    if((front==-1)||(front>rear))
        {
            cout << "Queue is empty\n";
            return 0; // return null on empty stack
        }
    val= Que[front];//item to be deleted
    front++;
    return val;
}
/*
------------------------------------------------------------
The main function
------------------------------------------------------------
*/
void main()
{
    Queue <char> Q1;
    Queue <int> Q2;
    int i;
    //clrscr();
    Q1.init();
    Q2.init();
    Q1.insert('p');
    Q1.insert('q');
    Q1.insert('r');
    Q2.insert(10);
    Q2.insert(20);
    Q2.insert(30);
    cout << "Delete from Queue of characters: "<<endl;
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
    cout << "Delete from Queue of doubles: "<<endl;
    for (i=0; i<2; i++)
        cout<<"  "<<Q3.delet() << "\n";
    getch();
}

