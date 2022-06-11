import QtQuick 2.0

Item {
    anchors.fill: parent

    ListView {
        id: listView
        anchors.fill: parent
        clip: true

        model: card_model

        delegate: Rectangle {
            height: m_model.getBorderWidth() * 2
            color: "red"
            anchors {
                left: parent.left
                right: parent.right
            }
            Text {
                height: parent.height / 2
                anchors {
                    left: parent.left
                    right: parent.right
                    top: parent.top
                }
                text: field
            }
            Text {
                height: parent.height / 2
                anchors {
                    left: parent.left
                    right: parent.right
                    bottom: parent.bottom
                }
                text: content
            }
        }
    }
}
