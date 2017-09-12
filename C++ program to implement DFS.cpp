/*************************************************************
Program to create a Graph and check whether the graph
is connected or not using DFS
*************************************************************/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define size	20
#define TRUE	1
#define FALSE 0

int g[size][size];
int visit[size];

int    Q[size];
int    front, rear;
int n;
void main ()
{
    int v1, v2,flag;
    void create();
    void Dfs(int v1);
    int isconn();
    clrscr();
    create();
    clrscr();
    printf("The Adjacency Matrix for the graph is \n");
    for ( v1 = 0; v1 < n; v1++)
        {
            for ( v2 = 0; v2 < n; v2++)
                printf(" %d ", g[v1][v2]);
            printf("\n");
        }
    getch();
    for ( v1 = 0; v1 < n; v1++)
        visit[v1] = FALSE;
    Dfs(0);
    flag=isconn();
    if(flag==1)
        printf("\n The Roads are Connected to different cities");
}

void  create()
{
    int 	v1, v2,dist;
    printf("\nEnter no. of nodes ");
    scanf("%d",&n);
    for ( v1 = 0; v1 < n; v1++)
        for ( v2 = 0; v2 < n; v2++)
            g[v1][v2] = FALSE;
    printf("\n Enter the distance between JPNAGAR and JAYANAGAR ");
    scanf("%d",&dist);
    g[0][1] = dist;
    printf("\n Enter the distance between JAYANAGAR and BTM ");
    scanf("%d",&dist);
    g[1][2] = dist;
    printf("\n Enter the distance between BTM to V.V. PURAM ");
    scanf("%d",&dist);
    g[2][3] = dist;
    printf("\n Enter the distance between V.V. PURAM to JAYANAGAR ");
    scanf("%d",&dist);
    g[3][1] = dist;
    printf("\n Enter the distance between BTM to JPNAGAR ");
    scanf("%d",&dist);
    g[2][0] = dist;
}

void Dfs(int v1)
{
    int v2;
    printf("\nThe road is connected to:");
    switch(v1)
        {
        case 0:
            printf(" JPNAGAR ");
            break;
        case 1:
            printf(" JAYANAGAR ");
            break;
        case 2:
            printf(" BTM ");
            break;
        case 3:
            printf(" V.V.PURAM ");
            break;
        case 4:
            printf(" K.R.PURAM ");
            break;
        }
    visit[v1] = TRUE;
    for ( v2 = 0; v2 < size; v2++)
        if ( g[v1][v2] != 0 &&  visit[v2] == FALSE )
            Dfs(v2);
}
int isconn()
{
    int i;
    for(i=0; i<n; i++)
        {
            if(visit[i]==FALSE)
                {
                    printf("\n The Road to K.R.PURAM is not Connected");
                    return 0;
                }
        }
    return 1;
}