/* Rysowanie figur za pomoc¹ znaków ASCII */

#include <stdio.h>
#include "trojkat.h"

void pustyTrojkat(unsigned int wysokosc)
{
	int odstep = wysokosc;
	unsigned int znakow = 1;
	int i,j,k;

	for (i = 0; i < wysokosc; i++)
	{
		for (j = 0; j < odstep; j++)
		{
			putchar(Z_ODSTEPU);
		}
		for (k = 0; k < znakow; k++)
		{
			if (odstep > 1)
			{
				if (k == 0 || k == znakow - 1)
					putchar(Z_WYPELNIENIA);
				else putchar(Z_ODSTEPU);
			}
			else putchar(Z_WYPELNIENIA);
		}
		znakow += 2;
		odstep -= 1;
		putchar('\n');
	}
}
void pelnyTrojkat(int wysokosc)
{
	int odstep = wysokosc;
	unsigned int znakow = 1;
	int i,j,k;

	for (i = 0; i < wysokosc; i++)
	{
		for (j = 0; j < odstep; j++)
		{
			putchar(Z_ODSTEPU);
		}
		for (k = 0; k < znakow; k++)
		{
			putchar(Z_WYPELNIENIA);
		}
		znakow += 2;
		odstep -= 1;
		putchar('\n');
	}
}