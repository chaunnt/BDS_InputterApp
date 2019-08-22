import QtQuick 2.0

Rectangle {
    color: "transparent"
    width: height
    height: baseButtonHeight * 2
    property string iconSource: ""
    property string value: "value"
    property string labelName: "labelName"
    Image {
        id: imgIcon
        source: iconSource
        height: parent.height / 2
        fillMode: Image.PreserveAspectFit
        anchors.top: parent.top
        anchors.left: parent.left
    }
    Text {
        id: txtValue
        text: value
        width: iconSource === "" ? parent.width : parent.width - imgIcon.width
        height: imgIcon.height
        font.bold: true
        font.pixelSize: normalFontSize
        anchors.right: parent.right
        anchors.top: parent.top
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: iconSource === "" ? Text.AlignHCenter : Text.AlignRight
        elide: Text.ElideRight
    }
    Text {
        id: txtLabelName
        text: labelName
        width: parent.width
        height: parent.height - imgIcon.height
        font.pixelSize: smallFontSize
        anchors.bottom: parent.bottom
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter

    }
}
