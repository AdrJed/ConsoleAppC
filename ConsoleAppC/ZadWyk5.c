#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/* Zadania WYKLAD 5 */
/* 5.1. Napisz funkcj� maksind, kt�ra dla danej tablicy t zawieraj�cej n liczb zmiennopozycyjnych zwr�ci pozycj� (indeks) maksymalnej warto�ci w zbiorze. */
int maxIndex(float fTab[], int tSize)
{
	int Index = 0;

	for (int i = 0; i < tSize - 1; i++)
	{
		if (fTab[i + 1] > fTab[i])
		{
			Index = i + 1;
		}
	}

	return Index;
}
void Wyk5Zad1()
{
#define T_SIZE 10

	float fTab[T_SIZE] = { 0 };
	int tSize = sizeof(fTab) / sizeof(fTab[0]),
		mIndex = 0;

	/* Wprowadzanie element�w do tablicy */
	printf("Wielkosc tablicy %d\n", tSize);

	for (int i = 0; i < T_SIZE; i++)
	{
		printf("fTab[%d]: ", i);
		scanf("%f", &fTab[i]);
		//fTab[i] = T_SIZE - i;
	}

	for (int i = 0; i < T_SIZE; i++) { printf("%g\t", fTab[i]); }

	mIndex = maxIndex(fTab, tSize);
	printf("Indeks maksymalnej liczby w tablicy jest rowny %d - liczba %g\n", mIndex, fTab[mIndex]);

#undef T_SIZE
}
/* 5.2. Napisz funkcj� sortuj, kt�ra korzystaj�c z funkcji maksind przeprowadzi procedur� sortowania element�w w tablicy liczb zmiennopozycyjnej zgodnie z algorytmem sortowania przez wyb�r (selection sort). */
void selectionSort(float fTab[], const int tSize)
{
	int Size = tSize;
	int maxInd;
	float tmp;

	for (int i = tSize-1; i != 0; i--)
	{
		maxInd = maxIndex(fTab, Size);
		if (maxInd != i)
		{
			tmp = fTab[maxInd];
			fTab[maxInd] = fTab[i];
			fTab[i] = tmp;
		}
		Size--;
	}
}
void Wyk5Zad2()
{
#define T_SIZE 10
	float fTab[T_SIZE] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	printf("Podaj wartosci do posortowania. \n");
	for (int i = 0; i < T_SIZE; i++)
	{
		printf("fTab[%d]: ", i);
		scanf("%f", &fTab[i]);		
	}

	selectionSort(fTab, T_SIZE);

	printf("Elementy posortowane:\n");
	for (int i = 0; i < T_SIZE; i++)
	{
		printf("| %g ", fTab[i]);
	}

#undef T_SIZE
}
/* 5.3. Napisz program lub funkcj� sortuj�c� elementy w tablicy za pomoc� algorytmu b�belkowego */
void bubbleSort(float fTab[], const int tSize)
{
	int swapCount = 0;
	float tmp = 0;

	while(true)
	{
		for (int i = 0; i < tSize - 1; i++)
		{
			if (fTab[i] > fTab[i + 1])
			{
				tmp = fTab[i + 1];
				fTab[i + 1] = fTab[i];
				fTab[i] = tmp;
				swapCount += 1;
			}
		}
		if (swapCount != 0) swapCount = 0;
		else break;
	}
}
void Wyk5Zad3()
{
#define T_SIZE 10

	float fTab[T_SIZE] = { 10,9,8,7,6,5,4,3,2,1 };

	printf("Podaj wartosci do posortowania.\n");
	for (int i = 0; i < T_SIZE; i++)
	{
		printf("fTab[%d]: ", i);
		scanf("%f", &fTab[i]);
	}

	bubbleSort(fTab, T_SIZE);

	printf("Elementy posortowane:\n");
	for (int i = 0; i < T_SIZE; i++)
	{
		printf("| %g ", fTab[i]);
	}

#undef T_SIZE
}
/* 5.4. Napisz funkcj� wyznaczaj�c� pierwiastki r�wnania kwadratowego. Dla danych warto�ci wsp�czynnik�w a, b, c funkcja zwraca struktur� zawieraj�c� informacj� o ilo�ci miejsc zerowych oraz warto�ci znalezionych pierwiastk�w (miejsc zerowych). */
struct fKwadratowa {
	float a, b, c, x1, x2, x0, delta;
};
struct fKwadratowa rKwadratowe(struct fKwadratowa f)
{
	f.delta = (f.b * f.b) - (4 * f.a * f.c);

