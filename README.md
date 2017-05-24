# cds
A dynamic structures library in C.

## Vector Example

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
