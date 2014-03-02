#include <stdio.h>
#include <stdbool.h>

#include "ZadInne.h"
#include "ZadWyk3.h"
#include "ZadWyk4.h"
#include "ZadWyk5.h"
#include "ZadWyk6.h"
#include "ZadWyk7.h"
#include "ZadWyk8.h"
#include "ZadWyk9.h"
#include "macierze2.h"

/* Maksymalny indeks w tablicy struktur dostêpnych programów.
Sprawdziæ czy zgadza siê po odkomentowaniu nowego programu */
#define WYK_COUNT 9 // Liczba wyk³adów !!!
#define PROG_COUNT 50 // Liczba programów !!!

/* Funkcja brakProgramu jesli nie znaleziono programu */ 
void brakProgramu()
{
	printf("brak programu \n");
}
/* Wyœwietla informacje o funkcjonalnoœci programu*/
void programInfo()
{
	printf("Adrian Jedrzejak - PROGRAMOWANIE PROCEDURALNE - zadania (v0.01) \n\nPOLECENIA: \n");
	printf("[kod] - uruchamia wybrany program, np: 3.12\n");
	printf("loop [kod] - uruchamia program w petli dopoki nie zostanie wpisane exit\n");
	printf("help [kod] - informacje o programie z podanym kodem\n");
	printf("list - wypisuje dostepne kody programow do uruchomienia\n");
	printf("list [nr wykladu] - wyswietla liste dostepnych programow dla wykladu\n");
	printf("tinfo - informacja o rozmiarach poszczegolnych typow danych\n");
	printf("exit - wyjscie\n");
}
/* Bezpieczna funkcja pobierania argumentow z stdin */
static int getLine(char *prmpt, char *buff, size_t sz) {
#define OK       0
#define NO_INPUT 1
#define TOO_LONG 2

	int ch, extra;

	// Get line with buffer overrun protection.
	if (prmpt != NULL) {
		printf("%s", prmpt);
		fflush(stdout);
	}
	if (fgets(buff, sz, stdin) == NULL)
		return NO_INPUT;

	// If it was too long, there'll be no newline. In that case, we flush
	// to end of line so that excess doesn't affect the next call.
	if (buff[strlen(buff) - 1] != '\n') {
		extra = 0;
		while (((ch = getchar()) != '\n') && (ch != EOF))
			extra = 1;
		return (extra == 1) ? TOO_LONG : OK;
	}

	// Otherwise remove newline and give string back to caller.
	buff[strlen(buff) - 1] = '\0';
	return OK;

#undef OK NO_INPUT TO_LONG
}

/* Struktura programów do uruchomienia  */
struct programContentStruct
{
	short int wykNr; // numer wyk³adu
	short int progNr; // numer programu dla danego wyk³adu
	void (*pPtr)(); // wskaŸnik na funkcjê danego programu
	char *pInfo; // wskaŸnik na informacjê o programie
};
struct programContentStruct findProgramContent(struct programContentStruct pS[], int wNr, int pNr)
{
	for (int i = 0; i < PROG_COUNT; i++)
	{
		if (pS[i].wykNr == wNr && pS[i].progNr == pNr) return pS[i];
	}

	return pS[0]; //Jeœli nie znaleziono odpowiedniego programu, zwróc strukturê brakProgramu
}
/* Funkcja dodaj¹ca do tablicy struktur aktualnie gotowe programy */
void addProgramContent(struct programContentStruct pS[], int p)

