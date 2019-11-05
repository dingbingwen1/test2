#include "my.h"

int main()
{
	char *arg[]={"./test","123","abc","hello","ncu","edu",NULL};
	int ret;
	printf("call1:pid=%d,ppid=%d\n",getpid(),getppid());
	ret=execvp("./test2",arg);	
	printf("after calling! ret=%d\n",ret);
	return 0;	
}
