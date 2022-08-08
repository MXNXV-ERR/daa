#include<stdio.h>
#include<math.h>
int board[20],count;
void print(int n)
{	printf("\n\nSolution %d:\n\n",++count);
 	for(int i=1;i<=n;printf("\t%d",i++));
 	
  	for(int i=1;i<=n;++i)
	{	printf("\n\n%d",i);
  		for(int j=1;j<=n;board[i]==j++?printf("\tQ"):printf("\t-"));
	}
}
int place(int row,int column)
{	for(int i=1;i<=row-1;++i)
  		if(board[i]==column||abs(board[i]-column)==abs(i-row))
   			return 0;
	return 1; 
}
void queen(int row,int n)
{
	for(int column=1;column<=n;++column)
		if(place(row,column))
  		{	board[row]=column; 
   			if(row==n)
    			print(n); 
   			else 
    			queen(row+1,n);
  		}
}
int main()
{	int n;
 	printf("Enter number of Queens:");
	scanf("%d",&n);
	queen(1,n);
	return 0;
}
