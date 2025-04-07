#pragma once
#include "bscs23058piece.h"

class pawn : public piece {
public:
    pawn(int sr, int sc, int er, int ec, COLOR _C);
    void draw() override;
    bool islegalmove(int sr, int sc, int er, int ec) override;
};
