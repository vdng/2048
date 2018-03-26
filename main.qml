import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id: window
    visible: true
    width: 480
    height: 640
    title: qsTr("2048")

    Rectangle {
        id: fond
        color: "#e7e5e5"
        anchors.fill: parent

        Rectangle {
            id: jeu
            y: 175
            width: 450
            height: 450
            color: "#a08f71"
            radius: 10
            anchors.left: parent.left
            anchors.leftMargin: 15
            anchors.horizontalCenter: parent.horizontalCenter

            Grid {
                id: grilleFond
                anchors.fill: parent

                Rectangle {
                    id: case33
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.left: parent.left
                    anchors.leftMargin: 340
                    anchors.top: parent.top
                    anchors.topMargin: 340
                }

                Rectangle {
                    id: case32
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.left: parent.left
                    anchors.leftMargin: 230
                    anchors.top: parent.top
                    anchors.topMargin: 340
                }

                Rectangle {
                    id: case31
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.topMargin: 340
                    anchors.leftMargin: 120
                }

                Rectangle {
                    id: case30
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.rightMargin: 1
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.topMargin: 340
                    anchors.leftMargin: 10
                }

                Rectangle {
                    id: case23
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.left: parent.left
                    anchors.leftMargin: 340
                    anchors.top: parent.top
                    anchors.topMargin: 230
                }

                Rectangle {
                    id: case22
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.left: parent.left
                    anchors.leftMargin: 230
                    anchors.top: parent.top
                    anchors.topMargin: 230
                }

                Rectangle {
                    id: case21
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.topMargin: 230
                    anchors.leftMargin: 120
                }

                Rectangle {
                    id: case20
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.topMargin: 230
                    anchors.leftMargin: 10
                }

                Rectangle {
                    id: case13
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.left: parent.left
                    anchors.leftMargin: 340
                    anchors.top: parent.top
                    anchors.topMargin: 120
                }

                Rectangle {
                    id: case12
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.left: parent.left
                    anchors.leftMargin: 230
                    anchors.top: parent.top
                    anchors.topMargin: 120
                }

                Rectangle {
                    id: case11
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.topMargin: 120
                    anchors.leftMargin: 120
                }

                Rectangle {
                    id: case10
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.topMargin: 120
                    anchors.leftMargin: 10
                }

                Rectangle {
                    id: case03
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.left: parent.left
                    anchors.leftMargin: 340
                    anchors.top: parent.top
                    anchors.topMargin: 10
                }

                Rectangle {
                    id: case02
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.left: parent.left
                    anchors.leftMargin: 230
                    anchors.top: parent.top
                    anchors.topMargin: 10
                }

                Rectangle {
                    id: case01
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.topMargin: 10
                    anchors.leftMargin: 120
                }

                Rectangle {
                    id: case00
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    anchors.top: parent.top
                    anchors.topMargin: 10
                }
            }

            Grid {
                id: plateau
                anchors.fill: parent
            }
        }


        Text {
            id: titre
            x: 15
            height: 100
            text: qsTr("2048")
            anchors.top: parent.top
            anchors.topMargin: 40
            font.family: "Tahoma"
            font.pixelSize: 86
        }

        Rectangle {
            id: affichage_score
            x: 365
            y: 47
            width: 100
            height: 100
            color: "#a08f71"
            radius: 10
            anchors.verticalCenter: titre.verticalCenter

            Text {
                id: titre_score
                color: "#cfb3af"
                text: qsTr("Score")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.left: parent.left
                anchors.leftMargin: 0
                font.pixelSize: 28
            }

            Text {
                id: score
                x: -9
                color: "#342014"
                text: vueObjectSco.scoQML
                anchors.top: titre_score.bottom
                anchors.topMargin: 10
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.left: parent.left
                anchors.right: parent.right
                font.pixelSize: 42
                anchors.rightMargin: 0
                anchors.leftMargin: 0
            }
        }

    }
}
