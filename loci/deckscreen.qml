import QtQuick

Item {
    anchors.fill: parent

    Rectangle {
        id: redRect
        height: parent.height * (1/2)
        width: parent.width * (4/5)
        color: "red"
        anchors {
            top: parent.top
            right: parent.right

        }

        DeckTableView {
        }

        Component.onCompleted: {
            console.log(anchors.leftMargin)
            console.log(anchors.rightMargin)
        }
    }
}
