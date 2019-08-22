import QtQuick 2.0

Rectangle {
    property bool isSkipped: false
    Column{
        y: 20 * dpiToPixelValue
        x: 10 * dpiToPixelValue
        width: parent.width
        spacing: 5 * dpiToPixelValue
        Text {
            width: parent.width
            font.pixelSize: normalFontSize
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            text: qsTr("Ngày bắt đầu: ")
        }
        Materials_TextBox{
            width: parent.width - 20 * dpiToPixelValue
            text: "01/01/2018"
            placeholderText: "DD/YY/MMMM"
        }
//        Rectangle {
//            width: parent.width
//            height: baseButtonHeight
//            Rectangle{
//                id:ckbSkip
//                height: parent.height / 2
//                width:  height
//                y:  parent.height / 2 - height / 2
//                anchors.left: parent.left
//                anchors.leftMargin: 5 * dpiToPixelValue
//                radius: height / 2
//                border.color: baseColor
//                border.width: 1
//                Rectangle{
//                    width: parent.width - 6 * dpiToPixelValue
//                    height: width
//                    color: baseColor
//                    visible: isSkipped == false ? false : true
//                    anchors.centerIn: parent
//                    radius: height / 2
//                }
//            }
//            Text {
//                width: parent.width - ckbSkip.width - 10 * dpiToPixelValue
//                x: ckbSkip.width + 5 * dpiToPixelValue
//                text: qsTr("Bỏ qua thông tin trùng lặp")
//                font.pixelSize: normalFontSize
//                verticalAlignment: Text.AlignVCenter
//                height: parent.height
//                clip: true
//            }
//            MouseArea{
//                anchors.fill: parent
//                onClicked: {
//                    isSkipped = !isSkipped
//                }
//            }
//        }
//        Rectangle {
//            width: parent.width
//            height: baseButtonHeight
//            Rectangle{
//                height: parent.height / 2
//                width:  height
//                y:  parent.height / 2 - height / 2
//                anchors.left: parent.left
//                anchors.leftMargin: 5 * dpiToPixelValue
//                radius: height / 2
//                border.color: baseColor
//                border.width: 1
//                Rectangle{
//                    width: parent.width - 6 * dpiToPixelValue
//                    height: width
//                    color: baseColor
//                    visible: isSkipped == false ? true : false
//                    anchors.centerIn: parent
//                    radius: height / 2
//                }
//            }
//            Text {
//                width: parent.width - ckbSkip.width - 10 * dpiToPixelValue
//                x: ckbSkip.width + 5 * dpiToPixelValue
//                font.pixelSize: normalFontSize
//                verticalAlignment: Text.AlignVCenter
//                text: qsTr("Ngừng quét khi có thông tin trùng lặp")
//                height: parent.height
//                clip: true
//            }
//            MouseArea{
//                anchors.fill: parent
//                onClicked: {
//                    isSkipped = !isSkipped
//                }
//            }
//        }

        ListModel{
            id:lmLoaiBDS
            ListElement{
                displayText:"Biệt thự / villa / Penthouse"
                displayActive:false
            }
//            ListElement{
//                displayText:"Chung cư"
//                displayActive:false
//            }
            ListElement{
                displayText:"Nhà hẻm / ngõ"
                displayActive:true
            }
            ListElement{
                displayText:"Nhà mặt tiền / phố"
                displayActive:true
            }
//            ListElement{
//                displayText:"Đất"
//                displayActive:false
//            }
//            ListElement{
//                displayText:"Đất dự án"
//                displayActive:false
//            }
//            ListElement{
//                displayText:"Khác"
//                displayActive:false
//            }
        }

        CustomComboboxWithCheckbox{
            id:cbbLoaiBDS
            currentText: "Loại bất động sản"
            width: parent.width - 20 * dpiToPixelValue
            model:lmLoaiBDS
            onItemCheckedChanged: {
                appManager.changeSetting_LoaiBDS(itemText, itemChecked)
            }
        }
        ListModel{
            id:lmQuanHuyen
            ListElement{
                displayText:"Quận 1"
                displayActive:true
            }
            ListElement{
                displayText:"Quận 3"
                displayActive:true
            }
            ListElement{
                displayText:"Quận Bình Thạnh"
                displayActive:true
            }
            ListElement{
                displayText:"Quận Gò Vấp"
                displayActive:true
            }
            ListElement{
                displayText:"Quận Phú Nhuận"
                displayActive:true
            }
        }
//        CustomComboboxWithCheckbox{
//            id:cbbQuanHuyen
//            currentText: "Quận / Huyện"
//            width: parent.width - 20 * dpiToPixelValue
//            model:lmQuanHuyen
//            onItemCheckedChanged: {
//                appManager.changeSetting_QuanHuyen(itemText, itemChecked)
//            }
//        }

        CustomButton{
            width: parent.width - 20 * dpiToPixelValue
            buttonText: "Bắt đầu quét"
            onClicked: {
                mainStackView.push("qrc:/ScreenHome.qml")
            }
        }
    }
}
