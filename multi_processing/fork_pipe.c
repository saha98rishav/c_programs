#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char* argv[]) {
	int arr[] = {1,2,3,4,1,2};
	int arrSize = sizeof(arr) / sizeof(int);
	int start, end;

	int fd[2]; // file descriptor
	if (pipe(fd) == -1) // pipe the file descriptor; fd[0] -> read, fd[1] -> write
		return 1;

	int id = fork(); // fork a child process
	if (id == -1)
		return 2;

	if (id == 0) {
		// child process
		start = 0;
		end = arrSize / 2;
	} else {
		// parent process
		start = arrSize / 2;
		end = arrSize;
	}

	// calculate the partial sums
	int sum = 0, i;
	for (i = start; i < end; i += 1)
		sum += arr[i];

	printf("Partial sum: %d\n",sum);

	if (id == 0) {
		// child process
		// write sum from child process to file descriptor
		close(fd[0]);
		if (write(fd[1], &sum, sizeof(int)) == -1)
			return 3;
		close(fd[1]);
	} else {
		// parent process
		// read from file descriptor and calculate total sum
		int sumFromChild;
		close(fd[1]);
		if (read(fd[0], &sumFromChild, sizeof(int)) == -1)
			return 4;
		close(fd[0]);

		int totalSum = sumFromChild + sum;
		printf("Total sum is %d\n", totalSum);
		wait(NULL);
	}

	return 0;
}
