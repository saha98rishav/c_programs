#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char* argv[]) {
	int arr[5], i, sum = 0;

	int fd = open("sum", O_RDONLY);
	if (fd == -1) {
		printf("Error in opening FIFO!\n");
		return 1;
	}

	if (read(fd, arr, sizeof(int) * 5) == -1) {
		printf("Error in reading from FIFO!\n");
		return 2;
	}

	close(fd);

	for (i = 0; i < 5; i+=1)
		sum += arr[i];

	printf("Summation of all the numbers are: %d\n", sum);
	return 0;
}
