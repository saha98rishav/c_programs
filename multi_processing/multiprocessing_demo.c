#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {
	int id=fork();
	if (id!=0) {
		fork();
	}
	printf("Hello world from id: %d\n",id);
	return 0;
}
