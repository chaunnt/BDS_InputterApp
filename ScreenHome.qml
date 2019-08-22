import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Rectangle{
    id:recHome
    color: "white"
    Rectangle{
        id:recAccountInfo
        width: parent.width - 20 * dpiToPixelValue
        height: baseButtonHeight * 2
        x: 10 * dpiToPixelValue
        y: 10 * dpiToPixelValue
        color: "transparent"
        Rectangle{
            id:recAccountImage
            height: baseButtonHeight * 2
            width: height
            anchors.left: parent.left
            anchors.top: parent.top
            color: "transparent"
            Rectangle{
                anchors.fill: parent
                radius: height / 2
                border.color: baseColor
                border.width: 1
                Image {
                    id: imgProfile
                    source: "qrc:/resource/icon_hobe.png"
                    fillMode: Image.PreserveAspectFit
                    width: parent.width
                }
            }
        }
        Text {
            id: txtAccountName
            text: appManager.userFullName
            font.pixelSize: bigFontSize
            anchors.top: parent.top
            anchors.left: recAccountImage.right
            anchors.leftMargin: 5 * dpiToPixelValue
            width: parent.width - recAccountImage.width
            elide: Text.ElideRight
        }
        Rectangle{
            id:recAccountPointInfo
            anchors.bottom: parent.bottom
            anchors.left: recAccountImage.right
            anchors.leftMargin: 5 * dpiToPixelValue
            width: parent.width - recAccountImage.width - 10 * dpiToPixelValue
            height: parent.height - txtAccountName.height
            CustomRecWithIconTextValue{
                width: parent.width / 3
                height: parent.height
                labelName: qsTr("Tổng điểm")
                value: "99999"
                anchors.left: parent.left
            }
            CustomRecWithIconTextValue{
                width: parent.width / 3
                height: parent.height
                labelName: qsTr("Đã lưu")
                value: appManager.countSubmittedBDS
                anchors.centerIn: parent
            }
            CustomRecWithIconTextValue{
                width: parent.width / 3
                height: parent.height
                labelName: qsTr("Bị lỗi")
                value: appManager.countUnsubmittedBDS
                anchors.right: parent.right
            }
        }
    }

    Rectangle{
        id:recNotificationsList
        width: parent.width - 20 * dpiToPixelValue
        height: parent.height - 30 * dpiToPixelValue - recAccountInfo.height
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10 * dpiToPixelValue
        radius: 5 * dpiToPixelValue
        x: 10 * dpiToPixelValue
        border.color: "lightgray"
        border.width: 1
        color: "transparent"
        Text {
            text: qsTr("Chưa có thông báo mới")
            font.pixelSize: normalFontSize
            anchors.centerIn: parent
            visible: lvNotificationList.count < 1
        }
        ListView{
            id:lvNotificationList
            clip: true
            width: parent.width - 10 * dpiToPixelValue
            height: parent.height - 10 * dpiToPixelValue
            anchors.centerIn: parent
            model: appManager.notificationList
            spacing: 5 * dpiToPixelValue
            delegate: Rectangle{
                width: parent.width
                height: recPriorityAndDate.height + txtTitle.height + 10 * dpiToPixelValue
                radius: 5 * dpiToPixelValue
                border.color: baseColor
                border.width: 1
                Text {
                    id: txtTitle
                    text: qsTr("Notification text Notification text Notification text Notification text Notification text Notification textNotification textNotification textNotification textNotification textNotification textNotification textNotification textNotification textNotification textNotification textNotification text")
                    width: parent.width - 10 * dpiToPixelValue
                    height: txtTitle.implicitHeight
                    x : 5 * dpiToPixelValue
                    verticalAlignment: Text.AlignTop
                    font.pixelSize: normalFontSize
                    anchors.top:parent.top
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere

                }
                Rectangle{
                    id: recPriorityAndDate
                    width: parent.width - 10 * dpiToPixelValue
                    x: 5 * dpiToPixelValue
                    height: baseButtonHeight
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 5 * dpiToPixelValue
                    Text{
                        id:txtDate
                        text:"yyyy-mm-dd"
                        font.pixelSize: normalFontSize
                        anchors.left: parent.left
                        height: parent.height
                        verticalAlignment: Text.AlignVCenter
                    }
                    Rectangle{
                        height: baseButtonHeight
                        width: txtPriority.width + 10 * dpiToPixelValue
                        radius: height / 2
                        color: "limegreen"
                        y:parent.height / 2 - height / 2
                        anchors.right: parent.right
                        Text{
                            id:txtPriority
                            text:"Bình thường"
                            font.pixelSize: normalFontSize
                            anchors.centerIn: parent
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignRight
                        }
                    }

                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        mainStackView.push("qrc:/ScreenNotification.qml")
                    }
                }
            }
        }
    }
    Rectangle{
        id:recAddBDS
        height: baseButtonHeight * 1.5
        width: height
        radius: height / 2
        anchors.right: parent.right
        anchors.rightMargin: 10 * dpiToPixelValue
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10 * dpiToPixelValue
        color: baseColor
        MouseArea{
            anchors.fill: parent
            onClicked: {
                appManager.startInputSequence()
                isStartSequence = true
                mainswipeIndex = 0
                settingQML.initPoint()
                mainStackView.push("qrc:/ScreenLandInputSequence.qml")
                drawer.activeIndex = 1
            }
        }
        Text {
            text: qsTr("+")
            font.pixelSize: extraFontSize
            anchors.centerIn: parent
            color:baseTextColor
        }
//        Loader {
//            id: dialOutlineLoader
//            asynchronous: true
//            anchors.fill: parent
//            Component.onCompleted: dialOutlineLoader.setSource("/Application/DockSense/DialOutline.qml", { appPresenter: appPresenter })
//        }
    }
}
