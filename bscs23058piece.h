#pragma once
#include"bscs23058Header.h"
class board;
class piece
{
protected:
	int _sr, _sc, _er, _ec;
	position P;
	COLOR C;
	char sym;
public:
	piece(int _sr,int _sc,int _er,int _ec,COLOR m_c);
	virtual void draw();
	void undraw();
	bool isHorizontal(int sr,int sc,int er,int ec);
	//~piece() {};
	bool isVerticalPath( int sr, int sc, int er, int ec);
	bool isHorizontalPath( int sr, int sc, int er, int ec);
	bool isDiagnolPath(int sr, int sc, int er, int ec);
	void move(int er,int ec);
	bool isHM( int sr, int sc, int er, int ec);
	bool  isDM(int sr, int sc, int er, int ec);
	bool isVM(int sr, int sc, int er, int ec);
	virtual bool islegalmove( int sr, int sc, int er, int ec)=0;
	COLOR getcolor();
	/*bool isbishoplegal(int sr, int sc, int er, int ec);
	bool isrooklegal(int sr, int sc, int er, int ec);
	bool isqueenlegal(int sr, int sc, int er, int ec);*/
};
