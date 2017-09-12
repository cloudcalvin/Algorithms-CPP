/************************************************************************
Program for deque implementation using STL
/************************************************************************/
#include<iostream.h>
#include<stdlib.h>
#include<deque>
using namespace std;
deque<int> IDeque;
deque<char>CDeque;
deque<int>::iterator Iptr;
deque<char>::iterator Cptr;

void Insert_Front(char ch)
{
    int I_item;
    char C_item;
    if(ch=='i')
        {
            cout<<"\n Enter the element for insertion ";
            cin>>I_item;
            IDeque.push_front(I_item);
        }
    else if(ch=='c')
        {
            cout<<"\n Enter the element for insertion ";
            cin>>C_item;
            CDeque.push_front(C_item);
        }
}
void Insert_Rear(char ch)
{
    int I_item;
    char C_item;
    if(ch=='i')
        {
            cout<<"\n Enter the element for insertion ";
            cin>>I_item;
            IDeque.push_back(I_item);
        }
    else if(ch=='c')
        {
            cout<<"\n Enter the element for insertion ";
            cin>>C_item;
            CDeque.push_back(C_item);
        }
}
void Delete_Front(char ch)
{
    int I_item;
    char C_item;
    if(ch=='i')
        {
            if(IDeque.empty())
                {
                    cout<<"\n Queue is empty!!!";
                    return;
                }
            I_item=IDeque.front();
            IDeque.pop_front();
            cout<<"\n The popped element is: "<<I_item;
        }
    else if(ch=='c')
        {
            if(CDeque.empty())
                {
                    cout<<"\n Queue is empty!!!";
                    return;
                }
            C_item=CDeque.front();
            CDeque.pop_front();
            cout<<"\n The popped element is: "<<C_item;
        }
}
void Delete_Rear(char ch)
{
    int I_item;
    char C_item;
    if(ch=='i')
        {
            if(IDeque.empty())
                {
                    cout<<"\n Queue is empty!!!";
                    return;
                }
            I_item=IDeque.back();
            IDeque.pop_back();
            cout<<"\n The popped element is: "<<I_item;
        }
    else if(ch=='c')
        {
            if(CDeque.empty())
                {
                    cout<<"\n Queue is empty!!!";
                    return;
                }
            C_item=CDeque.back();
            CDeque.pop_back();
            cout<<"\n The popped element is: "<<C_item;
        }
}
void Display(char ch)
{
    if(ch=='i')
        {
            if(IDeque.empty())
                {
                    cout<<"\n Queue is empty!!!";
                    return;
                }
            cout<<"\n The Queue is \n";
            for(Iptr=IDeque.begin(); Iptr!=IDeque.end(); Iptr++)
                cout<<"   "<<*Iptr;
        }
    else if(ch=='c')
        {
            if(CDeque.empty())
                {
                    cout<<"\n Queue is empty!!!";
                    return;
                }
            cout<<"\n The Queue is \n";
            for(Cptr=CDeque.begin(); Cptr!=CDeque.end(); Cptr++)
                cout<<"   "<<*Cptr;
        }
}
void main()
{
    int choice;
    char ans='y';
    char ch=' ';
    cout<<"\n Program for implementing deque ";
    cout<<"\n Enter 'i' for integer queue and 'c' for character queue ";
    cin>>ch;
    if(ch=='i')
        {
            do
                {
                    cout<<"\n Main Menu ";
                    cout<<"\n 1.Insert from front-end ";
                    cout<<"\n 2.Insert from rear-end ";
                    cout<<"\n 3.Delete from front-end ";
                    cout<<"\n 4.Delete from rear-end ";
                    cout<<"\n 5.Display ";
                    cout<<"\n Enter Your Choice ";
                    cin>>choice;
                    switch(choice)
                        {
                        case 1:
                            Insert_Front(ch);
                            break;
                        case 2:
                            Insert_Rear(ch);
                            break;
                        case 3:
                            Delete_Front(ch);
                            break;
                        case 4:
                            Delete_Rear(ch);
                            break;
                        case 5:
                            Display(ch);
                        }
                    cout<<"\n Do you want to go back to Main Menu? ";
                    cin>>ans;
                }
            while(ans=='y');
        }
    else
        {
            do
                {
                    cout<<"\n Main Menu ";
                    cout<<"\n 1.Insert from front-end ";
                    cout<<"\n 2.Insert from rear-end ";
                    cout<<"\n 3.Delete from front-end ";
                    cout<<"\n 4.Delete from rear-end ";
                    cout<<"\n 5.Display ";
                    cout<<"\n Enter Your Choice ";
                    cin>>choice;
                    switch(choice)
                        {
                        case 1:
                            Insert_Front(ch);
                            break;
                        case 2:
                            Insert_Rear(ch);
                            break;
                        case 3:
                            Delete_Front(ch);
                            break;
                        case 4:
                            Delete_Rear(ch);
                            break;
                        case 5:
                            Display(ch);
                        }
                    cout<<"\n Do you want to go back to Main Menu? ";
                    cin>>ans;
                }
            while(ans=='y');
        }
}
