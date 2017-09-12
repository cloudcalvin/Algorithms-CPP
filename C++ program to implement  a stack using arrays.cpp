/************************************************************
Program for  implementing a stack using arrays.It involves
various operations such as push,pop,stack empty,stack full and
display.
*************************************************************/
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#define size 5
/* stack structure*/
class STACK_CLASS
{
private:
    struct stack
    {
        int s[size];
        int top;
    } st;
public:
    STACK_CLASS();
    int stfull();
    void push(int item);
    int stempty();
    int pop();
    void display();
};
//constructor is used to initialise stack
STACK_CLASS::STACK_CLASS()
{
    st.top=-1;
    for(int i=0; i<size; i++)
        st.s[i]=0;
}

/*
 The stfull Function
 Input:none
 Output:returns 1 or 0 for stack full or not
 Called By:main
 Calls:none
*/
int STACK_CLASS::stfull()
{
    if(st.top>=size-1)
        return 1;
    else
        return 0;
}
/*
 The push Function
 Input:item which is to be pushed
 Output:none-simply pushes the item onto the stack
 Called By:main
 Calls:none
*/
void STACK_CLASS::push(int item)
{
    st.top++;
    st.s[st.top] =item;
}
/*
 The stempty Function
 Input:none
 Output:returns 1 or 0 for stack empty or not
 Called By:main
 Calls:none
*/
int STACK_CLASS::stempty()
{
    if(st.top==-1)
        return 1;
    else
        return 0;
}
/*
 The pop Function
 Input:none
 Output:returns the item which is popped from the stack
 Called By:main
 Calls:none
*/
int STACK_CLASS::pop()
{
    int item;
    item=st.s[st.top];
    st.top-- ;
    return(item);
}
/*
 The display Function
 Input:none
 Output:none-displays the contents of the stack
 Called By:main
 Calls:none
*/
void STACK_CLASS::display()
{
    int i;
    if(stempty())
        cout<<"\n Stack Is Empty!";
    else
        {
            for(i=st.top; i>=0; i--)
                cout<<"\n"<<st.s[i];
        }
}
/*
 The main Function
 Input:none
 Output:none
 Called By:O.S.
 Calls:push,pop,stempty,stfull,display
*/
void main(void)
{
    int item,choice;
    char ans;
    STACK_CLASS obj;
    clrscr();
    cout<<"\n\t\t Implementation Of Stack";
    do
        {
            cout<<"\n Main Menu";
            cout<<"\n1.Push\n2.Pop\n3.Display\n4.exit";
            cout<<"\n Enter Your Choice: ";
            cin>>choice;
            switch(choice)
                {
                case 1:
                    cout<<"\n Enter The item to be pushed ";
                    cin>>item;
                    if(obj.stfull())
                        cout<<"\n Stack is Full!";
                    else
                        obj.push(item);
                    break;
                case 2:
                    if(obj.stempty())
                        cout<<"\n Empty stack!Underflow !!";
                    else
                        {
                            item=obj.pop();
                            cout<<"\n The popped element is "<<item;
                        }
                    break;
                case 3:
                    obj.display();
                    break;
                case 4:
                    exit(0);
                }
            cout<<"\n Do You want To Continue?";
            ans=getche();
        }
    while(ans ==Y ||ans ==y);
    getch();
}
/******************** End Of Program ************************/





