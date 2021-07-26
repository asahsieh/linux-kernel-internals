#include <stdio.h>

int main ()
{
	int a[3] = {1, 3, 5};
	int *p;

	p = a; /* p points to a[0] */
//	printf("p=%d before + 1\n", *p);
//	p = p + 1; /* + 1 -> 1 * sizeof(int) */
//	printf("p=%d after  + 1\n", *p);
	*a = 5; /* sets a[0] to 5 */
	*(a+1) = 5; /* sets a[1] to 5 */
}
