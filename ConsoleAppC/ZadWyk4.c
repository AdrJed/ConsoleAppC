#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define INT_MAX 2147483647

/* Zadania WYKLAD 4 */
/* 4.1.a Napisz funkcj� sprawdzaj�c� czy podana w argumencie liczba ca�kowita n jest liczb� pierwsz�. */
void f41(short int fNumTab[], int *max)
{
	for (int i = 0; i <= max; i++) { fNumTab[i] = true; }
	/*
	for (int i = firstNum; i < x; i++)
	{
		//Liczby podzielne przez zmienn� jako niepierwsze - false
		if (i % firstNum == 0)
		{
			fNumTab[i] = 0;
		}
		//Liczby niepodzielne przez zmienn� jako pierwsze - true
		else
		{
			fNumTab[i] = 1;
		}
		//Szukanie kolejnej liczby pierwszej do por�wnania jesli osiagnieto INT_MAX
		if (i == x)
		{
			for (int i = 0; i < x; i++)
			{
				if (fNumTab[i] == 1)
				{
					firstNum = i;
					break;
				}
			}
		}
	}
	*/
	for (int i = 2; i*i <= max; ++i) // przeszukuj liczby od 2 do sqrt(n), 0 i 1 nie s� liczbami pierwszymi
	{
		if (fNumTab[i] == false) // je�eli dana liczba jest ju� wykre�lona
			continue; // to przejd� do kolejnej
		for (int j = 2 * i; j <= max; j += i) // przejd� od liczby 2 * i do n przesuwaj�c si� o i
			fNumTab[j] = false; // i ka�d� z nich usuwaj ze zbioru
	}
}
/* 4.1.b Napisz program, kt�ry dla podanej przez u�ytkownika liczby ca�kowitej x, wykorzystuj�c ow� funkcj� wyswietli wszystkie liczby pierwsze z przedzia�u od 2 do x. */
void Wyk4Zad1()
{
	int max = 0,
		firstNum = 2;
	short int *fNumTab;
	do
	{
		printf("Podaj liczbe x. Dla zakresu (2,x) program wyswietli liczby pierwsze: ");
		scanf("%d", &max);
	} while (max < 2 || max > INT_MAX);

	printf("Generowanie tablicy liczb pierwszych od 2 do %d\n", max);
	fNumTab = calloc(max + 1, sizeof(char));
	f41(fNumTab, &max);

	for (int i = 2; i < max; i++) { if (fNumTab[i] == true) printf("%d ", i); }

	free(fNumTab);
}
/* 4.2. Napisz funkcj� wyznaczaj�c� najmniejsz� wsp�ln� wielokrotno�� dw�ch liczb ca�kowitych a i b. */
//to co 3.10
/* 4.3. Napisz funkcj�, kt�ra dla danej warto�ci ca�kowitej n zwr�ci n-ty wyraz ci�gu Fibonacciego. */
int f43(int n)
{
	if (n == 0){ return 0; }
	else if (n == 1){ return 1; }
	else if (n > 1)
	{
		int a = 0,
			b = 1,
			i = 2;

		while (i <= n)
		{
			b = a + b;
			a = b - a;
			i++;
		}
		return b;
	}
}
void Wyk4Zad3()
{
	int n = 0;
	printf("Podaj element n ciagu fibonacciego do wyswietlenia: ");
	scanf("%d", &n);
	printf("fib(%d) = ", f43(n));
}
/* 4.4. Napisz funkcj�, kt�ra dla danych 2 liczb ca�kowitych, wyznaczy warto�� dwumianu Newtona */
//to co 3.15
/* 4.5. Napisz funkcj� zwracaj�c� warto�� sumy pierwszych n wyraz�w ci�gu arytmetycznego */
float f45(int n, float r)
{
	float sum = 0;
	int a1 = 1;
	float an = a1 + (n - 1)*r;
	sum = (a1 + an)*n / 2;

	return sum;
}
void Wyk4Zad5()
{
	int n = 0;
	float r = 0;
	printf("Suma ciagu arytmetycznego.\nn r: ");
	scanf("%d %f", &n, &r);
	printf("%g", f45(n, r));
}
/* 4.6. Napisz funkcj� zwracaj�c� warto�� sumy pierwszych n wyraz�w ci�gu geometrycznego */
float f46(int n, int q)
{
	float sum = 0;
	int a1 = 1;
	float an = a1 * pow(q, n - 1);
	sum = a1 * ((1 - pow(q, n)) / (1 - q));

	return sum;
}
void Wyk4Zad6()
{
	int n = 0;
	int q = 0;
	printf("Suma ciagu geometrycznego.\nn q: ");
	scanf("%d %f", &n, &q);
	printf("%g", f46(n, q));
}
/* 4.7. Napisz funkcj�, kt�ra dla podanych d�ugo�ci bok�w przyprostok�tnych tr�jk�ta prostok�tnego zwr�ci d�ugo�� boku przeciwprostok�tnej. */
float f47(float a, float b)
{
	float c = 0;
	c = sqrt((a*a) + (b*b));
	return c;
}
void Wyk4Zad7()
{
	float a = 0;
	float b = 0;
	printf("Wartosc boku przeciwprostokatnej trojkata.\na b: ");
	scanf("%f %f", &a, &b);
	printf("%g", f47(a, b));
}
