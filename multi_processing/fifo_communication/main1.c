#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char* argv[]) {
	srand(time(NULL));
	int arr[5];
	int i;

	for (i = 0; i < 5; i+=1) {
		int x = rand() % 10;
		printf("Generated: %d\n",x);
		arr[i] = x;
	}

	int fd = open("sum", O_WRONLY);
	if (fd == -1) {
		printf("Error in opening FIFO!\n");
		return 1;
	}

	if (write(fd, arr, sizeof(int) * 5) == 1) {
		printf("Error in writing to FIFO!\n");
		return 2;
	}

	close(fd);

	return 0;
}
