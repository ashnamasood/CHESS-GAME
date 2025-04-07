#include "bscs23058Knight.h"
#include<iostream>
#include"bscs23058board.h"
using namespace std;
Knight::Knight(int sr,int sc,int er,int ec, COLOR _C):piece(sr,sc,er,ec,_C)
{
	sym = ((_C == BLACK) ? 'H' : 'h');
}
void Knight::draw()
{
	std::cout << sym;
}
bool Knight::islegalmove(int sr, int sc, int er, int ec)
{
    int dr = abs(sc - ec);
    int dc = abs(sr - er);
    return (dr == 1 && dc == 2) || (dr == 2 && dc == 1);
}
//Knight::~Knight()
//{
//
//}