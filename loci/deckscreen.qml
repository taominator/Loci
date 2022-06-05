import QtQuick

Item {
    anchors.fill: parent

    Rectangle {
        id: deckRect
        width: parent.width * (1/5)
        color: "gray"
        anchors {
            top: parent.top
            left:parent.left
            bottom: parent.bottom
        }
    }

    Rectangle {
        id: rightRect
        width: parent.width * (4/5)
        color: "#E2F7F7"
        anchors {
            top: parent.top
            right:parent.right
            bottom: parent.bottom
        }

        Rectangle {
            id: tableRect
            height: parent.height * (1/2)
            color: "#EAF9F9"
            anchors {
                top: parent.top
                right: parent.right
                left: parent.left

                leftMargin: m_model.getBorderWidth()
                rightMargin: m_model.getBorderWidth()
                topMargin: m_model.getBorderWidth() / 2
            }

            DeckTableView {
            }

            Component.onCompleted: {
                console.log(anchors.leftMargin)
                console.log(anchors.rightMargin)
            }
        }
    }
}
