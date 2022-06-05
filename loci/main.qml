import QtQuick
import "."

Window {
    id: mainWindow
    //property int maxWidth
    //property int maxHeight
    visibility: "Maximized"
    visible: true
    title: qsTr("Loci")

    Loader {
        id: page_loader
        anchors.fill: parent
        source : "deckscreen.qml"
        visible: true
    }


    //For saving previous user window size
    /*Component.onCompleted: {
        maxWidth = mainWindow.width
        maxHeight = mainWindow.height
        mainWindow.visibility = "Windowed"
        mainWindow.width = 640
        mainWindow.height = 480
        x = screen.width / 2 - width / 2
        y = screen.height / 2 - height / 2
        //console.log(width)
        //console.log(height)
        console.log(maxWidth)
        //console.log(maxHeight)
        //console.log(screen.width)
        //console.log(screen.height)
        console.log(m_model.m_tableWidth)
    }*/
}
