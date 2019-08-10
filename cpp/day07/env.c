#include<stdio.h>
#include<unistd.h>                                                 
int main(int  argc,char* argv[]，char* env[]){           
    (void) argc;
    (void) argv;
    printf("argc:%d\n",argc);
    int i=0;                 
    for(;env[i]!=NULL;i++){
      printf("%s\n",env[i]);
    }                    
     return 0;       
   }            
