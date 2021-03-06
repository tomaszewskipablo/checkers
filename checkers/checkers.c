#include "stdafx.h"
#include "administration.h"
#include "control.h"
#include "beating.h"
#include "checking.h"
#include "definitions.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


int main(int argc, char* argv[]) {

	int tab[8][8] = { {0,1,0,1,0,1,0,1},		// Initial board
					  {1,0,1,0,1,0,1,0},
					  {0,1,0,1,0,1,0,1},
					  {3,0,3,0,3,0,3,0},
					  {0,3,0,3,0,3,0,3},
					  {2,0,2,0,2,0,2,0},
					  {0,2,0,2,0,2,0,2},
					  {2,0,2,0,2,0,2,0}
	};
	
	odczytaj_argumenty(argc, argv, tab);
	
	int turn = WHITE;	// WHITE starts

	while (AnyMovePossible(tab, turn))
	{
		YourMove(tab, turn);
		if (turn == WHITE) turn = BLACK;
		else turn = WHITE;
	}
	if (turn == WHITE) printf("\n\n\tWhite lost");
	else printf("\n\n\tBlack lost");
	return 0;
}



