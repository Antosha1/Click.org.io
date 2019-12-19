import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 200
    height: 200

    title: qsTr("Home")

    RoundButton {
        id: roundButton
        x: 0
        y: 0
        width: 200
        height: 200
        text: "+"
        font.underline: false
        font.weight: Font.Normal
        autoRepeat: false
    }
}
