import QtQuick

Item {
    anchors.fill: parent

    property string current_deck: ""
    Loader {
        id: my_loader
        z: 2
        height: parent.height * (19/20)
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

        source: "reviewscreen.qml"
        visible: item ? item.is_visible : false

        Connections {
                target: my_loader.item
                function onNextChanged()
                {
                    if(dbmanager.setReviewCard(current_deck)) {
                        my_loader.source = ""
                        my_loader.source = "reviewscreen.qml"
                        my_loader.item.is_visible = true
                        //console.log("yo: " + current_deck)
                    }
                    else if(dbmanager.setNewCard(current_deck)) {
                        my_loader.source = ""
                        my_loader.source = "reviewscreen.qml"
                        my_loader.item.is_visible = true
                        //console.log("hey: " + current_deck)
                    }
                }
            }
    }

    Rectangle {
        height: parent.height * (19/20)
        color: "red"
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

        Rectangle {
            color: "green"
            anchors {
                fill: parent

                leftMargin: parent.width * (1/30)
                rightMargin: parent.width * (1/30)
                topMargin: parent.width * (1/30)
                bottomMargin: parent.width * (1/30)
            }


            Rectangle {
                id: headers_bar
                color: "lime"
                height: parent.height * (1/10)
                anchors {
                    top: parent.top
                    left: parent.left
                    right: parent.right
                }

                Rectangle {
                    id: deckname_header
                    color: "orange"
                    width: parent.width * (8/10)
                    border.color: "gray"
                    anchors {
                        left: parent.left
                        top: parent.top
                        bottom: parent.bottom
                    }
                    Text {
                        anchors.centerIn: parent
                        font.pixelSize: parent.height * (1/2)
                        padding: m_model.getBorderWidth() * 0.2
                        text: "Deckname"
                    }
                }

                Rectangle {
                    id: new_card_header
                    color: "yellow"
                    width: parent.width * (1/10)
                    border.color: "gray"
                    anchors {
                        left: deckname_header.right
                        top: parent.top
                        bottom: parent.bottom
                    }
                    Text {
                        anchors.centerIn: parent
                        font.pixelSize: parent.height * (1/2)
                        padding: m_model.getBorderWidth() * 0.2
                        text: "N"
                    }
                }

                Rectangle {
                    id: review_card_header
                    color: "purple"
                    width: parent.width * (1/10)
                    border.color: "gray"
                    anchors {
                        left: new_card_header.right
                        top: parent.top
                        bottom: parent.bottom
                    }
                    Text {
                        anchors.centerIn: parent
                        font.pixelSize: parent.height * (1/2)
                        padding: m_model.getBorderWidth() * 0.2
                        text: "R"
                    }
                }
            }


            ListView {
                id: deckListView
                anchors {
                    top: headers_bar.bottom
                    bottom: parent.bottom
                    left: parent.left
                    right: parent.right
                }
                clip: true
                boundsBehavior: Flickable.StopAtBounds

                model: m_deckListModel

                delegate: Rectangle {
                    id: delegate_bar
                    color: "red"
                    height: m_model.getBorderWidth() * 2
                    width: parent.width

                    Rectangle {
                        id: deckname
                        color: "pink"
                        width: parent.width * (8/10)
                        border.color: "gray"
                        anchors {
                            left: parent.left
                            top: parent.top
                            bottom: parent.bottom
                        }
                        Text {
                            anchors.centerIn: parent
                            font.pixelSize: parent.height * (1/2)
                            padding: m_model.getBorderWidth() * 0.2
                            text: display
                        }
                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor

                            onClicked: {
                                current_deck = display
                                if(dbmanager.setReviewCard(display)) {
                                    my_loader.source = ""
                                    my_loader.source = "reviewscreen.qml"
                                    my_loader.item.is_visible = true
                                }
                                else if(dbmanager.setNewCard(display)) {
                                    my_loader.source = ""
                                    my_loader.source = "reviewscreen.qml"
                                    my_loader.item.is_visible = true
                                }
                            }
                        }
                    }

                    Rectangle {
                        id: new_card
                        color: "blue"
                        width: parent.width * (1/10)
                        border.color: "gray"
                        anchors {
                            left: deckname.right
                            top: parent.top
                            bottom: parent.bottom
                        }
                        Text {
                            anchors.centerIn: parent
                            font.pixelSize: parent.height / 2
                            text: dbmanager.getNumNewCards(display)
                        }

                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor

                            onClicked: {
                                if (dbmanager.setNewCard(display)) {
                                    my_loader.source = ""
                                    my_loader.source = "reviewscreen.qml"
                                    my_loader.item.is_visible = true
                                }
                            }
                        }
                    }

                    Rectangle {
                        id: review_card
                        color: "cyan"
                        width: parent.width * (1/10)
                        border.color: "gray"
                        anchors {
                            left: new_card.right
                            top: parent.top
                            bottom: parent.bottom
                        }
                        Text {
                            anchors.centerIn: parent
                            font.pixelSize: parent.height / 2
                            text: dbmanager.getNumReviewCards(display)
                        }

                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor

                            onClicked: {
                                if (dbmanager.setReviewCard(display)) {
                                    my_loader.source = ""
                                    my_loader.source = "reviewscreen.qml"
                                    my_loader.item.is_visible = true
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
