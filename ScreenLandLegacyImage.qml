import QtQuick 2.0
import QtWebView 1.1

Rectangle {
    id:itemLandLegacyImage
    Flickable {
        width: parent.width
        height: parent.height
        contentHeight: colContent.implicitHeight + txtHeader.height + 20 * dpiToPixelValue
        clip: true
        flickableDirection: Flickable.VerticalFlick
        visible: !scrLegacySearch.visible
        Text {
            text: qsTr("Hình ảnh pháp lý")
            font.pixelSize: extraFontSize
            color:baseTextColor
            width: parent.width
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            id:txtHeader
        }

        Column{
            id:colContent
            height: parent.height - txtHeader.height
            width: parent.width
            y: txtHeader.height
            spacing: 20 * dpiToPixelValue
            CustomHorizontaImagelList{
                id:recGiayToNha
                width: parent.width - 20 * dpiToPixelValue
                x: 10 * dpiToPixelValue
                model: currentBDSData.legacyImageList
                listName: qsTr("Giấy tờ nhà")
                imageType: settingQML.imageType_giaytonha
                onImageDeleted: {

                }
                onCaptureStarted: {
                    scrCamera.visible = true
                    scrCamera.imageType = imageType
                }
            }
//            CustomHorizontaImagelList{
//                id:recQuyHoachLoGioi
//                width: parent.width - 20 * dpiToPixelValue
//                x: 10 * dpiToPixelValue
//                model: currentBDSData.landPlanningImageList
//                listName: qsTr("Quy hoạch lộ giới")
//                imageType: settingQML.imageType_quyhoachlogioi
//                onImageDeleted: {

//                }
//                onCaptureStarted: {
//                    scrLegacySearch.visible = true
//                }
//            }
        }
    }
}
