import QtQuick

Item {
    anchors.fill: parent

    TopBar {
        id: top_bar
    }

    Rectangle {
        id: today_bar
        color: "blue"
        height: parent.height * (3/15)
        anchors {
            right: parent.right
            left: parent.left
            top: top_bar.bottom
        }


        Text {
            text: "Due Today"
            color: "orange"
            font.pixelSize: parent.height / 4
            anchors {
                horizontalCenter: parent.horizontalCenter
                top: parent.top
                bottom: today2.bottom
            }
        }

        Rectangle {
            id: today1
            height: parent.height * (1.8/3)
            width: parent.width / 3
            anchors {
                left: parent.left
                bottom: parent.bottom
            }
            color: "pink"
        }

        Rectangle {
            id: today2
            height: parent.height * (1.8/3)
            width: parent.width / 3
            anchors {
                left: today1.right
                bottom: parent.bottom
            }
            color: "white"
        }

        Rectangle {
            id: today3
            height: parent.height * (1.8/3)
            width: parent.width / 3
            anchors {
                left: today2.right
                bottom: parent.bottom
            }
            color: "black"
        }
    }

    Rectangle {
        id: tomorrow_bar
        height: parent.height * (3/15)
        anchors {
            right: parent.right
            left: parent.left
            top: today_bar.bottom
        }
        color: "green"


        Text {
            text: "Due Tomorrow"
            color: "orange"
            font.pixelSize: parent.height / 4
            anchors {
                horizontalCenter: parent.horizontalCenter
                top: parent.top
                bottom: today2.bottom
            }
        }

        Rectangle {
            id: tomorrow1
            height: parent.height * (1.8/3)
            width: parent.width / 3
            anchors {
                left: parent.left
                bottom: parent.bottom
            }
            color: "gray"
        }

        Rectangle {
            id: tomorrow2
            height: parent.height * (1.8/3)
            width: parent.width / 3
            anchors {
                left: tomorrow1.right
                bottom: parent.bottom
            }
            color: "purple"
        }

        Rectangle {
            id: tomorrow3
            height: parent.height * (1.8/3)
            width: parent.width / 3
            anchors {
                left: tomorrow2.right
                bottom: parent.bottom
            }
            color: "red"
        }
    }

    Rectangle {
        id: deck_bar
        height: parent.height * (8/15)
        anchors {
            right: parent.right
            left: parent.left
            top: tomorrow_bar.bottom
            bottom: parent.bottom
        }
        color: "yellow"
    }
}
