/* This program encrypts a given message by iterating over a key word and 
* and shifting the letters of the message up in the aphabet based on the 
* ASCII values of the letters in the key word */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, char *argv[])
{

	char Key[20];
	char message[200];
	int lenM =0;
	int lenK =0;
	int tempKey=0;
	//prints error if more or less than 2 cmdline args
	if (argc != 2)
	{
	printf("missing or improper number of cmd line arguments\n");
		return 1;
	}
	else
	{

		//converting cmdline arg to an array of chars
		strcpy(Key, argv[1]);
		lenK=strlen(Key);
		for (int step = 0; step < lenK; step++)
		{
			Key[step]=tolower(Key[step]);
		}
		for (int k = 0; k< lenK; k++)
		{
			if ((Key[k] < 95) || (Key[k] > 122))
			{
				printf("Key must be a sequence of letters\n");
				return 1;
			}
		}
		printf("Enter message to be encrypted: ");
		fgets(message, sizeof(message), stdin);
		printf("key is %s message is %s", Key, message);
		printf("encrypted message is: ");
		for (int i =0,lenM = strlen(message); i<lenM;i++)
		{
			tempKey = Key[i%lenK];
//			printf("%d", tempKey);
			if ((message[i] + tempKey -97 > 'z') && (message[i] <= 'z'))
			{
				tempKey=tempKey - 97;
				printf("%c", (message[i] + tempKey - 26));
			}
			else if((message[i] + tempKey -97 > 'Z') && (message[i] <= 'Z'))
			{
				tempKey= tempKey - 97;
				printf("%c", (message[i] + tempKey -26));
			}
			else if((message[i] <= 'z') && (message[i] >= 'a') && ((message[i] + tempKey -97 <= 'z'))) 
			{
				tempKey = tempKey -97;
				printf("%c", message[i] + tempKey);
			}
			else if ((message[i] <= 'Z') && (message[i] >= 'A') && (message[i] + tempKey -97 <= 'Z'))
			{
				tempKey = tempKey - 97;
				printf("%c", message[i] + tempKey);
			}
			else
			{
				printf("%c", message[i]);
			}
		}
	}
	printf("\n");
	return 0;
}
