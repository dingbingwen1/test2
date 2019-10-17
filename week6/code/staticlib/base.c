#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#define UNUMBER 5
void show(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%4d : %4d\n",i,a[i]);
}
void init(int *a)
{
    int i;
	int n=5;
    srand((int)time(0));
    for(i=0;i<n;i++)
		a[i]=1+(int)(100.0*rand()/(RAND_MAX+1.0));
}
	
			
