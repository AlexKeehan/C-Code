#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
	int pid = fork();
	if (pid == 0)
	{
		char *args[2];
		args[0] = "/bin/ls";
		args[1] = NULL;
		execv(args[0], args);
		//execvp(args[0], args);
	}
	else
	{
		int wc = wait(NULL);
	}
	return 0;
}
