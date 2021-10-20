#ifndef STRINGPARSER_H
#define STRINGPARSER_H
#include <QStringList>
#include "Board.h"
class StringParser
{
public:
    using BoardSetting = std::tuple<Board::PiecesMatrix, ColorPiece, int>;
    static const char FLASH = '/';
    static BoardSetting parseInitString(const QString& initString);
    static Board::PiecesMatrix parsePieceString(const QString& pieceString);
    static ColorPiece parsePieceColor(const QString& pieceColor);
    static int parseMoveNumber(const QString& moveNumber);
    static QStringList reversed(const QStringList& _list);
};
#endif // STRINGPARSER_H


