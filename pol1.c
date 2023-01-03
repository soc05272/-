#include <stdio.h>

int main(void)
{
	int i = 33;
	int *iPtr = &i;

	char ch = 'S';
	char *cPtr = &ch;

	float f = 34.567f;
	float *fPtr = &f;

	double d = 50000.123;
	double *dPtr = &d;

	printf("i=%d, *iPtr=%d\n", i, *iPtr);
	printf("&i=%x, iPtr=%x\n", &i, iPtr);
	printf("&iPtr=%x\n\n", &iPtr);

	printf("ch=%c, *cPtr=%c\n", ch, *cPtr);
	printf("&ch=%x cPtr=%x\n", &ch, cPtr);
	printf("&cPtr=%x\n\n", &cPtr);

	printf("f=%lf, *fPtr=%lf\n", f, *fPtr);
	printf("&f=%x, fPtr=%x\n", &f, fPtr);
	printf("&fPtr=%x\n\n", &fPtr);

	printf("d=%lf, *dPtr=%lf\n",d, *dPtr);
	printf("&d=%x, dPtr=%x\n", &d, dPtr);
	printf("&dPtr=%x\n\n", &dPtr);

	return 0;
}
