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
void vpush(Vector *v, void *data);
size_t vunshift(Vector *v, void *data);
void *vget(Vector *v, size_t index);
void *vset(Vector *v, size_t index, void *data);
void vfree(Vector *v);

#endif
