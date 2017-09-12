/***********************************************************************
Program for sorting the elements using topological sort
************************************************************************/
#include<iostream.h>
#include<conio.h>
#define MAX 20
class TOPOLOGY
{
private:
    int Q[MAX];
public:
    int front,rear,G[MAX][MAX];
    TOPOLOGY();
    int Build_Graph();
    void Display(int);
    void Insert_Q(int vertex);
    int Delete_Q();
    int Compute_Indeg(int node,int n);
};
TOPOLOGY::TOPOLOGY()
{
    front=-1;
    rear=-1;
    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
            G[i][j]=0;
}

int TOPOLOGY::Build_Graph()
{
    int i,n,edges,V1,V2;
    cout<<"Enter number of vertices : ";
    cin>>n;
    cout<<"\n Enter the total number of edges ";
    cin>>edges;
    for(i=1; i<=edges; i++)
        {
            cout<<"Enter edge "<<i<<"(-99 -99 to quit): ";
            cin>>V1;
            cin>>V2;
            if((V1==-99) && (V2==-99))
                break;
            if( V1 > n || V2 > n)
                {
                    cout<<"Error!!!\n";
                    break;
                }
            if( V1 <=0 || V2 <=0)
                {
                    cout<<"Error!!!\n";
                    break;
                }
            else
                G[V1][V2]=1;
        }
    return n;
}
void TOPOLOGY::Insert_Q(int vertex)
{
    if (rear==MAX-1)
        cout<<"Queue Overflow\n";
    else
        {
            if (front==-1) /*Empty Queue condition*/
                front=0;
            rear=rear+1;
            Q[rear] = vertex;/* Insering node into the Q*/
        }
}

int TOPOLOGY::Delete_Q()
{
    int item;
    if (front == -1 || front > rear)
        {
            cout<<"Queue Underflow\n";
            return -1;
        }
    else
        {
            item=Q[front];
            front=front+1;
            return item;
        }
}

int TOPOLOGY::Compute_Indeg(int node,int n)
{
    int v1,indeg_count=0;
    for(v1=1; v1<=n; v1++)
        if( G[v1][node] == 1 )//checking for incoming edge
            indeg_count++;
    return indeg_count++;
}
void TOPOLOGY::Display(int n)
{
    int V1,V2;
    for(V1=1; V1<=n; V1++)
        {
            for(V2=1; V2<=n; V2++)
                cout<<" "<<G[V1][V2];
            cout<<"\n";
        }
}
void main()
{
    int i,j=0,k,n;
    TOPOLOGY obj;
    int b[MAX],indegree[MAX];
    clrscr();
    n=obj.Build_Graph();
    cout<<"The adjacency matrix is :\n";
    obj.Display(n);
    for(i=1; i<=n; i++)
        {
            indegree[i]=obj.Compute_Indeg(i,n);
            if( indegree[i]==0 )
                obj.Insert_Q(i);
        }
    while(obj.front<=obj.rear)
        {
            k=obj.Delete_Q();
            b[j++]=k;
            for(i=1; i<=n; i++)
                {
                    if( obj.G[k][i]==1 )
                        {
                            obj.G[k][i]=0;
                            indegree[i]=indegree[i]-1;
                            if(indegree[i]==0)
                                obj.Insert_Q(i);
                        }
                }
        }
    cout<<"The result of after topological sorting is ...\n";
    for(i=0; i<n; i++)
        cout<<"  "<<b[i];
    cout<<endl;
    getch();
}
