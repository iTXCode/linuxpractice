#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(){
  char *result =getenv("PATH");
  printf("%s\n",result);
  return 0;
}
