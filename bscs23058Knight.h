#pragma once
#include "bscs23058piece.h"
class Knight :
    public piece
{
public:
    Knight(int sr, int sc, int er, int ec, COLOR _C);
    bool islegalmove(int sr, int sc, int er, int ec);
    void draw()override;
  /*  ~Knight() {};*/
};
