#include<stdio.h>
#include<pthread.h>
long var=10;
void *f2(void *arg);
void *f1(void *arg);
pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m1=PTHREAD_MUTEX_INITIALIZER;
int main()
{
 pthread_t t1,t2;
 printf("Parent Thread starts\n"); 
 pthread_create(&t1,NULL,f1,NULL);
 pthread_create(&t2,NULL,f2,NULL);
 pthread_join(t1,NULL);
 pthread_join(t2,NULL);
 printf("Final value of var=%ld\n",var);
 printf("Parent Thread Ends\n"); 
}
void *f1(void *arg)
{
  long i;
pthread_mutex_lock(&m);
  printf("Thread-1\n");
  for(i=0;i<1000;i++){
    
     var=var+1;
  
  }
 pthread_mutex_unlock(&m);
  pthread_exit(NULL);//return NULL;
}
void *f2(void *arg)
{
  long i;
 pthread_mutex_lock(&m1);
  printf("Thread-2\n");
  for(i=0;i<1000;i++){
   
     var=var-1;
    
  }
pthread_mutex_unlock(&m1);
  pthread_exit(NULL);//return NULL;
}
