#pragma once
#include "bscs23058piece.h"
class king :
    public piece
{
public:
    king(int sr, int sc, int er, int ec, COLOR _C);
    bool islegalmove(int sr, int sc, int er, int ec);
    void draw()override;
   /* ~king() {};*/
};

