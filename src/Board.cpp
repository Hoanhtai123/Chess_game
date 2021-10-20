#include "header/Board.h"
#include "header/StringParser.h"
#define CLASS Board

const QString Board::INIT_STRING =
    "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

void CLASS::setInit(const QString &initString)
{
    auto _initTuple = StringParser::parseInitString(initString);
    std::tie(_pieces, _color, _moveNumber) = _initTuple;
}

QString CLASS::piecesString()
{
    QString res;
    res.reserve(64);
    for (auto i = 0; i < 8; i++)
    {
        for (auto j = 0; j < 8; j++)
        {
            res.push_front(_pieces.at(j).at(i) ? _pieces.at(j).at(i)->letter() : ' ');
        }
    }
    return res;
}

void CLASS::move(int x_from, int y_from, int x_to, int y_to)
{
    auto currPiece = _pieces.at(y_from).at(x_from);
    if(currPiece)
    {
        if(currPiece->isMovePermitted(x_from, y_from, x_to, y_to, *this))
        {
            _pieces.at(y_to).at(x_to) = currPiece;
            _pieces.at(y_from).at(x_from).reset();
        }
    }
}