{
	/* Aktualnie niegotowe programy s¹ zakomentowane */
	struct programContentStruct pCS[] = {
		[0] = { 0, 0, brakProgramu, "brak programu" },//struktura brakProgramu
		[1] = { 3, 1, Wyk3Zad1, "3.1 - oblicza dla a,b: a+b, a-b, a*b, a/b" },
		[2] = { 3, 2, Wyk3Zad2, "3.2 - sprawdzanie parzystosci liczby" },
		[3] = { 3, 3, Wyk3Zad3, "3.3 - sprawdzanie czy liczba jest pierwsza" },
		[4] = { 3, 4, Wyk3Zad4, "3.4 - wyswietlanie tabliczki mnozenia NxN" },
		[5] = { 3, 5, Wyk3Zad5, "3.5 - rozwiazywanie rownania kwadratowego" },
		[6] = { 3, 6, Wyk3Zad6, "3.6 - obliczanie pola trojkata a,h" },
		[7] = { 3, 7, Wyk3Zad7, "3.7 - wyznaczanie punktu przeciecia dwoch prostych" },
		[8] = { 3, 8, Wyk3Zad8, "3.8 - wyznaczanie x,y dla ukladu rownan" },
		[9] = { 3, 9, Wyk3Zad9, "3.9 - wyswietlanie n elementow ciagu Fibonacciego" },
		[10] = { 3, 10, Wyk3Zad10, "3.10 - NWW dla a,b" },
		[11] = { 3, 11, Wyk3Zad11, "3.11 - rozklad liczby calkowitej na czynniki" },
		[12] = { 3, 12, Wyk3Zad12, "3.12 - wyswietlanie n elementow ciagu Eulera" },
		[13] = { 3, 13, Wyk3Zad13, "3.13 - dodawanie i mnozenie ulamkow" },
		//[] = { 3, 14, Wyk3Zad14, "3.14 - " },
		[15] = { 3, 15, Wyk3Zad15, "3.15 - obliczanie symbolu Newtona - n! / k!*(n-k)!" },	
		[16] = { 3, 16, Wyk3Zad16, "3.16 - polozenie prostej wzgledem okregu" },
		//[] = { 3, 17, Wyk3Zad17, "3.17 - " },
		[18] = { 4, 1, Wyk4Zad1, "4.1 - wyswietlanie liczb pierwszych od 2 do x, sprawdzanie czy liczba jest pierwsza" },
		[19] = { 4, 2, Wyk3Zad10, "4.2 - to co 3.10 - NWW dla a,b" },
		[20] = { 4, 3, Wyk4Zad3, "4.3 - wyswietlanie elementu n ciagu Fibonacciego" },
		[21] = { 4, 4, Wyk3Zad15, "4.4 - to co 3.15 -  oblicznanie dwumianu Newtona" },
		[22] = { 4, 5, Wyk4Zad5, "4.5 - suma pierwszych n wyrazow ciagu arytmetycznego" },
		[23] = { 4, 6, Wyk4Zad6, "4.6 - suma pierwszych n wyrazow ciagu geometrycznego" },
		[24] = { 4, 7, Wyk4Zad7, "4.7 - obliczanie przeciwprostokatnej w trojkacie" },
		[25] = { 5, 1, Wyk5Zad1, "5.1 - zwracanie indeksu maksymalnej wartoœci w zbiorze" },
		[26] = { 5, 2, Wyk5Zad2, "5.2 - sortowanie przez wybor elementow tablicy" },
		[27] = { 5, 3, Wyk5Zad3, "5.3 - sortowanie babelkowe elementow tablicy" },
		[28] = { 5, 4, Wyk5Zad4, "5.4 - Pierwiastki rownania kwadratowego" },
		[29] = { 5, 5, Wyk5Zad5, "5.5 - Obliczanie wielomianu n-tego stopnia dla danego x" },
		[30] = { 5, 6, Wyk5Zad6, "5.6 - Zwracanie struktury z minimalna i maksymalna wartoscia w tablicy" },
		[31] = { 5, 7, Wyk5Zad7, "5.7 - wyznaczanie dla zbioru liczb zmiennopozycyjnych:\n-sumy elementow\n-sumy elementow >0\n-sredniej\n-odchylenia standardowego\n-wariancji\n-rozstepu\nmediany\n-liczby elementow w przedziale <a,b>" },
		[32] = { 5, 8, Wyk5Zad8, "5.8 - dodawanie, odejmowanie, mnozenie liczb urojonych" },
		[33] = { 5, 9, Wyk5Zad9, "5.9 - dodawanie, odejmowanie, mnozenie, dzielenie ulamkow" },
		[34] = { 5, 10, Wyk5Zad10, "5.10 - odleglosc miedzy punktami w przestrzeni 3D " },
		//[] = { 5, 11, Wyk5Zad11, "5.11 - " },
		//[] = { 6, 1, Wyk6Zad1, "6.1 - " },
		//[] = { 6, 2, Wyk6Zad2, "6.2 - " },
		[38] = { 6, 3, Wyk6Zad3, "6.3 - odwracanie elementow w tablicy" },
		[39] = { 7, 1, Wyk7Zad1, "7.1 - zamiana z systemu binarnego w dziesietny" },
		[40] = { 8, 1, Wyk8Zad1, "8.1 - lista znakow ASCII" },
		[41] = { 9, 2, Wyk9Zad2, "9.2 - zapis losowych liczb do pliku" },
		[PROG_COUNT] = { 0, 0, brakProgramu, "koniec listy" },
	};

	for (int i = 0; i < p; i++)
	{
		pS[i] = pCS[i];
	}
}
void runProgram(struct programContentStruct pS[], int wNr, int pNr)
{
	findProgramContent(pS, wNr, pNr).pPtr();
}
void printProgramHelp(struct programContentStruct pS[], int wNr, int pNr)
{
	printf(findProgramContent(pS, wNr, pNr).pInfo);
}
void printProgramList(struct programContentStruct pS[], int wNr)
{
	int listedCount = 0; // Licznik iloœci wyœwietlonych programów

	// Jesli nie wprowadzono numeru wykladu, beda wyswietlone wszystkie programy
	if (wNr == 0)
	{
		for (int i = 0; i < PROG_COUNT; i++)
		{
			if (pS[i].pInfo != NULL)
			{
				printf("%s \n", pS[i].pInfo);
				listedCount++;
			}
		}
		printf("Lacznie programow: %d\n", listedCount);
	}
	// Jesli wprowadzono numer wykladu, listuje dan¹ grupê
	else
	{
		for (int i = 0; i < PROG_COUNT; i++)
		{
			if (pS[i].pInfo != NULL && pS[i].wykNr == wNr)
			{
				printf("%s \n", pS[i].pInfo);
				listedCount++;
			}
		}
		if (listedCount > 0) printf("Lacznie programow: %d\n", listedCount);
		else printf("Brak programow z danego wykladu\n");
	}
}

