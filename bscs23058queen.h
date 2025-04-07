#pragma once
#include "bscs23058Bishop.h"
#include "bscs23058Rook.h"
#include "bscs23058piece.h"
class queen :
    public piece
{
public:
    queen(int sr,int sc,int er,int ec, COLOR _C);
    bool islegalmove(int sr, int sc, int er, int ec);
    void draw()override;
    /*~queen();*/
};

