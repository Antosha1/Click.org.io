import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: swidth
    height: sheight

    title: qsTr("Home")

    Label {
        text: qsTr("You are on Page 1.")
        anchors.centerIn: parent
    }

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
        text: "Play again"
        font.underline: false
        font.weight: Font.Normal
        autoRepeat: false
        font.pixelSize: 36
    }
    Connections {
        target: roundButton
        onClicked: stackView.push("StartForm.ui.qml")
    }

    ProgressBar {
        id: timeBar
        x: (swidth - width)/2
        y: timeBar.height
        value: time
    }

}


