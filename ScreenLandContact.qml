import QtQuick 2.0

Rectangle {
    function updateContactInfo(ctName, ctSoDienThoai, ctEmail, ctDiachi, ctGioiTinh, ctDoTuoi){
        appManager.updateContactInfo(ctName, ctSoDienThoai, ctEmail, ctDiachi, ctGioiTinh, ctDoTuoi)
    }
    Text {
        text: qsTr("Thông tin môi giới")
        font.pixelSize: extraFontSize
        color:baseTextColor
        width: parent.width
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        id:txtHeader
    }
    Column{
        height: parent.height - txtHeader.height
        width: parent.width
        y: txtHeader.height
        spacing: 20 * dpiToPixelValue

        Materials_TextBox{
            id:txtTen
            placeholderText: qsTr("Họ và Tên")
            width: parent.width - 20 * dpiToPixelValue
            x: 10 * dpiToPixelValue
            dataPoint: settingQML.point_ContactName
            text: !isUpdateSequence ? "" : currentBDSData.contactFullName
            onActiveFocusChanged: {
                if (!activeFocus){
                    finishEditing()
                }
            }
            Keys.onEnterPressed: {
                finishEditing()
                txtSoDienThoai.forceActiveFocus()
            }

            function finishEditing() {
                updateContactInfo(txtTen.text, txtSoDienThoai.text, txtEmail.text, txtDiaChi.text, cbbGioiTinh.currentValue, cbbDoTuoi.currentTextValue)
                settingQML.pointRunning_ContactName = settingQML.point_ContactName
            }
        }
        Materials_TextBox{
            id:txtSoDienThoai
            placeholderText: qsTr("Số điện thoại")
            width: parent.width - 20 * dpiToPixelValue
            x: 10 * dpiToPixelValue
            dataPoint: settingQML.point_ContactPhone
            text: !isUpdateSequence ? "" : currentBDSData.contactPhone
            onActiveFocusChanged: {
                if (!activeFocus){
                    finishEditing()
                }
            }
            Keys.onEnterPressed: {
                finishEditing()
                txtEmail.forceActiveFocus()
            }

            function finishEditing() {
                updateContactInfo(txtTen.text, txtSoDienThoai.text, txtEmail.text, txtDiaChi.text, cbbGioiTinh.currentValue, cbbDoTuoi.currentTextValue)

                settingQML.pointRunning_ContactPhone = settingQML.point_ContactPhone
            }
        }

        Materials_TextBox{
            id:txtEmail
            placeholderText: qsTr("Email")
            width: parent.width - 20 * dpiToPixelValue
            x: 10 * dpiToPixelValue
            dataPoint: settingQML.point_ContactEmail
            text: !isUpdateSequence ? "" : currentBDSData.contactEmail
            onActiveFocusChanged: {
                if (!activeFocus){
                    finishEditing()
                }
            }
            Keys.onEnterPressed: {
                finishEditing()
                txtDiaChi.forceActiveFocus()
            }

            function finishEditing() {
                updateContactInfo(txtTen.text, txtSoDienThoai.text, txtEmail.text, txtDiaChi.text, cbbGioiTinh.currentValue, cbbDoTuoi.currentTextValue)
                settingQML.pointRunning_ContactEmail = settingQML.point_ContactEmail
            }
        }

        Materials_TextBox{
            id:txtDiaChi
            placeholderText: qsTr("Địa chỉ")
            width: parent.width - 20 * dpiToPixelValue
            x: 10 * dpiToPixelValue
            dataPoint: settingQML.point_ContactAddress
            text: !isUpdateSequence ? "" : currentBDSData.contactAddress
            onActiveFocusChanged: {
                if (!activeFocus){
                    finishEditing()
                }
            }
            Keys.onEnterPressed: {
                finishEditing()
                cbbGioiTinh.forceActiveFocus()
            }

            function finishEditing() {
                updateContactInfo(txtTen.text, txtSoDienThoai.text, txtEmail.text, txtDiaChi.text, cbbGioiTinh.currentValue, cbbDoTuoi.currentTextValue)
                settingQML.pointRunning_ContactAddress = settingQML.point_ContactAddress
            }
        }

        Materials_Combobox{
            dataPoint: settingQML.point_ContactGender
            //            headerEnabled: true
            headerText: qsTr("Giới tính")
            id:cbbGioiTinh
            width: parent.width - 20 * dpiToPixelValue
            x: 10 * dpiToPixelValue
            currentTextValue: !isUpdateSequence ? "" : (currentBDSData.contactGender === true ? "Nam" : "Nữ")
            model:appManager.sexList
            onCurrentValueChanged: {
                updateContactInfo(txtTen.text, txtSoDienThoai.text, txtEmail.text, txtDiaChi.text, cbbGioiTinh.currentValue, cbbDoTuoi.currentTextValue)
                cbbDoTuoi.forceActiveFocus()
                settingQML.pointRunning_ContactGender = settingQML.point_ContactGender
            }
        }

        Materials_Combobox{
            dataPoint: settingQML.point_ContactAge
            //            headerEnabled: true
            headerText: qsTr("Độ tuổi")
            id:cbbDoTuoi
            currentTextValue: !isUpdateSequence ? "" : currentBDSData.contactAge
            width: parent.width - 20 * dpiToPixelValue
            x: 10 * dpiToPixelValue
            model:appManager.ageList
            onCurrentValueChanged: {
                updateContactInfo(txtTen.text, txtSoDienThoai.text, txtEmail.text, txtDiaChi.text, cbbGioiTinh.currentValue, cbbDoTuoi.currentTextValue)
                settingQML.pointRunning_ContactAge = settingQML.point_ContactAge
            }
        }
    }
}
