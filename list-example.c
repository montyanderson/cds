#include <stdio.h>
#include "src/list.h"

struct User {
	char name[30];
	unsigned age;
};

void printUser(size_t i, void *data) {
	struct User user = * (struct User *) data;

	printf("Name: %s\n", user.name);
	printf("Age: %u\n\n", user.age);
}

int main() {
	struct User John = { "John Smith", 29 };
	struct User Sarah = { "Sarah Brown", 42 };
	struct User Maddy = { "Maddy Green", 78 };

	List l;

	linit(&l, sizeof(struct User));

	lpush(&l, &John);
	lunshift(&l, &Sarah);
	lpush(&l, &Maddy);

	leach(&l, &printUser);
}
