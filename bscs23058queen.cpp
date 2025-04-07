#include "bscs23058queen.h"
#include<iostream>
#include"bscs23058Rook.h"
#include"bscs23058Bishop.h"
#include"bscs23058piece.h"
using namespace std;
queen::queen(int sr,int sc,int er,int ec, COLOR _C) :piece(sr,sc,er,ec, _C)
{
	sym = ((_C == BLACK) ? 'Q' : 'q');
}
void queen::draw()
{
	std::cout << sym;
}
bool queen::islegalmove(int sr, int sc, int er, int ec)
{
	//piece* p;
	//Rook r(sr, sc, er, ec, C);
	//Bishop b(sr, sc, er, ec, C);
	return (sr == er ||sc == ec || abs(sr - er) == abs(sc-ec));
}

//queen::~queen()
//{
//
//}