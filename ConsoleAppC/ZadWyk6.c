
/* 6.1 Zaimplementuj funkcj� rozwi�zuj�c� uk�ad r�wna� z 2 niewiadomymi.Funkcja zwraca warto�� - 1 je�eli nie istniej� rozwi�zania(uk�ad jest sprzeczny), 0 je�eli uk�ad posiada niesko�czenie wiele rozwi�za� oraz 1 je�eli istnieje rozwi�zanie.Warto�ci szukane x i y s� przekazywane przez adres.
Zaimplementuj program rozwi�zuj�cy uk�ad r�wna�. */
int uklRownan(float *x1, float *y1, float *x2, float *y2)
{

}
void Wyk6Zad1()
{
	printf("");
}
/* 6.2 Zaimplementuj funkcj� znajduj�c� miejsca zerowe paraboli.Warto�ci� zwracan� funkcji jest liczba ca�kowita okre�laj�ca ilo�� miejsc zerowych(0, 1 lub 2).Warto�ci szukane x1 i x2 s� przekazywane przez wska�nik.
Zaimplementuj program wyznaczaj�cy miejsca zerowe dla dowolnego wielomianu stopnia 2. */

char f62(const float *a,const float *b,const float *c, float *x1, float *x2)
{

}
void Wyk6Zad2()
{

}
/* 6.3 Zaimplementuj funkcj� odwracaj�c� kolejno�� pierwszych n element�w w tablicy liczb zmiennopozycyjnych(typu float).
Warto�ci� zwracan� funkcji jest adres pierwszego elementu tablicy, tak aby mo�liwe by�o wywo�anie funkcji odwracanie(odwracanie(tablica, n), n).
Takie wywo�anie powinno w efekcie da� tablice z elementami u�o�ynymi w pierwotnej kolejno�ci. */
float* odwracanie(float fTab[], int n)
{
	n--;
	float tmp;

	for (int i = 0; i <= n/2; i++)
	{
		tmp = fTab[i];
		fTab[i] = fTab[n - i];
		fTab[n - i] = tmp;
	}

	return fTab;
}
void Wyk6Zad3()
{
#define T_SIZE 10

	float fTab[T_SIZE] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int ileOdwrocic;

	printf("Wprowadz liczby do tablicy:\n");
	for (int i = 0; i < T_SIZE; i++)
	{
		printf("fTab[%d]: ",i);
		scanf("%f", &fTab[i]);
	}

	do
	{
		printf("ile pierwszych elementow odwrocic: ");
		scanf("%d", &ileOdwrocic);
	} while (ileOdwrocic > T_SIZE);

	//odwracanie(odwracanie(fTab, ileOdwrocic), ileOdwrocic);
	odwracanie(fTab, ileOdwrocic);

	for (int i = 0; i < T_SIZE; i++)
	{
		printf("| %g ", fTab[i]);
	}

#undef T_SIZE
}