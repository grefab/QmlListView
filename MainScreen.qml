import QtQuick 2.2
import QtQuick.Window 2.1

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
}
