#include<stdio.h>//Standard input output
int main()//Main Function
{
	int i,j,n,ne,a,b,min_cost=0,min;
	printf("Enter the number of nodes\n");
	scanf("%d",&n);//Input number of nodes
	printf("Enter cost matrix\n");
	int cost[n][n],parent[n];
	for(i=1;i<=n;parent[i++]=0)
		for(j=1;j<=n;j++)
			scanf("%d",&cost[i][j]);//Input cost matrix
	printf("Minimum cost spanning tree is\n");
 	for(ne=1;ne<n;min=999)
	{	for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(cost[i][j]<min)//Checking if it is the minimum edge
					min=cost[a=i][b=j];//Finding the minimum edge		
		while(parent[a])a=parent[a];
		while(parent[b])b=parent[b];
		if(a!=b)//Checking for cycles
		{	printf("\nEdge%d\t(%d->%d)=%d",ne++,a,b,min);
			min_cost+=min;//Adding minimum edge cost to sum
			parent[b]=a;
		}
		cost[a][b]=cost[b][a]=999;//Disconnecting the edge
	}											//to avoid re-calculation
	printf("\nMinimum cost %d \n",min_cost);//Printing the minimum cost
}
