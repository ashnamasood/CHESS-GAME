#include "bscs23058Rook.h"
#include<iostream>
#include"bscs23058board.h"
using namespace std;
#include"bscs23058piece.h"
Rook::Rook(int sr,int sc,int er,int ec, COLOR _C):piece(sr,sc,er,ec, _C)
{
	sym = ((_C == BLACK) ? 'R' : 'r');
}
void Rook::draw()
{
	std::cout << sym;
}
bool Rook::islegalmove(int sr, int sc, int er, int ec)
{
	return (sr == er || sc == ec);
}
//Rook::~Rook()
//{
//
//}