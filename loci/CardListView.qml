import QtQuick 2.0

Item {
    anchors.fill: parent

    ListView {
        id: listView
        anchors.fill: parent
        clip: true

        model: card_model

        property string deckname
        property string card_id
        property string question_content
        property string answer_content
        delegate: Rectangle {
            height: m_model.getBorderWidth() * 2
            color: "red"
            clip: true
            anchors {
                left: parent.left
                right: parent.right
            }
            Text {
                height: parent.height / 2
                anchors {
                    left: parent.left
                    right: parent.right
                    top: parent.top
                }
                text: field
            }

            property string original_content
            TextEdit {
                height: parent.height / 2
                anchors {
                    left: parent.left
                    right: parent.right
                    bottom: parent.bottom
                }
                text: content

                onTextChanged: {
                    if (original_content === listView.question_content) {

                    }
                    else if(original_content === listView.answer_content) {

                    }
                    else {

                    }

                }
            }

            Component.onCompleted: {
                original_content = content
                if (field === "deckname") {
                    listView.deckname = content
                }
                else if (field === "id") {
                    listView.card_id = content
                }
                else if(field === "Question") {
                    listView.question_content = content
                }
                else if (field === "Answer") {
                    listView.answer_content = content
                }
            }
        }
    }
}
