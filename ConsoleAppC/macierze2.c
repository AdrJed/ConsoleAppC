/* Adrian Jêdrzejak - 267531
* Dzia³ania na macierzach w tablicach dynamicznych
* z okreœleniem dzia³añ pomiêdzy parami macierzy
*/
#include <stdio.h>
#include <stdlib.h>

#ifndef MACIERZE_MAX
#define MACIERZE_MAX 10
#endif
#ifndef M_X_MAX
#define M_X_MAX 255
#endif
#ifndef M_Y_MAX
#define M_Y_MAX 255
#endif

typedef struct
{
	unsigned int mX;
	unsigned int mY;
	float **m;
} Macierz;
Macierz* C_Macierz()
{
	Macierz *m;
	m = (Macierz*)malloc(sizeof(Macierz));
	m->mX = 0;
	m->mY = 0;
	return m;
}

void wczytajMacierz(Macierz *m)
{
	int x, y;
	float data;

	printf("Wczytaj macierz %dx%d\n", m->mX, m->mY);

	for (y = 0; y < m->mY; y++) /* m->mY to samo co (*m).mY */
	{
		for (x = 0; x < m->mX; x++)
		{
			printf("%d,%d: ", x + 1, y + 1);
			scanf(" %f", &(m->m[x][y]));
		}
	}
}
void wyswietlMacierz(Macierz *m)
{
	int x, y;
	for (y = 0; y < m->mY; y++)
	{
		for (x = 0; x < m->mX; x++)
		{
			printf("| %g |", m->m[x][y]);
		}
		printf("\n");
	}
}

void zwolnijMacierz(Macierz *m)
{
	int i;
	for (i = 0; i < m->mX; i++)
	{
		free(m->m[i]);
	}
	if ((m->mX != 0) && (m->mY != 0))
	{
		free(m->m);
	}
}
void alokujMacierz(Macierz *m, int x, int y)
{
	m->mX = x;
	m->mY = y;
	m->m = (float**)malloc(x*sizeof(float*));
	int i, j;
	for (i = 0; i < m->mX; i++)
	{
		m->m[i] = (float*)malloc(m->mY*sizeof(float));
		//for (j = 0; j < m->mY; j++)
		//{
		//	m->m[i][j] = 0;
		//}
	}
}
void kopiujMacierz(Macierz *zrodlo, Macierz *cel)
{
	int x = 0, y = 0;
	alokujMacierz(cel, zrodlo->mX, zrodlo->mY);
	for (x = 0; x < zrodlo->mX; x++)
	{
		for (y = 0; y < zrodlo->mY; y++)
		{
			cel->m[x][y] = zrodlo->m[x][y];
		}
	}
}

void pomnozMacierze(Macierz *m1, Macierz *m2, Macierz *mw)
{
	float wynik = 0;
	int ax = 0, ay = 0;
	int move = 0;

	for (ay = 0; ay < mw->mY; ay++)
	{
		for (ax = 0; ax < mw->mX; ax++)
		{
			for (move = 0; move < m1->mX; move++)
			{
				wynik += m1->m[move][ay] * m2->m[ax][move];
			}

			mw->m[ax][ay] = wynik;
			wynik = 0;
		}
	}
}
void dodajMacierze(Macierz *m1, Macierz *m2, Macierz *mw)
{
	int ax = 0, ay = 0;

	for (ay = 0; ay < mw->mY; ay++)
	{
		for (ax = 0; ax < mw->mX; ax++)
		{
			mw->m[ax][ay] = m1->m[ax][ay] + m2->m[ax][ay];
		}
	}
}
void odejmijMacierze(Macierz *m1, Macierz *m2, Macierz *mw)
{
	int ax = 0, ay = 0;

	for (ay = 0; ay < mw->mY; ay++)
	{
		for (ax = 0; ax < mw->mX; ax++)
		{
			mw->m[ax][ay] = m1->m[ax][ay] - m2->m[ax][ay];
		}
	}
}
void transponujMacierz(Macierz *m)
{
	int x = 0, y = 0;
	Macierz *t = (Macierz*)malloc(sizeof(Macierz));
	alokujMacierz(t, m->mY, m->mX);

	for (x = 0; x < m->mX; x++)
	{
		for (y = 0; y < m->mY; y++)
		{
			t->m[y][x] = m->m[x][y];
		}
	}

	zwolnijMacierz(m);
	free(m);
	*m = *t;
}
/* Sprawdza czy dwie macierze spe³niaj¹ kryteria do wykonania danego dzia³ania */
int sprawdzDzialanie(char dzialanie, Macierz *m1, Macierz *m2)
{
	switch (dzialanie)
	{
	case '+':
		if ((m1->mX == m2->mX) && (m1->mY == m2->mY))
			return 0;
		else
			return 1;
		break;
	case '-':
		if ((m1->mX == m2->mX) && (m1->mY == m2->mY))
			return 0;
		else
			return 1;
		break;
	case '*':
		if ((m1->mX == m2->mY))
			return 0;
		else
			return 1;
		break;
	default:
		return 1;
		break;
	}
}
/* Wykonuje dzia³ania na ju¿ sprawdzonych macierzach */
void wykonajDzialanie(char dzialanie, Macierz *m1, Macierz *m2, Macierz *mw)
{
	switch (dzialanie)
	{
	case '+':
		alokujMacierz(mw, m1->mX, m2->mY);
		dodajMacierze(m1, m2, mw);
		break;
	case '-':
		alokujMacierz(mw, m1->mX, m2->mY);
		odejmijMacierze(m1, m2, mw);
		break;
	case '*':
		alokujMacierz(mw, m1->mY, m2->mX);
		pomnozMacierze(m1, m2, mw);
		break;
	default: break;
	}
}
void wczytajDzialania(char *dzialania, unsigned int mCount, Macierz *m)
{
	int i = 0;
	printf("Okresl operacje pomiedzy macierzami ( + , - , * )\n");
	for (i = 0; i < mCount - 1; i++)
	{
		if (i == 0)
		{
			printf("miedzy m%d i m%d: ", i + 1, i + 2);
			scanf(" %c", (dzialania + i));
		}
		else
		{
			printf("miedzy mWynikowa i m%d: ", i + 2);
			scanf(" %c", (dzialania + i));
		}
		if (sprawdzDzialanie(dzialania[i], (m + i), (m + i + 1)) == 1)
		{
			/* Jeœli okreœlone dzia³anie nie jest mo¿liwe, wprowadŸ je ponownie */
			i--;
			printf("Nie mozna wykonac tego dzialania na podanych macierzach. Wprowadz ponownie\n");
			continue;
		}
	}
}
void wyswietlDzialania(char *dzialania, unsigned int mCount)
{
	int i = 0;
	for (i = 0; i < mCount; i++)
	{
		if (i == 0)
		{
			printf("( m%d %c m%d )", i + 1, dzialania[i], i + 2);
		}
		else if (i < mCount - 1)
		{
			printf(" %c m%d )", dzialania[i], i + 2);
		}
		else {
			printf("\n");
		}
	}
}

