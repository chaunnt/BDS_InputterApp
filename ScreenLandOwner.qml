import QtQuick 2.0

Rectangle {
    function updateHostInfo(ctName, ctSoDienThoai, ctEmail, ctDiachi, ctGioiTinh, ctDoTuoi){
        appManager.updateHostInfo(ctName, ctSoDienThoai, ctEmail, ctDiachi, ctGioiTinh, ctDoTuoi)
    }
    Text {
        text: qsTr("Thông tin chủ nhà")
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
            dataPoint: settingQML.point_OwnerName
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
                updateHostInfo(txtTen.text, txtSoDienThoai.text, txtEmail.text, txtDiaChi.text, cbbGioiTinh.currentValue, cbbDoTuoi.currentTextValue)

                settingQML.pointRunning_OwnerName = settingQML.point_OwnerName
            }
        }
        Materials_TextBox{
            id:txtSoDienThoai
            placeholderText: qsTr("Số điện thoại")
            width: parent.width - 20 * dpiToPixelValue
            x: 10 * dpiToPixelValue
            dataPoint: settingQML.point_OwnerPhone
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
                updateHostInfo(txtTen.text, txtSoDienThoai.text, txtEmail.text, txtDiaChi.text, cbbGioiTinh.currentValue, cbbDoTuoi.currentTextValue)

                settingQML.pointRunning_OwnerPhone = settingQML.point_OwnerPhone
            }
        }

        Materials_TextBox{
            id:txtEmail
            placeholderText: qsTr("Email")
            width: parent.width - 20 * dpiToPixelValue
            x: 10 * dpiToPixelValue
            dataPoint: settingQML.point_OwnerEmail
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
                updateHostInfo(txtTen.text, txtSoDienThoai.text, txtEmail.text, txtDiaChi.text, cbbGioiTinh.currentValue, cbbDoTuoi.currentTextValue)

                settingQML.pointRunning_OwnerEmail = settingQML.point_OwnerEmail
            }
        }

        Materials_TextBox{
            id:txtDiaChi
            placeholderText: qsTr("Địa chỉ")
            width: parent.width - 20 * dpiToPixelValue
            x: 10 * dpiToPixelValue
            dataPoint: settingQML.point_OwnerAddress
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
                updateHostInfo(txtTen.text, txtSoDienThoai.text, txtEmail.text, txtDiaChi.text, cbbGioiTinh.currentValue, cbbDoTuoi.currentTextValue)

                settingQML.pointRunning_OwnerAddress = settingQML.point_OwnerAddress
            }
        }

        Materials_Combobox{
            dataPoint: settingQML.point_OwnerGender
            //            headerEnabled: true
            headerText: qsTr("Giới tính")
            id:cbbGioiTinh
            currentTextValue: !isUpdateSequence ? "" : (currentBDSData.hostGender === true ? "Nam" : "Nữ")
            width: parent.width - 20 * dpiToPixelValue
            x: 10 * dpiToPixelValue
            model:appManager.sexList
            onCurrentValueChanged: {
                updateHostInfo(txtTen.text, txtSoDienThoai.text, txtEmail.text, txtDiaChi.text, cbbGioiTinh.currentValue, cbbDoTuoi.currentTextValue)
                cbbDoTuoi.forceActiveFocus()
                settingQML.pointRunning_OwnerGender = settingQML.point_OwnerGender
            }
        }
        Materials_Combobox{
            dataPoint: settingQML.point_OwnerAge
            //            headerEnabled: true
            headerText: qsTr("Độ tuổi")
            id:cbbDoTuoi
            currentTextValue: qsTr("Độ tuổi")
            width: parent.width - 20 * dpiToPixelValue
            x: 10 * dpiToPixelValue
            model:appManager.ageList
            onCurrentValueChanged: {
                updateHostInfo(txtTen.text, txtSoDienThoai.text, txtEmail.text, txtDiaChi.text, cbbGioiTinh.currentValue, cbbDoTuoi.currentTextValue)
                settingQML.pointRunning_OwnerAge = settingQML.point_OwnerAge
            }
        }
    }
}
