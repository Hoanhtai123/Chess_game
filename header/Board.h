#ifndef BOARD_H
#define BOARD_H
#include "PieceInf.h"
#include <tuple>
#include <memory>
#include "QStringList"
class Board
{
public:
    using PieceInfPtr = std::shared_ptr<PieceInf>;
    using PiecesMatrix = std::array<std::array<PieceInfPtr, 8>, 8>;
    static const QString INIT_STRING;
    Board() {}
    void setInit(const QString& initString);
    QString piecesString();
    void move(int x_from, int y_from, int x_to, int y_to);
    PiecesMatrix getPiecesMatrix() {return _pieces;}
protected:
    ColorPiece _color;
    int _moveNumber;
    PiecesMatrix _pieces;

};
#endif // BOARD_H


