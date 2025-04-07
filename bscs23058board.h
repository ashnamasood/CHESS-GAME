#pragma once

#include"bscs23058piece.h"
#include"bscs23058Header.h"


class board
{
    int dim;
    int boxSize;
    piece*** ps;
    int sr, sc, er, ec;
    bool currentturn;

public:
    bool highlightedPositions[8][8];
    board();
    void init();
    void draw();
    void play();
    /*virtual bool islegalmove(board board, int sr, int sc, int er, int ec);*/
    bool isvalid(int sr, int sc, int er, int ec);
    void move(int sr, int sc, int er, int ec, int& turn);
    void pieceat(int r, int c);
   // ~board();
    piece* getpiece(int r, int c);
    bool HVDPC(int sr, int sc, int er, int ec);
    int turnchange(int turn);
    void turnmsg(int turn);
    bool highlight(int sr, int sc);
    //virtual void islegalmove(int sr, int sc, int er, int ec);
    void selectpos(int& r, int& c);
    void updateboard(int sr, int sc, int er, int ec,int& turn);
    void findKing(int color, int& kingRow, int& kingCol);
    bool isUnderThreat(int kingRow, int kingCol, int color);
    bool isInCheck(int color);
    bool isCheckmate(int color);
    bool isStalemate(int color);
    bool continuegame;
    bool isSelfCheck(int sr, int sc, int er, int ec, int color);
    bool isKingCaptured();
};
