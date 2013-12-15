// Mini biblioteka matematyczna - kod Ÿród³owy
// Dodawanie nowych funkcji w miarê zapotrzebowania

double silnia(double n)
{
	if (n == 1) return 1;
	else return n*silnia(n - 1);
}
double modul(double a)
{
	return a < 0 ? -a : a;
}
double pierwiastek(double liczba, int stopien)
{
	//poczatkowe przyblizenie
	double result = liczba;
	//x^n-1
	double tmp = potega((int)result, (stopien - 1));
	//dokladnosc obliczen
	double e = 0.00000001;

	//dopoki wynik jest mniej dokladny niz zadana wartosc
	while (modul(liczba - tmp * result) >= e)
	{
		//oblicz nowe przyblizenie
		result = 1 / stopien*((stopien - 1)*result + (liczba / tmp));
		//x^n-1
		tmp = potega(result, stopien - 1);
	}

	return result;
}
int potega(int liczba, int wykladnik)
{
	if (wykladnik == 0) return 1;
	if (wykladnik == 1) return liczba;
	if (liczba % 2 != 0) return potega(liczba, wykladnik - 1);
	else
	{
		liczba = potega(liczba, wykladnik / 2);
		return liczba*liczba;
	}
}