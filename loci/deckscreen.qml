import QtQuick

Item {
    anchors.fill: parent

    Rectangle {
        id: deckRect
        width: parent.width * (1/5)
        color: "gray"
        z: 0
        anchors {
            top: parent.top
            left:parent.left
            bottom: parent.bottom
        }
    }

    Rectangle {
        id: rightRect
        width: parent.width * (4/5)
        color: "teal"//"#E2F7F7"
        z: 0
        anchors {
            top: parent.top
            right:parent.right
            bottom: parent.bottom
        }

        Rectangle{
            id: upperRightRect
            height: parent.height * (1/2)
            color: "green"
            anchors {
                top: parent.top
                right: parent.right
                left: parent.left
            }

            Rectangle {
                id: tableRect
                color: "#EAF9F9"
                z: 1
                anchors {
                    top: parent.top
                    right: parent.right
                    left: parent.left
                    bottom: parent.bottom

                    leftMargin: m_model.getBorderWidth()
                    rightMargin: m_model.getBorderWidth()
                    topMargin: m_model.getBorderWidth() / 2
                    bottomMargin: m_model.getBorderWidth() / 2
                }

                DeckTableView {
                }

                Component.onCompleted: {
                    console.log(anchors.leftMargin)
                    console.log(anchors.rightMargin)
                }
            }
        }
        Rectangle {
            id: lowerRightRect
            height: parent.height * (1/2)
            width: rightRect.width
            color: "yellow"
            anchors {
                right: parent.right
                bottom: parent.bottom
            }

            Rectangle {
                id: fieldRect
                color: "#696969"
                z: 1
                anchors {
                    fill: parent

                    leftMargin: m_model.getBorderWidth()
                    rightMargin: m_model.getBorderWidth()
                    topMargin: m_model.getBorderWidth() / 2
                    bottomMargin: m_model.getBorderWidth() / 2
                }

            }
        }
    }
}
