#include <stdio.h>
#include <stdlib.h>
#include "dylib.h"
#include <dlfcn.h>
int main(){
	void *hd;
	void(*f1)();
	char *error;
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
	f1();	
	 if(dlclose(hd)<0){
    fprintf(stderr,"%s\n",dlerror());
        exit(1);
   }
	return 0;

}
