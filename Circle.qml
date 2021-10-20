import QtQuick 2.0


Item {
    id: circleForm
    width: height
    height: 200
    property string letter: " "
    property alias displayFontstyleName: display.font.styleName
    property alias text1Text: display.text
    property alias item1Height: circleForm.height
    property bool white_color: false
    property alias circleColor: circle.color
    MouseArea
    {
        id: mouseArea
        width: circleForm.width
        height: circleForm.height
        anchors.centerIn: parent
        enabled: letter !== " "
        drag.target: circle
        onPressed: console.log("Pressed" + index)
        onReleased:
        {
        }
        Rectangle {
            id: circle
            color: "#bd1313"
            radius: height*0.5
            anchors.fill: parent
            Drag.active: mouseArea.drag.active
            Drag.hotSpot.x : circleForm.width/2
            Drag.hotSpot.y: circleForm.height/2

            Text {
                id: display
                color: white_color ? "white" : "black"
                text: letter
                anchors.fill: parent
                font.pixelSize: item1Height/10
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
            }
        }

    }


}
