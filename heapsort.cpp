#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void heapify(int a[], int n, int i)  
{  
    int big = i;   
    int l = 2 * i + 1;   
    int r = 2 * i + 2;    
    if (l < n && a[l] > a[big])  
        big = l;   
    if (r < n && a[r] > a[big])  
        big = r;    
    if (big != i) 
	{    
        int temp = a[i];  
        a[i] = a[big];  
        a[big] = temp;  
        heapify(a, n, big);  
    }  
}  
void heapSort(int a[], int n)  
{  
    for (int i = n / 2 - 1; i >= 0; i--)  
        heapify(a, n, i);  
    for (int i = n - 1; i >= 0; i--) 
	{  
    	int temp = a[0];  
        a[0] = a[i];  
        a[i] = temp;  
        heapify(a, i, 0);  
    }  
}  

int main()
{
	clock_t s,e;
	float t;
	int n;
	printf("Enter the number of ele");
	scanf("%d",&n);
	int a[n];	
	for(int i=0;i<n;i++)
	{
		a[i]=(int)rand();
		printf("%d\n",a[i]);
	}
	s=clock();
	heapSort(a,n);
	e=clock();
	t=(double)(e-s)/CLOCKS_PER_SEC;
	for(int i=0;i<n;i++)
		printf("%d\n",a[i]);
	printf("Total time %e",t);
	
}
