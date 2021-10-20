#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#endif // GAMECONTROLLER_H

#include <QObject>
#include "Board.h"
class GameController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString pieces READ pieces NOTIFY piecesChanged)

public:
    GameController(QObject* _parent = nullptr);
    QString pieces() {return  _board.piecesString();}

signals:
    void piecesChanged(QString _pieces);

private:
    Board _board;
};
