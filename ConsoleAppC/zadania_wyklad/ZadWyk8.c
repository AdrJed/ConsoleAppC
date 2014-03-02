
/* Zadania WYK£AD 8 */

/* 8.1 Napisz program wypisuj¹cy wszystkie znaki kodu ASCII wraz z odpowiadaj¹cymi im wartoœciami w postaci dziesiêtnej,
	ósemkowej i szesnastkowej. */
void listASCII()
{
	int i;
	printf("\t  ASCII\t  Dec\t  Oct\t  Hex  \n");
	printf("\t%c", 201);for(i=0;i<31;i++)printf("%c", 205); printf("%c\n", 187);
	for (int i = 0; i < 256; i++)
	{
		printf("\t%c %c\t%c %d\t %c%o\t %c%x \t%c\n",186, i,186, i,186, i,186, i, 186);
	}
	printf("\t%c", 200);for(i=0;i<31;i++)printf("%c",205); printf("%c\n", 188);
}
void Wyk8Zad1()
{
	listASCII();
}
/* 8.2 Napisz kalkulator wykonuj¹cy operacje dodawania, odejmowania, mno¿enia i dzielenia bez reszty na liczbach ca³kowitych 
	zawieraj¹cych nawet do 200 cyfr.Sygnalizuj odpowiednim komunikatem wyst¹pienie nadmiaru. */
void overloadWarningCalc()
{

}
void Wyk8Zad2()
{

}
/* 8.3 Napisz program, który po wczytaniu jednej linii teksu zakoñczy swoje dzia³anie wyœwietlaj¹c
	liczbê liter alfabetu podanych w tej linii. */
char* szyfrCezara(char* text)
{

}
void Wyk8Zad3()
{

}
/* 8.4 Napisz program, który po wczytaniu ca³ego tekstu ze standardowego wejœcia wyœwietli iloœæ
wszystkich znaków w tekœcie, iloœæ linii, iloœæ zdañ oraz iloœæ wyrazów. Zak³adamy, ¿e zdanie koñczy siê 
znakiem ., ? lub ! a wyraz to ci¹g znaków drukowalnych oddzielony przynajmniej jednym bia³ym znakiem. */
void Wyk8Zad4()
{

}

/*
8.5 Napisz program, który odwróci wielkoœæ liter alfabetu w tekœcie wczytanym ze standardowego wejœcia.

8.6 Napisz program zamieniaj¹cy w tekœcie wszystkie tabulacje na spacje.

8.7 Napisz program, który wypisze najd³u¿szy wiersz tekstu podanego na wejœciu.

8.8 Napisz program, który dla podanego na wejœciu tekstu wypisze linie zawieraj¹ce wyra¿enie ''„abc”'.

8.9 Napisz program szyfruj¹cy podany ci¹g znaków za pomoc¹ szyfru Cezara.

8.10 Napisz program szyfruj¹cy podany ci¹g znaków za pomoc¹ zmodyfikowanego szyfru Cezara, w którym to u¿ytkownik podaje
	o ile miejsc w alfabecie przesuniêty bêdzie ka¿dy znak.

8.11 Napisz funkcjê zamieniaj¹c¹ ³añcuch znakowy na liczbê ca³kowit¹

8.12 Napisz funkcjê zamieniaj¹c¹ ³añcuch na liczbê float

8.13 Program pozwalaj¹cy zamieniaæ liczby pomiêdzy systemami liczbowymi o podstawach od 2 do 16.
	U¿ytkownik podaje podstawê systemu wejœciowego oraz docelowego oraz liczbê wyra¿on¹ w systemie wejœciowym (np. szesnastkowym).

8.14 Napisz program, który dla podanego na standardowym wejœciu tekstu wyznaczy czêstoœci wystêpowania wszystkich drukowalnych 
	znaków kodu ASCII

8.15 Napisz program, który ka¿dy wyraz z dowolnego tekstu wejœciowego wypisuje w osobnej linii

8.16 Napisz program tworz¹cy histogram d³ugoœci s³ów wejœciowych. W wersji trudniejszej histogram powinien byæ rysowany poziomo.

8.17 Napisz program zamieniaj¹cy tekst wejœciowy podany w kodowaniu latin2 na kodowanie cp1250.

*/