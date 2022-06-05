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
	{	int min=i;
		for(int j=i+1;j<n;j++)
			if(a[min]>a[j])
				min=j;
			int temp=a[min];
			a[min]=a[i];
			a[i]=temp;
	}
	e=clock();
	printf("After Sorting");
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
	ttt=(double)(e-s)/CLOCKS_PER_SEC;
	printf("Time taken=%e",ttt);
	
}
