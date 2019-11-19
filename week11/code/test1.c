#include <my.h>

int main()
{
	int pid;
	if(pid=fork()<0)
	{
		perror("failes to fork!\n");
		return -1;
	}
	else if(pid=0)
	{
		printf("child exit now.\n");
		exit(0);	
	}
	else{
		while(1);	
	}
	exit(0);
}
