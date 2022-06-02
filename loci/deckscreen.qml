import QtQuick

Item {
    anchors.fill: parent

    Rectangle {
        id: redRect
        height: parent.height
        width: parent.width * (4/5)
        color: "red"
        anchors {
            top: parent.top
            right: parent.right
        }

        DeckTableView {
        }

        Component.onCompleted: {
            console.log("Rectangle Height: " + redRect.height)
            console.log("Rectangle Width: " + redRect.width)
        }
    }
}
