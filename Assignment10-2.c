#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


void * ThreadProc1(void *ptr)
{
  int i = 0;

  for(i = 1; i <= 500; i++)
  {
    printf("Thread with counter : %d\n",i);
  }
}

void * ThreadProc2(void *ptr)
{
  int i = 0;

  for(i = 1; i >= 500; i++)
  {
    printf("Thread with counter : %d\n",i);
  }
}

int main()
{
    pthread_t TID1;
    pthread_t TID2;
    int ret1 = 0;
    int ret2 =0;

    ret1 = pthread_create(&TID1,        
                          NULL,       
                          ThreadProc1,
                          NULL);      

    if(ret1 != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }

    printf("Thread is created with ID : %d\n",TID1);

    ret2 = pthread_create(&TID2,        
                          NULL,       
                          ThreadProc2,
                          NULL);      

    if(ret2 != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }

    printf("Thread is created with ID : %d\n",TID2);

    printf("End of main thread\n");
    return 0;
}