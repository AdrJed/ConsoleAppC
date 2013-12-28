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
	double tmp = potega(result, (stopien - 1));
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
float potega(float liczba, int wykladnik)
{
	float wynik = liczba;
	if (wykladnik == 0) return 1;
	if (wykladnik == 1) return liczba;
	for (int i = 0; i < wykladnik; i++)
	{
		wynik *= liczba;
	}
	return wynik;
}

struct wynikRK
{
	float W1,W2;
};
struct wynikRK rownanieKwadratowe(const float *Ax2, const float *Bx, const float *C)
{
	struct wynikRK wRK;
	float delta = ((*Bx) * (*Bx)) - (4 * (*Ax2) * (*C));

	if (delta == 0)
	{
		wRK.W1 = (-(*Bx)) / (2 * (*Ax2));
		wRK.W2 = 0;
		return wRK;
	}
	else if (delta > 0)
	{
		wRK.W1 = ((-(*Bx)) - pierwiastek(delta, 2)) / (2 * (*Ax2));
		wRK.W2 = ((-(*Bx)) + pierwiastek(delta, 2)) / (2 * (*Ax2));
		return wRK;
	}
	else
	{
		wRK.W1 = 0; 
		wRK.W2 = 0;
		return wRK;
	}

}