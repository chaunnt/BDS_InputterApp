import QtQuick 2.0

Rectangle{
    color: "white"
    ListView {
        id:lvLandList
        width: parent.width
        height: parent.height - 20 * dpiToPixelValue
//        y: 10 * dpiToPixelValue
//        clip: true
//        model:appManager.submittedBDSList
//        spacing: 5 * dpiToPixelValue
//        delegate: Rectangle{
//            id:recItems
//            width: parent.width - 10 * dpiToPixelValue
//            height: colItemDetails.implicitHeight + 10 * dpiToPixelValue
//            border.color: modelData.bdsStatus ? baseColor : "red"
//            border.width: 1 * dpiToPixelValue
//            radius: 5 * dpiToPixelValue
//            x: 5 * dpiToPixelValue
//            MouseArea{
//                anchors.fill: parent
//                onClicked: {
//                    isUpdateSequence = true
//                    isStartSequence = true
//                    waitingDialog.show("Đang lấy dữ liệu... ")
//                    appManager.selectSubmittedBDS(index)
//                    mainStackView.push("qrc:/ScreenLandInputSequence.qml")
//                    waitingDialog.close()
//                }
//            }

//            Column{
//                id:colItemDetails
//                width: parent.width
//                height: implicitHeight
//                spacing: 5 * dpiToPixelValue
//                CustomBaseText {
//                    id: txtDiachi
//                    text:modelData.homenumber + "  " + modelData.street
//                    font.bold: true
//                    width: parent.width - 10 * dpiToPixelValue
//                }
//                CustomBaseText {
//                    id: txtGia
//                    width: parent.width - 10 * dpiToPixelValue
//                    text: qsTr("Giá: ") + modelData.price + qsTr(" Tỷ")
//                }
//                CustomBaseText {
//                    id: txtGiaM2
//                    width: parent.width - 10 * dpiToPixelValue
//                    text: qsTr("Giá m2: ") + modelData.priceUnit + qsTr(" Triệu/m2")
//                }

//                CustomBaseText {
//                    id: txtCreatedDate
//                    text: modelData.bdsCreatedDate
//                    height: parent.height
//                    anchors.right: parent.right
//                    verticalAlignment: Text.AlignVCenter
//                }
//                Rectangle{
//                    width: parent.width - 10 * dpiToPixelValue
//                    height: baseButtonHeight / 2
//                    x : 5 * dpiToPixelValue
//                    visible: !modelData.bdsStatus
//                    Rectangle{
//                        width: txtTrangThaiSubmit.width + 10 * dpiToPixelValue
//                        height: baseButtonHeight / 2
//                        color: "transparent"
//                        border.color: modelData.bdsStatus ? baseColor : "red"
//                        border.width: 1
//                        radius: height / 2
//                        anchors.left: parent.left
//                        CustomBaseText {
//                            id: txtTrangThaiSubmit
//                            text: modelData.bdsStatus ? "đã lưu" : "chưa lưu"
//                            anchors.centerIn: parent
//                            color: modelData.bdsStatus ? baseColor : "red"
//                        }
//                    }
//                }
//            }
//        }
    }

    Rectangle{
        width: parent.width - 40 * dpiToPixelValue
        height: parent.height - 40 * dpiToPixelValue
        color: "transparent"
        border.color: baseTextColor
        radius: 10 * dpiToPixelValue
        anchors.centerIn: parent
        visible: lvLandList.count === 0
    }

    CustomBaseText{
        anchors.centerIn: parent
        color: baseTextColor
        visible: lvLandList.count === 0
        text: qsTr("Chưa có thông tin lịch sử")
    }
}


