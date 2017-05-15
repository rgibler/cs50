//this is a test for the sorting algorithm in helpers.c

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int values[] = {5 , 4, 8, 9, 2, 1, 3, 7, 6};
	int n = sizeof(values)/sizeof(values[0]);
	printf("%d\n\n", n);
	int i = 0;
	for (i=0;i<n;i++)
	{
		printf("%d\n", values[i]);
	}

	printf("\n \n");
		for (int m=0; m<n; m++)
		{
			for (int j =0; j < n-1; j++)
                	{	
//	                        printf("%d---%d\n", values[j], values[j+1]);

				if (values[j] > values[j+1])
                        	{
                                	int min = values[j+1];
                                	values[j+1]= values[j];
					values[j]= min;
                        	}
				else if (values[j] < values[j+1])
				{
					printf("%d***%d\n", values[j], values[j+1]);
				}
				
			printf("\n");
                 	}
		printf("\n");
		m++;
		}
		printf("\n \n");
	for (int k = 0; k < n; k++)
	{
		printf("%d\n", values[k]);
	}
}
