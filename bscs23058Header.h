#pragma once
struct position
{
	int ri;
	int ci;
};
enum  COLOR{BLACK,WHITE};
void getRowColbyLeftClick(int& rpos, int& cpos);
void gotoRowCol(int rpos, int cpos);