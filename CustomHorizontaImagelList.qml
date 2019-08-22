import QtQuick 2.0

Rectangle{
    id:recHorizontalImageList
    width: 500 * dpiToPixelValue
    height: lvMatTien.height + txtMatTienLabel.height + 30 * dpiToPixelValue
    property var model
    property string listName: ""
    property string imageType: "mattien"
    signal imageDeleted()
    signal captureStarted()
    Text {
        id: txtMatTienLabel
        text: listName
        font.pixelSize: normalFontSize
        width: parent.width
        anchors.top: parent.top
        color:baseTextColor
    }

    Flow{
        id:lvMatTien
        anchors.top: txtMatTienLabel.bottom
        anchors.topMargin: 10 * dpiToPixelValue
        width: parent.width
        height: implicitHeight
        spacing: 5 * dpiToPixelValue
        Rectangle{
            height: baseButtonHeight * 3
            width: baseButtonHeight * 3
            border.width: 1
            border.color: baseSelectingColor
            radius: 5 * dpiToPixelValue
            Text {
                id: name
                text: qsTr("+")
                anchors.centerIn: parent
                color: baseTextColor
                font.pixelSize: bigFontSize
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    captureStarted()
                }
            }
        }
        Repeater{
            id:rptHinhAnhPhapLy
            model: recHorizontalImageList.model
            delegate: Rectangle{
                id:recItemHinhAnh
                height: baseButtonHeight * 3
                width: height
                border.width: 1
                border.color: baseSelectingColor
                radius: 5 * dpiToPixelValue
                clip: true
                Image {
                    anchors.fill: parent
                    fillMode: Image.Stretch
                    source: modelData
                }
                Rectangle{
                    height: baseButtonHeight / 2
                    width: height
                    color: "red"
                    radius: height / 2
                    anchors.top: parent.top
                    anchors.right: parent.right
                    Image {
                        source: "qrc:/resource/X_1_White.png"
                        fillMode: Image.PreserveAspectFit
                        anchors.centerIn: parent
                        width: height
                        height: parent.height / 4 * 3
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            recItemHinhAnh.visible = false
                            appManager.removeImage(imageType, index)
                            recHorizontalImageList.imageDeleted()
                        }
                    }
                }
            }
        }
    }
}
