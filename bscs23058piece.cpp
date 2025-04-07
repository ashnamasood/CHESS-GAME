
#include<iostream>
#include "bscs23058piece.h"
using namespace std;
#include"bscs23058board.h"
piece::piece(int sr,int sc,int er,int ec, COLOR c)
{
    _sr = sr;
    _sc = sc;
    _ec = ec;
    _er = er;
    C = c;
}
void piece::draw()
{
    gotoRowCol(_sr, _sc);
    cout << sym;
}
void piece::undraw()
{
    gotoRowCol(_er, _ec);
    cout << " ";
}
//bool piece::isHM(int sr, int sc, int er, int ec)
//{
//    return sr == er;
//}
//bool piece::isVM(int sr, int sc, int er, int ec)
//{
//    return sc == ec;
//}
//bool piece::isDM(int sr, int sc, int er, int ec)
//{
//    int dr = er - sr;
//    int dc = ec - sc;
//    return abs(dr) == abs(dc);
//}
bool piece::isHorizontalPath( int sr, int sc, int er, int ec)
{
    return sr == er && abs(sc - ec) == 1;
}
bool piece::isVerticalPath(int sr, int sc, int er, int ec)
{
    return sc == ec && abs(sr - er) == 1;
}
bool piece::isDiagnolPath(int sr, int sc, int er, int ec)
{
    return abs(sr - er) == 1 && abs(sc - ec) == 1;
}
void piece::move(int er, int ec)
{
    _er = er;
    _ec = ec;
}

COLOR piece::getcolor()
{
    return C;
}
//bool piece::isbishoplegal(int sr, int sc, int er, int ec)
//{
//    return isDM(sr, sc, er, ec);
//}
//bool piece::isrooklegal(int sr, int sc, int er, int ec)
//{
//    return isHM(sr, sc, er, ec) && isVM(sr, sc, er, ec);
//}
//bool piece::isqueenlegal(int sr, int sc, int er, int ec)
//{
//    piece* p;
//    //Rook r(sr, sc, er, ec, C);
//    //Bishop b(sr, sc, er, ec, C);
//    bool isRookLegal = p->isrooklegal(sr, sc, er, ec);
//    bool isbishopLegal = p->isbishoplegal(sr, sc, er, ec);
//    return (isRookLegal && isbishopLegal);
//}








