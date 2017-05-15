/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
//#include <cs50.h>
#include<stdio.h>
#include "helpers.h"
#include <stdbool.h>
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int needle, int haystack[], int size)
{
	int max = size;
        int min = 0;
        int mid = (min + max)/2;

        if (needle == haystack[mid])
        {
                return true;
        }
        else{
                do
                {
                        if (needle > haystack[mid])
                        {
                                min=mid;
                                printf("New min is %d\n", min);
                                mid = (min+max)/2;
                        }
                        else if (needle < haystack[mid])
                        {
                                max=mid;
                                printf("new maximum is %d\n", max);
                                mid= (min+max)/2;
                        }
                        else
                        {
                                printf("value %d is in the %d index of the array\n", needle, mid+1);
                                return true;
                        }
                }while(needle != haystack[max]);
        }
        return true;        
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
//        int values[] = {5 , 4, 8, 9, 2, 1, 3, 7, 6};
//       int n = sizeof(values)/sizeof(values[0]);
//        printf("%d\n\n", n);
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
//                              printf("%d---%d\n", values[j], values[j+1]);

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
                }
                printf("\n \n");
        for (int k = 0; k < n; k++)
        {
                printf("%d\n", values[k]);
        }
}
