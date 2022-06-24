import QtQuick 2.0

Item {
    anchors.fill: parent

    Rectangle {
        color: "red"
        id: page_content
        height: parent.height * (19/20)

        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }


        Rectangle {
            id: card_side
            color: "teal"
            anchors {
                left: parent.left
                right: parent.right
                top: parent.top
                bottom: show_bar.top
            }

            property bool show_front: true
            ListView {
                id: review_view
                anchors.fill: parent

                model: card_model

                delegate: Rectangle {
                    //height: model.row !== m_model.m_numInternalFields ? 0 : m_model.getBorderWidth() * 4
                    //height: card_side.show_front ? (model.row === m_model.m_numInternalFields ? m_model.getBorderWidth() * 4 : 0) : (model.row < m_model.m_numInternalFields ? 0 : m_model.getBorderWidth() * 4)
                    height: dbmanager.get_height(card_side.show_front, model.row)
                    color: "red"
                    clip: true
                    width: review_view.width

                    Text {
                        height: parent.height / 2
                        anchors.centerIn: parent
                        //anchors {
                        //    left: parent.left
                        //    right: parent.right
                        //    top: parent.top
                        //}
                        text: content
                        font.pixelSize: parent.height * (1.5/3)
                    }
                }
            }
        }

        Rectangle {
            id: show_bar
            color: "cyan"
            height: parent.height * (1/10)
            anchors {
                left: parent.left
                right: parent.right
                bottom: parent.bottom
            }

            Text {
                anchors.centerIn: parent
                text: "Show Answer"
                font.pixelSize: parent.height / 3
            }
            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor

                onClicked: {

                    card_side.show_front = false
                    review_view.forceLayout()
                }
            }
        }
    }
}
