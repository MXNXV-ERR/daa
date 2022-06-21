#include<stdio.h>//Standard input output
int main()//Main Function
{
	int i,j,n,ne,min_cost=0,min=999,source,a,b;
	printf("Enter the number of nodes");
	scanf("%d",&n);//Input number of nodes
	printf("Enter cost matrix\n");
	int cost[n][n],visited[n];
	for(i=1;i<=n;i++,visited[i]=0)
		for(j=1;j<=n;j++)
			scanf("%d",&cost[i][j]);//Input cost matrix
	printf("Enter root node\n");
	scanf("%d",&source);//Input source node
	visited[source]=1;
	printf("Minimum cost spanning tree is\n");
 	for(ne=1;ne<n;min=999)
	{	for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(cost[i][j]<min&&i!=j)//Checking if it is the minimum edge
					if(visited[i]==1)//Checking if node already visited
						min=cost[a=i][b=j];//Finding the minimum edge
											//to avoid re-calculation
		if(visited[a]==0||visited[b]==0)//Checking for cycles
		{	printf("\nEdge%d\t(%d->%d)=%d",ne++,a,b,min);
			min_cost+=min;//Adding minimum edge cost to sum
			visited[b]=1;//Make the vertex as visited
		}
		cost[a][b]=cost[b][a]=999;//Disconnecting the edge
	}
	printf("\nMinimum cost %d \n",min_cost);//Printing the minimum cost
}
