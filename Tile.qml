import QtQuick 2.2

Rectangle {
    id: tile
    property string value: ""

    width: 70
    height: 70
    color: "#cbbeb1"
    radius: 5

    Text {
        id: valeur
        text: value
        font.pointSize: 25
        anchors.centerIn: parent
        color: "black"
    }

    states:[
    State{
            name:"0"
            PropertyChanges{target : tile; color: "#cbbeb1";}
            PropertyChanges{target: valeur; color: "#cbbeb1";}
        },
    State{
            name:"2"
            PropertyChanges{target : tile; color: "#eee4da";}
        },
    State{
            name:"4"
            PropertyChanges{target : tile; color: "#eae0c8";}
        },
    State{
            name:"8"
            PropertyChanges{target : tile; color: "#f59563";}
        },

    State{
            name:"16"
            PropertyChanges{target : tile; color: "#f8804e";}
        },

    State{
            name:"32"
            PropertyChanges{target : tile; color: "#e86127";}
        },
    State{
            name:"64"
            PropertyChanges{target : tile; color: "#f14208";}
        },
    State{
            name:"128"
            PropertyChanges{target : tile; color: "#f9ee8c";}
        },
    State{
            name:"256"
            PropertyChanges{target : tile; color: "#f3e56f";}
        },
    State{
            name:"512"
            PropertyChanges{target : tile; color: "#eddb3a";}
        },
    State{
            name:"1024"
            PropertyChanges{target : tile; color: "#f3dc0c";}
        },
    State{
            name:"2048"
            PropertyChanges{target : tile; color: "#fbc401";}
        }

    ]
}
