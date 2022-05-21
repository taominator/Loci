import QtQuick

Item {
    anchors.fill: parent

    TopBar {
        id: top_bar
    }

    Rectangle{
        id:deck_list
        color: "blue"
        width: parent.width /5
        anchors {
            left: parent.left
            top: top_bar.bottom
            bottom:parent.bottom
        }
    }

    Rectangle {
        id: deck_table
        color: "lime"
        width: parent.width * (4/5)
        height: parent.height
        anchors {
            left: deck_list.right
            top: top_bar.bottom
        }
    }

}