	if (f.delta > 0)
	{
		f.x1 = (-f.b - sqrt(f.delta) / (2 * f.a));
		f.x2 = (-f.b + sqrt(f.delta) / (2 * f.a));
		return f;
	}
	else if (f.delta == 0)
	{
		f.x0 = -f.b / (2 * f.a);
		return f;
	}
	else if (f.delta < 0)
	{
		return f;
	}

	return f;
}
void Wyk5Zad4()
{
	struct fKwadratowa fK;

	printf("Podaj wspolczynniki a b c:");
	scanf("%f %f %f", &fK.a, &fK.b, &fK.c);

	fK = rKwadratowe(fK);

	if (fK.delta > 0)
	{
		printf("Rownanie ma dwa rozwiazania: %g i %g .\n", fK.x1, fK.x2);
	}
	else if (fK.delta == 0)
	{
		printf("Rownanie ma jedno podwojne rozwiazanie: %g .\n", fK.x0);
	}
	else if (fK.delta < 0)
	{
		printf("Rownanie nie posiada rozwiazan.\n");
	}
}
/* 5.5. Napisz funkcj� wyznaczaj�c� warto�� wielomianu dowolnego stopnia w punkcie x. Wsp�czynniki wielomianu oraz jego stopie� s� argumentami funkcji - wsp�czynniki umieszczone s� w tablicy. Do wyznaczenia warto�ci wielomianu wykorzystaj schemat Hornera. */
void Wyk5Zad5()
{
#define wTabMax 256

	int stopien;
	float wTab[wTabMax];// tablica wsp�czynnik�w wielomianu
	float x;
	double result = 0 ;

	do
	{
		printf("Podaj stopien wielomianu : ");
		scanf("%d", &stopien);
	} while (stopien > wTabMax || stopien < 0);

	for (int i = 0; i <= stopien; i++)
	{
		printf("wspolczynnik stopnia %d: ", i);
		scanf("%f", &wTab[i]);
	}

	printf("Podaj argument x: ");
	scanf("%f", &x);

	for (int i = 0; i <= stopien; i++)
	{
		if (i == 0) printf("%g", wTab[i]);
		else {
			printf(" + %gx^%d", wTab[i], i);
		}
		result += wTab[i]*x;
	}

	printf(" =  %g", result);

#undef wTabMax
}
/* 5.6. Napisz funkcj�, kt�ra dla danej tablicy zawieraj�cej n liczb zmiennopozycyjnych zwr�ci struktur� zwracaj�c� warto�� maksymaln� oraz minimaln� z tablicy. Postaraj si� zaimplementowa� algorytm wyszukiwania w spos�b optymalny, tak aby wykona� minimaln� liczb� operacji por�wnania. */
struct minMaxTab
{
	float min, max;
};
struct minMaxTab szukajMinMaxWTablicy(float fTab[], const int tSize)
{
	struct minMaxTab minMax;

	minMax.min = fTab[0];
	minMax.max = fTab[0];

	for (int i = 0; i < tSize; i++)
	{
		if (fTab[i] > minMax.max)
		{
			minMax.max = fTab[i];
		}
		else if (fTab[i] < minMax.min)
		{
			minMax.min = fTab[i];
		}
	}

