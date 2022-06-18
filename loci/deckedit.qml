import QtQuick

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
            color: "yellow"
            id: edit_deck
            height: parent.height * (4/10)
            anchors{
                top: parent.top
                left: parent.left
                right: parent.right
            }

            Rectangle {
                color: "orange"
                id: add_delete_deck
                height: parent.height / 3
                anchors {
                    top: parent.top
                    left: parent.left
                    right: parent.right
                }

                Text {
                    anchors.centerIn: parent
                    text: "Add / Delete Deck"
                    font.pixelSize: parent.height * (1/2)
                }
            }

            Rectangle {
                color: "green"
                id: deck_deckname
                height: parent.height / 3
                anchors {
                    top: add_delete_deck.bottom
                    left: parent.left
                    right: parent.right
                }

                Rectangle {
                    color: "red"
                    id: placeholder_deck
                    width: parent.width / 5
                    anchors {
                        top: parent.top
                        left: parent.left
                        bottom: parent.bottom
                    }

                    Text {
                        anchors.centerIn: parent
                        text: "Deckname: "
                        font.pixelSize: parent.height / 3
                    }

                }

                Rectangle {
                    color: "cyan"
                    id: deckinput_deck
                    anchors {
                        top: parent.top
                        bottom: parent.bottom
                        right: parent.right
                        left: placeholder_deck.right
                    }

                    TextInput {
                        anchors {
                            verticalCenter: parent.verticalCenter
                            left: parent.left
                        }
                        font.pixelSize: parent.height / 3
                        text: "Enter deckname here"
                    }
                }

            }

            Rectangle {
                color: "blue"
                id: buttons_deck
                anchors {
                    top: deck_deckname.bottom
                    bottom: parent.bottom
                    left: parent.left
                    right: parent.right
                }

                Rectangle {
                    color: "gray"
                    id: add_deck
                    width: parent.width / 2
                    anchors {
                        top: parent.top
                        bottom: parent.bottom
                        left: parent.left
                    }
                    Text {
                        anchors.centerIn: parent
                        text: "Add Deck"
                        font.pixelSize: parent.height / 3
                    }
                }

                Rectangle {
                    color: "pink"
                    id: delete_deck
                    width: parent.width / 2
                    anchors {
                        top: parent.top
                        bottom: parent.bottom
                        left: add_deck.right
                    }
                    Text {
                        anchors.centerIn: parent
                        text: "Delete Deck"
                        font.pixelSize: parent.height / 3
                    }
                }
            }
        }


        Rectangle {
            color: "indigo"
            id: field_rect
            anchors {
                top: edit_deck.bottom
                left: parent.left
                right: parent.right
                bottom: parent.bottom
            }

            Rectangle {
                color: "orange"
                id: add_delete_field
                height: parent.height / 4
                anchors {
                    top: parent.top
                    left: parent.left
                    right: parent.right
                }

                Text {
                    anchors.centerIn: parent
                    text: "Add / Delete Field"
                    font.pixelSize: parent.height * (1/2)
                }
            }

            Rectangle {
                color: "green"
                id: field_fieldname
                height: parent.height / 4
                anchors {
                    top: add_delete_field.bottom
                    left: parent.left
                    right: parent.right
                }

                Rectangle {
                    color: "red"
                    id: placeholder_field
                    width: parent.width / 5
                    anchors {
                        top: parent.top
                        left: parent.left
                        bottom: parent.bottom
                    }

                    Text {
                        anchors.centerIn: parent
                        text: "Fieldname: "
                        font.pixelSize: parent.height / 3
                    }

                }

                Rectangle {
                    color: "cyan"
                    id: fieldinput_field
                    anchors {
                        top: parent.top
                        bottom: parent.bottom
                        right: parent.right
                        left: placeholder_field.right
                    }

                    TextInput {
                        anchors {
                            verticalCenter: parent.verticalCenter
                            left: parent.left
                        }
                        font.pixelSize: parent.height / 3
                        text: "Enter fieldname here"
                    }
                }

            }

            Rectangle {
                color: "green"
                id: field_deckname
                height: parent.height / 4
                anchors {
                    top: field_fieldname.bottom
                    left: parent.left
                    right: parent.right
                }

                Rectangle {
                    color: "yellow"
                    id: placeholder_deck_field
                    width: parent.width / 5
                    anchors {
                        top: parent.top
                        left: parent.left
                        bottom: parent.bottom
                    }

                    Text {
                        anchors.centerIn: parent
                        text: "Deckname: "
                        font.pixelSize: parent.height / 3
                    }

                }

                Rectangle {
                    color: "green"
                    id: deckinput_field
                    anchors {
                        top: parent.top
                        bottom: parent.bottom
                        right: parent.right
                        left: placeholder_deck_field.right
                    }

                    TextInput {
                        anchors {
                            verticalCenter: parent.verticalCenter
                            left: parent.left
                        }
                        font.pixelSize: parent.height / 3
                        text: "Enter deckname here"
                    }
                }

            }

            Rectangle {
                color: "blue"
                id: buttons_field
                anchors {
                    top: field_deckname.bottom
                    bottom: parent.bottom
                    left: parent.left
                    right: parent.right
                }

                Rectangle {
                    color: "gray"
                    id: add_field
                    width: parent.width / 2
                    anchors {
                        top: parent.top
                        bottom: parent.bottom
                        left: parent.left
                    }
                    Text {
                        anchors.centerIn: parent
                        text: "Add Field"
                        font.pixelSize: parent.height / 3
                    }
                }

                Rectangle {
                    color: "pink"
                    id: delete_field
                    width: parent.width / 2
                    anchors {
                        top: parent.top
                        bottom: parent.bottom
                        left: add_field.right
                    }
                    Text {
                        anchors.centerIn: parent
                        text: "Delete field"
                        font.pixelSize: parent.height / 3
                    }
                }
            }
        }
    }
}