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
        text: "Start"
        font.underline: false
        font.weight: Font.Normal
        autoRepeat: false
        font.pixelSize: 36
    }
    Connections {
        target: roundButton
        onClicked: stackView.push("HomeForm.ui.qml")
    }

    Text {
        id: startmessage
        x: (swidth - width)/2
        y: height
        text: qsTr("Enter the nickname:3")
        font.pixelSize: 36
    }

    TextField {
        id: nickname
        width: startmessage.width
        x: (swidth - width)/2
        y: startmessage.height + nickname.height*2
        text: qsTr("Chicken")
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 36
    }

}


