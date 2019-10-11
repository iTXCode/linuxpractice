#include <stdio.h>
#include <string.h>
int main()
{
 FILE *fp = fopen("myfile", "w");  
    //myfile为目标文件，w为写操作
 if(!fp){
	 printf("fopen error!\n");
 }
 const char *msg = "hello bit!\n"; //书写的内容
 int count = 5;
 while(count--){
	 fwrite(msg, strlen(msg), 1, fp); 
 //size_t fwrite(const void *ptr, size_t size, size_t nmemb,
 //FILE *stream);
 }
 fclose(fp);
 return 0;
}
