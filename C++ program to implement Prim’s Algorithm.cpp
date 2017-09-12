/**********************************************************************
This program is to implement Prim’s Algorithm
**********************************************************************/
# include<iostream.h>
# include<conio.h>
# define SIZE 20
# define INFINITY 32767
class MST
{
private:
    int G[SIZE][SIZE],nodes;
public:
    MST();
    void Prim();
    void get_data();
};
/*	 This function finds the minimal spanning tree by Prim’s Algorithm   */

MST::MST()
{
    for (int i=0 ; i<SIZE ; i++)       // Initialize the graph
        for (int j=0 ; j<SIZE ; j++)
            G[i][j] = 0;
}
void MST::Prim()
{
    int select[SIZE], i, j, k;
    int min_dist, v1, v2,total=0;
    for (i=0 ; i<nodes ; i++)   // Initialize the selected vertices list
        select[i] = 0;
    cout<<"\n\n The Minimal Spanning Tree Is :\n";
    select[0] = 1;
    for (k=1 ; k<nodes ; k++)
        {
            min_dist = INFINITY;
            for (i=0 ; i<nodes ; i++) // Select an edge such that one vertex is
                {
                    // selected and other is not and the edge
                    for (j=0 ; j<nodes ; j++) // has the least weight.
                        {
                            if (G[i][j] && ((select[i] && !select[j]) || (!select[i] && select[j])))
                                {
                                    if (G[i][j] < min_dist)//obtained edge with minimum wt
                                        {
                                            min_dist = G[i][j];
                                            v1 = i;
                                            v2 = j;   //picking up those vertices
                                        }
                                }
                        }
                }
            cout<<"\n Edge ("<<v1<<" "<<v2<<") and weight = "<<min_dist;
            select[v1] = select[v2] = 1;
            total =total+min_dist;
        }
    cout<<"\n\n\t Total Path Length Is =  "<<total;
}
void MST::get_data()
{
    int v1, v2, length, n;
    cout<<"\n Enter Number of Nodes in The Graph  ";
    cin>>nodes;
    cout<<"\n Enter Number of Edges in The Graph  ";
    cin>>n;
//entering weighted graph
    cout<<"\n Enter edges and weights \n";
    for (int i=0 ; i<n; i++)
        {
            cout<<"\n Enter Edge by V1 and V2 : ";
            cin>>v1>>v2;
            cout<<"\n Enter corresponding weight :";
            cin>>length;
            G[v1][v2] = G[v2][v1] = length;
        }
}
void main( )
{
    MST obj;
    clrscr( );
    cout<<"\n\t Prim’S Algorithm\n";
    obj.get_data();
    cout<<"\n\t";
    clrscr( );
    obj.Prim();
    getch();
}
Output
