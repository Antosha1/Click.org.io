import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: swidth
    height: sheight

    title: qsTr("Home")

    RoundButton {
        id: roundButton
        //x: 0
        //y: 0
        //width: 200
        //height: 200
        x:swidth/2.76
        y:sheight/3.13
        width: swidth/3.6
        height: sheight/8.66
        text: "+"
        font.underline: false
        font.weight: Font.Normal
        autoRepeat: false
    }
}
