#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    char Buffer1[512];

    int iCnt = 0, iRet = 0, i = 0, fd1= 0, fd2 = 0, fd3= 0;
    int ret1 = 0, ret2 = 0, ret3= 0;
    int pid1,pid2,pid3;
    int status1,status2;

   ret1 = fork();
   if(ret1 == 0)
   {
        execl("./Process1","Demo.txt",NULL);
        return -1;
   }

    fd1 = open("Demo.txt",O_RDONLY);

    while((iRet = read(fd1,Buffer1,sizeof(Buffer1))) != 0)
    {
        for(i = 0; i < iRet ; i++)
        {
            if((Buffer1[i] >= 'a') && (Buffer1[i] <= 'z'))
            {
                iCnt++;
            }
        }
    }

    printf("Number of small characters are : %d\n",iCnt);

    close(fd1);

        wait(&status1);

    ret2 = fork();
    
    if(ret2 == 0)
   {
        execl("./Process2","hello.txt",NULL);
   }


    fd2 = open("hello.txt",O_RDONLY);

    while((iRet = read(fd1,Buffer1,sizeof(Buffer1))) != 0)
    {
        for(i = 0; i < iRet ; i++)
        {
            if((Buffer1[i] >= 'a') && (Buffer1[i] <= 'z'))
            {
                iCnt++;
            }
        }
    }

    printf("Number of small characters are : %d\n",iCnt);

    wait(&status2);

    close(fd2);
    
    ret3 = fork();
   if(ret3 == 0)
   {
        execl("./Process2","NULL",NULL);
   }
    
    return 0;
}