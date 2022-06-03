import QtQuick

Item {
    anchors.fill: parent

    Rectangle {
        id: rightRect
        width: parent.width * (4/5)
        color: "green"
        anchors {
            top: parent.top
            right:parent.right
            bottom: parent.bottom
        }

        Rectangle {
            id: redRect
            height: parent.height * (1/2)
            color: "red"
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
