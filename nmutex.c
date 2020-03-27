#include<stdio.h>
#include<pthread.h>
long var=10;
void *f2(void *arg);
void *f1(void *arg);
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
  for(i=0;i<10000000;i++){
     var=var+1;
  }
  pthread_exit(NULL);//return NULL;
}
void *f2(void *arg)
{
  long i;
  for(i=0;i<10000000;i++){
     var=var-1;
  }
  pthread_exit(NULL);//return NULL;
}
