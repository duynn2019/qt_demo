import QtQuick 2.0
import QtGraphicalEffects 1.0

Rectangle {
    id:coverflow
    color:"red"

    property ListModel model
    property int itemCount: 3

    width: 200
    height: 200

    clip : true

    PathView{
        id:pathView
        model:coverflow.model
        onDragEnded: { console.log("current id:: " + currentIndex.toString())}

        highlightMoveDuration : 1000

        width: 200
        height: 200

        delegate: Item {
            id:delegateItem
            width: 200
            height: 200
            z:PathView.iconZ
            scale:PathView.iconScale

            Image{
                id:image
                source: url
                width: delegateItem.width
                height: delegateItem.height
            }
            Text {
                text: abc.toString()
                anchors.centerIn: parent
                font.pixelSize: 50
            }

            transform: Rotation{
                origin.x:image.width/2.0
                origin.y:image.height/2.0
                axis{x:0;y:1;z:0}
                angle: delegateItem.PathView.iconAngle
            }
        }
        path:coverFlowPath
        pathItemCount: coverflow.itemCount
        anchors.fill: parent

        preferredHighlightBegin: 0.5
        preferredHighlightEnd: 0.5

    }


    Path{
        id:coverFlowPath
        startX: coverflow.width/2
        startY: coverflow.height/2 - 300

        PathAttribute{name:"iconZ";value: 0}
        PathAttribute{name:"iconAngle";value: 0}
        PathAttribute{name:"iconScale";value: 1}

        PathLine{x:coverflow.width/2;y:coverflow.height/2}

        PathAttribute{name:"iconZ";value: 100}
        PathAttribute{name:"iconAngle";value: 0}
        PathAttribute{name:"iconScale";value: 1.0}

        PathLine{x:coverflow.width/2 ;y:coverflow.height/2 + 300}

        PathAttribute{name:"iconZ";value: 0}
        PathAttribute{name:"iconAngle";value: 0}
        PathAttribute{name:"iconScale";value: 1}
        PathPercent{value:1.0}

    }

    Timer {
        interval: 2000; running: true; repeat: true
        onTriggered: pathView.incrementCurrentIndex()
    }

}
