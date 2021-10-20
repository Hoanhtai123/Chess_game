#ifndef BISHOP_H
#define BISHOP_H
#include "PieceInf.h"

class Bishop : virtual public PieceInf
{
public:
    Bishop(ColorPiece _color);
    PieceInf::Type type()
    {
        return PieceInf::Type::Bishop;
    }
    bool areDestPermitted(int x_from, int y_from, int x_to, int y_to, Board& _board);
};

#endif // BISHOP_H
