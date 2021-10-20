#ifndef PAWN_H
#define PAWN_H
#include "PieceInf.h"

class Pawn : virtual public PieceInf
{
public:
    Pawn(ColorPiece _color);
    PieceInf::Type type()
    {
        return PieceInf::Type::Pawn;
    }
    bool areDestPermitted(int x_from, int y_from, int x_to, int y_to, Board& _board);
    bool check(int x_from, int y_from, int x_to, int y_to);
};
#endif // PAWN_H
