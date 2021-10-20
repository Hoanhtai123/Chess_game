


import QtQuick 2.0

Item {
    id: cell

    property alias cellColor: rectangle.color
    property alias border: rectangle.border
    property alias blueProp: blue.visible
    property alias redProp: red.visible
    property alias checkProp: check.visible
    property int chessX
    property int chessY

    signal clicked( int x, int y )
    signal hovered( int x, int y )

    Rectangle {
        id: rectangle
        anchors.fill: parent
        border.width: 1
    }

    Rectangle {
        id: check
        visible: false
        anchors.fill: parent
        color: "#88FFFF00"
    }

    Rectangle {
        id: red
        visible: false
        anchors.fill: parent
        color: "#88FF0000"
    }

    Rectangle {
        id: blue
        visible: false
        anchors.fill: parent
        color: "#880000FF"
    }

    property alias source: image.source

    Image {
        width: parent.width - 5
        height: parent.height - 5
        id: image
        anchors.centerIn: parent
        fillMode: Image.PreserveAspectFit
        horizontalAlignment: Image.AlignHCenter
        verticalAlignment: Image.AlignVCenter
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true

        onClicked: cell.clicked( chessX, chessY )
//        onEntered: cell.hovered( chessX, chessY )
    }
}
