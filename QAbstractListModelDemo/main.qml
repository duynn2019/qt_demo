import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
    width: 640
    height: 640
    Component {
        id: delegate
        Item {
            width: 200; height: 200
            scale: PathView.iconScale
            opacity: PathView.iconOpacity
            z: PathView.iconOrder
            Image { anchors.fill: parent; source: modelData }
        }
    }

    PathView {
        id: view
        anchors.fill: parent
        anchors.bottomMargin: 150
        anchors.topMargin: 50
        pathItemCount: 7
        preferredHighlightBegin: 0.5                         //
        preferredHighlightEnd: 0.5                           // That should center the current item
        highlightRangeMode: PathView.StrictlyEnforceRange    //
        model:
            [
            "http://placeimg.com/200/200/any?rand=" + Math.random(),
            "http://placeimg.com/200/200/any?rand=" + Math.random(),
            "http://placeimg.com/200/200/any?rand=" + Math.random(),
            "http://placeimg.com/200/200/any?rand=" + Math.random(),
            "http://placeimg.com/200/200/any?rand=" + Math.random(),
            "http://placeimg.com/200/200/any?rand=" + Math.random(),
            "http://placeimg.com/200/200/any?rand=" + Math.random(),
            "http://placeimg.com/200/200/any?rand=" + Math.random(),
            ]
        delegate: delegate
        path: Path {
            startX: 0; startY: view.height/2
            PathAttribute { name: "iconScale"; value: 0.2 }
            PathAttribute { name: "iconOpacity"; value: 10.2 }
            PathAttribute { name: "iconOrder"; value: 0 }
            PathLine {x: view.width / 2; y: view.height/2 }
            PathAttribute { name: "iconScale"; value: 1.2 }
            PathAttribute { name: "iconOpacity"; value: 1 }
            PathAttribute { name: "iconOrder"; value: 8 }
            PathLine {x: view.width; y: view.height/2 }
        }
    }
}
