import QtQuick
import "."

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Loci")

    Loader {
        id: page_loader
        anchors.fill: parent
        source : "deckscreen.qml"
        visible: true
    }
}
