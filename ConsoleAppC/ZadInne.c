
/* -- Zadania ze wska�nik�w -- */
/* 1.1 Napisz program, kt�ry wy�wietla informacje o wielko�ci(w bajtach) zmiennych nast�puj�cych typ�w :
shot int, int, long int, long long int(je�eli si� uda), float, char i double.
Zobacz, jakie s� to wielko�ci.Do zbadania wielko�ci danego typu mo�esz u�y� funkcji sizeof(typ).
1.2 Rozbuduj poprzedni program tak, aby pokazywa� tak�e rozmiar napisu "Kulfon" oraz rozmiar
nast�puj�cych tablic: int[20], float[20], double[20] oraz wielowymiarowych int[5][2][10],
float[5][5][5], i double[2][2][6]. Przed napisaniem programu spr�buj oszacowa� ile zajmuj� w
pami�ci podane tablice. Sprawd� te�, ile bajt�w pami�ci zajmuje sama zmienna wska�nikowa. */
void Wskazniki1()
{
	short int sInt; int I; long int lInt; long long int llInt;
	float F; char c; double D;
	char *cNapis[] = { 'K', 'u', 'l', 'f', 'o', 'n' };
	int iTab[20]; float fTab[20]; double dTab[20];
	int mDimITab[5][2][10]; float mDimFTab[5][5][5]; double mDimDTab[2][2][6];

	printf("Size of variables in bytes (B)\n");
	printf(
		" short int = %d\n int = %d\n long int = %d\n long long int = %d\n float = %d\n char = %d\n double = %d\n",
		sizeof(sInt), sizeof(I), sizeof(lInt), sizeof(llInt), sizeof(F), sizeof(c), sizeof(D));
	printf(
		" char[6] = %d\n int[20] = %d\n float[20] = %d\n double[20] = %d\n",
		sizeof(cNapis), sizeof(iTab), sizeof(fTab), sizeof(dTab)
		);
	printf(
		" int[5][2][10] = %d\n float[5][5][5] = %d\n double[2][2][6] = %d\n",
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