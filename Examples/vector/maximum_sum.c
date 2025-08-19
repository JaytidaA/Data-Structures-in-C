/*
 * maximum_sum.c
 * Example of Vectors solving the maximum sum subarray problem.
 * Author: https://github.com/JaytidaA/
 */

#include "vector/vector.h"
#include "vector/vector_utils.h"
#include <stdio.h>

void maximum_sum_subarray(Vector *v)
{
	int sum = *(int *) front(v);
	int maxsum = sum;
	int next;
	int start = 0, end = 0;
	for (int i = 1; i < size(v); i++) {
		next = *(int *) at_ptr(v, i);
		if (next > sum + next) {
			start = i;
			end = i;
			sum = next;
		} else {
			sum = sum + next;
		}

		if (maxsum < sum) {
			end = i;
			maxsum = sum;
		}
	}
	printf("The subarray with the maximum sum is: ");
	Vector temp = (Vector) { .arr = (v->arr + start), .elm_size = sizeof(int), .size = end - start + 1 };
	print_vector(&temp, int, "%d");
	printf("The maximum sum is: %d\n", maxsum);
}

int main(void)
{
	int num = 0;
	Vector *vec = new_vector(sizeof(int));

	printf("Enter a set of numbers (0 to stop): ");
	do {
		scanf("%d", &num);
		push_back(vec, int, num);
	} while (num != 0); 

	// Pop back the final zero which was pushed
	pop_back(vec);

	if (empty(vec)) {
		printf("Enter at least one number!\n");
		return 1;
	}

	maximum_sum_subarray(vec);

	delete_vector(vec);
	return 0;
}
