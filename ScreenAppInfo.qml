import QtQuick 2.0

Item {
    Column{
        width: parent.width - 20 * dpiToPixelValue
        x: 10 * dpiToPixelValue
        spacing: 20 * dpiToPixelValue
        CustomBaseText{
            text: qsTr("Copyright © Công ty cổ phần HOBE Coporation")
            width: parent.width
            horizontalAlignment: Text.AlignHCenter
        }
        Rectangle{
            width: parent.width
            height: baseButtonHeight * 2
            CustomBaseText{
                text: qsTr("Liên hệ")
                width: parent.width
                horizontalAlignment: Text.AlignHCenter
                font.bold: true
                anchors.top: parent.top
            }
            Rectangle{
                width: parent.width
                height: baseButtonHeight
                anchors.bottom: parent.bottom
                Row{
                    spacing: 20 * dpiToPixelValue
                    height: baseButtonHeight
                    width: parent.width
                    x:parent.width / 2 - implicitWidth / 2
                    Image {
                        source: "qrc:/resource/WWW_Icon_DarkBlue.png"
                        height: parent.height
                        fillMode: Image.PreserveAspectFit
                    }

                    Image {
                        source: "qrc:/resource/FB_Style2.png"
                        height: parent.height
                        fillMode: Image.PreserveAspectFit
                    }
                }
            }
        }
    }
}
