#include <stdio.h>
#include "src/vector.h"

struct User {
	char name[30];
	unsigned age;
};

int main() {
	struct User John = { "John Smith", 29 };
	struct User Sarah = { "Sarah Brown", 42 };
	struct User Maddy = { "Maddy Green", 78 };
	struct User user;

	Vector v;

	vinit(&v, sizeof(struct User));

	vpush(&v, &John);
	vpush(&v, &Sarah);
	vpush(&v, &Maddy);

	for(size_t i = 0; i < v.length; i++) {
		user = * (struct User *) vget(&v, i);

		printf("Name: %s\n", user.name);
		printf("Age: %u\n\n", user.age);
	}
}
