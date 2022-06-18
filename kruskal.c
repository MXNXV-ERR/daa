#include<stdio.h>//Standard input output
int main()//Main Function
{
	int i,j,n,ne,a,b,u,v,min_cost=0,min=999;
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
					min=cost[u=a=i][v=b=j];//Finding the minimum edge		
		while(parent[a])a=parent[a];
		while(parent[b])b=parent[b];
		if(a!=b)//Checking for cycles
		{	printf("\nEdge%d\t(%d->%d)=%d",ne++,u,v,min);
			min_cost+=min;//Adding minimum edge cost to sum
			parent[b]=a;
		}
		cost[u][v]=cost[v][u]=999;//Disconnecting the edge
	}								//to avoid re-calculation
	printf("\nMinimum cost %d \n",min_cost);//Printing the minimum cost
}
