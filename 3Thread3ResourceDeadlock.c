// It will show all three processes have locked all three resources.
// Compile :- gcc -pthread 3Thread3Resource.c -o 3Thread3Resource.c
// Run :- ./3Thread3Resource

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

void *function1() ; // function declaration of first thread
void *function2() ; // function declaration of second thread
void *function3() ; // function declaration of third thread 

pthread_mutex_t first_mutex ;  // first mutex variable declaration
pthread_mutex_t second_mutex ; // second mutex variable declaration
pthread_mutex_t third_mutex ;  // third mutex variable declaration

int main()
{

	pthread_mutex_init ( &first_mutex  , NULL  ) ; //initializing the variable to default attribute
	pthread_mutex_init ( &second_mutex  ,NULL  ) ; //initializing the variable to default attribute
	pthread_mutex_init ( &third_mutex  , NULL  ) ; //initializing the variable to default attribute 

	pthread_t one, two, three ; //thread declaration

	pthread_create (&one,   NULL, function1, NULL) ; // creating thread one
	pthread_create (&two,   NULL, function2, NULL) ; // creating thread two
	pthread_create (&three, NULL, function3, NULL) ; // creating thread three


	pthread_join (one ,  NULL) ;
	pthread_join (two ,  NULL) ;
	pthread_join (three ,NULL) ;

	printf("Thread joined\n");
}

void *function1() 
{

	pthread_mutex_lock(&first_mutex); // to acquire the lock on first resource
	printf("Thread 1 acquired first_mutex\n");
	sleep(1);
	
	pthread_mutex_lock(&second_mutex); // to acquire the lock on second resource
	printf("Thread 1 acquired second_mutex\n");
	
	pthread_mutex_lock(&third_mutex); // to acquire the lock on third resource
	printf("Thread 1 acquired second_mutex\n");
	
	pthread_mutex_unlock(&third_mutex); // to release the resource/mutex lock
	printf("Thread 1 released third_mutex\n");
	
	pthread_mutex_unlock(&second_mutex); // to release the resource/mutex lock
	printf("Thread 1 released second_mutex\n");
	
	pthread_mutex_unlock(&first_mutex); // to release the resource/mutex lock
	printf("Thread 1 released first_mutex\n");
	
}

void *function2() {

	pthread_mutex_lock(&second_mutex);
	printf("Thread 2 acquired second_mutex\n");// to acquire the lock on second resource
	sleep(1);

	pthread_mutex_lock(&third_mutex);
	printf("Thread 2 acquired third_mutex\n"); // to acquire the lock on third resource

	pthread_mutex_lock(&first_mutex);
	printf("Thread 2 acquired first_mutex\n"); // to acquire the lock on first resource

	pthread_mutex_unlock(&first_mutex); // to release the resource/mutex lock
	printf("Thread 2 released first_mutex\n");

	pthread_mutex_unlock(&third_mutex);
	printf("Thread 2 acquired third_mutex\n"); // to release the resource/mutex lock

	pthread_mutex_unlock(&second_mutex); // to release the resource/mutex lock
	printf("Thread 2 released second_mutex\n");
}

void *function3() 
{

	pthread_mutex_lock (&third_mutex);
	printf("Thread 3 acquired third_mutex\n");// to acquire the lock on third resource
	sleep(1);

	pthread_mutex_lock (&first_mutex);
	printf("Thread 3 acquired first_mutex\n"); // to acquire the lock on first resource
	
	pthread_mutex_lock (&second_mutex);
	printf("Thread 3 acquired second_mutex\n"); // to acquire the lock on second resource
	
	
	pthread_mutex_unlock(&second_mutex); // to release the resource/mutex lock
	printf("Thread 3 released second_mutex\n");

	pthread_mutex_unlock(&first_mutex); // to release the resource/mutex lock
	printf("Thread 3 released first_mutex\n");
	
	
	pthread_mutex_unlock(&third_mutex); // to release the resource/mutex lock
	printf("Thread 3 released third_mutex\n");


}
