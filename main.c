#include <stdio.h> 
#include <unistd.h> 
#include<sys/wait.h>
#include<stdlib.h>

void altamish(int a,int z)
{
    char cody[100];
    sprintf(cody,"From Child %d init n=%d,",z,a);
    printf("%s",cody);
    if(a>1 & a<40)
    {
        while(a>1)
        {
            if(a%2!=0)
            {
                a=(a*3)+1;
                sprintf(cody,"From Child %d n=%d,",z,a);
                printf("%s",cody);
            }
            else
            {
                a=a/2;
                sprintf(cody,"From Child %d n=%d,",z,a);
                printf("%s",cody);
            }
        }
        printf("\n");
    }
}


int main(int argc, char *argv[])
{
int A=atoi(argv[1]);
int pid1,pid2;

pid1=fork();

if(pid1==0)
{
    altamish(A,1);
}
else
{
    pid2=fork();
    if(pid2==0)
    {
        altamish(A+3,2);
    }
    else
    {
        wait(0);
        printf("children Completed\n");
    }
}


return 0;
}

