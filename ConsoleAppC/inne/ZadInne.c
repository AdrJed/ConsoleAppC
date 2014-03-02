
/* -- Zadania ze wskaŸników -- */
/* 1.1 Napisz program, który wyœwietla informacje o wielkoœci(w bajtach) zmiennych nastêpuj¹cych typów :
shot int, int, long int, long long int(je¿eli siê uda), float, char i double.
Zobacz, jakie s¹ to wielkoœci.Do zbadania wielkoœci danego typu mo¿esz u¿yæ funkcji sizeof(typ).
1.2 Rozbuduj poprzedni program tak, aby pokazywa³ tak¿e rozmiar napisu "Kulfon" oraz rozmiar
nastêpuj¹cych tablic: int[20], float[20], double[20] oraz wielowymiarowych int[5][2][10],
float[5][5][5], i double[2][2][6]. Przed napisaniem programu spróbuj oszacowaæ ile zajmuj¹ w
pamiêci podane tablice. SprawdŸ te¿, ile bajtów pamiêci zajmuje sama zmienna wskaŸnikowa. */
void primitiveTypesSizeInfo()
{
	short int sInt; int I; long int lInt; long long int llInt;
	float F; char c; double D;
	char *cNapis[] = { 'K', 'u', 'l', 'f', 'o', 'n' };
	int iTab[20]; float fTab[20]; double dTab[20];
	int mDimITab[5][2][10]; float mDimFTab[5][5][5]; double mDimDTab[2][2][6];

	printf("Rozmiar typow prymitywnych w bajtach(B)/bitach(b)\n");
	printf(
		" short int = %dB/%db\n int = %dB/%db\n long int = %dB/%db\n long long int = %dB/%db\n float = %dB/%db\n char = %dB/%db\n double = %dB/%db\n",
		sizeof(sInt), sizeof(sInt)* 8, sizeof(I), sizeof(I)*8, sizeof(lInt), sizeof(lInt)*8, sizeof(llInt), sizeof(llInt)*8,
		sizeof(F), sizeof(F)*8, sizeof(c), sizeof(c)*8, sizeof(D),sizeof(D)*8);
	printf(
		" char[6] = %dB\n int[20] = %dB\n float[20] = %dB\n double[20] = %d\n",
		sizeof(cNapis), sizeof(iTab), sizeof(fTab), sizeof(dTab)
		);
	printf(
		" int[5][2][10] = %dB\n float[5][5][5] = %dB\n double[2][2][6] = %dB\n",
		sizeof(mDimITab), sizeof(mDimFTab), sizeof(mDimDTab)
		);
}
/* 2.1 Napisz program, który alokuje tablicê 100 liczb typu int, nastêpnie wpisuje do niej liczby od 0 do 99, a potem usuwa ca³¹ tablicê.
Wykorzystaæ operatory new i delete (tworzenie tablicy : nazwa = new int[rozmiar]; , usuwanie: delete nazwa;). */
void Wskazniki2()
{
	int tSize = 100;
	int *iTab;

	iTab = malloc(tSize * sizeof(*iTab));

	for (int i = 0; i < tSize; i++)
	{
		iTab[i] = i;
		printf("%d ", iTab[i]);
	}

	free(iTab);
}

void Wskazniki3()
{
	int **a[2];
	int *b[2], *c[3];
	int q=1, w=2, e=3, r=4, y=5;

	b[0] = q; b[1] = w;
	c[0] = e; c[1] = r; c[2] = y;

	a[0] = b;
	a[1] = c;

	printf("a[0][0] = %d\na[0][1] = %d\na[1][0] = %d\na[1][1] = %d\n", a[0][0], a[0][1], a[1][0], a[1][2]);
	printf("&a[0][1] = %p, &b[1] = %p", &a[0][1], &b[1]);
	printf("&a[0] = %p\n", &a[0]);

	int ****h=0;
	int ***j=0;
	int **k=0;
	int *l=0;

	h = &j;
	j = &k;
	k = &l;
	l = &q;

	printf("%d", h[0][0][0][0]);

}