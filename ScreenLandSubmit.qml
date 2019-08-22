import QtQuick 2.0

Rectangle {
    Timer{
        id:tmBack
        interval: 2000
        repeat: false
        onTriggered: {
            mainStackView.pop()
        }
    }
    Component.onCompleted: {
        tmBack.start()
    }

    Rectangle{
        width: parent.width * 70 / 100
        height: width
        anchors.centerIn: parent
        border.width: 1
        border.color: baseTextColor
        radius: width / 2
        Image {
            anchors.fill: parent
            source: "qrc:/resource/Check_Green.png"
            fillMode: Image.PreserveAspectFit
            anchors.centerIn: parent
        }
    }
}
