

#ifndef CHESS__SIGNALS_HPP__INCLUDED
#define CHESS__SIGNALS_HPP__INCLUDED

// Qt include.
#include <QObject>


namespace Chess {

//
// Signals
//

//! Signals.
class Signals
	:	public QObject
{
	Q_OBJECT

public:
	//! Color.
	enum Color {
		//! White.
		White = 0,
		//! Black.
		Black = 1
	}; // enum Color

	Q_ENUM( Color )

	enum TransformationFigure {
		Queen = 0,
		Castle = 1,
		Knight = 2,
		Bishop = 3
	}; // enum TransformationFigure

	Q_ENUM( TransformationFigure )

signals:
	//! Checkmate.
	void checkmate();
	//! Draw game.
	void drawgame();
	//! Transformation.
	void pawnTransformation( int color, int fx, int fy );
	//! Rotate board.
	void rotate( int angle );
	//! Turn made.
	void turnMade();
	//! No more undo.
	void noMoreUndo();

public:
	Signals()
	{
	}

	virtual ~Signals()
	{
	}
}; // class Signals

} /* namespace Chess */

#endif // CHESS__SIGNALS_HPP__INCLUDED
