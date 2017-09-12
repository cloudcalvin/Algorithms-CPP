/******************************************************************************************
Program for addition of two binary numbers
*******************************************************************************************/
#include<iostream.h>
#include<stack>
using namespace std;
void main()
{
    stack<int> A;
    stack<int> B;
    stack<int> C;
    char First_number[5],Second_number[5];
    int a=0,b=0;
    cout<<"\n Enter the first binary number ";
    cin>>First_number;
    for(int i=0; First_number[i]!='\0'; i++)
        {
            if(First_number[i]=='0')
                A.push(0);
            else
                A.push(1);
        }
    //First stack stores first binary number
    cout<<"\n Enter the Second binary number ";
    cin>>Second_number;
    for(i=0; Second_number[i]!='\0'; i++)
        {
            if(Second_number[i]=='0')
                B.push(0);
            else
                B.push(1);
        }
    //Second stack stores first binary number
    int carry=0;
    while(!A.empty()||!B.empty())
        {
            a=0;
            b=0;
            if(!A.empty())//length of first number is larger than second
                {
                    a=A.top();
                    A.pop();
                }
            if(!B.empty())//length of second number is larger than first
                {
                    b=B.top();
                    B.pop();
                }
            int sum=carry+a+b;//performing addition
            C.push(sum%2);//pushing the result onto the third stack
            carry=sum/2;//setting carry
        }
    if(carry==1)//if carry is there then
        C.push(carry);//it is pushed at the end onto the stack
    cout<<"\n Addition of two binary numbers is ... ";
    while(!C.empty())
        {
            cout<<C.top();
            C.pop();
        }
    cout<<"\n";
}
