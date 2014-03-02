#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "minimath.h"
#include <math.h>
/* Zadania WYK£AD 3 */

/* 3.1. Napisz program, który wczyta dwie liczby rzeczywiste a i b i wyœwietli wyniki operacji arytmetycznych: a+b, a-b, a*b, a/b.
Zabezpiecz program na wypadek podania danych powoduj¹cych dzielenie przez 0.
Wyniki wyœwietl z dok³adnoœci¹ do 2 miejsc po przecinku. */
void Wyk3Zad1()
{
	float a, b;
	printf("Wprowadz liczby rzeczywiste a,b.\na b: ");
	scanf("%f %f", &a, &b);

	printf("\t %.f \n", a + b);
	printf("\t %.f \n", a - b);
	printf("\t %.f \n", a * b);
	if (b == 0) { printf("Nie mo¿na dzieliæ przez %f", b); }
	else { printf("\t %2.f \n", a / b); }
}
/* 3.2. Napisz program sprawdzaj¹cy, czy wprowadzona przez u¿ytkownika liczba ca³kowita jest liczb¹ podzieln¹ przez 2 (tzn. czy jest parzysta). */
void Wyk3Zad2()
{
	int a = 0;
	printf("Wprowadz liczbe calkowita a.\na: ");
	scanf("%d", &a);

	if (a % 2 == 0) { printf("\t %d jest parzysta \n", a); }
	else { printf("\t %d jest nieparzysta \n", a); }
}
/* 3.3. Napisz program sprawdzaj¹cy, czy wprowadzona przez u¿ytkownika liczba ca³kowita jest liczb¹ pierwsz¹. */
void Wyk3Zad3()
{
#define MAX 4096

	int firstNum = 2, a = 0;
	bool firstNumTab[MAX + 1];
	char input[8];

	for (int x = 2; x <= MAX; x++) { firstNumTab[x] = true; }

	printf("Generowanie tablicy liczb pierwszych < %d \n", MAX);
	for (int i = 2; i*i <= MAX; ++i) // przeszukuj liczby od 2 do pierwiastek(n), 0 i 1 nie s¹ liczbami pierwszymi
	{
		if (firstNumTab[i] == false) // je¿eli dana liczba jest ju¿ wykreœlona
			continue; // to przejdŸ do kolejnej
		for (int j = 2 * i; j <= MAX; j += i) // przejdŸ od liczby 2 * i do n przesuwaj¹c siê o i
			firstNumTab[j] = false; // i ka¿d¹ z nich usuwaj ze zbioru
	}
	printf("\t Wygenerowano \n");
	printf("Wprowadz 0 aby wyjsc.\n");
	//for (int i = 2; i < MAX; i++) { if (firstNumTab[i] == true) printf("%d ", i); }

	do	//	Wykonywanie dopóki liczba poza zakresem {INT_MIN,...,INT_MAX} && a != 0	
	{
		do
		{
			printf("\nWprowadz liczbe calkowita a: ");
			fgets(input, 8, stdin);
			a = atoi(input);
			
			if (a <= MAX && a >= -MAX) { break; } // Przerywanie pêtli je¿eli podana liczba nale¿y do zakresu
			else { printf("Wprowadzono liczbe z poza zakresu tablicy liczb pierwszych \n"); }
		} while (a >= MAX && a <= -MAX);

		if (firstNumTab[a] == true){ printf("Liczba %d jest liczba pierwsza \n", a); }
		else{ printf("Liczba %d nie jest liczba pierwsza \n", a); }
	} while (a != 0);

#undef MAX
}
/* 3.4. Napisz program wyœwietlaj¹cy na ekranie tabliczkê mno¿enia o wymiarach N x N, gdzie wartoœæ ca³kowit¹ N podaje u¿ytkownik. */
void Wyk3Zad4()
{
	int N = 0;

	printf("Podaj wartosc N jako bok tabliczki mnozenia.\nN: ");
	scanf("%d", &N);

	for (int y = 0; y <= N; y++)
	{
		if (y == 0)
		{
			for (int y0 = 0; y0 <= N; y0++) { printf("%d\t", y0); }
			printf("\n\n");
		}
		printf("%d", y);
		for (int x = 0; x <= N; x++) {
			printf("|%d\t", x*y);
			if (x == N) printf("\n");
		}
	}
}
/* 3.5. Napisz program wyznaczaj¹cy miejsca zerowe wielomianu stopnia 2 (paraboli). Do obliczania pierwiastka wykorzystaj algorytm Herona z wyk³adu. */
void Wyk3Zad5()
{
	float a, b, c, delta;
	a = b = c = delta = 0;

	printf("Podaj parametry a,b,c.\na b c: ");
	scanf("%f %f %f", &a, &b, &c);
	delta = (b*b) - (4 * a*c);

	printf("Rownanie ma postac %gx^2 + %gx + %g = 0\n", a, b, c);
	if (delta > 0)
	{
		float x1, x2;
		x1 = (-b - /*pierwiastek*/sqrt(delta)) / 2 * a;
		x2 = (-b + /*pierwiastek*/sqrt(delta)) / 2 * a;

		printf("\tDelta(%g) > 0. Rownanie ma dwa rozwiazania\n", delta);
		printf("\tx1 = %g\tx2 = %g\n", x1, x2);
	}
	else if (delta == 0)
	{
		float x = (-b) / (2 * a);
		printf("\tDelta(%g) = 0. Rownanie ma podwojne rozwiazanie\n", delta);
		printf("\tx = %g\n", x);
	}
	else if (delta < 0)
	{
		printf("\tDelta(%g) < 0. Rownanie nie ma rozwiazan\n", delta);
	}
}
/* 3.6. Napisz program wyznaczaj¹cy pole trójk¹ta dla podanych wartoœci podstawy a i wysokoœci h. */
void Wyk3Zad6()
{
	float a, h, pole;
	printf("Podaj podstawe a i wysokosc h trojkata.\na h: ");
	scanf("%f %f", &a, &h);

	pole = (a*h) / 2;
	printf("Pole podanego trojkata wynosi %gj^2", pole);
}
/* 3.7. Napisz program wyznaczaj¹cy punkt przeciêcia dwóch prostych na p³aszczyŸnie (okreœlonych w dwuwymiarowej przestrzeni) */
void Wyk3Zad7()
{
	float a1, b1, a2, b2, p1, p2;

	printf("Podaj parametry a i b pierwszej prostej y1 = ax1 + b: ");
	scanf("%f %f", &a1, &b1);
	printf("\nPodaj parametry a i b drugiej prostej y2 = ax2 + b: ");
	scanf("%f %f", &a2, &b2);

	p1 = (b2 - b1) / (a1 - a2);
	p2 = a1*p1 + b1;

	printf("Proste przecinaja sie w punkcie P(%g,%g)", p1, p2);
}
/* 3.8. Napisz program znajduj¹cy rozwi¹zanie uk³adu równañ z dwiema niewiadomymi. */
void Wyk3Zad8()
{
	float a1, b1, wynik1,
		a2, b2, wynik2,
		x=1, y=1;

	printf("Podaj rownanie w postaci a1x + b1y = wynik1.\na + b = w: ");
	scanf("%fx + %fy = %f", &a1, &b1, &wynik1);
	printf("Podaj rownanie w postaci a2x + b2y = wynik2.\na + b = w: ");
	scanf("%fx + %fy = %f", &a2, &b2, &wynik2);

	printf("1. %gx + %gy = %g\n", a1, b1, wynik1);
	printf("2. %gx + %gy = %g\n\n", a2, b2, wynik2);

	y = (a2*b1 - a1*b2) / (a2*wynik1 - a1*wynik2);
	x = (wynik1 - b1*y) / a1;

	printf("x = %g\t y = %g", x, y);

}
/* 3.9. Napisz program wyœwietlaj¹cy n pierwszych elementów ci¹gu Fibonacciego */
void Wyk3Zad9()
{
	int n = 0;

	printf("Podaj liczbe n elementow ciagu Fibonacciego: ");
	scanf("%d", &n);

	if (n == 0){ printf("0"); }
	else if (n == 1){ printf("1"); }
	else if (n > 1)
	{
		int a = 0,
			b = 1,
			i = 2;
		printf("%d %d ", a, b);

		while (i <= n)
		{
			b = a + b;
			a = b - a;
			printf("%d ", b);
			i++;
		}
	}
}
/* 3.10. Napisz program wyznaczaj¹cy najmniejsz¹ wspóln¹ wielokrotnoœæ NWW(a,b) dwóch liczb ca³kowitych a i b. */
void Wyk3Zad10()
{
	int a, b, iloczyn,NWW, tmp;
	printf("Podaj a , b dla NWW(a,b): ");
	scanf("%d %d", &a, &b);

	iloczyn = a * b;
	while (a != 0)
	{
		b = b%a;
		tmp = b;
		b = a;
		a = tmp;
	}

	NWW = iloczyn/b;

	printf("NWW: %d ", NWW);
}
/* 3.11. Napisz program przeprowadzaj¹cy rozk³ad dowolnej liczby ca³kowitej na czynniki. */
void Wyk3Zad11()
{
	int a;
	printf("Podaj liczbe calkowita do rozlozenia na czynniki: ");
	scanf("%d", &a);

	int i = 2;

	if (a < 0)
	{
		printf("-");
		a = -a;
	}

	while (a != 1)
	{

		if (a%i == 0)
		{
			a = a / i;
			printf("%d ", i);
		}
		else
		{
			i++;
		}
	}
}
/* 3.12. Napisz program wypisuj¹cy n pierwszych elementów ci¹gu Eulera: a0, a1, … , an-1 */
void Wyk3Zad12()
{
	int n, y;
	printf("Podaj liczbe elementow do wypisania w ciagu (n^2 - n + 41): ");
	scanf("%d", &n);

	for (int i = 0; i <= n; i++)
	{
		y = (i*i) - i + 41;
		printf("y(%d)=%d\t", i, y);
	}
}
/* 3.13. Napisz program wykonuj¹cy dodawanie i mno¿enie dwóch liczb wymiernych (u³amków). Zadbaj o skrócenie wynikowego u³amka. */
struct fraction
{
	int c;// counter - licznik
	int d;// denominator - mianownik
};
struct fraction fReduce(struct fraction F)
{
	if (F.c == F.d)
	{
		F.c = 1; F.d = 1;
		return F;
	}
	else
	{
		int min = (F.c > F.d) ? F.d : F.c;
		int div = 2;
		while (div <= min)
		{
			if (F.c%div == 0 && F.d%div == 0) { F.c /= div; F.d /= div; }
			else { div++; }
		}
		return F;
	}
}
struct fraction fMultiply(struct fraction A, struct fraction B)
{
	struct fraction Result;
	Result.c = A.c * B.c;
	Result.d = A.d * B.d;

