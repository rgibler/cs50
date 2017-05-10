
//This program takes a user's inputted full name and returns
//capitalized initials

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(void)
{
	//sets max possible length of name as 100 characters
	char name[100];
	int length=0;
	

	printf("Input full name: ");
//fgets is a function that allows me to scan in the username
//from terminal with spaces
	fgets(name, sizeof(name), stdin);
//makes first letter uppercase if not allready and prints it
	printf("%c", toupper(name[0]));
// looping through word to find the letters that follow spaces
	for (int i = 0, length = strlen(name); i < length; i++)
	{
		if (name[i-1] ==' ')
		{ 
			printf("%c", toupper(name[i]));
		}
	}
	printf("\n");
}
