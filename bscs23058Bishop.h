#pragma once
#include"bscs23058piece.h"
#include"bscs23058board.h";
class Bishop:
	public piece
{
public:
	Bishop(int sr, int sc, int er, int ec, COLOR _C);
	bool islegalmove(int sr, int sc, int er, int ec);
	void draw()override;
	/*~Bishop() {};*/
};

