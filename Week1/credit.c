//This program tells the user what credit card provider a given card number is from and whether or not it is a valid number
//THIS PROGRAM IS BUGGED OUT!! KEEP GETTING WEIRD VALUES
#include<stdio.h>
#include<string.h>

int main(void)
{
	//introducing variables

	long long cnumber=0;
	char cstring[17];
	int length=0;
	int sum=0;
	int temp_val=0;
	char temp_str[3];
	int i;

	//assigning credit card number to string for manipulation

	printf("Input credit card number without hyphens or spaces: ");
	scanf("%lld", &cnumber);
	sprintf(cstring, "%lld", cnumber);
	length = strlen(cstring);
	printf("The credit card number is %s, with a length of %d\n", cstring, length);
	
	i = length -2;
	do 
	{
		temp_val =(cstring[i]-48) * 2 + temp_val;
		if (((cstring[i]-48) *2) >= 10)
		{
			sprintf(temp_str, "%d", ((cstring[i])-48)*2);
			for(int j; j<2;j++)
			{
				temp_val= temp_str[j]-48 + temp_val;
//				temp_val= temp_val - ((cstring[i])-48)*2;
				printf("%d--%d\n", temp_str[j]-48, temp_val);
			}
			
		}	
		printf("%d--%d\n", cstring[i]-48, temp_val);
		i=i-2;
	}while(i>0);
//	for (int k = length; k > 0; k=k-2)
//	{
//		temp_val = cstring[k] -48 + temp_val;
//	}
//	if ( temp_val % 10 == 0)
//	{
//		printf("Card number is valid\n");
//	}
//	else
//	{
//		printf("Invalid Card number\n");
//	}
}

