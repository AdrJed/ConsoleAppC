/* Modu³ rysowania zbieraj¹cy w ca³oœæ funkcje rysowania */
#define RYSUJ_START_MAIN 0

#include <stdio.h>
#include "RysujMain.h"
#include "trojkat.h"

#if RYSUJ_START_MAIN == 1
int main()
#else
int rysujMain()
#endif
{
	int height = 0;
	printf("Wysokosc trojkata: ");
	scanf_s(" %d", &height);
	pelnyTrojkat(height);
	pustyTrojkat(height);
	system("pause");
	return 0;
}
