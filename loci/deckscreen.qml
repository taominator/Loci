import QtQuick

Item {
    anchors.fill: parent

    Rectangle {
        id: leftRect
        width: parent.width * (1/5)
        height: parent.height * (19/20)
        color: "gray"
        z: 0
        anchors {
            left:parent.left
            bottom: parent.bottom
        }

        //--------------------------------------------------------------------------------

        Rectangle {
            id: drag_area
            width: m_model.getBorderWidth()
            color: "blue"
            z: 1
            anchors {
                top: parent.top
                right: parent.right
                bottom: parent.bottom
            }

            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.SplitHCursor
                hoverEnabled: true
                property int oldMouseX

                onPressed: {
                    oldMouseX = mouseX
                }

                onPositionChanged: {
                    if (pressed) {
                            leftRect.width = leftRect.width + (mouseX - oldMouseX)
                            rightRect.width = rightRect.width - (mouseX - oldMouseX)

                        if(leftRect.width < m_model.getBorderWidth()*3)
                        {
                            leftRect.width = m_model.getBorderWidth()*3
                            rightRect.width = mainWindow.maxWidth - m_model.getBorderWidth()*3
                        }
                        else if (rightRect.width < m_model.getBorderWidth()*3)
                        {
                            rightRect.width = m_model.getBorderWidth()*3
                            leftRect.width = mainWindow.maxWidth - m_model.getBorderWidth()*3
                        }
                    }
                }
            }
        }

        //--------------------------------------------------------------------------------

        Rectangle {
            id: due_today
            color: today_mouse_area.containsMouse? "#A7C2D9" : "#E6F4F4"
            height: m_model.getBorderWidth() * 1.5
            width: parent.width - m_model.getBorderWidth() * 2
            anchors {
                horizontalCenter: parent.horizontalCenter
                top: parent.top
            }

            Text {
                anchors.fill: parent
                font.pixelSize: m_model.getBorderWidth() * 0.8
                padding: m_model.getBorderWidth() * 0.2
                text: "Due Today"
            }

            MouseArea {
                id: today_mouse_area
                anchors.fill: parent
                hoverEnabled: true

            }
        }

        //--------------------------------------------------------------------------------

        Rectangle{
            id: card_state
            color: "gray"
            height: state_view.minimized? m_model.getBorderWidth() * 1.5 : parent.height * (3/10)
            anchors {
                top: due_today.bottom
                right: parent.right
                left: parent.left
            }

            Rectangle {
                id: minimize_state
                height: m_model.getBorderWidth() * 1.5
                width: m_model.getBorderWidth()
                color: "purple"
                anchors{
                    top: parent.top
                    left: parent.left
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        state_view.minimized = !state_view.minimized
                    }
                }
            }

            Rectangle {
                id: state_bar
                height: m_model.getBorderWidth() * 1.5
                color: statebar_mouse_area.containsMouse? "#A7C2D9" : "#E6F4F4"
                anchors{
                    top: parent.top
                    left: parent.left
                    right: parent.right

                    leftMargin: m_model.getBorderWidth()
                    rightMargin: m_model.getBorderWidth()
                }

                Text {
                    anchors.fill: parent
                    font.pixelSize: m_model.getBorderWidth() * 0.8
                    padding: m_model.getBorderWidth() * 0.2
                    text: "Card State"
                }

                MouseArea {
                    id: statebar_mouse_area
                    anchors.fill: parent
                    hoverEnabled: true

                }
            }

            Rectangle {
                id: state_view
                property bool minimized: false
                color: "pink"
                height: parent.height - m_model.getBorderWidth() * 2
                width: state_bar.width - m_model.getBorderWidth()
                anchors {
                    top: state_bar.bottom
                    right: parent.right

                    bottom: minimized? parent.top : parent.bottom
                    leftMargin: m_model.getBorderWidth()
                    rightMargin: m_model.getBorderWidth()
                }

                ListView {
                    anchors.fill: parent
                    clip: true
                    boundsBehavior: Flickable.StopAtBounds

                    model: ListModel {
                        ListElement {name: "New"}
                        ListElement {name: "Learning"}
                        ListElement {name: "Review"}
                        ListElement {name: "Suspended"}
                        ListElement {name: "Buried"}
                    }

                    delegate: Rectangle {
                        height: m_model.getBorderWidth() * 1.5
                        width: deckbar.width
                        color: stateview_mouse_area.containsMouse? "#A7C2D9" : "#E6F4F4"
                        Text {
                            anchors.fill: parent
                            font.pixelSize: m_model.getBorderWidth() * 0.8
                            padding: m_model.getBorderWidth() * 0.2
                            text: name
                        }

                        MouseArea {
                            id: stateview_mouse_area
                            anchors.fill: parent
                            hoverEnabled: true

                        }
                    }
                }
            }
        }

        //--------------------------------------------------------------------------------

        Rectangle {
            id: decklist
            color: "lime"
            anchors {
                top: card_state.bottom
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }
            property int selectedIndex: -2

            Rectangle {
                id: minimize_decklist
                height: m_model.getBorderWidth() * 1.5
                width: m_model.getBorderWidth()
                color: "purple"
                anchors{
                    top: parent.top
                    left: parent.left
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        deckview.minimized = !deckview.minimized
                    }
                }
            }

            Rectangle {
                id: deckbar
                height: m_model.getBorderWidth() * 1.5
                color: -1 === decklist.selectedIndex ? "#91B9DA" : (deckbar_mouse_area.containsMouse? "#A7C2D9" : "#E6F4F4")
                anchors{
                    top: parent.top
                    left: parent.left
                    right: parent.right

                    leftMargin: m_model.getBorderWidth()
                    rightMargin: m_model.getBorderWidth()
                }

                Text {
                    anchors.fill: parent
                    font.pixelSize: m_model.getBorderWidth() * 0.8
                    padding: m_model.getBorderWidth() * 0.2
                    text: "Decks"
                }

                MouseArea {
                    id: deckbar_mouse_area
                    anchors.fill: parent
                    hoverEnabled: true

                    onClicked: {
                        decklist.selectedIndex = -1
                    }
                }
            }

            Rectangle {
                id: deckview
                color: "pink"
                width: deckbar.width - m_model.getBorderWidth()
                property bool minimized: false
                anchors {
                    top: deckbar.bottom
                    right: parent.right
                    bottom: minimized? parent.top : parent.bottom

                    leftMargin: m_model.getBorderWidth()
                    rightMargin: m_model.getBorderWidth()
                }

                ListView {
                    id: deck_listview
                    anchors.fill: parent
                    clip: true
                    boundsBehavior: Flickable.StopAtBounds
                    model: m_deckListModel
                    delegate: Rectangle {
                        height: m_model.getBorderWidth() * 1.5
                        width: deckbar.width
                        color: index === decklist.selectedIndex ? "#91B9DA" : (deck_mouse_area.containsMouse? "#A7C2D9" : "#E6F4F4")
                        Text {
                            anchors.fill: parent
                            font.pixelSize: m_model.getBorderWidth() * 0.8
                            padding: m_model.getBorderWidth() * 0.2
                            text: display
                        }

                        MouseArea {
                            id: deck_mouse_area
                            anchors.fill: parent
                            hoverEnabled: true

                            onClicked: {
                                decklist.selectedIndex = index
                                m_model.callSql("SELECT * FROM " + display)
                            }
                        }
                    }
                }
            }
        }
    }

    Rectangle {
        id: rightRect
        height: parent.height * (19/20)
        width: parent.width * (4/5)
        color: "teal"//"#E2F7F7"
        z: 0
        anchors {
            //top: parent.top
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
