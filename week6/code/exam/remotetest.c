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
   char *error;
   void *hd;
   void(*f1)();
   void(*f4)();
   int (*f2)(),(*f3)();
   hd=dlopen("../dynamiclib/libdylib.so",RTLD_LAZY);
   if(!hd){
        fprintf(stderr,"%s\n",dlerror());
        exit(1);
   }
   f1=dlsym(hd,"show");
   if((error=dlerror())!=NULL){
    fprintf(stderr,"%s\n",dlerror());
        exit(1);
   }
   f2=dlsym(hd,"max");
   if((error=dlerror())!=NULL){
    fprintf(stderr,"%s\n",dlerror());
        exit(1);
   }
   f3=dlsym(hd,"sum");
   if((error=dlerror())!=NULL){
    fprintf(stderr,"%s\n",dlerror());
        exit(1);
   }
   f4=dlsym(hd,"init");
   if((error=dlerror())!=NULL){
    fprintf(stderr,"%s\n",dlerror());
        exit(1);
   }
   f4(a,n);
   f1(a,n);
   printf("max=%d\n",f2(a,n));
   printf("sum=%d\n",f3(a,n));
   if(dlclose(hd)<0){
    fprintf(stderr,"%s\n",dlerror());
        exit(1);
   }

   return 0;
}
