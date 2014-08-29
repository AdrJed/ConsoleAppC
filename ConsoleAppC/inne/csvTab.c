#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COL_SEPARATOR ','
#define ROW_SEPARATOR '\n'

typedef struct Tab2D
{
	int x;
	int y;
	int **t;
} Tab2D;

void print_array(int *tab, int length)
{
	int i = 0;
	printf("[ ");
	for (; i < length; i++, tab++)
	{
		printf("%d  ", *tab);
	}
	printf("]\n");
}

void printArray2D(int **tab, int x, int y)
{
	int i = 0, j = 0;

	printf("\n");

	for (i = 0; i<x; i++)
	{
		printf("| ");
		for (j = 0; j<y; j++)
		{
			printf("%d ", tab[i][j]);
		}
		printf("|\n");
	}
}

int** mallocArray2D(int x, int y)
{
	int i = 0, j = 0;
	int **tab = (int**)malloc(sizeof(int*)* x);

	for (i = 0; i<x; i++)
	{
		(tab[i]) = (int*)malloc(sizeof(int)*y);
	}

	for (i = 0; i<x; i++)
	{
		for (j = 0; j<y; j++)
		{
			tab[i][j] = 0;
		}
	}

	return tab;
}

void freeArray2D(int **tab, int x)
{
	int i = 0;

	for (i = 0; i < x; i++)
	{
		free(*(tab + i));
	}
	free(tab);
}

void loadArray2D(int *x, int *y)
{
	printf("Podaj rozmiar x y: ");
	scanf(" %d %d", x, y);

	if (*x > 0 && *y > 0)
		printf("Tablica o wymiarach %d na %d\n", *x, *y);
	else
		printf("Stefan! Nie wczytujemy!\n");
}

void writeArray2D(int **tab, int x, int y)
{
	int i = 0, j = 0;

	if (x != 0 || y != 0)
		printf("Wczytywanie danych do tablicy %d x %d\n", x, y);
	else
		return;

	for (i = 0; i<x; i++)
	{
		for (j = 0; j<y; j++)
		{
			printf("tab[%d][%d]: ", i + 1, j + 1);
			scanf(" %d", (*(tab + i) + j));
		}
	}
}

int str_char_count(char * str, char ch)
{
	int count = 0;
	int i = 0;
	while (*str != '\0')
	{
		if (*str == ch)
			count++;

		str++;
	}
	return count;
}

int str_len(char *str) {
	int len = 0;
	while (str[len] != '\0') len++;
	return len;
}

int str_cmp(char *strA, char *strB) {
	int i = 0;
	int result = 0;

	int lenA = str_len(strA);
	int lenB = str_len(strB);

	if (lenA != lenB) {
		return -1;
	}
	while (strA[i] != '\0' && !(result = (strA[i] - strB[i]))) {
		i++;
	}
	return result;
}

int fsize(FILE *f)
{
	int i = 0;

	rewind(f);
	while (getc(f) != EOF) i++;

	return i;
}

// funkcja pomocnicza 2
void WriteCsvToTable(FILE *f, Tab2D *tab)
{
	char c = '0';
	char *cVal = (char*)malloc(sizeof(char)*16);
	int iVal = 0,
		i = 0,
		X = 0,
		Y = 0;

	rewind(f);
	while ((c = getc(f)) != EOF)
	{
		for (i = 0; !(c==',' || c=='\n'); i++)
		{
			cVal[i] = c;
			if ((c = getc(f)) == EOF)
			{
				i++;
				break;
			}
		}
		cVal[i] = '\0';
		iVal = atoi(&cVal);

		tab->t[Y][X] = iVal;

		if (c == ',') X++;
		if (c == '\n'){X = 0; Y++;}

	}

}

//funkcja pomocnicza 1
int CsvTabSize(FILE *f, Tab2D *tab)
{
	char c = 0;
	int x = 0, y = 0;

	rewind(f);
	while ((c = getc(f)) != EOF)
	{
		if (c == ',') x++;
		if (c == '\n')
		{
			x = 0;
			y++;
		}
	}

	tab->x = x+1;
	tab->y = y+1;
	return 0;
}


Tab2D* CsvToTable(FILE *f)
{
	Tab2D *tab = (Tab2D*)malloc(sizeof(Tab2D));
	
	CsvTabSize(f, tab);
	tab->t = mallocArray2D(tab->x, tab->y);

	WriteCsvToTable(f, tab);

	return tab;
}


// PUNKT WEJŒCIOWY
int csvtab(int argc, char *argv[])
{
	char ch,
		fileName[256] = { 0 };
	int i = 0,
		tabNum = 0;
	Tab2D *tab[2] = { NULL };
	FILE *file = NULL;

	while (file == NULL && i < 2)
	{
		printf("\nPodaj nazwe pliku %d: ", i+1);
		scanf(" %s", &fileName);
		printf("Nazwa pliku: %s \n", &fileName);

		file = fopen(fileName, "r");
		if (file == NULL)
		{
			printf("Nie znaleziono pliku. Sprobuj jeszcze raz...\n");
			continue;
		}

		printf("Zawartosc pliku:\n");
		while ((ch = getc(file)) != EOF) putchar(ch);

		tab[i] = CsvToTable(file);
		fclose(file);
		file = NULL;

		i++;
		if (i == 2)
		{
			tabNum = i;
			break;
		}
	}

	for (i = 0; i < tabNum; i++)
	{
		printf("\nTabela %d: \n", i);
		printArray2D(tab[i]->t, tab[i]->y, tab[i]->x);
	}

	// nie wiem co siê dzieje z free
	freeArray2D(tab[0]->t, tab[0]->x);
	freeArray2D(tab[1]->t, tab[1]->x);
	free(tab[0]);
	free(tab[1]);

	//printf("Podaj znak aby zakonczyc...\n ");
	//while( !isalpha(getchar()) ){}
	return 0;
}
