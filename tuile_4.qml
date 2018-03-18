import QtQuick 2.0

Item {
    Rectangle {
        id: rectangle_4
        width: 100
        height: 100
        color: "#e9d9b1"
        radius: 10

        Text {
            id: texte_4
            color: "#4c4545"
            text: qsTr("4")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pixelSize: 40
        }
    }
}
