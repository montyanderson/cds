#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

#define _vsize(v) ((v)->container * (v)->member)

void vinit(Vector *v, size_t member) {
	v->member = member;
	v->length = 0;
	v->container = 1;
	v->array = malloc(_vsize(v));
}

ssize_t vpush(Vector *v, void *data) {
	size_t index = v->length++;

	if(v->container < v->length) {
		v->container *= 2;
		v->array = realloc(v->array, _vsize(v));
	}

	memcpy(v->array + (v->member * index), data, v->member);

	return (v->array == NULL) ? -1 : index;
}

void *vget(Vector *v, size_t index) {
	if(index >= v->length) {
		return NULL;
	} else {
		return v->array + (v->member * index);
	}
}

void *vset(Vector *v, size_t index, void *data) {
	if(index >= v->length) {
		v->length = index + 1;

		while(v->container < v->length) {
			v->container *= 2;
		}

		if((v->array = realloc(v->array, _vsize(v))) == NULL) {
			return NULL;
		}
	}

	void *element = v->array + (v->member * index);
	memcpy(element, data, v->member);

	return element;
}

void vfree(Vector *v) {
	v->member = 0;
	v->length = 0;
	v->container = 0;
	free(v->array);
	v->array = NULL;
}
