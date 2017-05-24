# cds
A dynamic structures library in C.

## Vector Example

### Integers

``` C
#include <stdio.h>
#include "vector.h"

int main() {
	size_t i, n;
	Vector v;

	vinit(&v, sizeof(int));

	for(i = 0; i < 10; i++) {
		n = i * 3;
		vpush(&v, &n);
	}

	for(i = 0; i < v.length; i++) {
		printf("%d\n", * (int *) vget(&v, i));
	}
}

```

```
0
3
6
9
12
15
18
21
24
27
```

### Structures

``` C
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
```

```
Name: John Smith
Age: 29

Name: Sarah Brown
Age: 42

Name: Maddy Green
Age: 78

```
