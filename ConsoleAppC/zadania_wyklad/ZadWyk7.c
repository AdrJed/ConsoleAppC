#include <stdio.h>
#include <stdlib.h>

/* 7.1 Zaimplementuj program zamieniaj¹cy ci¹g zer i jedynek na liczbê w systemie dziesiêtnym zak³adaj¹c,
	¿e ci¹g bitów reprezentuje liczbê ca³kowit¹ za pomoc¹ naturalnego kodu binarnego.*/
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
/* 7.2 Zaimplementuj program zamieniaj¹cy ci¹g zer i jedynek na liczbê w systemie dziesiêtnym zak³adaj¹c,
	¿e ci¹g bitów koduje liczbê ca³kowit¹ ze znakiem w reprezentacji uzupe³nieniowej do dwóch U2.*/
int U2ToDec(char *U2)
{

}
void Wyk7Zad2()
{

}
/* 7.3 Zaimplementuj program zamieniaj¹cy ci¹g 32 bitów(zer i jedynek) na liczbê rzeczywist¹ zak³adaj¹c,
	¿e ci¹g bitów koduje liczbê zmiennopozycyjn¹ pojedynczej precyzji zgodnie ze standardem IEEE 754.*/
float bit32ToFloat(char *bit32)
{

}
void Wyk7Zad3()
{
	char bit32[32] = { '0' };
}
/* 7.4 Skonstruuj algorytm, który ma na celu wyznaczenie najwiêkszej mo¿liwej liczby dodatniej mo¿liwej do reprezentacji w
	pojedynczej precyzji.Zaimplementuj ten algorytm i porównaj uzyskan¹ wartoœæ ze sta³¹ FLT_MAX zdefiniowan¹ w pliku nag³ówkowym float.h . */ 
char* floatMax()
{

}
void Wyk7Zad4()
{

}
/* 7.5 Skonstruuj algorytm, który ma na celu wyznaczenie najmniejszej liczby dodatniej wiêkszej od zera w reprezentacji pojedynczej precyzji.
	Zaimplementuj ten algorytm i porównaj uzyskan¹ wartoœæ ze sta³¹ FLT_MIN zdefiniowan¹ w pliku nag³ówkowym float.h . */
char *floatMin()
{

}
void Wyk7Zad5()
{

}
/* 7.6 Napisz program, który zamienia ci¹g cyfr na liczbê w systemie dziesiêtnym, zak³adaj¹c, ¿e podany ci¹g liczb reprezentuje
	liczbê ca³kowit¹ dodatni¹ zapisan¹ w systemie pozycyjnym o podstawie n, gdzie liczba n jest podan¹ przez u¿ytkownika
	liczb¹ ca³kowit¹ z zakresu od 2 do 9. */
int customSystemToInt(char *value, int podstawa)
{

}
void Wyk7Zad6()
{

}
