import QtQuick

Item {
    anchors.fill: parent

    ListView {
        id: listView
        anchors.fill: parent
        clip: true
        boundsBehavior: Flickable.StopAtBounds

        model: card_model

        property string deckname
        property string card_id
        property string question_content
        property string answer_content
        delegate: Rectangle {
            height: m_model.getBorderWidth() * 2
            color: "red"
            clip: true
            width: listView.width

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
            TextInput {
                height: parent.height / 2
                anchors {
                    left: parent.left
                    right: parent.right
                    bottom: parent.bottom
                }
                text: content

                onEditingFinished: {
                    if (parent.original_content == listView.question_content) {
                        dbmanager.updateQuestion(listView.deckname, listView.card_id, field, text)
                    }
                    else if(parent.original_content == listView.answer_content) {
                        dbmanager.updateAnswer(listView.deckname, listView.card_id, field, text)
                    }
                    else {
                        dbmanager.updateFieldContent(listView.deckname, listView.card_id, field, text)
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