	Result = fReduce(Result);
	return Result;
}
struct fraction fAdd(struct fraction A, struct fraction B)
{
	struct fraction Result;

	Result.d = A.d * B.d;
	Result.c = (A.c*B.d) + (B.c*A.d);

	Result = fReduce(Result);
	return Result;
}
void Wyk3Zad13()
{
	struct fraction A;
	struct fraction B;
	struct fraction Result;
	printf("Podaj dwa ulamki do dodania i mnozenia w postaci licznik/mianownik.");
	printf("a/b c/d: ");
	scanf("%d/%d %d/%d", &A.c, &A.d, &B.c, &B.d);
	//A.c = -3; A.d = 4; B.c = 5; B.d = 6;

	Result = fAdd(A, B);
	printf("Wynik dodawania to: ");
	if (Result.c == 0) printf("0\n");
	else if (Result.c < 0 && Result.d < 0) printf("%d/%d\n", -Result.c, -Result.d);
	else if (Result.c > 0 && Result.d < 0) printf("%d/%d\n", -Result.c, -Result.d);
	else printf("%d/%d\n", Result.c, Result.d);

	Result = fMultiply(A, B);
	printf("Wynik mnozenia to: %d/%d\n", Result.c, Result.d);

}
/*TODO: 3.14. Zaproponuj algorytm zamiany dowolnej liczby wymiernej (w postaci u³amka) do postaci u³amka egipskiego.
	Napisz przogram realizuj¹cy tak¹ zamianê. */

