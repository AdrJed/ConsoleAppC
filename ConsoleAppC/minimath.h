// Mini biblioteka matematyczna - nag³ówek
// Dodawanie nowych funkcji w miarê zapotrzebowania

//double silnia(double n);
double modul(double a);
double pierwiastek(double liczba, int stopien);
float potega(float liczba, int wykladnik);
struct wynikRK
{
	float W1, W2;
};
struct wynikRK rownanieKwadratowe(const float *Ax2, const float *Bx, const float *C)