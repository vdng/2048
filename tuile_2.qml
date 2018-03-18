import QtQuick 2.0

Item {
    Rectangle {
        id: rectangle_2
        width: 100
        height: 100
        color: "#efeeeb"
        radius: 10

        Text {
            id: texte_2
            color: "#4c4545"
            text: qsTr("2")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pixelSize: 40
        }
    }
}
