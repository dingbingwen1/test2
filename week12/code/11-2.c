#include "my.h"
int count=0;
int main(){
	pid_t p1,p2,p3;
	int r_num,i,sum;
	int pipefd1[2];
	int pipefd2[2];
	int buf[4097];
	if(pipe(pipefd1)<0)
	{
		perror("pipe1 failed!\n");
		return -1;
	}
	if(pipe(pipefd2)<0)
	{
		perror("pipe2 failed!\n");
		return -1;	
	}
	p1=fork();
	if(p1<0)
	{
		perror("fork failed!\n");
		return -1;
	}
	else if(p1==0)
	{
		count+=1;
		printf("child1 pid=%d,pidd=%d,count=%d\n",getpid(),getppid(),count);
		for(i=0;i<4097;i++)
		buf[i]=i;
		close(pipefd1[0]);
		write(pipefd1[1],buf,sizeof(buf));
		close(pipefd1[1]);
		exit(99);
	}
	else
	{
		p2=fork();
		if(p2<0)
		{
			perror("fork2 failed\n");
			return -1;
		}
		else if(p2==0)
		{
			count+=1;
			printf("child2 pid=%d,pidd=%d,count=%d\n",getpid(),getppid(),count);
			close(pipefd1[1]);
			r_num=read(pipefd1[0],buf,sizeof(buf));
			for(i=0;i<4097;i++)
			printf("%d\n",buf[i]);
			close(pipefd1[0]);

			close(pipefd2[0]);
			write(pipefd2[1],buf,sizeof(buf));
			close(pipefd2[1]);
			exit(34);
		}
		else
		{
			p3=fork();
			if(p3<0)
			{
				perror("fork failed\n");
				return -1;	
			}
			else if(p3==0)
			{
				count+=1;
				printf("child3 pid=%d,pidd=%d,count=%d\n",getpid(),getppid(),count);
				close(pipefd2[1]);
				if((r_num=read(pipefd2[0],buf,sizeof(buf)))>0)
				{
					for(i=0;i<4097;i++)
						sum=sum+buf[i];	
				}
				printf("child3:sum=%d",sum);
				close(pipefd2[0]);
				return 0;
			}
		else{
				printf("parent waitting\n");
				sleep(5);
				printf("parent pid=%d,pidd=%d,count=%d\n",getpid(),getppid(),count);
				return 0;	
			}
		}
	}

}
