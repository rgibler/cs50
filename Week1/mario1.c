#include<stdio.h>

// this program creates a right aligned pyramid with a user defined height

int main(void)
{
	int height = -1;
	int line, column;

	while ( height <= -1 || height >= 24 )
	{
		printf("Enter a height for the pyramid: ");
		scanf("%d", &height);
		printf("\n");
	}

	for (line = 1; line <= height; line++)
	{
		for (column = 1; column <= height; column++)
		{
			if (column == height + 1 - line)
			{
				printf("#");
			}
			if (column >= height +1 - line)
			{
				printf("#");
			}
			else
			{
				printf(" ");
			}
		}
	printf("\n");
	}
}

