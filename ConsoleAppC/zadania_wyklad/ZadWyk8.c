
/* Zadania WYK�AD 8 */

/* 8.1 Napisz program wypisuj�cy wszystkie znaki kodu ASCII wraz z odpowiadaj�cymi im warto�ciami w postaci dziesi�tnej,
	�semkowej i szesnastkowej. */
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
/* 8.2 Napisz kalkulator wykonuj�cy operacje dodawania, odejmowania, mno�enia i dzielenia bez reszty na liczbach ca�kowitych 
	zawieraj�cych nawet do 200 cyfr.Sygnalizuj odpowiednim komunikatem wyst�pienie nadmiaru. */
void overloadWarningCalc()
{

}
void Wyk8Zad2()
{

}
/* 8.3 Napisz program, kt�ry po wczytaniu jednej linii teksu zako�czy swoje dzia�anie wy�wietlaj�c
	liczb� liter alfabetu podanych w tej linii. */
char* szyfrCezara(char* text)
{

}
void Wyk8Zad3()
{

}
/* 8.4 Napisz program, kt�ry po wczytaniu ca�ego tekstu ze standardowego wej�cia wy�wietli ilo��
wszystkich znak�w w tek�cie, ilo�� linii, ilo�� zda� oraz ilo�� wyraz�w. Zak�adamy, �e zdanie ko�czy si� 
znakiem ., ? lub ! a wyraz to ci�g znak�w drukowalnych oddzielony przynajmniej jednym bia�ym znakiem. */
void Wyk8Zad4()
{

}

/*
8.5 Napisz program, kt�ry odwr�ci wielko�� liter alfabetu w tek�cie wczytanym ze standardowego wej�cia.

8.6 Napisz program zamieniaj�cy w tek�cie wszystkie tabulacje na spacje.

8.7 Napisz program, kt�ry wypisze najd�u�szy wiersz tekstu podanego na wej�ciu.

8.8 Napisz program, kt�ry dla podanego na wej�ciu tekstu wypisze linie zawieraj�ce wyra�enie ''�abc�'.

8.9 Napisz program szyfruj�cy podany ci�g znak�w za pomoc� szyfru Cezara.

8.10 Napisz program szyfruj�cy podany ci�g znak�w za pomoc� zmodyfikowanego szyfru Cezara, w kt�rym to u�ytkownik podaje
	o ile miejsc w alfabecie przesuni�ty b�dzie ka�dy znak.

8.11 Napisz funkcj� zamieniaj�c� �a�cuch znakowy na liczb� ca�kowit�

8.12 Napisz funkcj� zamieniaj�c� �a�cuch na liczb� float

8.13 Program pozwalaj�cy zamienia� liczby pomi�dzy systemami liczbowymi o podstawach od 2 do 16.
	U�ytkownik podaje podstaw� systemu wej�ciowego oraz docelowego oraz liczb� wyra�on� w systemie wej�ciowym (np. szesnastkowym).

8.14 Napisz program, kt�ry dla podanego na standardowym wej�ciu tekstu wyznaczy cz�sto�ci wyst�powania wszystkich drukowalnych 
	znak�w kodu ASCII

8.15 Napisz program, kt�ry ka�dy wyraz z dowolnego tekstu wej�ciowego wypisuje w osobnej linii

8.16 Napisz program tworz�cy histogram d�ugo�ci s��w wej�ciowych. W wersji trudniejszej histogram powinien by� rysowany poziomo.

8.17 Napisz program zamieniaj�cy tekst wej�ciowy podany w kodowaniu latin2 na kodowanie cp1250.

*/