	return minMax;
}
void Wyk5Zad6()
{
#define T_SIZE 10

	float fTab[T_SIZE] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	struct minMaxTab minMax;

	printf("Podaj liczby do tablicy:\n");
	for (int i = 0; i < T_SIZE; i++)
	{
		printf("fTab[%d]: ", i);
		scanf("%f", &fTab[i]);
	}

	minMax = szukajMinMaxWTablicy(fTab, T_SIZE);

	printf("Minimalna wartosc w tablicy: %g\n", minMax.min);
	printf("Maksymalna wartosc w tablicy: %g\n", minMax.max);

#undef T_SIZE
}
/* 5.7. Napisz funkcj�, kt�ra dla danej tablicy zawieraj�cej n liczb zmiennopozycyjnych zwr�ci: sum� element�w,sum� element�w wi�kszych od zera,warto�� �redni�,odchylenie standardowe,wariancj�,rozst�p,median�,liczb� element�w zawartych w podanym przedziale [a,b] */
float sumaElementow(float fTab[], int tSize)
{
	float sum = 0;

	for (int i = 0; i < tSize; i++)
	{
		sum = sum + fTab[i];
	}
	return sum;
}
float sumaElementowWiekszychOdZera(float fTab[], int tSize)
{
	float sum2 = 0;

	for (int i = 0; i < tSize; i++)
	{
		if (fTab[i] > 0)
		{
			sum2 = sum2 + fTab[i];
		}
	}

	return sum2;

}
float sredniaElementow(float fTab[], int tSize)
{
	float srednia = 0;
	float sum = 0;

	for (int i = 0; i < tSize; i++)
	{
		sum = sum + fTab[i];
	}
	srednia = sum / tSize;
	return srednia;
}
float wariancja(float fTab[], int tSize)
{
	float wariancja = 0;
	float srednia = sredniaElementow(fTab, tSize);

	for (int i = 0; i < tSize; i++)
	{
		wariancja = wariancja + pow(fTab[i] - srednia, 2);
	}
	wariancja = wariancja / tSize;
	return wariancja;
}
float odchylenieStandardowe(float wariancja)
{
	float odchylenie = 0;
	odchylenie = sqrt(wariancja);
	return odchylenie;
}
float rozstep(float fTab[], int tSize)
{
	float fmin = 0;
	float fmax = 0;
	float rozstep = 0;

	fmin = fmax = fTab[0];
	for (int i = 0; i < tSize; i++)
	{
		if (fTab[i] > fmax)
		{
			fmax = fTab[i];
		}
		if (fTab[i] < fmin)
		{
			fmin = fTab[i];
		}
	}
	rozstep = fmax - fmin;
	return rozstep;
}
int sortTab(float fTab[], int tSize)
{
	int i = 0;
	char sorted = 0;
	int sortedCount = 0;
	float tmp = 0;
	int steps = 0;

	while (true)
	{
		for (i = 0; i < tSize - 1; i++)
		{
			if (fTab[i] > fTab[i + 1])
			{
				tmp = fTab[i];
				fTab[i] = fTab[i + 1];
				fTab[i + 1] = tmp;
				steps++;
			}
			else { sortedCount++; }
		}
		if (sortedCount == tSize - 1) { break; }
		else { sortedCount = 0; }
	}

	return steps;
}
float mediana(float fTab[], int tSize)
{
	sortTab(fTab, tSize);
	if (tSize % 2 != 0)
	{
		return fTab[tSize / 2];
	}
	else
	{
		return (fTab[tSize / 2] + fTab[tSize / 2 - 1]) / 2;
	}
}
void lElementowWPrzedziale(float fTab[], int tSize)
{
	int a = 0; int b = 0;
	int lElementow = 0;

	printf("Podaj przedzial liczbowy: ");
	scanf("%d %d", &a, &b);
	for (int i = 0; i < tSize; i++)
	{
		if (fTab[i] >= a && fTab[i] <= b)
		{
			lElementow++;
			printf("%g\t", fTab[i]);
		}
	}
	printf("Liczba elementow: %d", lElementow);
}

void Wyk5Zad7()
{
#define T_SIZE 10

	int a = 0;
	int b = 0;
	int lElementow = 0;

	float fTab[T_SIZE] = { 0 };
	int tSize = sizeof(fTab) / sizeof(fTab[0]);

	/* Wprowadzanie element�w do tablicy */
	printf("Wielkosc tablicy %d\n", tSize);

	for (int i = 0; i < T_SIZE; i++)
	{
		/*printf("fTab[%d]: ",i);
		scanf("%f",&fTab[i]);*/
		fTab[i] = T_SIZE - i;
	}

	for (int i = 0; i < T_SIZE; i++)
	{
		printf("%g\t", fTab[i]);
	}

	int steps = sortTab(fTab, tSize);
	printf("Elementy posortowane\n");
	for (int i = 0; i < T_SIZE; i++)
	{
		printf("%g\t", fTab[i]);
	}
	printf("Liczba zamian: %d\n", steps);
	printf("Suma elementow w tablicy: %g\n", sumaElementow(fTab, tSize));
	printf("Suma elementow w tablicy wiekszych od zera: %g\n", sumaElementowWiekszychOdZera(fTab, tSize));
	printf("Wartosc srednia: %g\n", sredniaElementow(fTab, tSize));
	printf("Wariancja: %g\t Odchylenie standardowe: %g\n", wariancja(fTab, tSize), odchylenieStandardowe(wariancja(fTab, tSize)));
	printf("Rozstep: %g\n", rozstep(fTab, tSize));
	printf("Mediana: %g\n", mediana(fTab, tSize));
	/*lElementowWPrzedziale(fTab, tSize);*/

#undef T_SIZE
}

/* 5.8 Zaimplementuj zestaw funkcji realizuj�cych podstawowe operacje na liczbach zespolonych(dodawanie, odejmowanie, mno�enie, modu�).Liczby zespolone reprezentuj za pomoc� odpowiednich struktur.
	Napisz program wczytuj�cy dwie liczby urojone i wy�wietlaj�cy wyniki operacji dodawania i mno�enia tych dw�ch liczb. */
