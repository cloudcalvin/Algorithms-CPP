/*************************************************************
	Program to evaluate a given postfix expression.
	Here the stack using arrays is implemented in separate
	file named stack.h

*************************************************************/
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*included the header file as stack using array*/
#include "d:\stackpost.h"
#define size 80

/*
--------------------------------------------------------------
	The main function
	Input : None
	Output: None
	Parameter Passing Method :None
	Called By : OS
	Calls :post()
--------------------------------------------------------------
*/
void main ()
{
    char exp[size];
    int	 len;
    double  Result;
    double post(char exp[]);
    clrscr();
    cout<<"Enter the postfix Expression\n ";
    cin>>exp;
    len = strlen(exp);
    exp[len] ='$'; /* Append $ at the end as a 	endmarker*/
    Result = post(exp);
    cout<<"The Value of the expression is "<<Result;
    getch();
    exit(0);
}
/*
---------------------------------------------------------------
 The post function which is for evaluating postfix expression
 Input : A post Expression of single digit operand
 Output: Resultant value after evaluating the expression
 Parameter Passing Method :by reference
 Called By : main()
 Calls :push(), pop()
---------------------------------------------------------------
*/
double  post( char exp[])
{
    STK_CLASS obj;
    char   ch,*type;
    double  result, val, op1, op2;
    int i;
    i=0;
    ch = exp[i];
    while ( ch !='$' )
        {
            if ( ch >= '0' && ch <= '9')
                type ="operand";
            else if ( ch == '+'|| ch == '-'||
                      ch == '*'|| ch == '/' ||
                      ch == '^' )
                type="operator";
            if( strcmp(type,"operand")==0)/*if the character is operand*/
                {
                    val = ch - 48;
                    obj.push( val);
                }
            else if (strcmp(type,"operator")==0) /*if it is operator*/
                {
                    op2 = obj.pop();
                    op1 = obj.pop();
                    switch(ch)
                        {
                        case '+' :
                            result = op1 + op2;
                            break;
                        case '-' :
                            result = op1 - op2;
                            break;
                        case '*' :
                            result = op1 * op2;
                            break;
                        case '/' :
                            result = op1 / op2;
                            break;
                        case '^' :
                            result = pow(op1,op2);
                            break;
                        }/* switch */
                    obj.push(result);
                }
            i++;
            ch=exp[i];
        } /* while */
    result = obj.pop(); /*pop the result*/
    return(result);
}
