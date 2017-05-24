#ifndef CDS_VECTOR
#define CDS_VECTOR

#include <stdio.h>

typedef struct {
	size_t member;
	size_t length;
	size_t container;
	void *array;
} Vector;

void vinit(Vector *v, size_t member);
ssize_t vpush(Vector *v, void *data);
void *vget(Vector *v, size_t index);
void *vset(Vector *v, size_t index, void *data);
void vfree(Vector *v);

#endif
