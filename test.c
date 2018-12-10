#include<stdio.h>

int main()
{
int i=0;
int j=0;
int a[10]={0};
int tmp=0;
printf("pelase enter 10 number:");
for(i=0;i<10;i++)
{
scanf("%d",a[i]);
}
for(i=0;i<9;i++)
{
for(j=0;j<9-i;j++)
{
if(a[j]>a[j+1])
{
tmp=a[j];
a[j]=a[j+1];
a[j+1]=tmp;
}
}
}
for(i=0;i<10;i++)
{
printf("%d ",a[i]);
}
return 0;
}
