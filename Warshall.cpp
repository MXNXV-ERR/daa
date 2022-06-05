#include<stdio.h>//Standard input output

int main()//Main function
{
	int n;//Number of vertices
	printf("Enter the number of vertices:");
	scanf("%d",&n);//Input the number of vertices
	printf("Enter the adjecency matrix\n");
	int a[n][n];//Adjecency matrix of size n X n
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);//Input the adjecency matrix
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				a[i][j]=a[i][j]||(a[i][k]&&a[k][j]);
	//^a[i][j] element is 1 if a[i][j] is 1 in previous iteration ^ 
	//^or if a[i][k] and a[k][j] both are 1 ^
	
	printf("The path matrix is \n");
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		//Printing path matrix(Transitive Closure) in matrix form
		printf("\n");
	}//End of for
}//End of main
