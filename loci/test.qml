import QtQuick
import QtQuick.Window
import QtQuick.Controls

Item {
    anchors.fill:parent

    // Uncomment this, if you want to call query from qml
    // If you uncomment this, remember to comment out the followin line in main.cpp
    // mysqlModel.callSql("SELECT * FROM users");

    //    Component.onCompleted: {
    //        MysqlModel.callSql("SELECT * FROM users")
    //    }

    TableView {
        id: tableView

        columnWidthProvider: function (column) { return 100; }
        rowHeightProvider: function (column) { return 60; }
        anchors.fill: parent

        ScrollBar.horizontal: ScrollBar{}
        ScrollBar.vertical: ScrollBar{}
        clip: true

        model: m_model

        // Table Body

        delegate: Rectangle {
            Text {
                text: display // This is set in mysqlmodel.cpp roleNames()
                anchors.fill: parent
                anchors.margins: 10
                color: 'black'
                font.pixelSize: 15
                verticalAlignment: Text.AlignVCenter
            }
        }


        // Table Header

        Row {
            id: columnsHeader
            y: tableView.contentY
            z: 2
            Repeater {
                model: tableView.columns > 0 ? tableView.columns : 1
                Label {
                    width: tableView.columnWidthProvider(modelData)
                    height: 35
                    text: m_model.headerData(modelData, Qt.Horizontal)
                    font.pixelSize: 15
                    padding: 10
                    verticalAlignment: Text.AlignVCenter

                    background: Rectangle { color: "#ccc" }
                }
            }
        }


        ScrollIndicator.horizontal: ScrollIndicator { }
        ScrollIndicator.vertical: ScrollIndicator { }
    }
}
