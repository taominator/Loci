import QtQuick

/*Item {
    anchors.fill: parent
    Rectangle{
        id: field1
        height: parent.height /7
        anchors{
            top: parent.top
            left: parent.left
            right:parent.right
        }
        color: "red"
        Text{
            text: deck.getFields()[0] //Either Q_INVOKABLE or no ()paranthesis for function call in QML
            font.pixelSize: parent.height / 1.5
        }

    }

    Rectangle{
        id: field2
        height: parent.height /7
        anchors{
            top: field1.bottom
            left: parent.left
            right:parent.right
        }
        color: "orange"
        Text{
            text: deck.getFields()[1]
            font.pixelSize: parent.height / 1.5
        }
    }

    Rectangle{
        id: field3
        height: parent.height /7
        anchors{
            top: field2.bottom
            left: parent.left
            right:parent.right
        }
        color: "yellow"
        Text{
            text: deck.getFields()[2]
            font.pixelSize: parent.height / 1.5
        }
    }

    Rectangle{
        id: field4
        height: parent.height /7
        anchors{
            top: field3.bottom
            left: parent.left
            right:parent.right
        }
        color: "green"
        Text{
            text: deck.getFields()[3]
            font.pixelSize: parent.height / 1.5
        }
    }

    Rectangle{
        id: field5
        height: parent.height /7
        anchors{
            top: field4.bottom
            left: parent.left
            right:parent.right
        }
        color: "blue"
        Text{
            text: deck.getFields()[4]
            font.pixelSize: parent.height / 1.5
        }
    }

    Rectangle{
        id: field6
        height: parent.height /7
        anchors{
            top: field5.bottom
            left: parent.left
            right:parent.right
        }
        color: "indigo"
        Text{
            text: deck.getFields()[5]
            font.pixelSize: parent.height / 1.5
        }
    }

    Rectangle{
        id: field7
        height: parent.height /7
        anchors{
            top: field6.bottom
            left: parent.left
            right:parent.right
        }
        color: "purple"
        Text{
            text: deck.getFields()[6]
            font.pixelSize: parent.height / 1.5
        }
    }

}*/

Item {
    anchors.fill: parent

    Component {
        id: cardDelegate
        Text {
            text:
        }
    }

    ListView {
        anchors.fill: parent
        model: selectedCard.getCardModel()
    }
}
