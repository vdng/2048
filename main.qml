import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Layouts 1.1

Window {
    visible: true
    width: 360
    height: 380

    Rectangle {
        color: "#baab9e"
        anchors.fill: parent
        focus: true

        Keys.onPressed: {
            if (event.key==Qt.Key_Up) {grille.moveUp()}
            if (event.key==Qt.Key_Right) {grille.moveRight()}
            if (event.key==Qt.Key_Left) {grille.moveLeft()}
            if (event.key==Qt.Key_Down) {grille.moveDown()}
        }

        ColumnLayout {
            anchors.fill: parent
            RowLayout {
                Text {
                    text: {
                        if (grille.a_gagne) {
                            return "Gagné !"
                        } else if (grille.finJeu) {
                            return "GAME OVER";
                        } else {
                            return "";
                        }
                    }
                    color: "#f3eaea"
                    opacity: 0.3
                    font.pointSize: 30
                    font.family: "Verdana"
                    Layout.fillWidth: true
                }
                Text {
                    text: grille.get_score
                    color: "#f3eaea"
                    opacity: 0.3
                    font.pointSize: 30
                    font.family: "Verdana"
                }
            }
            Grid {
                y: 10
                anchors.horizontalCenter: parent.horizontalCenter
                rows: 4
                columns: 4
                spacing: 10

                Repeater {
                    model: grille
                    delegate: Tile {
                        value: display
                        state : display
                    }
                }
            }
        }
    }
}
