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

    Text {
        id: endmessage
        property string winnername: ""
        x: (swidth - width)/2
        y: height
        text: winnername + qsTr(" wins")
        font.pixelSize: 36
        Connections {
                target: appCore
                onSendWinnerNickName: {
                    endmessage.winnername = nickName
                }
        }
    }

}


