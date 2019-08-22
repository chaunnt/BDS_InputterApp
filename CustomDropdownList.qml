import QtQuick 2.9
import QtQuick.Controls 2.2


Column{
    id: cbbMain
    property string currentTextValue: ""
    property bool isDropDowned: false
    height: implicitHeight
    spacing: 20 * dpiToPixelValue
    Rectangle {
        id: recDisplay
        width: parent.width
        height: baseButtonHeight
        radius: 5 * dpiToPixelValue
        color: baseColor
        Text{
            id: txtDisplay
            text: currentTextValue
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            height: parent.height
            width: parent.width - parent.height / 2
            x:(parent.width - parent.height / 2) / 2 - width / 2
            color: baseTextColor
            font.pixelSize: normalFontSize
            elide: Text.ElideRight
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                isDropDowned = !isDropDowned
            }
        }
        Image {
            id: imgCbbLeftIcon
            width: height
            height: parent.height / 2
            source: "qrc:/resource/RightArrow_Gray.png"
            rotation: isDropDowned ? 90 : 0
            anchors.right: parent.right
            anchors.rightMargin: 5 * dpiToPixelValue
            y:parent.height / 2 - height / 2
        }
    }
}

