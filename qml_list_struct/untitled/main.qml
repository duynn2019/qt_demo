import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")


    Rectangle {

        Column {
            anchors.fill: parent
            Text{
                text: myModel.lstr[0].name1
            }
            Text{
                text: myModel.mystr.name1
            }
            Text{
                text:  myModel.lstr[1].name1
            }
            Button {
                onClicked: {myModel.handle()}
            }
        }


    }

}
