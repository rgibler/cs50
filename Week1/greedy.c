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
		
	do
	{
		while (owed >= 25)
		{
			owed = owed - 25;
			counter++;
			quarters++;
		}
		while (owed >= 10)
		{
			owed = owed - 10;
			counter++;
			dimes++;
		}		
		while (owed >= 5)
		{
			owed = owed - 5;
			counter++;
			nickels++;
		}
		while (owed >= 1)
		{
			owed = owed - 1;
			counter++;
			pennies++;
		}
				
	}
	while(owed > 0);

	printf("That is a few as %d coins\n", counter);
	printf("%.55f\n", owed);
	printf("That is %d quarters, %d dimes, %d nickels, and %d pennies.\n", quarters, dimes, nickels, pennies);
}