/* 3.15. Napisz program wyznaczaj¹cy wartoœæ symbolu Newtona dla dwóch liczb ca³kowitych a i b. */
float silnia2(int n)
{
	long wynik = 1;

	for (int i = 0; i <= n; i++)
		wynik *= i;

	return wynik;
}
void Wyk3Zad15()
{
	int n, k;
	float wynik;

	printf("symbol Newtona (n k) = n! / k!*(n-k)!\n");
	do
	{
		printf("Podaj n k: ");
		scanf("%d %d", &n, &k);
		if (k <= 0 || n < k) printf("n>k>0\t");
	} while ( k<=0 || n<k );

	wynik = silnia2(n) / silnia2(k)*silnia2(n - k);	

	printf("%g", wynik);
}
/* 3.16. Napisz program, który sprawdza czy prosta okreœlona na p³aszczyŸnie przecina zdefiniowane w tek przestrzeni ko³o lub czy jest styczna do ko³a.
U¿ytkownik wprowadza punkt [x,y] okreœlaj¹cy œrodek ko³a oraz jego promieñ r a tak¿e definiuje prost¹ y=ax+b za pomoc¹ wartoœci a i b. */
void Wyk3Zad16()
{
	float Ak, Bk, Rk,
		Ap, Bp, Cp,
		d;

	printf("Podaj wspolrzedne x,y i promien r okregu.\n");
	printf("x,y r: "); scanf("%d,%d %d", &Ak, &Bk, &Rk);
	printf("Podaj wspolrzedne A C prostej y = Ax + C.\n");
	printf("A C: "); scanf("%d %d", &Ap, &Cp); Bp = -1;

	d = abs(Ap*Ak + Bp*Bk + Cp) / sqrt(Ap*Ap + Bp*Bp);
	printf("promien okregu = %g , odleglosc od prostej = %g\n",Rk , d);

	if (Rk > d)
	{
		printf("promien okregu > odleglosc od prostej\n");
		printf("Prosta przecina sie w dwoch punktach z okregiem.\n");
	}
	else if (Rk == d)
	{
		printf("promien okregu == odleglosc od prostej\n");
		printf("Prosta jest styczna do okregu.\n");
	}
	else if (Rk < d)
	{
		printf("promien okregu < odleglosc od prostej\n");
		printf("Prosta nie przecina sie z okregiem.\n");
	}
}

/*TODO: 3.17 Rozszerz powy¿szy program tak aby wyœwietla³ punkty przeciêcia ko³a z prost¹ (je¿eli tylko istniej¹). */
void Wyk3Zad17()
{

}