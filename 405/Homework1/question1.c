#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	//Question one
	int x = 100;
	int pid = fork();
	if (pid == 0)
	{
		printf("Variable's value in the child: %d\n", ++x);
	}
	else
	{
		printf("Variable's value in the parent: %d\n", --x);
	}
	return 0;
}

