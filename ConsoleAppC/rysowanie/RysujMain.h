
#ifndef RYSUJ_START_MAIN
#define RYSUJ_START_MAIN 0		/* 1 je�li jest to punkt wej�cia */
#endif

#if RYSUJ_START_MAIN == 1
int main();
#else
int rysujMain();
#endif