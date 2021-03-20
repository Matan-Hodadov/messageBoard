#include "doctest.h"
#include "Board.hpp"
#include <string>

using namespace ariel;
using namespace std;

TEST_CASE("post an empty add")
{
    Board board;
    CHECK(board.read(0, 0, Direction::Vertical, 1) == string("_"));
    CHECK(board.read(0, 0, Direction::Horizontal, 1) == string("_"));
    board.post(0, 0, Direction::Horizontal, "");
    CHECK(board.read(0, 0, Direction::Vertical, 1) == string("_"));
    CHECK(board.read(0, 0, Direction::Horizontal, 1) == string("_"));
    board.post(0, 0, Direction::Vertical, "");
    CHECK(board.read(0, 0, Direction::Vertical, 1) == string("_"));
    CHECK(board.read(0, 0, Direction::Horizontal, 1) == string("_"));
}

TEST_CASE("one char read in vertical string")
{
    Board board;
    board.post(1, 1, Direction::Vertical, "VerticalString");
    CHECK(board.read(0, 1, Direction::Horizontal, 2) == string("_V"));
    CHECK(board.read(1, 1, Direction::Horizontal, 2) == string("V_"));
    CHECK(board.read(1, 1, Direction::Horizontal, 1) == string("V"));
    CHECK(board.read(0, 2, Direction::Horizontal, 2) == string("_e"));
    CHECK(board.read(1, 2, Direction::Horizontal, 2) == string("e_"));
    CHECK(board.read(1, 2, Direction::Horizontal, 1) == string("e"));
    CHECK(board.read(0, 3, Direction::Horizontal, 2) == string("_r"));
    CHECK(board.read(1, 3, Direction::Horizontal, 2) == string("r_"));
    CHECK(board.read(1, 3, Direction::Horizontal, 1) == string("r"));
    CHECK(board.read(0, 9, Direction::Horizontal, 2) == string("_S"));
    CHECK(board.read(1, 9, Direction::Horizontal, 2) == string("S_"));
    CHECK(board.read(1, 9, Direction::Horizontal, 1) == string("S"));
    CHECK(board.read(0, 10, Direction::Horizontal, 2) == string("_t"));
    CHECK(board.read(1, 10, Direction::Horizontal, 2) == string("t_"));
    CHECK(board.read(1, 10, Direction::Horizontal, 1) == string("t"));
    CHECK(board.read(0, 14, Direction::Horizontal, 2) == string("_g"));
    CHECK(board.read(1, 14, Direction::Horizontal, 2) == string("g_"));
    CHECK(board.read(1, 14, Direction::Horizontal, 1) == string("g"));
}

TEST_CASE("one char read in horizontal string")
{
    Board board;
    board.post(1, 1, Direction::Horizontal, "HorizontalString");
    CHECK(board.read(1, 0, Direction::Vertical, 2) == string("_H"));
    CHECK(board.read(1, 1, Direction::Vertical, 2) == string("H_"));
    CHECK(board.read(1, 1, Direction::Vertical, 1) == string("H"));
    CHECK(board.read(2, 0, Direction::Vertical, 2) == string("_o"));
    CHECK(board.read(2, 1, Direction::Vertical, 2) == string("o_"));
    CHECK(board.read(2, 1, Direction::Vertical, 1) == string("o"));
    CHECK(board.read(3, 0, Direction::Vertical, 2) == string("_r"));
    CHECK(board.read(3, 1, Direction::Vertical, 2) == string("r_"));
    CHECK(board.read(3, 1, Direction::Vertical, 1) == string("r"));
    CHECK(board.read(11, 0, Direction::Vertical, 2) == string("_S"));
    CHECK(board.read(11, 1, Direction::Vertical, 2) == string("S_"));
    CHECK(board.read(11, 1, Direction::Vertical, 1) == string("S"));
    CHECK(board.read(12, 0, Direction::Vertical, 2) == string("_t"));
    CHECK(board.read(12, 1, Direction::Vertical, 2) == string("t_"));
    CHECK(board.read(12, 1, Direction::Vertical, 1) == string("t"));
    CHECK(board.read(16, 0, Direction::Vertical, 2) == string("_g"));
    CHECK(board.read(16, 1, Direction::Vertical, 2) == string("g_"));
    CHECK(board.read(16, 1, Direction::Vertical, 1) == string("g"));
}

TEST_CASE("crossing adds")
{
    Board board;
    board.post(3, 3, Direction::Horizontal, "cpt");
    CHECK(board.read(3, 3, Direction::Horizontal, 3) == string("cpt"));
    board.post(5, 3, Direction::Vertical, "pt");
    CHECK(board.read(3, 3, Direction::Horizontal, 3) == string("cpp"));
    board.post(3, 4, Direction::Horizontal, "MatanWasHere");
    CHECK(board.read(3, 3, Direction::Vertical, 2) == string("cM"));
    CHECK(board.read(4, 3, Direction::Vertical, 2) == string("pa"));
    CHECK(board.read(5, 3, Direction::Vertical, 2) == string("pt"));
    CHECK(board.read(6, 4, Direction::Horizontal, 4) == string("anWa"));
    CHECK(board.read(9, 2, Direction::Horizontal, 2) == string("as"));
    CHECK(board.read(11, 2, Direction::Horizontal, 4) == string("Here"));
    board.post(8, 2, Direction::Vertical, "Kabom");
    CHECK(board.read(7, 4, Direction::Horizontal, 3) == string("nba"));
    
}

