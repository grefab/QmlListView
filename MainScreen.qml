import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.2

Rectangle {
    width: 400
    height: 400

    ListView {
        id: listView1
        x: 145
        y: 120
        width: 110
        height: 160
        clip: true
        model: dynamicListModel
        delegate: Item {
            x: 5
            width: 80
            height: 40
            Text {
                text: name
                anchors.verticalCenter: parent.verticalCenter
                font.bold: true
            }
        }
    }

    Button {
        id: button1
        x: 8
        y: 8
        text: qsTr("Button")

        onClicked: {
            dynamicListModel.addStuff(textField1.text);
        }
    }

    TextField {
        id: textField1
        x: 89
        y: 11
        placeholderText: qsTr("Text Field")
    }
}
