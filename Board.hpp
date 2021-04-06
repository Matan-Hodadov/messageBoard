#pragma once

#include <string>
#include "Direction.hpp"

namespace ariel {

    typedef unsigned int uint;
    
	class Board
    {
        private:
            std::vector<std::vector<char>> board;
            void fitSize(uint row, uint col, uint len, Direction dir);
            uint firstRow;
            uint firstCol;
            uint lastRow;
            uint lastCol;

        public:
        Board();
        void post(uint row, uint col, Direction dir, std::string msg);
        std::string read(uint row, uint col, Direction dir, uint len);
        void show();
    };
}