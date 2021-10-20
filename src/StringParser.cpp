
#include "header/StringParser.h"

#define CLASS StringParser

CLASS::BoardSetting CLASS::parseInitString(const QString& initString)
{
    auto _stringSplitted = initString.split(" ");
    auto _pieceInf = parsePieceString(_stringSplitted[0]);
    auto _firstColorMove = parsePieceColor(_stringSplitted[1]);
    int _maxNumberMove = parseMoveNumber(_stringSplitted[5]);
    return std::make_tuple(_pieceInf, _firstColorMove, _maxNumberMove);
}

Board::PiecesMatrix CLASS::parsePieceString(const QString& pieceString)
{
    auto _pieces = reversed(pieceString.split(FLASH));
    Board::PiecesMatrix _pieceMatrix;
    auto j = 0;
    for (auto const& _piece : _pieces)
    {
        auto i = 0;
        for (auto c : _piece)
        {
            auto ch = c.toLatin1();
            if(isdigit(ch))
            {
                i+= QString(ch).toInt();
                continue;
            }
            auto _color = isupper(ch) ? ColorPiece::White : ColorPiece::Black;
            _pieceMatrix.at(i).at(j) = PieceInf::make(PieceInf::fromLetter(ch), _color);
            ++i;
        }
        ++j;
    }
    return _pieceMatrix;
}

ColorPiece CLASS::parsePieceColor(const QString &pieceColor)
{
    if(pieceColor == 'w')
    {
        return ColorPiece::White;
    }
    else if(pieceColor == 'b')
    {
        return ColorPiece::Black;
    }
    else
        return ColorPiece::Black;
}

int CLASS::parseMoveNumber(const QString &moveNumber)
{
    auto ret = moveNumber.toInt();
    return ret;
}

QStringList CLASS::reversed(const QStringList& _list)
{
    QStringList result;
    result.reserve(_list.size());
    std::reverse_copy(_list.begin(), _list.end(), std::back_inserter(result));
    return result;
}
