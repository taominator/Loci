import QtQuick
import "."

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Loci")

    Loader {
        id: page_loader
        anchors.fill: parent
        source : "homescreen.qml"
        visible: true
    }
}
