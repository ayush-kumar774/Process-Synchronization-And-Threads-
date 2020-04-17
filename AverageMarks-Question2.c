// Average Marks Calculation Using Threads
// Compile -> gcc -pthread "AverageMarks-Question2.c" -o "AverageMarks-Question2"
// Run -> ./"AverageMarks-Question2"

#include<pthread.h>
#include<stdio.h>
void *averageMarks(void *mark)
{
 int n = *(int *)mark;
 int marks[n] ;
 int sum = 0,avg ;  
 int result ;
 int i ;
 
 for(i = 0; i < n ;i++)
 {
   printf("Please enter mark for %d subject:- ", i+1);
   scanf("%d",&marks[i]);
 }
 printf("calculate avg :-");
 for(i=0; i < n; i++)
 {
   sum = sum + marks[i];
 }
 avg = sum / n;
 result = avg;
 return ((void *)(long)result);

}
int main()
{
 int number;
 pthread_t tid;
 void *result;
 int res;
 printf("enter number of subject ");
 scanf("%d",&number);
 pthread_create (&tid , NULL , averageMarks , (void *)&number );
 pthread_join ( tid , (void **)&res );
 printf("%d\n",res);
 return 0;
}
