import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 600
    height: 400
    title: qsTr("Cover Flow")

    property int sign: 1

    ListModel{
        id:model
        ListElement{
            url:"qrc:/image/1.jpg"
            abc : 1
        }
        ListElement{
            url:"qrc:/image/2.jpg"
            abc: 2
        }
        ListElement{
            url:"qrc:/image/3.jpg"
            abc: 3
        }
//        ListElement{url:"qrc:/image/4.jpg"}
//        ListElement{url:"qrc:/image/5.jpg"}
    }

    CoverFlow{
        width: 200
        height: 200
        anchors.centerIn: parent
        model:model
    }


    Timer {
        interval: 200; running: true; repeat: true
        onTriggered: {
            for (var i = 0; i < 3; i++)  {
                model.setProperty(i, "abc", sign*i)
                sign = -sign
            }


        }
    }

}
