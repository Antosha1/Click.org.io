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
        property int my_score: 0
        text: my_score
        font.pixelSize: 36
        color: "red"
        Connections {
                target: appCore
                onSendMyScoreToQML: {
                    myScore.my_score = score
                }
        }
    }

    Text {
        id: score1
        x: (swidth - width)/2 - swidth/5
        y: (sheight-swidth/3.6)/2 - sheight/5
        property int curr_score: 0
        text: curr_score
        font.pixelSize: 24
        color: "blue"
        Connections {
                target: appCore
                onSendPlayer1ScoreToQML: {
                    score1.curr_score = score
                }
        }
    }

    Text {
        id: score2
        x: (swidth - width)/2
        y: (sheight-swidth/3.6)/2 - sheight/5
        property int curr_score: 0
        text: curr_score
        font.pixelSize: 24
        color: "green"

        Connections {
                target: appCore
                onSendPlayer2ScoreToQML: {
                    score2.curr_score = score
                }
        }
    }

    Text {
        id: score3
        x: (swidth - width)/2 + swidth/5
        y: (sheight-swidth/3.6)/2 - sheight/5
        property int curr_score: 0
        text: curr_score
        font.pixelSize: 24
        color: "yellow"

        Connections {
                target: appCore
                onSendPlayer3ScoreToQML: {
                    score3.curr_score = score
                }
        }
    }

    Connections {
        target: roundButton
        onClicked: appCore.qmlButtonClicked()
    }

    Connections {
            target: appCore
            onEndSession: {
                stackView.push("FinalForm.ui.qml")
            }
    }

    ProgressBar {
        id: timeBar
        x: (swidth - width)/2
        y: timeBar.height
        value: time
        Connections {
                target: appCore
                onSendTime: {
                    timeBar.time = time
                }
        }
    }

}
