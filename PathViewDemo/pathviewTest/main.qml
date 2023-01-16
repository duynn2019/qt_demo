import QtQuick 2.13
import QtQuick.Window 2.13

Window {
    visible: true
    width: 1000
    height: 800
    title: qsTr("Pathview example")

    Rectangle {
        anchors.fill: parent
        anchors.centerIn: parent

        Component {
            id: delegate
            Column {
                id: wrapper
                opacity: PathView.isCurrentItem ? 1 : 0.2
                Image {
                    anchors.horizontalCenter: nameText.horizontalCenter
                    width: 64; height: 64
                    source: icon
                }
                Text {
                    id: nameText
                    text: name
                    font.pointSize: 16
                }
            }
        }

        Rectangle {
            width: 10
            height: 10
            x: 300
            y : 300
            color: "red"
        }


        PathView {
            anchors.fill: parent
            model: kListModel
            delegate: delegate
            path: Path {
                startX: 300; startY: 300
                PathLine { x: 300; y: 200 }
                PathMove { x: 300; y: 400 }
                PathLine { x: 300; y: 400 }

            }
            //key navigation
            focus: true
            highlightMoveDuration: 1000
            Keys.onLeftPressed: decrementCurrentIndex()
            Keys.onRightPressed: incrementCurrentIndex()
        }
    }
}
