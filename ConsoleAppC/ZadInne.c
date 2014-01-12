
/* -- Zadania ze wska�nik�w -- */
/* 1.1 Napisz program, kt�ry wy�wietla informacje o wielko�ci(w bajtach) zmiennych nast�puj�cych typ�w :
shot int, int, long int, long long int(je�eli si� uda), float, char i double.
Zobacz, jakie s� to wielko�ci.Do zbadania wielko�ci danego typu mo�esz u�y� funkcji sizeof(typ).
1.2 Rozbuduj poprzedni program tak, aby pokazywa� tak�e rozmiar napisu "Kulfon" oraz rozmiar
nast�puj�cych tablic: int[20], float[20], double[20] oraz wielowymiarowych int[5][2][10],
float[5][5][5], i double[2][2][6]. Przed napisaniem programu spr�buj oszacowa� ile zajmuj� w
pami�ci podane tablice. Sprawd� te�, ile bajt�w pami�ci zajmuje sama zmienna wska�nikowa. */
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
/* 2.1 Napisz program, kt�ry alokuje tablic� 100 liczb typu int, nast�pnie wpisuje do niej liczby od 0 do 99, a potem usuwa ca�� tablic�.
Wykorzysta� operatory new i delete (tworzenie tablicy : nazwa = new int[rozmiar]; , usuwanie: delete nazwa;). */
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