int macierze()
{
	Macierz *macierze = NULL;	/* Tablica macierzy na których dzia³amy */
	Macierz *mw = NULL;			/* Macierz przechowuj¹ca wynik ostatniej operacji */
	Macierz *tmp = NULL;		/* Macierz do której kopiujê wynik ostatniej operacji, aby traktowaæ j¹ jako operand */
	unsigned int mCount = 0;	/* Iloœæ macierzy w tablicy macierzy */
	char *dzialania = NULL;		/* Tablica znaków dzia³añ pomiêdzy dwiema macierzami */
	int i = 0, x = 0, y = 0;

	do
	{
		printf("Podaj ilosc macierzy: ");
		scanf("%u", &mCount);

		if (mCount > MACIERZE_MAX)
		{
			printf("Przekroczono limit iloœci macierzy. Maksymalnie %d\n", MACIERZE_MAX);
			continue;
		}
		else if (mCount == 0)
		{
			printf("Jak nie to nie. Wychodze...");
			return 1;
		}
		else
		{
			mw = C_Macierz();
			tmp = C_Macierz();
			macierze = (Macierz*)malloc(mCount*sizeof(Macierz));
			dzialania = (char*)malloc(mCount*sizeof(char));
			break;
		}

	} while (!(mCount < MACIERZE_MAX));

	do
	{
		for (i = 0; i < mCount; i++)
		{
			printf("Podaj wymiary macierzy nr %d\nx,y: ", i + 1);
			scanf(" %d,%d", &x, &y);

			if ((x > 0 && x < M_X_MAX) && (y > 0 && y < M_Y_MAX))
			{
				alokujMacierz(&(macierze[i]), x, y); /* &(macierze[i]) to samo co (macierze+i) */
				wczytajMacierz((macierze + i));
				wyswietlMacierz((macierze + i));
			}
			else
			{
				printf("Niepoprawne argumenty. Jeszcze raz\n");
				i--;
				continue;
			}
		}

		if (mCount > 1)
		{
			wczytajDzialania(dzialania, mCount, macierze);
			wyswietlDzialania(dzialania, mCount);

			/* Wykonywanie dzia³añ */
			for (i = 0; i < mCount - 1; i++)
			{
				printf("Dzialanie nr %d\n", i + 1);
				if (i == 0) wykonajDzialanie(dzialania[i], &(macierze[i]), &(macierze[i + 1]), mw);
				else
				{
					kopiujMacierz(mw, tmp);
					wykonajDzialanie(dzialania[i], tmp, &(macierze[i + 1]), mw);
				}
				wyswietlMacierz(mw);
			}
		}
		else if (mCount == 1)
		{
			/* TODO: Wykonywanie przekszta³ceñ na jednej macierzy */
			printf("Transponowanie macierzy");
			transponujMacierz(macierze);
			wyswietlMacierz(macierze);
		}

		break;

	} while (0);

	/* Zwalnianie pamiêci dynamicznej */
	for (i = 0; i < mCount; i++)
	{
		zwolnijMacierz((macierze + i));
	}
	zwolnijMacierz(mw);
	zwolnijMacierz(tmp);
	free(mw);
	//free(tmp);
	free(macierze);
	free(dzialania);
	return 0;
}
