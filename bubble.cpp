#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	clock_t s,e;double ttt;int n;
	printf("Enter the number of elements");
	scanf("%d",&n);
	int a[n];
	srand(time(0));
	for(int i=0;i<n;i++)
		a[i]=(int)rand();
	printf("Before Sorting");
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
	s=clock();
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	e=clock();
	printf("After Sorting");
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
	ttt=(double)(e-s)/CLOCKS_PER_SEC;
	printf("Time taken=%e",ttt);
	
}
