#include "header/pawn.h"
#include "header/Board.h"
#define CLASS Pawn

CLASS::Pawn(ColorPiece _color)
    : PieceInf(_color)
{
}

bool CLASS::check(int x_from, int y_from, int x_to, int y_to)
{
    if(color()== ColorPiece::White)
    {
        if(x_from + 1 == x_to)
        {
            return true;
        }
    }
    else
        if(x_from - 1 == x_to)
        {
            return true;
        }
    return false;
}

bool CLASS::areDestPermitted(int x_from, int y_from, int x_to, int y_to, Board& _board)
{

    auto dest = _board.getPiecesMatrix().at(y_to).at(x_to);
    if(!dest)
    {
        if(y_to == y_from)
        {
            if(check(x_from, y_from, x_to, y_to))
            {
                return true;
            }
        }
    }
    else
    {
        if((y_from == y_to + 1) || (y_from == y_to - 1))
        {
            if (check(x_from, y_from, x_to, y_to))
            {
                return true;
            }
        }
    }
    return false;

}
