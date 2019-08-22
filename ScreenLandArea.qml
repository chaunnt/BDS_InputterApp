
import QtQuick 2.0

Rectangle {

    Text {
        id:txtHeader
        text: qsTr("Khu vực")
        font.pixelSize: extraFontSize
        color:baseTextColor
        width: parent.width
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    Component.onCompleted: {
        console.log("isUpdateSequence: " + isUpdateSequence)
        console.log("currentBDSData.province: " + currentBDSData.province)
    }

    Column{
        height: parent.height - txtHeader.height
        width: parent.width
        y: txtHeader.height
        spacing: 20 * dpiToPixelValue
        Materials_Combobox{
            dataPoint: settingQML.point_TinhThanh
//            headerEnabled: true
            headerText: qsTr("Tỉnh / Thành phố")
            id:cbbTinhThanh
            currentTextValue: !isUpdateSequence ? "" : currentBDSData.province
            width: parent.width - 20 * dpiToPixelValue
            x: 10 * dpiToPixelValue
            model:appManager.provinceList
            onCurrentValueChanged: {
                appManager.selectProvince(currentTextValue)
                settingQML.pointRunning_TinhThanh = settingQML.point_TinhThanh
            }
        }
        Materials_Combobox{
            dataPoint: settingQML.point_QuanHuyen
//            headerEnabled: true
            headerText: qsTr("Quận / Huyện")
            id:cbbQuanHuyen
            currentTextValue: !isUpdateSequence ? "" : currentBDSData.district
            width: parent.width - 20 * dpiToPixelValue
            x: 10 * dpiToPixelValue
            model:appManager.districtList
            onCurrentValueChanged: {
                appManager.selectDistrict(currentTextValue)
                settingQML.pointRunning_QuanHuyen = settingQML.point_QuanHuyen
            }
        }
        Materials_Combobox{
            dataPoint: settingQML.point_PhuongXa
//            headerEnabled: true
            headerText: qsTr("Phường / Xã")
            id:cbbPhuongXa
            currentTextValue: !isUpdateSequence ? "" : currentBDSData.ward
            width: parent.width - 20 * dpiToPixelValue
            x: 10 * dpiToPixelValue
            model:appManager.wardList
            onCurrentValueChanged: {
                appManager.selectWard(currentTextValue)
                settingQML.pointRunning_PhuongXa = settingQML.point_PhuongXa
            }
        }
        Materials_Combobox{
            dataPoint: settingQML.point_LoaiBDS
//            headerEnabled: true
            headerText: qsTr("Loại bất động sản")
            id:cbbLoaiBDS
            currentTextValue: !isUpdateSequence ? "" : currentBDSData.type
            width: parent.width - 20 * dpiToPixelValue
            x: 10 * dpiToPixelValue
            model:appManager.realEstateTypesList
            onCurrentValueChanged: {
                appManager.selectType(currentTextValue)
                settingQML.pointRunning_LoaiBDS = settingQML.point_LoaiBDS
            }
        }
    }
}
