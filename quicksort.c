#include<stdio.h> //Standard input output
#include<stdlib.h>//Standard library
#include<time.h>  //Time library for clock()
void quicksort(int a[],int low,int high)//Quicksort function
{	int i=low,j=high,pivot=low,t;//Declaring variables	
	if(i<j)//Check if i exceed j
	{	while(i<j)//Check if i exceed j
		{	while(a[i]<=a[pivot]&&i<high)//While a[i] is lesser than a[pivot]
				i++;//Increement i	
			while(a[j]>a[pivot])		 //While a[j] is greater than a[pivot]
				j--;//Decreement j
			if(i<j) //Check if i exceed j
			{	t=a[j];						
				a[j]=a[i];	//Swapping a[i] with a[j]
				a[i]=t;						
		    }//End of if
		}//End of while
		t=a[pivot];							
		a[pivot]=a[j];	//Swapping a[j] with pivot
		a[j]=t;								
		quicksort(a,low,j-1); //quicksort() for left side of pivot(Recursive)
		quicksort(a,j+1,high);//quicksort() for right side of pivot(Recursive)
	}//end of if
}//End of quicksort
int main()//Main function
{	clock_t s,e;   double t;  int n;//Declaring variables
	printf("Enter the number of elements");	//Asking for number of elements
	scanf("%d",&n);	//Input the value of n from user
	int a[n];//Declaring the array of size n
	printf("Before sorting\n");				
	for(int i=0;i<n;i++)
	{	a[i]=(int)rand(); //Giving random values using rand()
		printf("%d",a[i]);//Printing elements in unsorted order
	}//End of for
	s=clock();//Clock started
	quicksort(a,0,n-1);//Quicksort function called on a(array)
	e=clock();//Clock stopped
	t=(double)(e-s)/CLOCKS_PER_SEC;//Calculating amount of CPU time taken
	printf("After sorting\n");				
	for(int i=0;i<n;i++)					
		printf("%d\n",a[i]);//Printing elements in sorted order
	printf("Total time taken is %e",t);//Printing the total CPU time taken
}//End of main
