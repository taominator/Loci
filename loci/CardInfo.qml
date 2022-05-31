import QtQuick 2.14

Item {
    anchors.fill: parent
    Rectangle {
        anchors.fill:parent
        color:red
        TableView {
            //anchors.fill: parent
            model: m_model

        }
    }
}
