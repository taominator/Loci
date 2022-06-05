import QtQuick
import QtQuick.Window
import QtQuick.Controls

Item {
    id: item
    anchors.fill: parent

    // Uncomment this, if you want to call query from qml
    // If you uncomment this, remember to comment out the followin line in main.cpp
    // mysqlModel.callSql("SELECT * FROM users");

    //    Component.onCompleted: {
    //        MysqlModel.callSql("SELECT * FROM users")
    //    }

    TableView {
        id: tableView

        boundsBehavior: Flickable.StopAtBounds
        //interactive: false

        //columnWidthProvider: function (column) { return 100; }
        columnWidthProvider: function (column) { return m_model.getColumnWidth(column) }
        rowHeightProvider: function (column) { return 40; }

        anchors.fill: parent

        //leftMargin: rowsHeader.implicitWidth
        topMargin: columnsHeader.implicitHeight


        ScrollBar.horizontal: ScrollBar{policy: ScrollBar.AlwaysOn}
        ScrollBar.vertical: ScrollBar{policy: ScrollBar.AlwaysOn}
        clip: true

        model: m_model

        // Table Body

        property int selectedRow: 1
        delegate: ItemDelegate {
            clip: true

            highlighted: row === tableView.selectedRow
            onClicked: {
                tableView.selectedRow = row
            }
            property int delegateRow
            Component.onCompleted: {
                delegateRow = row
            }

            Rectangle {
                anchors.fill: parent
                color: parent.delegateRow%2 === 0 ? "#B8F4F4" : "#CEF1F1"
                border.color: "gray"
                visible: parent.delegateRow === tableView.selectedRow ? false : true
            }

            Text {
                text: model.display // This is set in mysqlmodel.cpp roleNames()
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
                id: repeater
                model: tableView.columns > 0 ? tableView.columns : 1
                delegate: Rectangle {
                    width: tableView.columnWidthProvider(modelData)
                    //width: m_model.getColumnWidth(modelData)
                    height: 35
                    color: "#A8BEBE"
                    border.color: "gray"
                    Label {
                        anchors.fill: parent
                        text: m_model.headerData(modelData, Qt.Horizontal)
                        elide: Text.ElideRight
                        font.pixelSize: 15
                        padding: 10
                        verticalAlignment: Text.AlignVCenter
                    }


                    property int mouseAreaWidth: 5
                    MouseArea {
                        id:rightArea
                        property int oldMouseX

                        cursorShape: Qt.SplitHCursor

                        anchors.right: parent.right
                        anchors.bottom: parent.bottom
                        width: mouseAreaWidth
                        height: 35
                        hoverEnabled: true

                        property int change
                        property int oldWidth
                        onPressed: {
                            oldMouseX = mouseX
                            //console.log("clicked")
                        }

                        /*onPositionChanged: {
                            if(pressed){
                                if(m_model.getColumnWidth(modelData) > 100) {
                                change = (mouseX - oldMouseX)
                                m_model.setColumnWidth(modelData, parent.width + change)
                                //m_model.correctLastColumnWidth
                                parent.width = parent.width + change
                                columnsHeader.forceLayout()
                                tableView.forceLayout()
                                m_model.updateSumColumnWidths(change)
                                m_model.print()
                                }
                            }
                        }*/

                        onPositionChanged: {
                            if (pressed) {
                                change = (mouseX - oldMouseX)
                                if(change > 0){
                                    parent.width = parent.width + change
                                    m_model.setColumnWidth(modelData, parent.width + change)
                                    columnsHeader.forceLayout()
                                    tableView.forceLayout()
                                    m_model.updateSumColumnWidths()
                                }
                                if(change < 0){
                                    if(parent.width > m_model.getDefaultColumnWidth()){
                                        parent.width = parent.width + change
                                        m_model.setColumnWidth(modelData, parent.width + change)
                                        columnsHeader.forceLayout()
                                        tableView.forceLayout()
                                        m_model.updateSumColumnWidths()
                                    }
                                }
                                if(parent.width < m_model.getDefaultColumnWidth()){
                                    oldWidth = parent.width
                                    parent.width = m_model.getDefaultColumnWidth()
                                    m_model.setColumnWidth(modelData, m_model.getDefaultColumnWidth())
                                    columnsHeader.forceLayout()
                                    tableView.forceLayout()
                                    m_model.updateSumColumnWidths()
                                }
                                if(m_model.tooSmallTable()){
                                    m_model.rectifyLastColumnWidth()
                                    repeater.itemAt(tableView.columns-1).width = m_model.lastColumnWidth()
                                    columnsHeader.forceLayout()
                                    tableView.forceLayout()
                                }
                                parent.width = m_model.getColumnWidth(modelData)
                                columnsHeader.forceLayout()
                                tableView.forceLayout()
                            }
                        }
                    }
                }
                //scrollbar hides mousearea
                Component.onCompleted: {
                    repeater.itemAt(tableView.columns-1).mouseAreaWidth = 25
                    console.log(tableView.rowCount)
                }
            }
        }
        ScrollIndicator.horizontal: ScrollIndicator { }
        ScrollIndicator.vertical: ScrollIndicator { }
    }

}

