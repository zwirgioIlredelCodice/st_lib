#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "st_vec.h"

void print_vec(st_vec *vec) {
	printf("capacity = %d, size = %d\n", vec->capacity, vec->size);
	for (int i = 0; i < vec->size; i++) {
		int output;
		st_vec_get(vec, i, &output);
		printf("%d ", output);
	}
	printf("\n");
}

int main() {
	srand(time(NULL));

	int iterations = 20;
	st_vec *vec = st_vec_create(sizeof(int));

	for (int i = 0; i < iterations; i++) {
		int num = rand() % 10;
		st_vec_append(vec, &num);
	}

	print_vec(vec);

	int num = 666;
	st_vec_insert(vec, &num, 2);
	print_vec(vec);
	st_vec_delete(vec, 2);
	print_vec(vec);

	for(int i = 0; i < 20; i++) {
		st_vec_pop(vec);
		printf("capacity = %d size = %d\n", vec->capacity, vec->size);
	}
	print_vec(vec);

	st_vec_dispose(vec);
}