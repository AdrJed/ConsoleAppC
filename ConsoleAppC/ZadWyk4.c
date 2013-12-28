#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define INT_MAX 2147483647

/* Zadania WYKLAD 4 */
/* 4.1.a Napisz funkcjê sprawdzaj¹c¹ czy podana w argumencie liczba ca³kowita n jest liczb¹ pierwsz¹. */
void f41(short int fNumTab[], int *max)
{
	for (int i = 0; i <= max; i++) { fNumTab[i] = true; }
	/*
	for (int i = firstNum; i < x; i++)
	{
		//Liczby podzielne przez zmienn¹ jako niepierwsze - false
		if (i % firstNum == 0)
		{
			fNumTab[i] = 0;
		}
		//Liczby niepodzielne przez zmienn¹ jako pierwsze - true
		else
		{
			fNumTab[i] = 1;
		}
		//Szukanie kolejnej liczby pierwszej do porównania jesli osiagnieto INT_MAX
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
	for (int i = 2; i*i <= max; ++i) // przeszukuj liczby od 2 do sqrt(n), 0 i 1 nie s¹ liczbami pierwszymi
	{
		if (fNumTab[i] == false) // je¿eli dana liczba jest ju¿ wykreœlona
			continue; // to przejdŸ do kolejnej
		for (int j = 2 * i; j <= max; j += i) // przejdŸ od liczby 2 * i do n przesuwaj¹c siê o i
			fNumTab[j] = false; // i ka¿d¹ z nich usuwaj ze zbioru
	}
}
/* 4.1.b Napisz program, który dla podanej przez u¿ytkownika liczby ca³kowitej x, wykorzystuj¹c ow¹ funkcjê wyswietli wszystkie liczby pierwsze z przedzia³u od 2 do x. */
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
/* 4.2. Napisz funkcjê wyznaczaj¹c¹ najmniejsz¹ wspóln¹ wielokrotnoœæ dwóch liczb ca³kowitych a i b. */
//to co 3.10
/* 4.3. Napisz funkcjê, która dla danej wartoœci ca³kowitej n zwróci n-ty wyraz ci¹gu Fibonacciego. */
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
/* 4.4. Napisz funkcjê, która dla danych 2 liczb ca³kowitych, wyznaczy wartoœæ dwumianu Newtona */
//to co 3.15
/* 4.5. Napisz funkcjê zwracaj¹c¹ wartoœæ sumy pierwszych n wyrazów ci¹gu arytmetycznego */
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
/* 4.6. Napisz funkcjê zwracaj¹c¹ wartoœæ sumy pierwszych n wyrazów ci¹gu geometrycznego */
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
/* 4.7. Napisz funkcjê, która dla podanych d³ugoœci boków przyprostok¹tnych trójk¹ta prostok¹tnego zwróci d³ugoœæ boku przeciwprostok¹tnej. */
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
