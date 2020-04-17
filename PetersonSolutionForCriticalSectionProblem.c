// Compile :- gcc PetersonSolutionForCriticalSectionProblem.c -o PetersonSolutionForCriticalSectionProblem
// Run :- ./PetersonSolutionForCriticalSectionProblem


#include<stdio.h>
#include<unistd.h>
int main()
{
	_Bool flag[2] = {1,1} ;
	int turn ;
	int first ;
	int m ;
	int n ;
	int counter ;
	int process[2];
	printf("We are taking two process for Critical Section Problem!\n");
	for(int i= 0 ; i <= 1; i++)
	{
		printf("Please enter %d process number ",i+1);
 		scanf("%d",&process[i]);
	}
	for(int i = 0 ; counter != 0 ; i++)
	{
		printf("which process you want to enter\n");
		scanf("%d", &first);
		printf("The process which is going to enter in critical section is %d\n",first);
		if(first == process[0])
		{
			m = 1 ;
			n = 0 ;
		}
		else
		{
			m = 0 ;
			n = 1 ;
		}
		flag[n] = 0;
		turn = m ;
                while(flag[m] && turn == n);
                {
			printf("your process %d is in critical section\n",process[n]);
			flag[n] = 1;
		}
		printf("If you want to exit press 0\n");
		printf("If you want to continue press 1\n");
		scanf("%d",&counter);
	}
}
