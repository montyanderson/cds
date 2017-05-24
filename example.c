#include <stdio.h>
#include "src/vector.h"

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
