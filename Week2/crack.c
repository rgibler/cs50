/*Given a password hash this program attempts to determine that password
* which the hash was made from assuming the password is alphabetical and 
* no longer than 4 letters*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define _XOPEN_SOURCE

int main(int argc, char argv[])
{
//I dont understand how to approach this problem at all so I will skip ahead to week 3 and come back to this later
	char salt[3];
	if (argc != 2)
	{
		printf("Program usage is \"./crack hash\"");
		return 1;
	}

	
}
