// It will show all three processes have locked all three resources.
// Compile :- gcc -pthread 3Thread3Resource.c -o 3Thread3Resource.c
// Run :- ./3Thread3Resource

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

void *function1() ; // 1st thread function
void *function2() ; // 2nd thread function
void *function3() ; // 3rd thread function

pthread_mutex_t first_mutex ;  // 1 thread mutex variable
pthread_mutex_t second_mutex ; // 2 thread mutex variable
pthread_mutex_t third_mutex ;  // 3 thread mutex variable

int main()
{

	pthread_mutex_init ( &first_mutex  , NULL  ) ;
	pthread_mutex_init ( &second_mutex  ,NULL  ) ; 
	pthread_mutex_init ( &third_mutex  , NULL  ) ; 

	pthread_t one, two, three ; //thread declaration

	pthread_create (&one,   NULL, function1, NULL) ; 
	pthread_create (&two,   NULL, function2, NULL) ; 
	pthread_create (&three, NULL, function3, NULL) ; 


	pthread_join (one ,  NULL) ;
	pthread_join (two ,  NULL) ;
	pthread_join (three ,NULL) ;

	printf("Thread joined\n");
}

void *function1() 
{

	pthread_mutex_lock(&first_mutex); // acquiring the lock on first resource
	printf("Thread 1 acquired first_mutex\n");
	sleep(1);
	
	pthread_mutex_lock(&second_mutex); // acquiring the lock on second resource
	printf("Thread 1 acquired second_mutex\n");
	
	pthread_mutex_lock(&third_mutex); // acquiring the lock on third resource
	printf("Thread 1 acquired second_mutex\n");
	
	pthread_mutex_unlock(&third_mutex); // release the resource/mutex lock from 3rd resource
	printf("Thread 1 released third_mutex\n");
	
	pthread_mutex_unlock(&second_mutex); // release the resource/mutex lock from 2nd resource
	printf("Thread 1 released second_mutex\n");
	
	pthread_mutex_unlock(&first_mutex); // release the resource/mutex lock from 1st resource
	printf("Thread 1 released first_mutex\n");
	
}

void *function2() {

	pthread_mutex_lock(&second_mutex);
	printf("Thread 2 acquired second_mutex\n"); // acquiring the lock on second resource
	sleep(1);

	pthread_mutex_lock(&third_mutex);
	printf("Thread 2 acquired third_mutex\n"); // acquiring the lock on third resource

	pthread_mutex_lock(&first_mutex);
	printf("Thread 2 acquired first_mutex\n"); // acquiring the lock on first resource

	pthread_mutex_unlock(&first_mutex); // release the resource/mutex lock from 1st resource
	printf("Thread 2 released first_mutex\n");

	pthread_mutex_unlock(&third_mutex);
	printf("Thread 2 acquired third_mutex\n"); // release the resource/mutex lock from 3rd resource

	pthread_mutex_unlock(&second_mutex); // release the resource/mutex lock from 2nd resource
	printf("Thread 2 released second_mutex\n");
}

void *function3() 
{

	pthread_mutex_lock (&third_mutex);
	printf("Thread 3 acquired third_mutex\n"); // acquiring the lock on third resource
	sleep(1);

	pthread_mutex_lock (&first_mutex);
	printf("Thread 3 acquired first_mutex\n"); // acquiring the lock on first resource
	
	pthread_mutex_lock (&second_mutex);
	printf("Thread 3 acquired second_mutex\n"); // acquiring the lock on second resource
	
	
	pthread_mutex_unlock(&second_mutex); // release the resource/mutex lock from 2nd resource
	printf("Thread 3 released second_mutex\n");

	pthread_mutex_unlock(&first_mutex); // release the resource/mutex lock from 1st resource
	printf("Thread 3 released first_mutex\n");
	
	
	pthread_mutex_unlock(&third_mutex); // release the resource/mutex lock from 3rd resource
	printf("Thread 3 released third_mutex\n");


}
