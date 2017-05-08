/*This program reads a given value stating what a customer owes
* and returns the smallest number coins that can be given in change */

#include<stdio.h>

int main(void)
{

	double owed;
	int counter = 0;
	int quarters =0;
	int dimes = 0;
	int nickels = 0;
	int pennies = 0;
	printf("How much change do you have?: ");
	scanf("%lf",&owed);
	printf("\n");
	owed = owed * 100;	
//	printf("%lf\n", owed);
		
	do
	{
//		if (owed >= 25)
//		{	
			while (owed >= 25)
			{
				owed = owed - 25;
				counter++;
				quarters++;
				printf("%.55f\n", owed);
			}
			
//		}
//		if ((owed < 0.25) && ( owed >= 0.1))
//		{
			while (owed >= 10)
			{
				owed = owed - 10;
				counter++;
				dimes++;
			 	printf("%.55f\n", owed);
			}
			
//		}
		while (owed >= 5)
		{
			owed = owed - 5;
			counter++;
			nickels++;
			 printf("%.55f\n", owed);
		}
		

		while (owed >= 1)
		{
			owed = owed - 1;
			counter++;
			pennies++;
			 printf("%.55f\n", owed);
		}
				
	}
	while(owed > 0);
/*		if (owed >= 0.25)
		{
			owed = owed -0.25;
			printf("%lf\n", owed);
			counter = counter +1;	
			printf("%d\n", counter);
		}
		else if ((owed < 0.25) && (owed >= 0.1))
		{
			owed = owed - 0.1;
			counter = counter +1;
		}
		else if ((owed < 0.1) && (owed >= 0.05))
		{
			owed = owed - 0.05;
			counter = counter + 1;
			
		}
		else if ((owed < 0.05) && (owed >= 0.01))
		{
			owed = owed - 0.01;
			counter = counter + 1;
		}
*/	

	printf("That is a few as %d coins\n", counter);
	printf("%.55f\n", owed);
	printf("That is %d quarters, %d dimes, %d nickels, and %d pennies.\n", quarters, dimes, nickels, pennies);
}
