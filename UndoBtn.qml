


import QtQuick 2.7

Image {
    property bool enabled: false
    source: "qrc:/img/undo_disabled.png"

    MouseArea {
        anchors.fill: parent

        onPressed: {
            if( undoBtn.enabled )
                undoBtn.source = "qrc:/img/undo_clicked.png"
        }

        onReleased: {
            if( undoBtn.enabled )
                undoBtn.source = "qrc:/img/undo.png"
        }

        onClicked: {
			if( undoBtn.enabled )
			{
				board.undo()
				disable()
			}
        }
    }

    Connections {
        target: board

        function onRotationStarted() {
            disable()
        }

        function onRotationDone() {
            if( gameImpl.turnsCount() > 1 )
                enable()
        }
    }

    function disable() {
        enabled = false
        source = "qrc:/img/undo_disabled.png"
    }

    function enable() {
        enabled = true
        source = "qrc:/img/undo.png"
    }
}
