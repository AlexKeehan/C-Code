#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	int pid = fork();

	if (pid == 0)
	{
		printf("Hello\n");
	}
	else
	{
		sleep(1);
		printf("Goodbye\n");
	}



	return 0;
}
