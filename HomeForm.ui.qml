import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    title: qsTr("Home")

    Rectangle {
        id: rectangle
        x: 200
        y: 100
        width: 200
        height: 200
        color: "#ffffff"
        radius: 90
        border.width: 10
    }

    RoundButton {
        id: roundButton
        x: 200
        y: 100
        width: 200
        height: 200
        text: "+"
    }
}
