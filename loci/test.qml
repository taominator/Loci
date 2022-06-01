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

        //columnWidthProvider: function (column) { return 100; }
        columnWidthProvider: function (column) { return m_model.getColumnWidth(column) }
        rowHeightProvider: function (column) { return 40; }
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

            Component.onCompleted: {
            console.log(display)
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
                    //width: tableView.columnWidthProvider(modelData)
                    width: m_model.getColumnWidth(modelData)
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

                        Component.onCompleted: {
                        console.log(modelData)
                        }
                    }

                    MouseArea {
                           id: mouseAreaLeft

                           property int oldMouseX

                           anchors.right: parent.right
                           anchors.bottom: parent.bottom
                           width: 15
                           height: 35
                           hoverEnabled: true

                           onPressed: {
                               oldMouseX = mouseX
                               //console.log("clicked")
                           }

                           onPositionChanged: {
                               if (pressed) {
                                   parent.width = parent.width + (mouseX - oldMouseX)
                                   m_model.setColumnWidth(modelData, parent.width + (mouseX - oldMouseX))
                                   columnsHeader.forceLayout()
                                   tableView.forceLayout()
                                   //console.log("position changed")
                               }
                           }
                       }
                }
            }
        }


        ScrollIndicator.horizontal: ScrollIndicator { }
        ScrollIndicator.vertical: ScrollIndicator { }
    }
}

