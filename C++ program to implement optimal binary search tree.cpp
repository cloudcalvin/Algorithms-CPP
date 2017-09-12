/********************************************************************
This Program is to implement optimal binary search tree
********************************************************************/
# include<stdio.h>
# include<conio.h>

# define SIZE 10

int p[SIZE];    //Probabilities with which we search for an element
int q[SIZE];       //Probabilities that an element is not found
int a[SIZE];     //Elements from which OBST is to be built
int w[SIZE][SIZE]; //Weight ‘w[i][j]’ of a tree having root 							 //‘r[i][j]’
int c[SIZE][SIZE]; //Cost ‘c[i][j]’ of a tree having root ‘r[i][j]’
int r[SIZE][SIZE]; // Represents Root
int n;             //Number of nodes

/*  This function accepts the input data	*/

void get_data()
{
    int i;
    clrscr();
    printf (“\n Optimal Binary Search Tree \n”);
    printf (“\n Enter the number of nodes   ”);
    scanf (“%d”,&n);
    printf (“\n Enter the data as  ....\n”);
    for (i=1 ; i<=n ; i++)
        {
            printf(“\n a[%d] ”,i);
            scanf(“%d”,&a[i]);
        }
    for (i=1 ; i<=n ; i++)
        {
            printf(“\n p[%d] ”,i);
            scanf(“%d”,&p[i]);
        }
    for (i=0 ; i<=n ; i++)
        {
            printf(“\n q[%d] ”,i);
            scanf(“%d”,&q[i]);
        }
}

/*This function returns a value in the range ‘r[i][j-1]’ to ‘r[i+1][j]’so that the cost ‘c[i][k-1] + c[k][j]’ is minimum  */

int Min_Value(int i, int j)
{
    int m,k;
    int minimum = 32000;
    for (m=r[i][j-1] ; m<=r[i+1][j] ; m++)
        {
            if ((c[i][m-1]+c[m][j]) < minimum)
                {
                    minimum = c[i][m-1] + c[m][j];
                    k = m;
                }
        }
    return k;
}

/*  This function builds the table from all the given probabilities
 It basically computes C,r,W values */

void OBST()
{
    int i, j, k, l, m;
    for (i=0 ; i<n ; i++)
        {
            //  Initialize
            w[i][i] = q[i];
            r[i][i] = c[i][i] = 0;
            //  Optimal trees with one node
            w[i][i+1] = q[i] + q[i+1] + p[i+1];
            r[i][i+1] = i+1;
            c[i][i+1] = q[i] + q[i+1] + p[i+1];
        }
    w[n][n] = q[n];
    r[n][n] = c[n][n] = 0;
    //  Find optimal trees with ‘m’ nodes
    for (m=2 ; m<=n ; m++)
        {
            for (i=0 ; i<=n-m ; i++)
                {
                    j = i+m;
                    w[i][j] = w[i][j-1] + p[j] + q[j];
                    k = Min_Value(i, j);
                    c[i][j] = w[i][j] + c[i][k-1] + c[k][j];
                    r[i][j] = k;
                }
        }
}

/*This function builds the tree from the tables made by the OBST function */

void build_tree()
{
    int i, j, k;
    int queue[20], front=-1, rear=-1;
    clrscr();
    printf (“ The Optimal Binary Search Tree For The Given Nodes Is ....\n”);
    printf (“\n The Root of this OBST is :: %d”, r[0][n]);
    printf (“\n The Cost Of this OBST is :: %d”, c[0][n]);
    printf (“\n\n\tNODE\tLEFT CHILD\tRIGHT CHILD”);
    printf(“\n       ---------------------------”);
    queue[++rear] = 0;
    queue[++rear] = n;
    while(front != rear)
        {
            i = queue[++front];
            j = queue[++front];
            k = r[i][j];
            printf (“\n\t%d\t”, k);
            if (r[i][k-1] != 0)
                {
                    printf (“%d\t\t”, r[i][k-1]);
                    queue[++rear] = i;
                    queue[++rear] = k-1;
                }
            else
                printf (“-\t\t”);
            if (r[k][j] != 0)
                {
                    printf (“%d\t”, r[k][j]);
                    queue[++rear] = k;
                    queue[++rear] = j;
                }
            else
                printf (“-\t”);
        }
    printf (“\n”);
}

/*  This is the main function	*/

void main()
{
    get_data();
    OBST();
    build_tree();
    getch();
}
