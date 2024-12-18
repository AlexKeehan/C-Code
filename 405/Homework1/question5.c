#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int pid = fork();

	if (pid == 0)
	{
		int wc = wait(NULL);
		printf("Child. Wait = %d\n", wc);
	}
	else
	{
		//int wc = wait(NULL);
		//printf("Parent. Wait = %d\n", wc);
		printf("Parent pid = %d\n", pid);
	}
	return 0;
}
