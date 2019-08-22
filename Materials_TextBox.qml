import QtQuick 2.0
import QtQuick.Controls 2.0

TextField {
    id:txtInputTextField
    height: 40 * dpiToPixelValue
    property double textBoxRadius: 5 * dpiToPixelValue
    property string previousText: ""
    property int dataPoint: 0

    background: Rectangle{
        id:bgText
        color: "transparent"
        radius: textBoxRadius
        anchors.fill: parent
        border.color: baseSelectingColor
        border.width: 1
        Rectangle{
            width: txtHeaderText.width + 10 * dpiToPixelValue
            height: txtHeaderText.height + 6 * dpiToPixelValue
            color: bgText.border.color
            y: bgText.y - height / 2
            x: textBoxRadius
            visible: txtInputTextField.text !== ""
            radius: height / 2
            Text {
                id:txtHeaderText
                text: txtInputTextField.placeholderText
                visible: txtInputTextField.text !== ""
                font.pixelSize: 9 * dpiToPixelValue
                color: txtInputTextField.activeFocus ? baseTextColor : baseColor
                anchors.centerIn: parent
            }
        }
    }
    font.pixelSize: 15 * dpiToPixelValue
    Rectangle{
        width: txtPoint.width + imgStar.width + 5 * dpiToPixelValue
        height: txtPoint.height
        color: "white"
        x: txtPoint.x
        y: txtPoint.y
        visible: dataPoint > 0
    }
    Text {
        id:txtPoint
        text: "+ " + dataPoint
        color: bgText.border.color
        font.pixelSize: txtInputTextField.font.pixelSize
        y:parent.height / 2 - height / 2
        anchors.right: imgStar.left
        anchors.rightMargin: 5 * dpiToPixelValue
        visible: dataPoint > 0
    }
    Image {
        id: imgStar
        source: "qrc:/resource/Star_Yellow.png"
        height: parent.height / 2
        width: height
        y:parent.height / 2 - height / 2
        anchors.right: parent.right
        anchors.rightMargin: 3 * dpiToPixelValue
        visible: dataPoint > 0
    }
    onActiveFocusChanged: {
        console.log(placeholderText + activeFocus)
        if(activeFocus){
            bgText.border.color = baseColor
        }else{
            bgText.border.color = baseSelectingColor
        }
    }
}
