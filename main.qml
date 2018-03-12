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
            x: 15
            y: 175
            width: 450
            height: 450
            color: "#a08f71"
            radius: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 15
            anchors.horizontalCenter: parent.horizontalCenter

            Grid {
                id: grille_de_fond
                anchors.fill: parent
                columns: 4
                spacing: 4

                Rectangle {
                    id: tuile
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    anchors.top: parent.top
                    anchors.topMargin: 10
                }

                Rectangle {
                    id: tuile1
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.top: parent.top
                    anchors.left: tuile.right
                    anchors.topMargin: 10
                    anchors.leftMargin: 10
                }

                Rectangle {
                    id: tuile2
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.right: tuile.left
                    anchors.rightMargin: -320
                    anchors.top: parent.top
                    anchors.topMargin: 10
                }

                Rectangle {
                    id: tuile3
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.right: tuile.left
                    anchors.rightMargin: -430
                    anchors.top: parent.top
                    anchors.topMargin: 10
                }

                Rectangle {
                    id: tuile4
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
                    id: tuile5
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
                    id: tuile6
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.top: parent.top
                    anchors.right: tuile7.left
                    anchors.rightMargin: 10
                    anchors.topMargin: 120
                }

                Rectangle {
                    id: tuile7
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.top: parent.top
                    anchors.right: parent.right
                    anchors.rightMargin: 10
                    anchors.topMargin: 120
                }

                Rectangle {
                    id: tuile8
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.top: tuile5.bottom
                    anchors.left: parent.left
                    anchors.topMargin: 10
                    anchors.leftMargin: 10
                }

                Rectangle {
                    id: tuile9
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.top: tuile5.bottom
                    anchors.left: parent.left
                    anchors.topMargin: 10
                    anchors.leftMargin: 120
                }

                Rectangle {
                    id: tuile10
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.top: tuile6.bottom
                    anchors.right: tuile11.left
                    anchors.rightMargin: 10
                    anchors.topMargin: 10
                }

                Rectangle {
                    id: tuile11
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.top: tuile7.bottom
                    anchors.right: parent.right
                    anchors.rightMargin: 10
                    anchors.topMargin: 10
                }

                Rectangle {
                    id: tuile12
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.rightMargin: 1
                    anchors.top: tuile8.bottom
                    anchors.left: parent.left
                    anchors.topMargin: 10
                    anchors.leftMargin: 10
                }

                Rectangle {
                    id: tuile13
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.top: tuile9.bottom
                    anchors.left: tuile12.right
                    anchors.topMargin: 10
                    anchors.leftMargin: 10
                }

                Rectangle {
                    id: tuile14
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.top: tuile10.bottom
                    anchors.right: tuile15.left
                    anchors.rightMargin: 10
                    anchors.topMargin: 10
                }

                Rectangle {
                    id: tuile15
                    width: 100
                    height: 100
                    color: "#ecdbc0"
                    radius: 10
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 10
                    anchors.right: parent.right
                    anchors.rightMargin: 10
                }
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
                text: qsTr("Score")
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
