import QtQuick

Rectangle {
    height: parent.height / 15
    anchors {
        right: parent.right
        left: parent.left
        top: parent.top
    }
    color: "red"

    Rectangle {
        id: home_button
        width: parent.width/6
        anchors {
            left: parent.left
            top: parent.top
            bottom: parent.bottom
        }
        color: "purple"
    }

    Rectangle {
        id: deck_button
        width: parent.width/6
        anchors {
            left: home_button.right
            top: parent.top
            bottom: parent.bottom
        }
        color: "cyan"
    }

    Rectangle {
        id: search_button
        width: parent.width/6
        anchors {
            right: parent.right
            top: parent.top
            bottom: parent.bottom
        }
        color: "yellow"
    }

}
