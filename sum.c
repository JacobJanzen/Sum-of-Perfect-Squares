#include <stdio.h>


void printOutput(int input, int i, int j, int k)
{
	if(j == 0 && k == 0) // if input is already a perfect square
		printf("%d = %d\n", input, i);
	else if(k == 0) // if it only requires two perfect squares
		printf("%d = %d + %d\n", input, i, j);
	else
		printf("%d = %d + %d + %d\n", input, i, j, k);
}

#define MAX_LINE 100
int main(void)
{
	int input, notFound = 1;

	// get input
	printf("Enter an integer: ");
	char line[MAX_LINE];
	fgets(line, MAX_LINE, stdin);
	sscanf(line, "%d", &input);

	//exit if invalid entry is given
	if(input<=0)
	{
		printf("Enter a positive number");
		return 1;
	}

	//iterate through every possible option
	for(int i = 1; i*i <= input && notFound; i++)
	{
		for(int j = 0; j <= i && notFound; j++)
		{
			for(int k = 0; k <= j && notFound; k++)
			{
				if(i*i+j*j+k*k==input)
				{
					printOutput(input, i*i, j*j, k*k);
					notFound = 0;
				}
			}
		}
	}

	// print out failure message
	if(notFound)
		printf("No three perfect squares add up to %d.\n", input);

	return 0;
}
