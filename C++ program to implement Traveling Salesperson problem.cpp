/**********************************************************
The implementation of Traveling Salesperson problem
**********************************************************/
#include<stdio.h>
#include<conio.h>
#define MAX 10

typedef struct
{
    int nodes[MAX];
    int vertex;
    int min;
} Path_node;        // structure to store the path

Path_node TSP(int source, Path_node list, int Element[][MAX], int max_no_cities)
{
    int i, j;
    Path_node new_list, new_path, new_min;
    if(list.vertex == 0)
        {
            new_min.min = Element[source][1];
            new_min.nodes[max_no_cities–1] = source; // store the vertex from in the list
            new_min.vertex = max_no_cities;
            return new_min;
        }
    for(i=0; i<list.vertex; i++)	//going through all the vertices
        {
            new_list.vertex = 0;
            for(j = 0; j < list.vertex; j++)
                if(i != j)
                    new_list.nodes[new_list.vertex++] = list.nodes[j];
            new_path = TSP(list.nodes[i], new_list, Element, max_no_cities);
            // call recursively
            new_path.min = Element[source][list.nodes[i]] + new_path.min;
            // updating new path
            new_path.nodes[max_no_cities – list.vertex –1] = source;
            if(i == 0)      // if the new_path is for the 1st node then that is the
                // current minimum path
                new_min = new_path;
            else          	// else check for better path
                if(new_path.min < new_min.min)
                    new_min = new_path;
        }
    return new_min;   // return the newly obtained min path
}                 // This is the minimum path
void display(Path_node Path)
{
    int i;
    printf("\n\nThe minimum cost is %d\n", Path.min);
    printf("\n The path is...\n");
    for(i = 0; i < Path.vertex; i++)
        printf("%d – – ", Path.nodes[i]);
    printf("%d", Path.nodes[0]);//returning to original node
}
main( )
{
    int i, j, Element[MAX][MAX], max_no_cities;
    Path_node Graph, Path;
    clrscr( );
    printf("\n How Many Number of Cities are there? ");
    scanf("%d", &max_no_cities);
    // accept the no. of vertices
    if(max_no_cities==0)
        {
            printf("Error:There is no city for processing the TSP");
        }
    else
        {
            for(i = 1; i <= max_no_cities; i++)
                {
                    for(j = 1; j <= max_no_cities; j++)
                        if(i == j)
                            Element[i][i] = 0;//self referancing path is set to 0
                        else
                            {
                                printf("Enter distace from city %d to %d ? ", i, j);
                                scanf("%d", &Element[i][j]);//create graph for finding TSP
                            }
                    if(i > 1)
                        Graph.nodes[i–2] = i;
                }
            Graph.vertex = max_no_cities - 1;//total number of cities
            Path = TSP(1, Graph, Element, max_no_cities);
            display(Path);
        }
    getch( );
    return 1;
}