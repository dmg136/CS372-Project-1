#include <stdio.h>
#include <stdlib.h>

int factorial(int);

int main(int argc, char** argv)
{

	//only valid input is ./fact int
	if (argc == 1) {
		printf("Specified too few arguments: must put positive integer\n");
		return 1;
	}
	else if (argc > 2) {
		printf("Specified too many arguments: must only include 1 positive integer\n");
	}	

	char *error;

	//printf("argv[1]: %s\n", argv[1]);

	long int number = strtol(argv[1], &error, 10);

	//printf("number: %ld\n", number);
	//printf("error: %s\n", error);

	if (error == argv[1])
	{
		printf("Huh?\n");
		printf("Couldn't convert argument to number\n");
		return 0;
	}

	else if ('\0' != *error)
	{
		printf("Huh?\n");
		printf("Argument has stuff appended to number\n");
		return 0;
	}

	else if (number <= 0)
	{
		printf("Huh?\n");
		printf("Argument not non-zero integer\n");
		return 0;
	}

	else{
		printf("%d\n", factorial(number));
		return 1;
	}
		
}

//precond: var number is a positive, non-zero integer
int factorial(int number)
{
	if (number <= 1)
		return 1;
	else
		return number * factorial(number-1); 	
}
