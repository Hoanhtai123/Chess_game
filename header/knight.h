#ifndef KNIGHT_H
#define KNIGHT_H
#include "PieceInf.h"

class Knight : virtual public PieceInf
{
public:
    Knight(ColorPiece _color);
    PieceInf::Type type()
    {
        return PieceInf::Type::Knight;
    }
    bool areDestPermitted(int x_from, int y_from, int x_to, int y_to, Board& _board);
};
#endif // KNIGHT_H
