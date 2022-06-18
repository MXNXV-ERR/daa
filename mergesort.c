#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void combine(int a[],int l,int h,int m)
{	int temp[h],i=l,j=m+1,k=l;
	while(i<=m&&j<=h)
		temp[k++]=a[i]<=a[j]?a[i++]:a[j++];	
	while(i<=m)
		temp[k++]=a[i++];
	while(j<=h)
		temp[k++]=a[j++];
	for(int i=l;i<=h;i++)
		a[i]=temp[i];
}
void mergesort(int a[],int l,int h)
{	if(l<h)
	{	int m=(l+h)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,h);
		combine(a,l,h,m);
	}
}
int main()
{	int n;  double ttt;
	clock_t s,e;
	printf("Enter the no of elements");
	scanf("%d",&n);
	int a[n];
	printf("Before sorting");
	srand(time(0));
	for(int i=0;i<n;i++)
	{	a[i]=(int)rand();
		printf("%d\t",a[i]);
	}		
	s=clock();
	mergesort(a,0,n-1);
	e=clock();
	printf("After sorting");
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
	ttt=(double)(e-s)/CLOCKS_PER_SEC;
	printf("Total time taken=%e",ttt);	
}
