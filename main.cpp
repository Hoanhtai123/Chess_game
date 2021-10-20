#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>

// Chess include.
#include "header/game.hpp"
#include "header/board.hpp"
#include "header/signals.hpp"


int main( int argc, char ** argv )
{
    QGuiApplication app( argc, argv );

    QIcon appIcon( "img/icon256x256.png" );
    appIcon.addFile( "img/icon128x128.png" );
    appIcon.addFile( "img/icon64x64.png" );
    appIcon.addFile( "img/icon48x48.png" );
    appIcon.addFile( "img/icon32x32.png" );
    appIcon.addFile( "img/icon22x22.png" );
    appIcon.addFile( "img/icon16x16.png" );
    appIcon.addFile( "img/icon8x8.png" );
    app.setWindowIcon( appIcon );


    QQmlApplicationEngine engine;
    Chess::Board board;
    Chess::Signals sigs;

    qmlRegisterType< Chess::Signals > ( "ChessSignals", 1, 0, "Chess" );

    engine.rootContext()->setContextProperty( "chessBoard", &board );
    engine.rootContext()->setContextProperty( "game", &sigs );

    engine.load( QUrl( "qrc:/main.qml" ) );

    if( engine.rootObjects().isEmpty() )
        return -1;

    try {
        Chess::Game game( engine.rootObjects().first(), board, sigs );

        engine.rootContext()->setContextProperty( "gameImpl", &game );

        return app.exec();
    }
    catch( const Chess::Error & )
    {
        return -1;
    }
}
