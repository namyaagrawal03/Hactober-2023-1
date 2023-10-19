#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//Negative cycle function
void Negative_cycle(int graph[10][3], int V, int E, int
distance[])
{
for(int j=0; j<E; j++)
{
//source vertex should not be infinity and
distance of source + weight should be less than the distance of
destination
if(distance[graph[j][0]] != INT_MAX &&
distance[graph[j][0]] + graph[j][2] < distance[graph[j][1]])
{
printf("Graph has negative cycle\nBellman-Ford
algorithm cannot be applied\n"); //Negative cycle found
exit (0);
}
}
// return 0; //No negative cycle
}
void Bellmanford(int graph[10][3], int V, int E, int scr)
{
int distance[V];
//initiallize distance variable for all vertices
for(int i=0; i<V; i++)
{
distance[i] = INT_MAX;
//intialize all vertices to infinity using in-built INT_MAX =
2147483647 (for 32-bit Integers)
}
distance[scr] = 0; //Assign source distance to 0
//Performing relaxation on every edge
for(int i=0; i<V-1; i++)
{
for(int j=0; j<E; j++)
{
//source vertex should not be infinity and
distance of source + weight should be less than the distance of
destination
if( distance[scr] != INT_MAX &&
distance[graph[j][0]] + graph[j][2] < distance[graph[j][1]])
{
//assign distance of source + weight to
distance of destination
distance[graph[j][1]] =
distance[graph[j][0]] + graph[j][2];
printf("\nRelaxation step %d:\n",i+1);
printf("Updated distance to vertex is: %d -
%d\n",graph[j][1], distance[graph[j][1]]);
}
}
}
Negative_cycle(graph,V,E,distance);
//Checking for negative cycle
printf("\nVertex distance from source\n");
for(int i=1; i<V+1; i++)
{
printf("%d\t%d\n", i, distance[i]);
//printing the vertex with their respective distance
}
}
int main() //main function
{
int V,E,source; //V=number of vertices E=number of edges
int graph[10][3];
//initialize graph where rows=edges and column having 3
components as source, destination, and weight between them
printf("Please enter the number of vertices:");
//user input for number of vertices
scanf("%d", &V);
printf("Please enter the number of edges:");
//user input for number of edges
scanf("%d", &E);
printf("Please enter source vertex, destination vertex and
weight:");
for(int i=0; i<E; i++)
{
scanf("%d %d %d", &graph[i][0], &graph[i][1],
&graph[i][2]); //user input for graph elements
}
printf("Please enter the source vertex:");
//user input for source vertex
scanf("%d", &source);
Bellmanford(graph,V,E,source);
//Function call
return 0;
}
