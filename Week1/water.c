//Code asks for amount of time spet in shower and returns amount of water in bottles used

#include<stdio.h>

int main(void)
{
	int min, bottles;

	printf(" How many minutes do you spend in the shower?: ");
	scanf("%d", &min);
	bottles = (192 * min) / 16;
	printf("The number of bottles you used is %d\n", bottles);
}
