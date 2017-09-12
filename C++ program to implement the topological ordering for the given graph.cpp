/***********************************************************************
Program for obtaining the topological ordering for the given graph
************************************************************************/
#include <stdio.h>
#include<conio.h>
#define TRUE 1
#define FALSE 0

int main()
{
    int i,j,k;
    int n,a[10][10],in[10],visit[10];
    int count=0;
    clrscr();
    printf("\n\t\t Topological Sorting");
    n=4;
    for(i=0; i<n; i++) //initialising the graph
        {
            for(j=0; j<n; j++)
                {
                    a[i][j]=0;
                }
        }
    printf("\n Graph is Created as follows -");
    printf("\n The node '0' and '1' are connected");
    a[0][1]=1;
    printf("\n The node '0' and '2' are connected");
    a[0][2]=1;
    printf("\n The node '3' and '2' are connected");
    a[3][2]=1;
    for(i=0; i<n; i++)
        {
            in[i]=0;
            visit[i]=FALSE;
        }
    /*Computing the indegree of each node*/
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            in[i]=in[i]+a[j][i];
    printf("\n\nThe topological order is:");
    while(count<n)
        {
            for(k=0; k<n; k++)
                {
                    if((in[k]==0) && (visit[k]==0))
                        {
                            /*Node having 0 degree is deleted and displayed*/
                            printf(" %d",k);
                            visit [k]=TRUE;
                        }
                    for(i=0; i<n; i++)
                        {
                            if(a[i][k]==1)
                                in[k]--;
                        }
                }
            count++;
        }
    getch();
    return 0;
}
