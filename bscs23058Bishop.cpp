#include "bscs23058Bishop.h"
//class piece;
#include "bscs23058piece.h"
#include<iostream>
using namespace std;
Bishop::Bishop(int sr,int sc,int er,int ec, COLOR _C):piece(sr,sc,er,ec,_C)
{
	sym = ((_C == BLACK) ? 'B' : 'b');
}
void Bishop::draw()
{
	std::cout << sym;
}
bool Bishop::islegalmove(int sr, int sc, int er, int ec)
{
	//return isDM(sr,sc,er,ec);
	int dr = abs(er - sr);
	int dc = abs(ec - sc);
	return (dr == dc);
}
//Bishop::~Bishop()
//{
//
//}