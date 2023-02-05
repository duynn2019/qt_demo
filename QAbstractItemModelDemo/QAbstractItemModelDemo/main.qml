import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15


Window {
    width: 800
    height: 600
    visible: true
    title: qsTr("Hello World")

    property int propertyListViewWidth: 0
    Column {
        width: 800
        anchors.top: parent.top
        anchors.bottom: textView.top
        TextField {
            id : textInput
            height: 40
            width: parent.width
        }

        Button {
            text: "Emit data"
            onClicked: {
                console.log("Input ::" + textInput.text )
                qmlcontrol.emitData(parseInt(textInput.text))
            }
        }

        Button {
            text: "Remove data"
            onClicked: {
                console.log("Input ::" + textInput.text )
                console.log("Width text" + textExam.width)
                qmlcontrol.removeData(parseInt(textInput.text))
            }
        }

        Text {
            x: 100
            id: textExam
            text: qsTr("The Timer type is synchronized with the animation timer.    The Timer type is synchronized with the animation timer")
        }


    }

    Rectangle {
        height: 300
        width: 300
        anchors.bottom: parent.bottom
        clip: true
        id : textView

        Rectangle {

        }

        ListView{
            id: listView
            height: 300
            width: 1000
            anchors.bottom: parent.bottom
            spacing: 50
            orientation: ListView.Horizontal
            model: qmlcontrol.getModel()
            clip: false

            delegate: Text {
                    height: 50
                    text : "Data" + dataInt + "::" + listView.width
                }

            move: Transition {
                     NumberAnimation { properties: "x,y"; duration: 1000 }
            }

        }

        Timer {
            interval: 50; running: true; repeat: true
            onTriggered: {
                if ( textExam.x > - textExam.width)
                {
                    textExam.x = textExam.x - 1
                }
                else {
                    textExam.x = 100
                }
            }
        }
    }

}
