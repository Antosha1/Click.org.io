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
        x:(swidth-swidth/3.6)/2
        y:(sheight-swidth/3.6)/2
        width: swidth/3.6
        height: swidth/3.6
        text: "+"
        font.underline: false
        font.weight: Font.Normal
        autoRepeat: false
    }

    Text {
        id: myScore
        x: (swidth - width)/2
        y: (sheight-swidth/3.6)/2 - sheight/10
        text: qsTr("Text Field")
        font.pixelSize: 36
        color: "red"
        //(Math.floor(Math.random()*1000))
        //"#F0000000"
        //Math.floor(Math.random())
    }

    Text {
        id: score1
        x: (swidth - width)/2 - swidth/5
        y: (sheight-swidth/3.6)/2 - sheight/5
        text: qsTr("Text Field")
        font.pixelSize: 24
        color: "blue"
    }

    Text {
        id: score2
        x: (swidth - width)/2
        y: (sheight-swidth/3.6)/2 - sheight/5
        text: swidth
        font.pixelSize: 24
        color: "green"
    }

    Text {
        id: score3
        x: (swidth - width)/2 + swidth/5
        y: (sheight-swidth/3.6)/2 - sheight/5
        text: qsTr("Text Field")
        font.pixelSize: 24
        color: "yellow"
    }



}
