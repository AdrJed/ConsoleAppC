/* Testowanie ró¿nych funkcji zamieniaj¹cych dwie zmienne */

/* makro do zamiany z u¿yciem operacji XOR */
#define SWAPIntXOR(A,B) ((int)(A)^=(int)(B)^=(A)^=(B))
#define SWAPIntArith(A,B) ((int)(A)-=(int)(B)+=(A)-=(B)-=(B))

void swapIntXOR(int *a, int *b);
void swapIntArith(int *a, int *b);
void swapInt(int *a, int *b);

void swapFuncTest();