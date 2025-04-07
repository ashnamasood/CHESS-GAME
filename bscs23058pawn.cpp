#include "bscs23058pawn.h"
#include "bscs23058board.h"
#include <cmath>
#include <iostream>

using namespace std;

pawn::pawn(int sr, int sc, int er, int ec, COLOR _C) : piece(sr, sc, er, ec, _C) {
    sym = ((_C == BLACK) ? 'P' : 'p');
}

void pawn::draw() {
    cout << sym;
}

bool pawn::islegalmove(int sr, int sc, int er, int ec) {
    board b;
    int dr = er - sr;
    int dc = ec - sc;
    int absDr = abs(dr);
    int absDc = abs(dc);
    piece* destination = b.getpiece(er, ec);

    if (C == WHITE) {
        if (dr == -1 && absDc == 0 && destination == nullptr) {
            return true; // Move one step forward
        }
        else if (dr == -2 && absDc == 0 && sr == 6 && destination == nullptr) {
            piece* intermediate = b.getpiece(sr - 1, sc);
            return intermediate == nullptr; // Move two steps forward from starting position
        }
        else if (dr == -1 && absDc == 1 && destination != nullptr && destination->getcolor() != C) {
            return true; // Capture diagonally
        }
    }
    else { // BLACK
        if (dr == 1 && absDc == 0 && destination == nullptr) {
            return true; // Move one step forward
        }
        else if (dr == 2 && absDc == 0 && sr == 1 && destination == nullptr) {
            piece* intermediate = b.getpiece(sr + 1, sc);
            return intermediate == nullptr; // Move two steps forward from starting position
        }
        else if (dr == 1 && absDc == 1 && destination != nullptr && destination->getcolor() != C) {
            return true; // Capture diagonally
        }
    }

    return false;
}
