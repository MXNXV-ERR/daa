#include<stdio.h>	//Standard input output 
#include<stdlib.h>	//Standard library
#include<string.h>	//String functions
int main()//Main function
{
	int table[126];			//Shift table
	char t[100],p[25];		//Text and pattern strings
	int n,i,k,j,m,flag=0;	//Decalaring variables
	
	printf("Enter the text\n");
	gets(t);	//Input text from user
	n=strlen(t);//Finding the length of input text
	
	printf("Enter the pattern\n");
	gets(p);	//Input pattern from the user
	m=strlen(p);//Finding the length of input pattern
	
	for(i=0;i<126;i++)		//Intializing all values in shift
		table[i]=m;			//table to length of pattern string
		
	for(j=0;j<m-1;j++)		//Calculating shift value of characters
		table[p[j]]=m-1-j;	//present in pattern string
		
	i=m-1;//Arranging pattern with the text string for comparision
		
	while(i<n)
	{
		k=0;
		while(k<m&&p[m-1-k]==t[i-k])	//Checking each character of 
			k++;						//pattern string with text string
		if(k==m)
		{
			printf("The postion of the pattern is %d\n",i-m+2);
			flag=1;	//If all characters of pattern string match
			break;	//Break the loop and print position
		}//End of if
		else					//If complete match is not found 
			i+=table[t[i]];		//then shift according to shift value 
	}//ENd of while
	if(!flag)	//Check if no match is found
		printf("Pattern not found!!\n");	
}//End of main
