#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    char Dirname[50];
    char Fname[20];
    char Arr[10];
    DIR *dp = NULL;
    struct dirent  *entry = NULL;
    int fd = 0, ret= 0;

    if (argc != 2)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    fd = creat(argv[1],0777);
    if (fd != -1)
    {
        printf("New file gets created\n",Fname);
    }
    
    printf("--------------------------------------------------\n");

    printf("Entry name of directory : \n");
    scanf("%s",Dirname);

    dp =opendir(Dirname);
    if (dp == NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    }


    while ((entry = readdir(dp)) !=NULL)
    {
        if ((strcmp(argv[2], entry->d_name)) == 0)
        {
            lseek(fd,atoi(argv[2]),0);

            ret = read(fd,Arr,10);

            printf("Data from file is \n");
            write(1,Arr,ret);
        
        }
        
    }

    if (entry == NULL)
    {
        printf("There is no such file\n");
        return -1;
    }

    closedir(dp);
    
    
    
    return 0;
}