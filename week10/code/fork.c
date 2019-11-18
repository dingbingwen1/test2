#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h> 
int main(void)
{
	pid_t pid  = -1;
	FILE *fp=NULL;
	
	fp = fopen("1.txt","w+");

	pid = fork();
	if(pid < 0)
	{
		perror("fork");
		return -1;
	}
	else if(pid == 0)
	{
		const char*msg="world";
		printf("这里是子进程.\n");
		fwrite(msg,strlen(msg) , 1,fp);		
		//printf("pid = %d.\n", pid);	
		//printf("子进程中的父进程id = %d.\n", getppid());	
		//sleep(1);
	}
	else
	{
		
		const char*lr="hello";
		printf("这里是父进程.\n");	
		fwrite(lr,strlen(lr),1, fp);
		//printf("pid = %d.\n", pid);	
		//sleep(1);
	}
	//printf("这一句是否打印两次pid = %d.\n",getpid());
	
	return 0;
}
