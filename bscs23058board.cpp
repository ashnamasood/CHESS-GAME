#include "bscs23058board.h"
#include"bscs23058pawn.h"
#include "bscs23058king.h"
#include "bscs23058Knight.h"
#include "bscs23058queen.h"
#include "bscs23058Bishop.h"
#include "bscs23058Header.h"
#include "bscs23058piece.h"
#include "bscs23058Rook.h"
#include<iostream>
using namespace std;
#include<windows.h>
void setConsoleColor(int foreground, int background) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foreground + (background * 16));
}
void setCursorPosition(int x, int y) {
	COORD coordinates = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOutput, scrn);
}
board::board() {
    dim = 8;
    boxSize = 1;
    ps = new piece * *[dim];
    for (int i = 0; i < dim; i++) {
        ps[i] = new piece * [dim] {};
        for (int j = 0; j < dim; j++) {
            ps[i][j] = nullptr;
            highlightedPositions[i][j] = false; 
        }
    }
    init();
    continuegame = true;
}
void board::init() {
    for (int r = 0; r < dim; r++) {
        for (int c = 0; c < dim; c++) {
            if (r == 1) {
                ps[r][c] = new pawn(sr,sc,er, ec,BLACK);
            }
            else if (r == 6) {
                ps[r][c] = new pawn(r, c, r, c, WHITE);
            }
            else if (r == 0 || r == 7) {
                if (c == 0 || c == 7)
                    ps[r][c] = new Rook(sr, sc, er, ec, r == 0 ? BLACK : WHITE);
                else if (c == 1 || c == 6)
                    ps[r][c] = new Knight(sr, sc, er, ec, r == 0 ? BLACK : WHITE);
                else if (c == 2 || c == 5)
                    ps[r][c] = new Bishop(sr, sc, er, ec,r == 0 ? BLACK : WHITE);
                else if (c == 3)
                    ps[r][c] = new queen(sr, sc, er, ec, r == 0 ? BLACK : WHITE);
                else if (c == 4)
                    ps[r][c] = new king(sr, sc, er, ec, r == 0 ? BLACK : WHITE);
            }
            else {
                ps[r][c] = nullptr;
            }
        }
    }
}
void board::draw() {
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if ((r + c) % 2 == 0) {
                setConsoleColor(0, 3); 
            }
            else {
                setConsoleColor(0, 11);
            }

            if (ps[r][c] != nullptr) {
                ps[r][c]->draw();
            }
            else {
                gotoRowCol(r, c);
                if (highlightedPositions[r][c]) {
                    setConsoleColor(15,4); 
                    cout << "x";
                }
                else {
                    cout << "-";
                }
            }
        }
        cout << endl;
    }
    setConsoleColor(15, 0);
}
piece* board::getpiece(int r, int c) {
    if (r >= 0 && r < 8 && c >= 0 && c < 8)
    {
        return ps[r][c];
    }
    return nullptr;
}
bool board::isvalid(int sr, int sc, int er, int ec)
{
    
    {
        if (er < 0 || er>7 || ec < 0 || ec>7)
        {
            return false;
        }
        return true;
    }
}
bool board::HVDPC(int sr, int sc, int er, int ec)
{
    int dr = (er > sr) ? 1 : ((er < sr) ? -1 : 0);
    int dc = (ec > sc) ? 1 : ((ec < sc) ? -1 : 0);
    int r = sr + dr;
    int c = sc + dc;
    while (r!=er || c!=ec)
    {
        if (ps[r][c] != nullptr)
        {
            return false;
        }r += dr;
        c += dc;
    }
    return true;
}
//void board::move(int sr, int sc, int er, int ec, int& turn)
//{
//    if (!isvalid(sr, sc, er, ec))
//    {
//        return;
//    }
//    piece* pis = ps[sr][sc];
//    if (pis == nullptr)
//    {
//        return;
//    }
//    if (!pis->islegalmove(sr, sc, er, ec))
//    {
//        return;
//    }
//    ps[er][ec] = pis;
//    ps[sr][sc] = nullptr;
//    turn = turnchange(turn);
//    if (isCheckmate(turn)) {
//        // End the game if in checkmate
//        continuegame = false;
//    }
//}
void board::turnmsg(int turn)
{
    if (turn==0)
    {
        cout << "Player1(White)'s Turn" << endl;
    }
    else
    {
        cout << "Player2(Black)'s Turn" << endl;
    }
}
void board::updateboard(int sr, int sc, int er, int ec, int& turn) {
    move(sr, sc, er, ec, turn); 
    draw();
    turn = turnchange(turn); 
    turnmsg(turn); 
}
int board:: turnchange(int turn)
{
    return (turn + 1) % 2;
}
bool board::highlight(int sr, int sc) {

    piece* pis = ps[sr][sc];

    if (pis == nullptr) {
        return false;
    }

    
    memset(highlightedPositions, 0, sizeof(highlightedPositions));

    
    bool highlighted = false;

   
    for (int er = 0; er < dim; er++) {
        for (int ec = 0; ec < dim; ec++) {
            if (pis->islegalmove(sr, sc, er, ec)) { 
                if (ps[er][ec] == nullptr || ps[er][ec]->getcolor() != pis->getcolor()) {
                    highlightedPositions[er][ec] = true; 
                    highlighted = true;
                }
            }
        }
    }
    return highlighted; 
}
void board::findKing(int color, int& kingRow, int& kingCol) {
    for (int r = 0; r < dim; r++) {
        for (int c = 0; c < dim; c++) {
            piece* p = ps[r][c];
            if (p != nullptr && p->getcolor() == color && dynamic_cast<king*>(p) != nullptr) {
                kingRow = r;
                kingCol = c;
                return;
            }
        }
    }
}
bool board::isUnderThreat(int kingRow, int kingCol, int color) {
    for (int r = 0; r < dim; r++) {
        for (int c = 0; c < dim; c++) {
            piece* p = ps[r][c];
            if (p != nullptr && p->getcolor() != color) {
                // Check if the opponent's piece can attack the king's position
                if (p->islegalmove(r, c, kingRow, kingCol)) {
                    return true;
                }
            }
        }
    }
    return false;
}
bool board::isCheckmate(int color) {
    // Check if the player is in check
    if (!isInCheck(color)) {
        return false; // Player is not in checkmate
    }

    // Check if the player can make any move to escape check
    for (int sr = 0; sr < dim; sr++) {
        for (int sc = 0; sc < dim; sc++) {
            piece* p = ps[sr][sc];
            if (p != nullptr && p->getcolor() == color) {
                for (int er = 0; er < dim; er++) {
                    for (int ec = 0; ec < dim; ec++) {
                        if (p->islegalmove(sr, sc, er, ec)) {
                            // Try making the move and see if the king is still under threat
                            piece* capturedPiece = ps[er][ec];
                            ps[er][ec] = p;
                            ps[sr][sc] = nullptr;
                            bool inCheckAfterMove = isInCheck(color);
                            ps[sr][sc] = p;
                            ps[er][ec] = capturedPiece;
                            if (!inCheckAfterMove) {
                                return false; // Player can escape check
                            }
                        }
                    }
                }
            }
        }
    }

    return true; // Player is in checkmate
}
bool board::isInCheck(int color) {
    
    int kingRow, kingCol;
    findKing(color, kingRow, kingCol);

    for (int r = 0; r < dim; r++) {
        for (int c = 0; c < dim; c++) {
            piece* p = ps[r][c];
            if (p != nullptr && p->getcolor() != color) {
               
                if (p->islegalmove(r, c, kingRow, kingCol)) {
                    return true;
                }
            }
        }
    }
    return false; 
}
bool board::isKingCaptured() {
    int whiteKingCount = 0;
    int blackKingCount = 0;
    for (int r = 0; r < dim; r++) {
        for (int c = 0; c < dim; c++) {
            if (dynamic_cast<king*>(ps[r][c]) != nullptr) {
                if (ps[r][c]->getcolor() == WHITE) {
                    whiteKingCount++;
                }
                else if (ps[r][c]->getcolor() == BLACK) {
                    blackKingCount++;
                }
            }
        }
    }
    return whiteKingCount == 0 || blackKingCount == 0;
}
void board::move(int sr, int sc, int er, int ec, int& turn) {
    if (!isvalid(sr, sc, er, ec)) {
        return;
    }
    piece* pis = ps[sr][sc];
    if (pis == nullptr) {
        return;
    }
    if (!pis->islegalmove(sr, sc, er, ec)) {
        return;
    }
    ps[er][ec] = pis;
    ps[sr][sc] = nullptr;
    turn = turnchange(turn);

    if (isKingCaptured()) {
        continuegame = false;
    }
}
bool board::isSelfCheck(int sr, int sc, int er, int ec, int color) {
    
    piece* tempDest = ps[er][ec];
    piece* tempSrc = ps[sr][sc];
    ps[er][ec] = ps[sr][sc];
    ps[sr][sc] = nullptr;

    
    int kingRow, kingCol;
    findKing(color, kingRow, kingCol);
    bool selfCheck = isUnderThreat(kingRow, kingCol, color);

   
    ps[sr][sc] = tempSrc;
    ps[er][ec] = tempDest;

    return selfCheck;
}
bool board:: isStalemate(int color)
{
    
    for (int sr = 0; sr < dim; sr++) {
        for (int sc = 0; sc < dim; sc++) {
            piece* p = ps[sr][sc];
            if (p != nullptr && p->getcolor() == color) {
                for (int er = 0; er < dim; er++) {
                    for (int ec = 0; ec < dim; ec++) {
                        if (p->islegalmove(sr, sc, er, ec)) {
                            
                            piece* capturedPiece = ps[er][ec];
                            ps[er][ec] = p;
                            ps[sr][sc] = nullptr;
                            bool inCheckAfterMove = isInCheck(color);
                            ps[sr][sc] = p;
                            ps[er][ec] = capturedPiece;
                            if (!inCheckAfterMove) {
                                return false; 
                            }
                        }
                    }
                }
            }
        }
    }

    return true; 
}


