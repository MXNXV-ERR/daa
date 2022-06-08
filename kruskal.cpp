#include<stdio.h>//Standard input output
int main()//Main Function
{
	int i,j,n,ne,min_cost=0,min,source;
	printf("Enter the number of nodes");
	scanf("%d",&n);//Input number of nodes
	printf("Enter cost matrix\n");
	int cost[n][n];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&cost[i][j]);//Input cost matrix
	printf("Minimum cost spanning tree is\n");
 	for(ne=1;ne<n;min=999)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(cost[i][j]<min)//Checking if it is the minimum edge
					{	min=cost[i][j];//Finding the minimum edge
						if(i!=j)//Checking for cycles
						{	printf("\nEdge%d\t(%d->%d)=%d",ne++,i,j,min);
							min_cost+=min;//Adding minimum edge cost to sum
						}
						cost[i][j]=cost[j][i]=999;//Disconnecting the edge
												//to avoid re-calculation
					}
	printf("\nMinimum cost %d \n",min_cost);//Printing the minimum cost
}
