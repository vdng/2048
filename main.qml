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
            if (event.key==Qt.Key_Up) {grille_transition.moveUp()}
            if (event.key==Qt.Key_Right) {grille_transition.moveRight()}
            if (event.key==Qt.Key_Left) {grille_transition.moveLeft()}
            if (event.key==Qt.Key_Down) {grille_transition.moveDown()}
        }

        ColumnLayout {
            anchors.fill: parent
            RowLayout {
                Text {
                    text: {
                        if (grille_transition.a_gagne) {
                            return "Gagné !"
                        } else if (grille_transition.finJeu) {
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
                    text: grille_transition.get_score
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
                    model: grille_transition
                    delegate: Tile {
                        value: display
                        state : display
                    }
                }
            }
        }
    }
}
