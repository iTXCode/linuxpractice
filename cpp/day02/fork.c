#include<stdio.h>

#include<unistd.h>
int main(){
  int i=0;
  for(;i<2;i++){
            pid_t ret=fork();
            if(ret>0){
                  printf("%c",'=');
                      
            }else if(ret==0){
                  printf("%c",'=');
                        
            }else{
                    perror("fork");
                        
            }    
         printf("\n"); 
                
  } 
  return 0;
}
