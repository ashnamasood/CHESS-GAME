#include <iostream>
#include <vector>
#include <string>
#include"bscs23058board.h"
using namespace std;
int main() {
    board b;
    b.init();
    b.draw();
    int sr, sc, er, ec;
    int turn = 0;

    do {
        do {
            getRowColbyLeftClick(sr, sc);
        } while (!b.isvalid(sr, sc, 0, 0));

        if (b.highlight(sr, sc)) {
            b.draw();
        }

        do {
            getRowColbyLeftClick(er, ec);
        } while (!b.isvalid(er, ec, 0, 0));

        if (b.highlightedPositions[er][ec]) {
            system("cls");

            if (b.isInCheck(turn)) {
                cout << "                            Check!" << endl;
            }

            b.move(sr, sc, er, ec, turn);

            if (!b.continuegame) {
                cout << "Checkmate! Player " << (turn == 0 ? 2 : 1) << " wins!" << endl;
                break;
            }

            if (b.isInCheck(b.turnchange(turn))) {
                cout << "                             Check!" << endl;
            }

            b.draw();

            b.turnmsg(b.turnchange(turn));

            turn = b.turnchange(turn);
        }
        else {
            b.draw();
        }
    } while (b.continuegame);

    return 0;
}



