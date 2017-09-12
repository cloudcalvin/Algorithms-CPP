/****************************************************************************
	Implementation of Floyd's Algorithm using OpenMP
****************************************************************************/
#include<stdio.h>
#include<omp.h>

void main()
{
    int wt[10][10],n,i,j;
    double startTime,endTime;
    int nthreads;
    void Floyd_shortest_path(int matrix[10][10],int n);
    omp_set_num_threads(3);
    nthreads=omp_get_max_threads();
    printf("\n create a graph using adjacency matrix");
    printf("\n\n How many vertices are there ?");
    scanf("%d",&n);
    printf("\n Enter the elements");
    printf("[Enter 999 as infinity value]");
    for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                {
                    printf("\nwt[%d][%d]",i,j);
                    scanf("%d",&wt[i][j]);
                }
        }
    printf("\n\t Computing All pair shortest path ...\n");
    #pragma omp parallel firstprivate(wt,n)
    {
        startTime=omp_get_wtime();
        #pragma omp parallel
        Floyd_shortest_path(wt,n);
        endTime=omp_get_wtime();
        printf("\nTime taken=%10.9f",(double)(endTime-startTime));
    }
    printf("\n Total Number of threads used is %d\n",nthreads);
}

void Floyd_shortest_path(int wt[10][10],int n)
{
    int D[5][10][10],i,j,k;
    int min(int,int);
    #pragma omp parallel for ordered schedule(runtime)
    for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                {
                    D[0][i][j]=wt[i][j];//computing D(0)
                }
        }
    for(k=1; k<=n; k++)
        {
            for(i=1; i<=n; i++)
                {
                    for(j=1; j<=n; j++)
                        {
                            D[k][i][j]= min(D[k-1][i][j],(D[k-1][i][k]+D[k-1][k][j]));
                        }
                }
        }
    /*
    printing D(k)
    */
    for(k=0; k<=n; k++)
        {
            printf(" D(%d)=\n",k);
            for(i=1; i<=n; i++)
                {
                    for(j=1; j<=n; j++)
                        {
                            printf(" %d",D[k][i][j]);
                        }
                    printf("\n");
                }
            printf("\n-------------------------\n");
        }
}

int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}