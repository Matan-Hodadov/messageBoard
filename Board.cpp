#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <exception>
#include <vector>

#include "Board.hpp"
using namespace std;
using ariel::Direction;

namespace ariel
{
    const uint starting_size = 0;
    const uint max_size = UINT32_MAX;

    Board::Board()
    {
        this->firstRow = max_size;
        this->firstCol = max_size;
        this->lastRow = starting_size;
        this->lastCol = starting_size;

        // board=vector<vector<char>>(rowEdge, vector<char>(colEdge, '_'));
        board = vector<vector<char>>();
        
    }

    void Board::post(uint row, uint col, Direction dir, std::string msg)
    {
        uint msgLen = msg.length();
        fitSize(row, col, msgLen, dir);
        if (dir == Direction::Horizontal)
        {
            if (col + msgLen > max_size)
            {
                msgLen = max_size - col;
            }
            for (size_t i = 0; i < msgLen; i++)
            {
                board[row][col+i] = msg.at(i);
            }
        }
        else
        {
            if (row + msgLen > max_size)
            {
                msgLen = max_size - row;
            }
            for (size_t i = 0; i < msgLen; i++)
            {
                board[row+i][col] = msg.at(i);
            }
        }
    }
    string Board::read(uint row, uint col, Direction dir, uint len)
    {
        string msg;
        if (dir == Direction::Horizontal)
        {
            for (size_t i = 0; i < len; i++)
            {
                if (row <= this->lastRow && row >= this->firstRow && col+i <= this->lastCol && col >= this->firstRow)
                {
                    msg += board[row][col+i];
                }
                else
                {
                    msg += '_';
                }
            }  
        }
        else
        {
            for (size_t i = 0; i < len; i++)
            {
                if (row+i <= this->lastRow && row >= this->firstRow && col <= this->lastCol && col >= this->firstRow)
                {
                    msg += board[row+i][col];
                }
                else
                {
                    msg += '_';
                }
                
            }
        }
        return msg;
    }
    void Board::show()
    {
        if(this->lastRow == starting_size)
        {
            cout << "\n The board is empty. feel free to add some msg\n" << endl;
        }
        else
        {
            uint rowNum = this->firstRow;
            uint totalCol = (this->lastCol) - (this->firstCol) + 1;
            uint totalRow = (this->lastRow) - (this->firstRow) + 1;

            for (size_t i = 0; i < totalRow; i++)
            {
                cout << rowNum << ":" << read(rowNum, this->firstCol, Direction::Horizontal, totalCol);
            }   
        }
    }

    void Board::fitSize(uint row, uint col, uint len, Direction dir)
    {
        this->firstRow = min(row, firstRow);
        this->firstCol = min(col, this->firstCol);

        if(dir == Direction::Horizontal)
        {
            this->lastCol = max(this->lastCol, col+len);
            this->lastRow = max(row+1, this->lastRow);
        }
        else
        {
            this->lastRow = max(this->lastRow, row+len);
            this->lastCol = max(col+1, this->lastCol);
        }
        board.resize(this->lastRow);
        for (size_t i = 0; i < this->lastRow; i++)
        {
            board[i].resize(this->lastCol, '_');
        }
    }
}