/* -- PUNKT WEJŒCIA -- */
int main()
{	
	int wN = 0,						// numer wyk³adu
		pN = 0;						// numer programu

	struct programContentStruct selectedPS;// struktura aktualnego programu;
	struct programContentStruct pS[PROG_COUNT];// lista struktur wszystkich dostepnych programow;
	addProgramContent(pS, PROG_COUNT);// dodawanie dostêpnych programów do listy

	programInfo();

	// pêtla pobierania argumentów od u¿ytkownika i wykonywania odpowiedniej akcji
	while (true)
	{
		char args[32] = { '0' };	// wszystkie wprowadzone argumenty
		char arg[32] = { '0' };		// wybrany argument
		wN = 0; pN = 0;				// numer wykladu i programu
		
		fflush(stdin);
		getLine("\n> ", args, sizeof(args));
		sscanf(args, "%s %d.%d", arg, &wN, &pN);

		// listowanie dostêpnych programów
		if (!strcmp("list", arg))
		{
			if (wN <= WYK_COUNT) 
				printProgramList(&pS, wN);
			else 
				printProgramList(&pS, 0);
			continue;
		}
		// zapêtlanie wykonywania wybranego programu
		else if (!strcmp("loop", arg))
		{
			char exitCheck[5] = "null\0";			
			selectedPS = findProgramContent(&pS, wN, pN);
			do
			{
				selectedPS.pPtr();
				printf("\n");			
				fgets(exitCheck, 5, stdin);
			// wychodzi jeœli wprowadzono w wywo³anej funkcji argument 'exit', ktory znajduje sie w stdin
			} while ( strcmp("exit\0", exitCheck) );
			continue;
		}
		// informacje programu o konkretnym numerze
		else if (!strcmp("help", arg))
		{
			if (wN == 0 && pN == 0) programInfo();
			else printProgramHelp(&pS, wN, pN);
			continue;
		}
		// mno¿enie macierzy
		else if (!strcmp("macierze", arg))
		{
			macierze();
			continue;
		}
		// informacja o rozmiarach typow danych komputera
		else if (!strcmp("tinfo", arg))
		{
			//Wskazniki3();
			primitiveTypesSizeInfo();
			continue;
		}
		// przerywa program, jeœli wpisano "exit"
		else if (!strcmp("exit", arg))
		{
			break;					
		}
		
		// Jeœli nie spe³niono powy¿szych warunków, pobierz adres wybranego programu i wykonaj go
		sscanf(args, "%d.%d", &wN, &pN);
		selectedPS = findProgramContent(&pS, wN, pN);
		if (selectedPS.progNr != 0)
		{
			printf("%s\n", selectedPS.pInfo);
			selectedPS.pPtr();
		}
	}

	return 0;
}