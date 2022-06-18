#include<stdio.h>
int max(int a,int b)
{	
	return a>b?a:b;	//Return maximum of a and b	
}

int knapsack(int M,int w[],int p[],int n)
{	
	int v[n+1][M+1];  //Table
	for(int i=0;i<=n;i++)
		for(int j=0;j<=M;j++)
		{	if(i==0||j==0)
				v[i][j]=0;
			else if(w[i-1]>j)
				v[i][j]=v[i-1][j];
			else
				v[i][j]=max(v[i-1][j],(v[i-1][j-w[i-1]])+p[i-1]);	
		}
	printf("What is this called???\n");
	for(int i=0;i<=n;i++,printf("\n"))
		for(int j=0;j<=M;j++)
			printf("%d\t",v[i][j]);
	printf("Select the items\n");
	for(int i=n,j=M;i>0&&j>0;i--)
		if(v[i][j]!=v[i-1][j])
		{	printf("%d\t",i);
			j-=w[i-1];
		}
	return v[n][M];
}

int main()
{	int M,n;
	printf("Enter the capacity of knapsack");
	scanf("%d",&M);
	printf("Enter the number of items");
	scanf("%d",&n);
	int w[n],p[n];
	printf("Enter weight of items");
	for(int i=0;i<n;i++)
		scanf("%d",&w[i]);
	printf("Enter profit of items");
	for(int i=0;i<n;i++)
		scanf("%d",&p[i]);
	printf("\nThe optimum solution is : %d",knapsack(M,w,p,n));
}
