#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define INITIAL_CAPACITY 10
#define GROWING_FACTOR 2

typedef struct st_vec {
	size_t items_size;
	size_t capacity; 	//number of items thata st_vec can store
	size_t size;		//number of items stored in st_vec
	void *items;
} st_vec;

st_vec *st_vec_create(size_t items_size) {
	st_vec * vec = malloc(sizeof(st_vec));
	vec->items_size = items_size;
	vec->capacity  = INITIAL_CAPACITY;
	vec->size      = 0;
	vec->items     = malloc(items_size * INITIAL_CAPACITY);
	return vec;
}

void st_vec_get(st_vec *vec, size_t index, void *output) {
	assert(index < vec->size);
	size_t index_memory = index * vec->items_size;
	memcpy(output, vec->items + index_memory, vec->items_size);
}

void st_vec_set(st_vec *vec, size_t index, const void *input) {
	assert(index < vec->size);
	size_t index_memory = index * vec->items_size;
	memcpy(vec->items + index_memory, input, vec->items_size);
}

void st_vec_append(st_vec *vec, const void *input) {
	if (vec->size == vec->capacity - 1) {
		vec->capacity *= GROWING_FACTOR;
		vec->items     = realloc(vec->items, vec->capacity * vec->items_size);
	}
	vec->size += 1;
	st_vec_set(vec, vec->size - 1, input);
}

void st_vec_pop(st_vec *vec) {
	assert(vec->size > 0);
	vec->size -= 1;
	if ((vec->size <= vec->capacity / GROWING_FACTOR) && (vec->capacity / GROWING_FACTOR >= INITIAL_CAPACITY)) {
		vec->capacity /= GROWING_FACTOR;
		vec->items     = realloc(vec->items, vec->capacity * vec->items_size);
	}
}

/*
* crash if try to insert element index greather than size
*/
void st_vec_insert(st_vec *vec, const void *input, size_t index) {
	assert(index <= vec->size + 1 && index >= 0);

	if (vec->size == vec->capacity - 1) {
		vec->capacity *= GROWING_FACTOR;
		vec->items     = realloc(vec->items, vec->capacity * vec->items_size);
	}
	memmove(vec->items + (
		vec->items_size * (index + 1)), 
		vec->items + (vec->items_size * index), 
		vec->items_size * (vec->size - index)
	); // move element after index by one for making space for the insertion

	vec->size += 1;
	st_vec_set(vec, index, input);
}

void st_vec_delete(st_vec *vec, size_t index) {
	assert(vec->size > 0);
	assert(index <= vec->size && index >= 0);

	vec->size -= 1;
	if ((vec->size <= vec->capacity / GROWING_FACTOR) && (vec->capacity / GROWING_FACTOR >= INITIAL_CAPACITY)) {
		vec->capacity /= GROWING_FACTOR;
		vec->items     = realloc(vec->items, vec->capacity * vec->items_size);
	}
	memmove(
		vec->items + (vec->items_size * (index)), 
		vec->items + (vec->items_size * (index + 1)), 
		vec->items_size * (vec->size - index)
	); // move element after index by one to left to fill delete value space

}

void st_vec_dispose(st_vec *vec) {
	free(vec->items);
	free(vec);
}
