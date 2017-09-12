4. Write program to perform Strassen’s Matrix multiplication

/***********************************************************************************************
Program to perform Strassen’s Matrix multiplication
***********************************************************************************************/

#include<stdio.h>
#include<conio.h>
void st_Mul(int *A,int *B,int *C,int n)
{
    if(n==1)
        {
            (*C)=(*C)+(*A)*(*B);
        }
    else
        {
            st_Mul(A,B,C,n/4);
            st_Mul(A,B+n/4,C+n/4,n/4);
            st_Mul(A+2*(n/4),B,C+2*(n/4),n/4);
            st_Mul(A+2*(n/4),B+(n/4),C+3*(n/4),n/4);
            st_Mul(A+(n/4),B+2*(n/4),C,n/4);
            st_Mul(A+(n/4),B+3*(n/4),C+(n/4),n/4);
            st_Mul(A+3*(n/4),B+2*(n/4),C+2*(n/4),n/4);
            st_Mul(A+3*(n/4),B+3*(n/4),C+3*(n/4),n/4);
        }
}
void main()
{
    int A[2][2],B[2][2],C[2][2],n,i,j;
    clrscr();
    printf("\n\tProgram for Strassen's Matrix multiplication ");
    printf("\n Enter the value of n: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                {
                    C[i][j]=0;
                }
        }
    printf("\n Enter the elements of matrix A:\n");
    for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                {
                    scanf("%d",&A[i][j]);
                }
        }
    printf("\n Enter the elements of matrix B:\n");
    for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                {
                    scanf("%d",&B[i][j]);
                }
        }
    st_Mul(&A[0][0],&B[0][0],&C[0][0],n*n);
    printf("\n Resultant matrix after multiplication is: \n");
    for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                {
                    printf(" %d",C[i][j]);
                }
            printf("\n");
        }
    getch();
}
