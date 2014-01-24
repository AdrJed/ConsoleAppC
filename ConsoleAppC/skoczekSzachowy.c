// Problem skoczka szachowego
// Mamy punkty A,B na planszy szachowej 8x8
// Ile ruchów musi wykonaæ konik aby przejœæ z A do B ?
// Konik mo¿e wykonywaæ ruchy nastêpuj¹co:
//	- najpierw ruch o dwa pola w pionie lub poziomie
//  - nastêpnie ruch o jedno pole prostopadle do poprzedniego ruchu w jedn¹ z dwóch stron

struct punkt
{
	char x, y;
};

int ruchySkoczka(struct punkt pStart, struct punkt pStop, char size, int ruchy)
{
	if (pStart.x == pStop.x && pStart.y == pStop.y) return ruchy;
	else if (pStart.x < size - 2 && pStart.y < size - 1)
	{
		pStart.x += 2; 
		pStart.y += 1;
		ruchy++;
		ruchySkoczka(pStart, pStop, size, ruchy);
	}

	//mozliwe ruchy, okreslic warunki dla ruchow

	pStart.x += 2; pStart.y += 1;
	pStart.x += 2; pStart.y -= 1;
	pStart.x -= 2; pStart.y += 1;
	pStart.x -= 2; pStart.y -= 1;

	pStart.y += 2; pStart.x += 1;
	pStart.y += 2; pStart.x -= 1;
	pStart.y -= 2; pStart.x += 1;
	pStart.y -= 2; pStart.x -= 1;
}

void skoczekSzachowy()
{
#define WYMIAR 8
	char plansza[WYMIAR][WYMIAR] = { 0 };
	int ruchy = 0;
	struct punkt pStart = { 0, 0 };
	struct punkt pStop = { 2, 1 };


	plansza[pStart.x][pStart.y] = 1;
	plansza[pStop.x][pStop.y] = 1;

	ruchy = ruchySkoczka(pStart, pStop, WYMIAR, ruchy);


}