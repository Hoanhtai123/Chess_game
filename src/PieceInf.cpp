#include "header/PieceInf.h"
#include "header/rook.h"
#include "header/knight.h"
#include "header/bishop.h"
#include "header/queen.h"
#include "header/king.h"
#include "header/pawn.h"
#include "header/Board.h"
#define CLASS PieceInf

CLASS::PieceInf(ColorPiece t_color):m_color(t_color)
{

}

CLASS::PieceInfPtr CLASS::make(Type t_type, ColorPiece t_side)
{
    using std::make_shared;
    switch (t_type) {
    case Type::Pawn:
        return make_shared<Pawn>(t_side);
    case Type::Knight:
        return make_shared<Knight>(t_side);
    case Type::Bishop:
        return make_shared<Bishop>(t_side);
    case Type::Rook:
        return make_shared<Rook>(t_side);
    case Type::Queen:
        return make_shared<Queen>(t_side);
    case Type::King:
        return make_shared<King>(t_side);
    default:
        return make_shared<Pawn>(t_side);
    }
}

char CLASS::letter()
{
    auto alpha = letter(type());
    return (m_color == ColorPiece::White) ? toupper(alpha) : alpha;
}

char CLASS::letter(Type t_type)
{
    return static_cast<char>(t_type);
}

CLASS::Type CLASS::fromLetter(char t_ch)
{
    return static_cast<Type>(tolower(t_ch));
}

bool CLASS::isMovePermitted(int x_from, int y_from, int x_to, int y_to, Board& _board)
{
    auto dest = _board.getPiecesMatrix().at(y_to).at(x_to);
    if(!dest)
    {
        if(m_color != dest->color())
        {
            return areDestPermitted(x_from, y_from, x_to, y_to, _board);
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}


