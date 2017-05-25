#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void linit(List *l, size_t member) {
	l->member = member;
	l->length = 0;
	l->start = NULL;
	l->end = NULL;
}

void lpush(List *l, void *data) {
	ListEntryHeader *entry = malloc(sizeof(ListEntryHeader) + l->member);
	memcpy(entry + sizeof(ListEntryHeader), data, l->member);

	l->length++;

	entry->next = NULL;
	entry->prev = NULL;

	if(l->start == NULL) {
		l->start = entry;
		l->end = entry;
	} else {
		l->end->next = entry;
		entry->prev = l->end;
		l->end = entry;
	}
}

void lunshift(List *l, void *data) {
	ListEntryHeader *entry = malloc(sizeof(ListEntryHeader) + l->member);
	memcpy(entry + sizeof(ListEntryHeader), data, l->member);

	l->length++;

	entry->next = NULL;
	entry->prev = NULL;

	if(l->start == NULL) {
		l->start = entry;
		l->end = entry;
	} else {
		l->start->prev = entry;
		entry->next = l->start;
		l->start = entry;
	}
}

void leach(List *l, void (*handler)(size_t i, void *data)) {
	ListEntryHeader *node = l->start;

	for(size_t i = 0; node != NULL; i++) {
		handler(i, node + sizeof(ListEntryHeader));
		node = node->next;
	}
}
