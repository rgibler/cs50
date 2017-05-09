//this program scans in a height and prints two opposing "#" pyramids separated by two spaces

#include<stdio.h>

int main(void)
 {
         int height = -1;
         int line, column;
	 int i =1; 
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
			 else if((column > height) && (column <= height +1))
			 {
			 	printf("  ");
			 }
		 	 if ((column > height +1) && (column <= (height + line +1)))
			 {
				
				do	
			 	{	
					printf("#");
					i++;
				}
				while(i<=line);
			 }
			 if (column < height + 1 - line)		 
			 {
				printf(" ");
			 }
		 }
	 printf("\n");
	 }
}
