// EightQueens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

typedef int Board[8][8];

void PrintBoard(Board board) {
    for(int j = 0; j < 8; ++j) {
        for(int i = 7; i >= 0; --i) {
            if(board[i][j] == 0) {
                putwchar(L'.');
            } else {
                putwchar(L'*');
            }
        }
        _putws(L"");
    }
    _putws(L"");
}

bool ValidatePosition(Board board, int column, int row) {
    for(int i = 1; i <= column; ++i) {
        int current_column = column-i;

        // check horizontal axis
        if(board[current_column][row] != 0) {
            return false;
        }

        // check upper diagonal
        if((row+i < 8) && (board[current_column][row+i] != 0)) {
            return false;
        }

        // check lower diagonal
        if((row-i >= 0) && (board[current_column][row-i] != 0)) {
            return false;
        }
    }
    return true;
}

void NextPosition(Board board, int column) {
    if(column == 8) {
        PrintBoard(board);
    } else {
        for(int row = 0; row < 8; ++row) {
            if(ValidatePosition(board, column, row)) {
                board[column][row] = 1;
                NextPosition(board, column+1);
                board[column][row] = 0;
            }
        }
    }
}

int _tmain(int argc, _TCHAR* argv[]) {

    // initialize the board
    Board board;
    memset(board, 0, sizeof(board));

    // find positions
    NextPosition(board, 0);
    return 0;
}

