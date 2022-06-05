#include<stdio.h>
int main()
{
	int i,j,n,ne,min_cost=0,min,source;
	printf("Enter the number of nodes");
	scanf("%d",&n);
	printf("Enter cost matrix\n");
	int cost[n][n],visited[n];
	for(i=1;i<=n;i++,visited[i]=0)
		for(j=1;j<=n;j++)
			scanf("%d",&cost[i][j]);
	printf("Enter root node\n");
	scanf("%d",&source);
	visited[source]=1;
	printf("Minimum cost spanning tree is\n");
 	for(ne=1;ne<n;min=999)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(cost[i][j]<min)
					if(visited[i]==1)
					{	min=cost[i][j];
						if(visited[i]==0||visited[j]==0)
						{	printf("\nEdge%d\t(%d->%d)=%d",ne++,i,j,min);
							min_cost+=min;
							visited[j]=1;
						}
						cost[i][j]=cost[j][i]=999;
					}
	printf("\nMinimum cost %d \n",min_cost);
}
