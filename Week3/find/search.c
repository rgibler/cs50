//test file for making search algorithm

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int value = 0;
	int max = sizeof(array)/sizeof(int);
	int min = 0;
	int mid = (min + max)/2;
	printf("Input value you wih to search for: ");
	scanf("%d", &value);
	printf("\n");
	if (value == array[mid])
	{
		 printf("value %d was found in the %d index of the array\n", value, mid+1);
		return 0;
	}
	else{
		do
		{
			if (value > array[mid])
			{
				min=mid;
				printf("New min is %d\n", min);
				mid = (min+max)/2;
			} 
			else if (value < array[mid])
			{
				max=mid;
				printf("new maximum is %d\n", max);
				mid= (min+max)/2;
			}
			else
			{
				printf("value %d is in the %d index of the array\n", value, mid+1);
				return 0;
			}
		}while(value != array[max]);	
	}
	printf("value %d was found in the %d index of the array\n", value, max);
}
