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

    Connections {
            target: appCore
            onStartSession: {
                stackView.push("HomeForm.ui.qml")
            }
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
        text: "+"
        font.underline: false
        font.weight: Font.Normal
        autoRepeat: false
        font.pixelSize: 36
    }

    Text {
        id: startmessage
        x: (swidth - width)/2
        y: height
        text: qsTr("Searching for losers")
        font.pixelSize: 36
    }

    Text {
        id: ip1
        x: (swidth - width)/2
        y: startmessage.height + ip1.height*4
        property string ip: qsTr("")
        text: ip
        font.pixelSize: 24
        color: "blue"
        Connections {
                target: appCore
                onSendServerIp: {
                    ip1.ip = ipAddr
                }
        }
    }

    BusyIndicator {
        id: busyIndicator
        x: (swidth-swidth/3.6)/2
        y: (sheight-swidth/3.6)/2
        width: swidth/3.6
        height: swidth/3.6
    }

}


