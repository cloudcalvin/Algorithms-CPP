/**********************************************************************
This program is for Graph coloring Problem. The Backtracking method is
 used to solve this problem.
**********************************************************************/
#include<stdio.h>
#include<conio.h>
#define MAX 10

int G[MAX][MAX],m,edges;
int color_tab[MAX];
void main()
{
    int i,j,n;
    void Gen_Col_Value(int,int);
    void Gr_coloring(int,int);
    int get_data();
    void display(int);
    clrscr();
    printf("\n\n\t Graph Coloring \n");
    for(i=0; i<MAX; i++) /* intialilisation of the graph and color table*/
        {
            for(j=0; j<MAX; j++)
                {
                    G[i][j]=0;
                    color_tab[i]=0;
                }
        }
    n=get_data();
    Gr_coloring(1,n);
    display(n);
    getch();
}

void Gen_Col_Value(int k,int n)
{
    int j;
    int a,b;
    while(1)
        {
            a=color_tab[k]+1;
            b=m+1;
            color_tab[k] = a%b; // next highest color
            if(color_tab[k]==0) return;    // all colors have been used
            for(j=1; j<=n; j++)
                {
                    // check if this color is distinct from adjacent colors
                    if(G[k][j] && color_tab[k]==color_tab[j])
                        break;
                }
            if(j==n+1) return; // next new color found
        }
}

// such that adjacent vertices are assigned distinct integers
// k is the index of next vertex color.
void Gr_coloring(int k,int n)
{
    Gen_Col_Value(k,n);
    if(color_tab[k]==0) return;   // No new color available
    if(k==n)  return;     // at most m colors have been
    else Gr_coloring(k+1,n);  // used to color the n vertices
}
int get_data()
{
    int v1,v2,i,n;
    printf("\n Enter the number of nodes  ");
    scanf("%d",&n);
    printf("\n Enter the number of edges  ");
    scanf("%d",&edges);
    m=n-1;
    printf("\n Enter the edges of the graph");
    printf(" By giving values of V1 and V2\n");
    for (i=1; i<=edges; i++)
        {
            scanf("%d%d",&v1,&v2);
            G[v1][v2] = G[v2][v1] = 1;//if an edge is present then set it
        }
    return n;
}
void display(int n)
{
    int i;
    printf("\n The Vertices To be Coloured As...\n");
    for(i=1; i<=n; i++)
        printf("\n V%d:=%d",i,color_tab[i]);
}
