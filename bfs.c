#include<stdio.h>//Standard Input output
void bfs(int n,int a[n][n],int source,int visited[n])//BFS function
{
	int q[n];//Traversal queue
	int f=0,r=-1;//Initializing Queue parameters
	q[++r]=source;//Add source node to rear of queue
	while(f<=r)//Check if queue empty
	{	int u=q[f++];//Dequeue element
		for(int i=1;i<=n;i++)
			if(visited[i]==0&&a[u][i]==1)//Check if not visited but connected
			{	visited[i]=1;//Mark node as visited
				q[++r]=i;//Add node to traversal queue
			}
		printf("%d\n",u);//Print the node which is Dequeue
	}
}
int main()
{
	int n,source;
	printf("Enter the number of vertices");
	scanf("%d",&n);//Input number of vertices
	int a[n][n],visited[n];
	printf("Enter adjacency matrix");
	for(int i=1;i<=n;visited[i++]=0)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);//Input the adjaceny matrix
	printf("Enter the source node");
	scanf("%d",&source);//Input source node
	visited[source]=1;//Mark the source as visited
	bfs(n,a,source,visited);//Call the BFS function
}

