#include <stdio.h>
#include "dylib.h"
#include <dlfcn.h>
#include <stdlib.h>
int main()
{
   int n;
   int a[n]; 
   printf("please input n:\n");
   scanf("%d",&n);
   init(a,n);
   show(a,n);
   printf("max=%d\n",max(a,n));
   printf("sum=%d\n",sum(a,n));
   return 0;
}
