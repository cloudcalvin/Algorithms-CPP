/***********************************************************************************************
Parallelized Merge Sort
***********************************************************************************************/
#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define MAX_SIZE 1000
void GenerateNumbers(int * x, int n)
{
    int i;
    srand(10000);
    for (i = 0; i < n; i++)
        {
            int val = n * ((float)rand() / ((float)RAND_MAX +(float) 1));
            x[i] = val;
        }
}
void Display(int *A)
{
    printf("\nSorted List");
    #pragma omp parallel
    for(int i=0; i<5; i++) //displaying only 5 elements
        printf("\n%d",A[i]);
    printf("\n");
}

void Combine(int * A, int n, int * tmp)
{
    int i = 0;
    int j = n/2;
    int k = 0;
    while (i<n/2 && j<n)
        {
            if (A[i] < A[j])
                {
                    tmp[k] = A[i];
                    k++;
                    i++;
                }
            else
                {
                    tmp[k] = A[j];
                    k++;
                    j++;
                }
        }
    while (i<n/2)
        {
            /* lower half */
            tmp[k] = A[i];
            k++;
            i++;
        }
    while (j<n)
        {
            /* upper half */
            tmp[k] = A[j];
            k++;
            j++;
        }
    memcpy(A, tmp, n*sizeof(int));
    Display(A);
} // end of Combine()
//parallel version of merge sort carried out using parallel threads
void mergesort(int * A, int n, int * tmp,int nthreads)
{
    if (n < 2) return;
    #pragma omp parallel firstprivate(A, n, tmp)
    mergesort(A, n/2, tmp,nthreads/2);
    #pragma omp parallel firstprivate (A, n, tmp)
    mergesort(A+(n/2), n-(n/2), tmp,nthreads-nthreads/2);
    #pragma omp parallel
    /* Combine sorted halves into sorted list */
    Combine(A, n, tmp);
}
int main()
{
    int n = 50;
    int data[MAX_SIZE], tmp[MAX_SIZE];
    //clock_t start,stop;
    double startTime,endTime;
    omp_set_num_threads(5);
    int nthreads=omp_get_max_threads();
    GenerateNumbers(data, n);
    #pragma omp parallel
    {
        startTime=omp_get_wtime();
        #pragma omp parallel
        mergesort(data, n, tmp,nthreads);
        endTime=omp_get_wtime();
        printf("\nTime taken=%10.9f",(double)(endTime-startTime));
    }
    printf("\n Total Number of threads used for sorting %d\n",nthreads);
}