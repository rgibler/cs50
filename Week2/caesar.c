/* This program encrypts a user inputted message by shifting
* each letter in the message by a user selected number of
* spaces in the alphabet */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{

	int Key=0;
	char message[200];
	int len =0;
	
	//prints error if more or less than 2 cmdline args
	if (argc != 2)
	{
	printf("missing or improper number of cmd line arguments\n");
		return 1;
	}

	else
	{

		//converting cmdline arg to an int and storing message
		Key=atoi(argv[1]);
		printf("Enter message to be encrypted: ");
		fgets(message, sizeof(message), stdin);
		printf("key is %d, message is %s", Key, message);
		printf("encrypted message is: ");
		for (int i =0,len = strlen(message); i<len;i++)
		{
			if ((message[i] + Key > 'z') && (message[i] <= 'z'))
			{
				printf("%c", (message[i] + Key -26));
			}
			else if((message[i] + Key > 'Z') && (message[i] <= 'Z'))
			{
				printf("%c", (message[i] + Key -26));
			}
			else if((message[i] <= 'z') && (message[i] >= 'a') && ((message[i] + Key <= 'z'))) 
			{
				printf("%c", message[i] + Key);
			}
			else if ((message[i] <= 'Z') && (message[i] >= 'A') && (message[i] + Key <= 'Z'))
			{
				printf("%c", message[i] + Key);
			}
			else
			{
				printf("%c", message[i]);
			}
		}
	}
	printf("\n");
}
