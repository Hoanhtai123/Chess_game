
#ifndef CHESS__BOARD_HPP__INCLUDED
#define CHESS__BOARD_HPP__INCLUDED

// Chess include.
#include "figures.hpp"
#include "signals.hpp"

// Qt include.
#include <QVector>
#include <QSharedPointer>
#include <QAbstractListModel>

namespace Chess {


//
// Board
//

//! Board.
class Board Q_DECL_FINAL
	:	public QAbstractListModel
{
	Q_OBJECT

public:
	Board();
	virtual ~Board();

	Board( const Board & other );
	Board & operator = ( const Board & other );

	enum RoleNames {
		CellImageSourceRole = Qt::UserRole,
		CurrentPieceColorRole = CellImageSourceRole + 1,
		BluePieceColorRole = CurrentPieceColorRole + 1,
		RedPieceColorRole = BluePieceColorRole + 1,
		CheckPieceColorRole = RedPieceColorRole + 1,
		BorderColorRole = CheckPieceColorRole + 1
	}; // enum RoleNames

	//! Figures on board.
	typedef Figure* FiguresOnBoard[ 8 ][ 8 ];

	//! \return Figures on board.
	//! \note Returned type is two-dimensinal array and indexes are
	//! as in usual C array. I.e. Left white castle has indexes [ 7 ][ 0 ],
	//! whereas all positions in methods are in logical coordinates where
	//! top-left position is ( 0, 0 ), i.e. left white castle will has
	//! position ( 0, 7 ).
	FiguresOnBoard & figures();

	//! \return Figure by index in the array.
	Figure * figure( int index ) const;

	//! Make move.
	void move( int fromX, int fromY, int toX, int toY );

	//! Mark blue.
	void markBlue( int x, int y );
	//! Mark red.
	void markRed( int x, int y );
	//! Mark check.
	void markCheck( int x, int y );
	//! Clear blue|red.
	void clearColors();

	//! \return White king.
	King * whiteKing() const;
	//! \return Black king.
	King * blackKing() const;

	int rowCount( const QModelIndex & parent = QModelIndex() ) const
		Q_DECL_OVERRIDE;
	QVariant data( const QModelIndex & index, int role = Qt::DisplayRole ) const
		Q_DECL_OVERRIDE;
	QHash< int, QByteArray > roleNames() const Q_DECL_OVERRIDE;

public slots:
	//! New game.
	void newGame();
	//! Update.
	void update();
	//! Transformation.
	void transformation( Chess::Signals::TransformationFigure figure,
		Chess::Signals::Color c, int x, int y );

private:
	//! Init figures.
	QVector< QSharedPointer< Figure > > initFigures() const;
	//! Copy state of the board.
	void copyState( const Board & other );

private:
	//! Board.
	FiguresOnBoard m_board;
	//! Figures.
	QVector< QSharedPointer< Figure > > m_figures;
	//! Transformed figures.
	QVector< QSharedPointer< Figure > > m_transformed;
	//! White king.
	King * m_whiteKing;
	//! Black king.
	King * m_blackKing;

	enum Color {
		Blue,
		Red,
		Check,
		None
	}; // enum Color

	//! Figures on board.
	typedef Color Colors[ 8 ][ 8 ];

	//! Cells' marks.
	Colors m_colors;
}; // class Board

} /* namespace Chess */

#endif // CHESS__BOARD_HPP__INCLUDED
