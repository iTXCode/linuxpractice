#include<stdio.h>
#include<stdlib.h>

int main(){
  char *ret=getenv("PATH");
  printf("%s\n",ret);
  return 0;
}
