#include <stdio.h>
#include <stdlib.h>

int main() {
	int *numbers;
	int size = 2;
	numbers = malloc( sizeof(int) * size);
	int input = 0, i = 0;

	do {
		if (i == size) {
			size += 2;
			numbers = realloc(numbers, sizeof(int) * size);
		}
		printf("Enter (-1 to quit): ");
		scanf("%d", &input);
		if (input != -1) {
			numbers[i] = input;
			i += 1;
		}
	} while (input != -1);

	int num_elements = i, total = 0;

	for (int j=0; j<num_elements; j+=1)
		total += numbers[j];

	printf("Average = %d\n", total/num_elements);

	free (numbers);
	return 0;
}
