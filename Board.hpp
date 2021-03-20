#pragma once

#include <string>
#include "Direction.hpp"

namespace ariel {
    typedef unsigned int uint;
    class Point
    {
        public:
        uint x,y;
        Point()
        {
            this->x = 0;
            this->y = 0;
        }
    };

	class Board
    {
        public:
        // Point
        Board()
        {
            
        }
        void post(uint x, uint y, Direction dir, std::string str);
        std::string read(uint x, uint y, Direction dir, uint numOfChar);
        void show();
    };
}