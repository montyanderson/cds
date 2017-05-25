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

void vpush(Vector *v, void *data) {
	size_t index = v->length++;

	if(v->container < v->length) {
		v->container *= 2;
		v->array = realloc(v->array, _vsize(v));
	}

	memcpy(v->array + (v->member * index), data, v->member);
}

size_t vunshift(Vector *v, void *data) {
	v->length++;

	if(v->container < v->length) {
		v->container *= 2;
		v->array = realloc(v->array, _vsize(v));
	}

	for(size_t i = v->length - 1; i > 0; i--) {
		memcpy(v->array + (v->member * i), v->array + (v->member * (i - 1)), v->member);
	}

	memcpy(v->array, data, v->member);

	return v->length;
}

size_t vinsert(Vector *v, size_t index, void *data) {
	v->length = index >= v->length ? index + 1 : v->length + 1;

	if(v->container < v->length) {
		v->container *= 2;
		v->array = realloc(v->array, _vsize(v));
	}

	for(size_t i = v->length - 1; i > index; i--) {
		memcpy(v->array + (v->member * i), v->array + (v->member * (i - 1)), v->member);
	}

	memcpy(v->array + (v->member * index), data, v->member);

	return v->length;
}

void *vget(Vector *v, size_t index) {
	return (index >= v->length) ? NULL : v->array + (v->member * index);
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
