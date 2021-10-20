#include "header/gamecontroller.h"

#define CLASS GameController

CLASS::GameController(QObject* _parent): QObject(_parent)
{
    _board.setInit(_board.INIT_STRING);
    piecesChanged(_board.piecesString());
}


