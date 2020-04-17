// Average Marks Calculation Using Threads
// Compile -> gcc -pthread "AverageMarks-Question2.c" -o "AverageMarks-Question2"
// Run -> ./"AverageMarks-Question2"


#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>

int marks[5] ;

void *averageMarks_Thread(void *mark)
{
    int *marks_array ;
    marks_array = mark ;

    int marks1, marks2, marks3, marks4, marks5;
    float sum = 0 ;
    float average ;
    marks1 = marks_array[0] ;
    marks2 = marks_array[1] ;
    marks3 = marks_array[2] ;
    marks4 = marks_array[3] ;
    marks5 = marks_array[4] ;
    sum = marks1 + marks2 + marks3 + marks4 + marks5 ;
    average = sum / 5 ;
    printf("Total Marks = %.1f\n",sum);
    printf("The average marks is %.1f\n",  average);

    return NULL;
}

int main() 
{
    printf("Please enter the marks of Subject1 :- ");
    scanf("%d",&marks[0]);

    printf("Please enter the marks of Subject2 :- ");
    scanf("%d",&marks[1]);

    printf("Please enter the marks of Subject3 :- ");
    scanf("%d",&marks[2]); 

    printf("Please enter the marks of Subject4 :- ");
    scanf("%d",&marks[3]); 

    printf("Please enter the marks of Subject5 :- ");
    scanf("%d",&marks[4]);
    
    pthread_t avgMarks;
    pthread_create ( &avgMarks , NULL , averageMarks_Thread , marks ) ;
    pthread_join ( avgMarks , NULL ) ;

    return 0;
}
