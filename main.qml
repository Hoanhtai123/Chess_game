import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: appWindow
    visible: true

    property int offset: 16
    property int minSize: offset * 2 + 50 * 8

    width: minSize
    height: minSize + offset + 64

    Rectangle {
        id: rect
        anchors.fill: parent

        UndoBtn {
            id: undoBtn
            width: Math.min( Math.min( appWindow.width, appWindow.height ) / 10, 64 )
            height: width
            x: appWindow.width - width - 10
            y: 10
        }

        Board {
            id: board
            width: Math.min( parent.width,
                parent.height - offset - undoBtn.height - 10 - turn.height )
            height: Math.min( parent.width,
                parent.height - offset - undoBtn.height - 10 - turn.height )
            x: Math.abs( rect.width - width ) / 2
            y: Math.abs( rect.height - height - turn.height - undoBtn.height - 10 ) / 2 + undoBtn.height + 10

            objectName: "board"
        }

        Text {
            id: turn
            objectName: "turn"
            height: offset
            anchors.horizontalCenter: rect.horizontalCenter
            y: board.y + board.height
            font.bold: true
            font.pointSize: 14

            text: qsTr( "White" )
        }
    }

    CheckMateDialog {
        id: checkmate

        appWindowSize: Qt.size( appWindow.width, appWindow.height )
        turnText: turn.text

        onClosed: { board.newGame() }
    }

    DrawGameDialog {
        id: drawgame

        appWindowSize: Qt.size( appWindow.width, appWindow.height )

        onClosed: { board.newGame() }
    }

    TransformDialog {
        id: transform

        appWindowSize: Qt.size( appWindow.width, appWindow.height )

        onClosed: { board.transformation( figure, color, fx, fy ) }
    }

    Connections {
        target: game

        function onCheckmate() {
            checkmate.open()
        }

        function onDrawgame() {
            drawgame.open()
        }

        function onPawnTransformation( color, fx, fy ) {
            transform.color = color
            transform.fx = fx
            transform.fy = fy

            transform.open()
        }

        function onNoMoreUndo() {
            undoBtn.disable()
        }
    }
}