struct compl
{
	int re; //cz�� rzeczywista
	int im; //cz�� urojona
};
struct compl addCompl(struct compl a, struct compl b)
{
	struct compl result;
	result.re = a.re + b.re;
	result.im = a.im + b.im;
	return result;
}
struct compl subtractCompl(struct compl a, struct compl b)
{
	struct compl result;
	result.re = a.re - b.re;
	result.im = a.im - b.im;
	return result;
}
struct compl multiplyCompl(struct compl a, struct compl b)
{
	struct compl result;
	result.re = (a.re * b.re) + (-1 * a.im * b.im);
	result.im = (a.re * b.im) + (b.re * a.im);
	return result;
}
void Wyk5Zad8()
{
	struct compl c1, c2, result;

	printf("Podaj dwie liczby urojone, np. -3 4i 6 -2i.\n");
	printf("Re i Re i: ");
	scanf("%d %di %d %di", &c1.re, &c1.im, &c2.re, &c2.im);

	result = addCompl(c1, c2);
	printf("(%d %di)+(%d %di) = (%d %di)\n", c1.re, c1.im, c2.re, c2.im, result.re, result.im);
	result = subtractCompl(c1, c2);
	printf("(%d %di)-(%d %di) = (%d %di)\n", c1.re, c1.im, c2.re, c2.im, result.re, result.im);
	result = multiplyCompl(c1, c2);
	printf("(%d %di)x(%d %di) = (%d %di)\n", c1.re, c1.im, c2.re, c2.im, result.re, result.im);
}
/* 5.9 Zaimplementuj zestaw funkcji realizuj�cych podstawowe operacje na u�amkach(dodawanie, odejmowanie, mno�enie, dzielenie).U�amki reprezentuj za pomoc� odpowiednich struktur.
	Napisz program wczytuj�cy dwa u�amki i wy�wietlaj�cy wyniki operacji dodawania, odejmowania, mno�enia i dzielenia u�amk�w.Zadbaj o to, aby wy�wietlane u�amki by�y zawsze sprowadzone do najprostszej postaci. */

/* 5.10 Napisz funkcj� wyznaczaj�c� odleg�o�� euklidesow� pomi�dzy dowolnymi punktami w przestrzeni tr�jwymiarowej.Punkty okre�lone wsp�rz�dnymi x, y i z reprezentuj za pomoc� odpowiedniej struktury.
	Napisz program kt�ry wczyta 2 punkty i wy�wietli ich odleg�o��. */
struct point3d{
	float x, y, z;
};
double point3dDistance(struct point3d a, struct point3d b)
{
	double distance = sqrt((a.x + b.x)*(a.x + b.x) + (a.y + b.y)*(a.y + b.y) + (a.z + b.z)*(a.z + b.z));
	return distance;
}
void Wyk5Zad10()
{
	struct point3d a, b;
	double distance;

	printf("Podaj wspolrzedne dwoch punktow w przestrzeni euklidesowej, np. 29.8,5.4,2 5,2.78,-3 .\n");
	printf("x,y,z x,y,z: ");
	scanf("%f,%f,%f %f,%f,%f", &a.x, &a.y, &a.z, &b.x, &b.y, &b.z);

	distance = point3dDistance(a, b);
	printf("Odleglosc miedzy punktami wynosi %g", distance);
}
/* 5.11 Napisz funkcje wyznaczaj�ce odleg�o�� euklidesow� oraz iloczyn skalarny dw�ch punkt�w w przestrzeni n wymiarowej(zak�adamy, �e n<1000).Reprezentuj punkt(wektor) w przestrzeni n wymiarowej za pomoc� odpowiedniej struktury.
	Napisz program, kt�ry wczyta wsp�rz�dne 2 wektor�w o takim samym wymiarze i wy�wietli odleg�o�� euklidesow� oraz iloczyn skalarny dla tych wektor�w. */
struct wektor
{
	float wsp[1000];
	const int wymiar;
};
float odlegloscEuklidesowa(struct wektor *w1, struct wektor *w2)
{
	float odleglosc = 0;

	return odleglosc;
}
float iloczynSkalarny(struct wektor *w1, struct wektor *w2)
{
	float iloczyn = 0;

	return iloczyn;
}
void Wyk5Zad11()
{
	int wymiar;

	do
	{
		printf("Podaj ilosc wymiarow wektorow: ");
		scanf("%d", &wymiar);
	} while (wymiar < 1000);

	struct wektor w1 = { { 0 }, wymiar };
	struct wektor w2 = { { 0 }, wymiar };
}