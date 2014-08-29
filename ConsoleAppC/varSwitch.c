/* Testowanie r�nych funkcji zamieniaj�cych dwie zmienne */

#include <stdio.h>
#include <time.h>
#include "varSwitch.h"

/* Zamiana zmiennych z u�yciem operacji arytmetycznych */
void swapIntArith(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

/* Zamiana zmiennych z u�yciem operacji XOR */
void swapIntXOR(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void swapInt(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/* Testowanie czasu i zaj�to�ci pami�ciowej poszczeg�lnych funkcji zamieniaj�cych
 */
void swapFuncTest()
{
	// TODO dopracowa� pomiar czasu
	int a,a1,b,b1;
	clock_t timeDiff, now;
	
	printf("Podaj dwie liczby do test�w\na b: ");
	scanf(" %d %d", &a, &b);

	a1 = a; b1 = b;

	printf("Test swapIntArith( a = %d, b = %d)\n\n", a1, b1);
	now = clock();
	swapIntArith(&a1, &b1);
	timeDiff = clock();
	printf("a = %d, b = %d\n czas: %f\n", a1, b1, (timeDiff - now) / CLOCKS_PER_SEC);

	a1 = a; b1 = b;

	printf("Test swapIntXOR( a = %d, b = %d)\n\n", a1, b1);
	now = clock();
	swapIntArith(&a1, &b1);
	timeDiff = clock();
	printf("a = %d, b = %d\n czas: %f\n", a1, b1, (timeDiff - now)/CLOCKS_PER_SEC);

	a1 = a; b1 = b;

	printf("Test swapIntArith( a = %d, b = %d)\n\n", a1, b1);
	now = clock();
	swapInt(&a1, &b1);
	timeDiff = clock();
	printf("a = %d, b = %d\n czas: %g\n", a1, b1, (timeDiff - now)/CLOCKS_PER_SEC);

}
