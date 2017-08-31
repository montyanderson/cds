#include <stdio.h>
#include "src/vector.h"

int main() {
	size_t i;
	int n;
	Vector v;

	vinit(&v, sizeof(int));

	for(i = 0; i < 10; i++) {
		n = i * 3;
		vpush(&v, &n);
	}

	for(i = 0; i < v.length; i++) {
		vget(&v, i, &n);

		printf("%d\n", n);
	}
}
