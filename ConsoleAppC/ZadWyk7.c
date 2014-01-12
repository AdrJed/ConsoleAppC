#include <stdio.h>
#include <stdlib.h>

/* 7.1 Zaimplementuj program zamieniaj�cy ci�g zer i jedynek na liczb� w systemie dziesi�tnym zak�adaj�c,
	�e ci�g bit�w reprezentuje liczb� ca�kowit� za pomoc� naturalnego kodu binarnego.*/
void normalizeBitString(char *ciag, int length)
{
	char *tmp = (char*)malloc(length);
	int x = 0, i=0;
	int start = 0;
	
	for (i = 0; i < length; i++)
	{
		if (ciag[i] == '0') start++;
		else break;
	}
	for (i = start; i < length; i++)
	{
		if (ciag[i] == '\0')
		{
			tmp[x] = '\0';
			break;
		}		
		else
		{
			tmp[x] = ciag[i];
			x++;
		}
	}
	for (i = 0; i <= x; i++)
	{
		ciag[i] = tmp[i];
	}

	free(tmp);
}
long long int binToInt(const char *ciag, int length)
{
	int bitLength = 0;
	long long int n = 1;
	long long int result = 0;

	for (int i = 0; i < length; i++)
	{
		if (ciag[i] != '\0') bitLength++;
		else break;
	}

	for (int i=0; i < length; i++)
	{
		if (ciag[i] == '\0') break;
		else if (ciag[i] == '0')continue;
		else
		{
			for (int pow = bitLength; pow > i+1; pow--) n *= 2;
			result += n;
			n = 1;
		}
	}

	return result;
}
void Wyk7Zad1()
{
#define TAB_SIZE 33

	char ciag[TAB_SIZE] = { '\0' };
	long long int result;

	printf("ciag bitow: ");
	fgets(ciag, sizeof(ciag), stdin);
	// usuwa zera z poczatku
	normalizeBitString(ciag, TAB_SIZE);
	result = binToInt(ciag, TAB_SIZE);
	printf("%s -> %lld",ciag, result);

#undef TAB_SIZE
}
/* 7.2 Zaimplementuj program zamieniaj�cy ci�g zer i jedynek na liczb� w systemie dziesi�tnym zak�adaj�c,
	�e ci�g bit�w koduje liczb� ca�kowit� ze znakiem w reprezentacji uzupe�nieniowej do dw�ch U2.*/
int U2ToDec(char *U2)
{

}
void Wyk7Zad2()
{

}
/* 7.3 Zaimplementuj program zamieniaj�cy ci�g 32 bit�w(zer i jedynek) na liczb� rzeczywist� zak�adaj�c,
	�e ci�g bit�w koduje liczb� zmiennopozycyjn� pojedynczej precyzji zgodnie ze standardem IEEE 754.*/
float bit32ToFloat(char *bit32)
{

}
void Wyk7Zad3()
{
	char bit32[32] = { '0' };
}
/* 7.4 Skonstruuj algorytm, kt�ry ma na celu wyznaczenie najwi�kszej mo�liwej liczby dodatniej mo�liwej do reprezentacji w
	pojedynczej precyzji.Zaimplementuj ten algorytm i por�wnaj uzyskan� warto�� ze sta�� FLT_MAX zdefiniowan� w pliku nag��wkowym float.h . */ 
char* floatMax()
{

}
void Wyk7Zad4()
{

}
/* 7.5 Skonstruuj algorytm, kt�ry ma na celu wyznaczenie najmniejszej liczby dodatniej wi�kszej od zera w reprezentacji pojedynczej precyzji.
	Zaimplementuj ten algorytm i por�wnaj uzyskan� warto�� ze sta�� FLT_MIN zdefiniowan� w pliku nag��wkowym float.h . */
char *floatMin()
{

}
void Wyk7Zad5()
{

}
/* 7.6 Napisz program, kt�ry zamienia ci�g cyfr na liczb� w systemie dziesi�tnym, zak�adaj�c, �e podany ci�g liczb reprezentuje
	liczb� ca�kowit� dodatni� zapisan� w systemie pozycyjnym o podstawie n, gdzie liczba n jest podan� przez u�ytkownika
	liczb� ca�kowit� z zakresu od 2 do 9. */
int customSystemToInt(char *value, int podstawa)
{

}
void Wyk7Zad6()
{

}
