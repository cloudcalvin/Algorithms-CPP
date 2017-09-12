
/*************************************************************
		Program To implement cursor of List ADT
*************************************************************/
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#define  MAX 20
class LIST
{
private:
    int List[MAX];
public:
    int create();
    void display(int);
    void reverse(int);
    int  Search(int);
    void delet(int);
};
/*
------------------------------------------------------------
	Function		: create
	Input	: None
	Output	: Creates the list
	Calls	: None
------------------------------------------------------------
*/
int LIST::create()
{
    int n,i;
    clrscr();
    cout<<"\nHow Many Elements You Want in the list : ";
    cin>>n;
    if ( n > MAX )
        cout<<"\nError:Number of elements exceeds the limit ";
    for ( i=0; i <n; i++ )
        {
            cout<<"\nEnter the element Number "<<i+1<<": ";
            cin>>List[i];
        }
    cout<<"\nThe List is successfully created\n";
    getch();
    return(n);
}

/*
------------------------------------------------------------
	Function		: display
	Input			: The length of the list
	Output		: Prints the list
	Calls			: None
------------------------------------------------------------
*/
void LIST::display(int n)
{
    int i;
    clrscr();
    cout<<"\nThe List is ...\n";
    for ( i=0; i < n; i++)
        cout<<"\n"<<List[i];
    cout<<"\nPress any key to continue...\n";
    getch();
}
/*
------------------------------------------------------------


	Function: reverse
	Input	: The length of the list
	Output	: prints the list in reverse manner
	Calls   : None
------------------------------------------------------------
*/
void LIST::reverse(int n)
{
    int i;
    clrscr();
    cout<<"\nThe Reversed List is ...\n";
    for ( i=n-1; i >= 0; i--)
        cout<<"\n"<<List[i];
    cout<<"\nPress any key to continue...\n";
    getch();
}
/*
------------------------------------------------------------
	Function: Search
	Input	: The length of the list
	Output	: Reads a number & searches the list for a number
	Calls	: None
------------------------------------------------------------
*/

int LIST::Search(int n)
{
    int i, key;
    clrscr();
    cout<<"\nEnter the Number you want to Search ? ";
    cin>>key;
    /* Now Search in the list */
    for(i=0; i<n; i++)
        {
            if ( List[i] ==key )
                {
                    cout<<"\nThe given number is at position: "<<i<<"\n";
                    getch();
                    return i;
                }
        }
    cout<<"\nThe given number is not in the list\n";
    getch();
    return -1;
}
/*
------------------------------------------------------------
	Function	: delet
	Input		: The length of the list
	Output	: Deletes the number from the list
	Calls		: Search
	Called By :main
------------------------------------------------------------
*/

void LIST::delet(int n)
{
    int i;
    i=Search(n);
    List[i]=-1;
    cout<<"\n The element is now deleted!";
    cout<<"\n We Put -1 to indicate Empty Location";
    getch();
}

void main ()
{
    LIST obj;
    int choice,len,position;
    char ans;
    do
        {
            clrscr();
            cout<<"\n\tProgram To Perform Operations On Ordered List";
            cout<<"\n 1.Create";
            cout<<"\n 2.Display ";
            cout<<"\n 3.Search for a Number";
            cout<<"\n 4.Reverse ";
            cout<<"\n 5.Delete";
            cout<<"\n 6.Quit";
            cout<<"\nEnter Your Choice ( 1-6) ";
            cin>>choice;
            switch( choice)
                {
                case 1:
                    len =obj.create();
                    break;
                case 2:
                    obj.display(len);
                    break;
                case 3:
                    position=obj.Search(len);
                    break;
                case 4:
                    obj.reverse(len);
                    break;
                case 5:
                    obj.delet(len);
                    break;
                case 6:
                    cout<<"\nDo You Want to Exit ( y/n) ?";
                    ans=getche();
                    if(ans=='y')
                        exit(0);
                    else
                        break;
                default:
                    clrscr();
                    cout<<"\nInvalid Choice, Try again";
                    getch();
                }
        }
    while(choice != 6);
}
