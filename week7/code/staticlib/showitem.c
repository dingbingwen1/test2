#include <stdio.h>
#include "mylib.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <syslog.h>
#include <sys/stat.h>
#define MAX 10
void show(){
	int a=0;
	int i;
	int buf[MAX]={0};
	int buffer[MAX]={0};
	FILE *file=NULL;
	int n;
	while(1){
	printf("********************\n");
	printf("0.退出\n");
    printf("1.创建新文件\n");
	printf("2.写文件\n");
	printf("3.读文件\n");
	printf("4.修改文件权限\n");
	printf("5.查看当前的文件权限 修改文件权限\n");
	printf("********************\n");
	printf("please input your choice(0-5):\n");
	scanf("%d",&n);
	if(n==0){
     exit(0);
    }
	 if(n==1){
     file=fopen("./test.txt","w+");
		if(file==NULL){
			printf("failed to open file!\n");
			exit(0);		
		}
		else{
		printf("success!\n");
	}
	fclose(file);
    }
    if(n==2){
		if((file=fopen("./test.txt","r+"))==NULL){
			printf("failed to open file!\n");
			exit(0);
		}
		else{
		printf("success!\n");
		printf("please input message:\n");
		do{
			scanf("%d",&buf[a++]);
	    }while(getchar()!='\n');
	}
	fwrite(buf,sizeof(int),a+1,file);
	fclose(file);
	}
	if(n==3){
		if((file=fopen("./test.txt","r+"))==NULL){
			printf("failed to open file!\n");
			exit(0);
		}
		else{
			printf("success!\n");
			fread(buffer,sizeof(int),a+1,file);
			for(i=0;i<a;i++){
			printf("%d\n",buffer[i]);
            }
		}
	fclose(file);
	}
	if(n==4){
	change();
    }
	if(n==5){
	if(access("./test.txt",R_OK)==0)
		printf("./test.txt can be read\n");
	else{
	printf("./test.txt can not be read!\n");
    }
	if(access("./test.txt",W_OK)==0){
		printf("./test.txt can be write\n");	
	}
	else{
	printf("./test.txt can not be write\n");	
	}
	if(access("./test.txt",X_OK)==0){
	printf("./test.txt can be exec\n");
    }
	else{
	printf("./test.txt can not be exec\n");
	}
    }
}
}
