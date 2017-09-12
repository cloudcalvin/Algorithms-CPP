/*************************************************************
	Program for implementing the Queue using arrays

*************************************************************/
#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#define size 5
class MyQ
{
private:
    struct queue
    {
        int que[size];
        int front,rear;
    } Q;
public:
    MyQ();
    int Qfull();
    int insert(int);
    int Qempty();
    int delet();
    void display();
};
MyQ::MyQ()
{
    Q.front =-1;
    Q.rear  = -1;
}
/*
 The Qfull  Function
 Input:none
 Output:1 or 0 for q full or not
 Called By:main

*/
int MyQ::Qfull()
{
    if(Q.rear >=size-1)
        return 1;
    else
        return 0;
}
/*
 The insert  Function
 Input:item -which is to be inserted in the Q
 Output:rear value
 Called By:main
 Calls:none
*/
int MyQ::insert(int item)
{
    if(Q.front ==-1)
        Q.front++;
    Q.que[++Q.rear] = item;
    return Q.rear;
}
int MyQ::Qempty()
{
    if((Q.front == - 1) || (Q.front > Q.rear))
        return 1;
    else
        return 0;
}
/*
 The delete Function
 Input:none
 Output:front value
 Called By:main
 Calls:none
*/
int MyQ::delet()
{
    int item;
    item = Q.que[Q.front];
    Q.front++;
    cout<<"\n The deleted item is "<<item;
    return Q.front;
}
/*
 The display Function
 Input:none
 Output:none
 Called By:main
 Calls:none
*/
void MyQ::display()
{
    int i;
    for(i=Q.front; i<=Q.rear; i++)   <------Printing the queue from front to rear
        cout<<" "<<Q.que[i];
}
void main(void)
{
    int choice,item;
    char ans;
    MyQ obj;
    clrscr();
    do
        {
            cout<<"\n Main Menu";
            cout<<"\n1.Insert\n2.Delete\n3.Display";
            cout<<"\n Enter Your Choice: ";
            cin>>choice;
            switch(choice)
                {
                case 1:
                    if(obj.Qfull())       //checking for Queue overflow
                        cout<<"\n Can not insert the element";
                    else
                        {
                            cout<<"\n Enter The number to be inserted ";
                            cin>>item;
                            obj.insert(item);
                        }
                    break;
                case 2:
                    if(obj.Qempty())
                        cout<<"\n Queue Underflow!!";
                    else
                        obj.delet();
                    break;
                case 3:
                    if(obj.Qempty())
                        cout<<"\nQueue Is Empty!";
                    else
                        obj.display();
                    break;
                default:
                    cout<<"\n Wrong choice!";
                    break;
                }
            cout<<"\n Do You Want to continue?";
            ans =getche();
        }
    while(ans =='Y'||ans =='y');
}




