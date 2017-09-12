/************************************************************************************
This program is to implement n-queen's problem using backtracking
************************************************************************************/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<process.h>

int board[20];
int count;
void main()
{
    int n,i,j;
    void Queen(int row,int n);
    clrscr();
    printf("\n\t Program for n-Queen's Using Backtracking");
    printf("\nEnter Number of Queen's");
    scanf("%d",&n);
    Queen(1,n);//trace using backtrack
    getch();
}
/* This function is for printing the solution
		 to n-queen's problem
*/
void print_board(int n)
{
    int i,j;
    printf("\n\nSolution %d : \n\n",++count);
    //number of solution
    for(i=1; i<=n; i++)
        {
            printf("\t%d",i);
        }
    for(i=1; i<=n; i++)
        {
            printf("\n\n%d",i);
            for(j=1; j<=n; j++) // for  board
                {
                    if(board[i]==j)
                        printf("\tQ");//Queen at i,j position
                    else
                        printf("\t–");// empty slot
                }
        }
    printf("\n Press any key to continue...");
    getch();
}
/*
This function is for checking for the conflicts.
If there is no conflict for the desired position
it returns 1 otherwise it returns 0
*/
int place(int row,int column)
{
    int i;
    for(i=1; i<=row-1; i++)
        {
            //checking for column and diagonal conflicts
            if(board[i] == column)
                return 0;
            else if(abs(board[i] - column) == abs(i - row))
                return 0;
        }
    //no conflicts hence Queen can be placed
    return 1;
}
/* By this function we try the next free slot
and check for proper positioning of queen
*/
void Queen(int row,int n)
{
    int column;
    for(column=1; column<=n; column++)
        {
            if(place(row,column))
                {
                    board[row] = column;//no conflict so place queen
                    if(row==n)//dead end
                        print_board(n);
                    //printing the board configuration
                    else  //try next queen with next position
                        Queen(row+1,n);
                }
        }
}


