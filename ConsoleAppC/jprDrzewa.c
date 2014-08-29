#include <stdio.h>

// struktura drzewa
typedef struct TreeNode
{
	int xt, yt;
	int xb, yb;

	Obiekt *obst;

	TreeNode *tLeft;
	TreeNode *tRight;
	TreeNode *bLeft;
	TreeNode *bRight;
	  
} TreeNode;

typedef struct Obiekt
{
	int x, y;
} Obiekt;

void funkcja()
{
	scanf("%d", 0);
}
