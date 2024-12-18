#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int file = open("test.txt", O_RDWR);
	int pid = fork();
	int temp;
	char* c = (char*)calloc(100, sizeof(char));
	if (pid == 0)
	{
		printf("File descriptor in child process: %d\n", file);
		temp = write(file, "Child\n", strlen("Child\n"));
		temp = read(file, c, 20);
		printf("Child contents: %s\n", c);
	}
	else
	{
		printf("File descriptor in parent process: %d\n", file);
		temp = write(file, "Parent\n", strlen("Parent\n"));
		temp = read(file, c, 20);
		printf("Parent contents: %s\n", c);
	}

	return 0;
}
