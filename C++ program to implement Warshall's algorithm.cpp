/*****************************************************************
This program is for computing transitive closure
using Warshall's algorithm
*****************************************************************/

#include<stdio.h>
#include<conio.h>
#define FALSE 0
#define TRUE 1
void main()
{
    int g[10][10],n,i,j,dist;
    void Warshall(int g[10][10],int n);
    clrscr();
    printf("\n\t\t Warshall's Algorithm");
    printf("\n create a graph using adjacency matrix");
    printf("\n\n How many vertices are there ?");
    scanf("%d",&n);
    printf("\n Enter the elements");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            g[i][j] = FALSE;
    printf("\n Enter the distance between JPNAGAR and JAYANAGAR ");
    scanf("%d",&dist);
    g[1][2] = dist;
    printf("\n Enter the distance between JAYANAGAR and BTM ");
    scanf("%d",&dist);
    g[2][3] = dist;
    printf("\n Enter the distance between BTM to V.V. PURAM ");
    scanf("%d",&dist);
    g[3][4] = dist;
    printf("\n Enter the distance between V.V. PURAM to JAYANAGAR ");
    scanf("%d",&dist);
    g[4][2] = dist;
    printf("\n Enter the distance between BTM to JPNAGAR ");
    scanf("%d",&dist);
    g[3][1] = dist;
    printf("\n\t Computing Transitive closure ...\n");
    Warshall(g,n);
    getch();
}

void Warshall(int matrix[10][10],int n)
{
    int R[5][10][10],i,j,k;
    for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                {
                    R[0][i][j]=matrix[i][j];//computing R(0)
                }
        }
    for(k=1; k<=n; k++)
        {
            for(i=1; i<=n; i++)
                {
                    for(j=1; j<=n; j++)
                        {
                            R[k][i][j]=R[k-1][i][j]||(R[k-1][i][k]&&R[k-1][k][j]);
                        }
                }
        }
    /*
     printing R(k)
    */
    for(k=1; k<=n; k++)
        {
            printf("R(%d) = \n",k);
            for(i=1; i<=n; i++)
                {
                    for(j=1; j<=n; j++)
                        {
                            printf(" %d",R[k][i][j]);
                        }
                    printf("\n");
                }
        }