#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
	if (mkfifo("myfifo1", 0777) == -1) {
		if (errno != EEXIST) {
			printf("Could not create FIFO file\n");
			return 1;
		}
	}
	return 0;
}
