import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.2

Rectangle {
    id: mainScreen
    width: 400
    height: 100
    anchors.fill: parent

    Column {
        Row {
            Button {
                id: buttonAdd
                text: qsTr("Add")
                onClicked: myListModel.addStuff(textInput.text)
            }

            TextField {
                id: textInput
                placeholderText: qsTr("Text Field")
            }

            Button {
                id: buttonKill
                text: qsTr("Kill")
                onClicked: myListModel.killLast()
            }
        }

        ListView {
            id: myListView
            width: mainScreen.width
            height: 40

            clip: true
            orientation: Qt.Horizontal

            add: Transition { NumberAnimation { properties: "x"; from: -80; duration: 1000 } }
            addDisplaced: Transition { NumberAnimation { properties: "x"; duration: 1000 } }
            remove: Transition {
                    ParallelAnimation {
                        NumberAnimation { property: "opacity"; to: 0; duration: 1000 }
                        NumberAnimation { properties: "x"; duration: 1000 }
                    }
                }
            removeDisplaced: Transition { NumberAnimation { properties: "x"; duration: 1000 } }

            model: myListModel
            delegate: Item {
                x: 5
                width: 80
                height: 40
                Text {
                    text: foo + " " + bar

                    anchors.verticalCenter: parent.verticalCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                }
            }
        }
    }
}
