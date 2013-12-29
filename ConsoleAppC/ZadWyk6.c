
/* 6.1 Zaimplementuj funkcjê rozwi¹zuj¹c¹ uk³ad równañ z 2 niewiadomymi.Funkcja zwraca wartoœæ - 1 je¿eli nie istniej¹ rozwi¹zania(uk³ad jest sprzeczny), 0 je¿eli uk³ad posiada nieskoñczenie wiele rozwi¹zañ oraz 1 je¿eli istnieje rozwi¹zanie.Wartoœci szukane x i y s¹ przekazywane przez adres.
Zaimplementuj program rozwi¹zuj¹cy uk³ad równañ. */
int uklRownan(float *x1, float *y1, float *x2, float *y2)
{

}
void Wyk6Zad1()
{
	printf("");
}
/* 6.2 Zaimplementuj funkcjê znajduj¹c¹ miejsca zerowe paraboli.Wartoœci¹ zwracan¹ funkcji jest liczba ca³kowita okreœlaj¹ca iloœæ miejsc zerowych(0, 1 lub 2).Wartoœci szukane x1 i x2 s¹ przekazywane przez wskaŸnik.
Zaimplementuj program wyznaczaj¹cy miejsca zerowe dla dowolnego wielomianu stopnia 2. */

char f62(const float *a,const float *b,const float *c, float *x1, float *x2)
{

}
void Wyk6Zad2()
{

}
/* 6.3 Zaimplementuj funkcjê odwracaj¹c¹ kolejnoœæ pierwszych n elementów w tablicy liczb zmiennopozycyjnych(typu float).
Wartoœci¹ zwracan¹ funkcji jest adres pierwszego elementu tablicy, tak aby mo¿liwe by³o wywo³anie funkcji odwracanie(odwracanie(tablica, n), n).
Takie wywo³anie powinno w efekcie daæ tablice z elementami u³o¿ynymi w pierwotnej kolejnoœci. */
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