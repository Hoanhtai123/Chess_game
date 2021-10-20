#ifndef KING_H
#define KING_H
#include "PieceInf.h"

class King : virtual public PieceInf
{
public:
    King(ColorPiece _color);
    PieceInf::Type type()
    {
        return PieceInf::Type::King;
    }
    bool areDestPermitted(int x_from, int y_from, int x_to, int y_to, Board& _board);
};

#endif // KING_H
