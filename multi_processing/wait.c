#include <stdio.h>
#include <unistd.h>

void wait();

int main() {
	int id = fork();
	int n;

	if (id == 0) {
		n = 1;
	} else {
		n = 6;
	}

	if (id != 0) {
		wait();
	}

	int i;
	for (i=n;i<n+5;i+=1){
		printf("%d ", i);
		fflush(stdout);
	}
	if (id != 0)
		printf("\n");
	return 0;
}
