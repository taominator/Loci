import QtQuick
//import QtQuick.Window
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

        boundsBehavior: Flickable.StopAtBounds

        columnWidthProvider: function (column) { return 100; }
        rowHeightProvider: function (column) { return 60; }
        anchors.fill: parent

        //leftMargin: rowsHeader.implicitWidth
        topMargin: columnsHeader.implicitHeight


        ScrollBar.horizontal: ScrollBar{}
        ScrollBar.vertical: ScrollBar{}
        clip: true

        model: m_model

        // Table Body

        delegate: Rectangle {
            border.color: "gray"
            clip: true
            Text {
                text: display // This is set in mysqlmodel.cpp roleNames()
                anchors.fill: parent
                anchors.margins: 10
                elide: Text.ElideRight
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
            clip:true

            Repeater {
                model: tableView.columns > 0 ? tableView.columns : 1
                delegate: Rectangle {
                    width: tableView.columnWidthProvider(modelData)
                    height: 35
                    color: "#ccc"
                    border.color: "gray"
                    Label {
                        anchors.fill: parent
                        text: m_model.headerData(modelData, Qt.Horizontal)
                        elide: Text.ElideRight
                        font.pixelSize: 15
                        padding: 10
                        verticalAlignment: Text.AlignVCenter

                    }
                }
            }
        }


        ScrollIndicator.horizontal: ScrollIndicator { }
        ScrollIndicator.vertical: ScrollIndicator { }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:8}D{i:7}D{i:6}D{i:1}
}
##^##*/
