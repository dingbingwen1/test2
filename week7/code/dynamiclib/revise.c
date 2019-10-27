#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <syslog.h>
#include <sys/stat.h>

int change(){
    int n;
	mode_t mode=S_IWUSR;
	printf("1.change to only read\n");
	printf("2.change to only write\n");
	printf("3.change to only exec\n");
	printf("4.change to read and write and exec\n");
	printf("please input tour choice(1-4):\n");
	scanf("%d",&n);
	if(n==1){
	chmod("./test.txt",S_IRUSR);
	}
	if(n==2){
	chmod("./test.txt",S_IWUSR);
	}
	if(n==3){
	chmod("./test.txt",S_IXUSR);	
	}
	if(n==4){
	chmod("./test.txt",S_IRWXU);	
	}
	return 0;
}
