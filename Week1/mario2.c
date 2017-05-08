//this program scans in a height and prints two opposing # pyramids

#include<stdio.h>

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
                 for (column = 1; column <= (height + 2 + line); column++)
                 {
                         if ((column >= height + 1 - line) && (column <= height))
                         {
                                 printf("#");
                         }
			 if((column > height) && (column <= height +1))
			 {
			 	printf("  ");
			 }
		 	 if ((column > height +1) && (column <= (height + line +1)))
			 {
				
				for( int i =1; i <= line; i++)
			 	{	
					printf("#");
				}
			 }
			 if (column < height + 1 - line)		 
			 {
				printf(" ");
			 }
			 if (column >= height + line + 2)
			 {
				printf(" ");
			 }
		 }
	 printf("\n");
	 }
}
