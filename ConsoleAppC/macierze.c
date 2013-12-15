// Adrian Jêdrzejak - 267531
// Mno¿enie macierzy w tablicach dynamicznych

#include <stdio.h>
#include <stdlib.h>

void wczytajMacierz(float *(*tab), int Size_x, int Size_y)
{
	int x, y;
	float data;
	
	printf("Wczytaj macierz %dx%d\n", Size_x, Size_y);

	for (y = 0; y < Size_y; y++)
	{
		for (x = 0; x < Size_x; x++)
		{
			printf("%d,%d:", x+1, y+1);
			scanf("%f", &data);
			// blad przy bezposrednim wczytywaniu do tablicy
			// dziala przy przekazaniu przez zmienna posrednia
			*(*(tab+x)+y) = data;
		}
	}
}
void wyswietlMacierz(float *(*tab), int Size_x, int Size_y)
{
	int x, y;

	for (y = 0; y < Size_y; y++)
	{
		for (x = 0; x < Size_x; x++)
		{
			printf("| %g |", *(*(tab+x)+y));
		}
		printf("\n");
	}
}

void pomnozMacierze(float *(*m1), int sizeXm1,
					float *(*m2), int sizeXm2, 
					float *(*mw), int sizeXmw, int sizeYmw)
{
	float wMnozenie = 0, wKoncowy = 0;
	int ax=0, ay=0;
	int move = 0;
	
		for (ay = 0; ay < sizeYmw; ay++)		
		{
			for (ax = 0; ax < sizeXmw; ax++)
			{
				for (move = 0; move < sizeXm1; move++)
				{
					wMnozenie = m1[move][ay] * m2[ax][move];
					wKoncowy += wMnozenie;
				}

				mw[ax][ay] = wKoncowy;
				wKoncowy = 0;
			}
		}
}

float** alokujTablice2D(int x, int y)
{
	float** tab = (float**)malloc(x*sizeof(float*));
	int i;
	for (i = 0; i < x; i++)
	{
		tab[i] = (float*)malloc(y*sizeof(float));
	}

	return tab;
}
void zwolnijTablice2D(float **tab, int x)
{
	int i;
	for (i = 0; i < x; i++)
	{
		free(tab[i]);
	}
	free(tab);
}

void macierze()
{
	float **m1 = NULL,
		  **m2 = NULL,
		  **mw = NULL;
	int m1X, m1Y, m2X, m2Y, mwX, mwY;

	do
	{
		printf("Podaj wymiary pierwszej macierzy\nx,y: ");
		scanf("%d,%d", &m1X, &m1Y);

		printf("Podaj wymiary drugiej macierzy\nx,y: ");
		scanf("%d,%d", &m2X, &m2Y);

	
		if (m1X == m2Y && ( m1X > 0 && m2X > 0 && m1Y > 0 && m2Y > 0))
		{
			m1 = alokujTablice2D(m1X, m1Y);
			m2 = alokujTablice2D(m2X, m2Y);

			mwX = m2X; mwY = m1Y;
			mw = alokujTablice2D(mwX, mwY);

			wczytajMacierz(m1, m1X, m1Y);
			wyswietlMacierz(m1, m1X, m1Y);

			wczytajMacierz(m2, m2X, m2Y);
			wyswietlMacierz(m2, m2X, m2Y);

			printf("macierz wynikowa %dx%d\n", mwX, mwY);
			pomnozMacierze(m1, m1X, m2, m2X, mw, mwX, mwY);
			wyswietlMacierz(mw, mwX, mwY);

		}
		else
		{
			printf("Rozmiar macierzy jest ujemny lub\n");
			printf("Szerokosc jednej macierzy nie jest rowna dlugosci drugiej.\n");
			printf("Nie mozna mnozyc przez siebie takich macierzy.\n");
		}
	} while (!(m1X == m2Y && (m1X > 0 && m2X > 0 && m1Y > 0 && m2Y > 0)));

	if (mw != NULL)	zwolnijTablice2D(mw, mwX);
	if (m2 != NULL) zwolnijTablice2D(m2, m2X);
	if (m1 != NULL) zwolnijTablice2D(m1, m1X);
}

//void main(){macierze();}