#ifndef QUEEN_H
#define QUEEN_H
#include "PieceInf.h"

class Queen : virtual public PieceInf
{
public:
    Queen(ColorPiece _color);
    PieceInf::Type type()
    {
        return PieceInf::Type::Queen;
    }
    bool areDestPermitted(int x_from, int y_from, int x_to, int y_to, Board& _board);
};
#endif // QUEEN_H
