#include<stdio.h>

int main()
{
	int i=0, j=0, num = 0;
	int arr[] = {11,44,33,22,55,66,88,9,100};
	int size = sizeof(arr)/ sizeof(arr[0]);
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0;j<size - i - 1;j=j+1)
		{
			if (arr[j]>arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				num++;
			}	
		}
	}
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("%d\n", num);
	return 0;
}
