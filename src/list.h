#ifndef CDS_LIST
#define CDS_LIST

#include <stdio.h>

typedef struct {
	void *next;
	void *prev;
} ListEntryHeader;

typedef struct {
	size_t member;
	size_t length;
	ListEntryHeader *start;
	ListEntryHeader *end;
} List;

void linit(List *l, size_t member);
void lpush(List *l, void *data);
void lunshift(List *l, void *data);
void leach(List *l, void (*handler)(size_t i, void *data));

#endif
