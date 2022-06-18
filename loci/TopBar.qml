import QtQuick

Rectangle {

    property string page: "homescreen.qml"

    height: parent.height * (1/19)
    anchors {
        left: parent.left
        right: parent.right
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
        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            onClicked: {
                page = "homescreen.qml"
            }
        }
        Text {
            text: "Home"
            anchors.centerIn: parent
            font.pixelSize: m_model.getBorderWidth()
        }
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
        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            onClicked: {
                page = "deckscreen.qml"
            }
        }
        Text {
            text: "Browse"
            anchors.centerIn: parent
            font.pixelSize: m_model.getBorderWidth()
        }
    }

    Rectangle {
        id: edit_button
        width: parent.width/6
        anchors {
            left: deck_button.right
            top: parent.top
            bottom: parent.bottom
        }
        color: "gray"
        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            onClicked: {
                page = "deckedit.qml"
            }
        }
        Text {
            text: "Edit decks"
            anchors.centerIn: parent
            font.pixelSize: m_model.getBorderWidth()
        }
    }

    Rectangle {
        id: search_button
        anchors {
            left: edit_button.right
            right: parent.right
            top: parent.top
            bottom: parent.bottom
        }
        color: "green"
    }

}
