import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3
ApplicationWindow
{
    visible: true
    width: 400
    height: 400
    title: qsTr("Hello World")
    function getLetter(index)
    {
        var letter = GameControl.pieces[index];
        return letter;
    }

    function isWhite(index){
        var letter = getLetter(index);
        return letter === letter.toUpperCase();
    }

    Grid {
        id: chessgrid
        anchors.fill: parent
        rows: 8
        columns: 8
        Repeater {
            id: repeater
            model: 64
            DropArea {
                id: dropArea
                width: chessgrid.height/8
                height: width
                onDropped: console.log("dropped")
                onEntered: console.log("entered")
                Rectangle {
                    id: cell1
                    height: chessgrid.height/8
                    width: height
                    color: {
                        if ((Math.floor(index/8)%2) == 0)
                        {
                            if(index%2==1)
                                "black"
                            else
                                "white"
                        }
                        else
                        {
                            if(index%2==1)
                                "white"
                            else
                                "black"
                        }
                    }
                    states:[
                        State {
                            when: dropArea.containsDrag
                            PropertyChanges {
                                target: cell1; color : "grey"
                            }
                        }
                    ]
                }
            }
        }
    }
        Grid {
            id : pieceGrid
            anchors.fill: parent
            rows: 8
            columns: 8
            Repeater {

                model: 64


                Circle {
                    height: chessgrid.height/8
                    white_color: isWhite(index)
                    text1Text: getLetter(index)
                    circleColor :
                    {
                        if (getLetter(index) !== ' ')
                            return "red"
                        else
                            return "transparent"
                    }



                }
            }

        }
}


/*##^##
Designer {
    D{i:0;formeditorZoom:1.66}
}
##^##*/

