/**********************************************************************
Program for finding shortest path using dynamic programming approach for multistage graph
 **************************************************************************/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 20
int stages,stage_vertices[MAX],c[MAX][MAX];
int cost[MAX],p[MAX],n;
Get_min(int,int);
void Forward(int);
int create();
void display();

int Get_min(int s,int n)
{
    int min=9999;//equal to infinity
    int min_vertex;
    for(int i=0; i<n; i++)
        {
            if(min>(c[s][i]+cost[i]))
                {
                    min=c[s][i]+cost[i];
                    min_vertex=i;
                }
        }
    return min_vertex;
}
void Forward(int n)
{
    int i,r;
    int d[20];
    for(i=0; i<n; i++)
        cost[i]=0;//initalize graph by cost 0
    for(i=n-2; i>=0; i--)
        {
            r=Get_min(i,n);
            cost[i]=c[i][r]+cost[r];
            d[i]=r;
        }
    p[0]=0;
    p[stages-1]=n-1;
    for(i=1; i<stages-1; i++)
        p[i]=d[p[i-1]];
}

int create()
{
    int i,j,m,p,no_of_vertices=0;
    printf("\nEnter no of vertices: ");
    scanf("%d",&no_of_vertices);
    printf("\nEnter no of stages : ");
    scanf("%d",&stages);
    for(i=0; i<no_of_vertices; i++)
        for(j=0; j<no_of_vertices; j++)
            c[i][j]=9999;//initialization
    for(i=0; i<stages; i++)
        {
            printf("\nEnter no of vertices in stage %d: ",i+1);
            scanf("%d",&stage_vertices[i]);
        }
    i=0;
    j=stage_vertices[0];
    for(m=0; m<stages; m++)
        {
            j=i+stage_vertices[m];
            for(; i<j; i++)
                {
                    for(p=0; p<stage_vertices[m+1]; p++)
                        {
                            printf("\nEnter cost for %d to %d:",i+1,p+j+1);
                            scanf("%d",&c[i][p+j]);//entering the corresponding cost
                        }
                }
        }
    return no_of_vertices;
}
void display( )
{
    int i;
    printf(" Shortest path is...\n");
    for(i=0; i<stages-1; i++)
        printf(" %d",p[i]+1);
    printf(" %d",p[i]+1);//printing target node
}

void main()
{
    int n;
    clrscr();
    n=create();
    clrscr();
    Forward(n);
    display();
    getch();
}
