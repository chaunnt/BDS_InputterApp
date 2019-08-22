import QtQuick 2.0

Rectangle {
    Rectangle{
        border.width: 1
        border.color: baseColor
        radius: 5 * dpiToPixelValue
        width: parent.width - 10 * dpiToPixelValue
        height: parent.height - 10 * dpiToPixelValue
        anchors.centerIn: parent
        Flickable{
            anchors.fill: parent
            clip: true
            flickableDirection: Flickable.VerticalFlick
            contentHeight: txtNotificationContent.height
            Text {
                id: txtNotificationContent
                width: parent.width - 10 * dpiToPixelValue
                x: 5 * dpiToPixelValue
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                font.pixelSize: normalFontSize
                text: qsTr("Notification Content Notification Content Notification Content Notification Content Notification Content Notification Content Notification Content Notification Content Notification Content Notification Content Notification Content Notification Content Notification Content Notification Content Notification Content Notification Content Notification Content Notification Content Notification Content Notification Content Notification Content Notification Content ")
            }
        }
    }
}
