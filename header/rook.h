#ifndef ROOK_H
#define ROOK_H
#include "PieceInf.h"

class Rook : virtual public PieceInf
{
public:
    Rook(ColorPiece _color);
    PieceInf::Type type()
    {
        return PieceInf::Type::Rook;
    }
    bool areDestPermitted(int x_from, int y_from, int x_to, int y_to, Board& _board);
};
#endif // ROOK_H
