#include "bscs23058king.h"
#include"bscs23058queen.h"
#include<iostream>
#include"bscs23058board.h"
#include"bscs23058piece.h"
king::king(int sr,int sc,int er,int ec, COLOR _C):piece(sr,sc,er,ec,_C)
{
	sym = ((_C == BLACK) ? 'K' : 'k');
}
void king::draw()
{
	std::cout << sym;
}
bool king::islegalmove(int sr, int sc, int er, int ec)
{
	/*queen q(sr, sc, er, ec, C);
	bool isQueenLegal = q.isqueenlegal(sr, sc, er, ec);
    return (isQueenLegal<= 1);*/
	return (abs(sr - er) <= 1)&&(abs(sc-ec)<=1);
}
//king::~king()
//{
//
//}