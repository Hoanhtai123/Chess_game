#ifndef PIECEINF_H
#define PIECEINF_H
#include <memory>
#include "Variable.h"

class Board;
class PieceInf
{

public:
    using PieceInfPtr = std::shared_ptr<PieceInf>;
    enum class Type
    {
        Empty  = 32,  // ' '
        Pawn   = 112, // 'p'
        Knight = 110, // 'n'
        Bishop = 98,  // 'b'
        Rook   = 114, // 'r'
        Queen  = 113, // 'q'
        King   = 107  // 'k'
    };
    char letter();
    PieceInf(ColorPiece t_color);
    static PieceInfPtr make(Type t_type, ColorPiece _color);
    static Type fromLetter(char t_ch);
    static char letter(Type t_type);
    virtual Type type() = 0;
    ColorPiece color() { return m_color;}
    bool isMovePermitted(int x_from, int y_from, int x_to, int y_to, Board& _board);
    virtual bool areDestPermitted(int x_from, int y_from, int x_to, int y_to, Board& _board) = 0;
protected:
    ColorPiece m_color;
};
#endif // PIECEINF_H

