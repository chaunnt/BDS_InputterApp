import QtQuick 2.0

Rectangle{
    Flickable {
        id:flkLandDetail
        clip: true
        width: parent.width
        height: parent.height
        contentHeight: colContent.implicitHeight + txtHeader.height + 200 * dpiToPixelValue
        flickableDirection : Flickable.VerticalFlick
        boundsBehavior: Flickable.StopAtBounds
        Text {
            text: qsTr("Thông tin bất động sản")
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

            CustomDropdownList{
                id:cdlDiaChi
                currentTextValue: qsTr("Địa Chỉ")
                width: parent.width - 20 * dpiToPixelValue
                x: 10 * dpiToPixelValue
                Materials_TextBox{
                    id:txtSoNha
                    placeholderText: qsTr("Số nhà")
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlDiaChi.isDropDowned
                    inputMethodHints: "ImhDigitsOnly"
                    dataPoint: settingQML.point_DiaChiNha
                    text: !isUpdateSequence ? "" : currentBDSData.homenumber
                    onActiveFocusChanged: {
                        if (!activeFocus){
                            finishEditing()
                        }
                    }
                    Keys.onEnterPressed: {
                        finishEditing()
                        txtTenDuong.forceActiveFocus()
                    }

                    function finishEditing() {
                        currentBDSData.homenumber = text
                        if(previousText !== text){
                            previousText = text
                            settingQML.pointRunning_DiaChiNha = settingQML.point_DiaChiNha
                        }
                    }
                }
                Materials_TextBox{
                    id:txtTenDuong
                    placeholderText: qsTr("Tên đường")
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlDiaChi.isDropDowned
                    dataPoint: settingQML.point_TenDuong
                    text: !isUpdateSequence ? "" : currentBDSData.street
                    onActiveFocusChanged: {
                        if (!activeFocus){
                            finishEditing()
                        }
                    }
                    Keys.onEnterPressed: {
                        finishEditing()
                        txtViTri.forceActiveFocus()
                    }

                    function finishEditing() {
                        if(previousText !== text){
                            currentBDSData.street = text
                            previousText = text
                            settingQML.pointRunning_TenDuong = settingQML.point_TenDuong
                        }
                    }
                }
                Materials_Combobox{
                    dataPoint: settingQML.point_ViTri
                    //                    headerEnabled: true
                    headerText: qsTr("Vị Trí")
                    id:txtViTri
                    currentTextValue: !isUpdateSequence ? "" : currentBDSData.landPosition
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    model:appManager.landPositionList
                    visible: cdlDiaChi.isDropDowned
                    onCurrentValueChanged: {
                        appManager.selectLandPosition(currentTextValue)
                        txtChieuRongDuong.forceActiveFocus()
                        settingQML.pointRunning_ViTri = settingQML.point_ViTri
                    }
                }
                Materials_TextBox{
                    id:txtChieuRongDuong
                    placeholderText: qsTr("Chiều rộng đường (m)")
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlDiaChi.isDropDowned
                    inputMethodHints: "ImhDigitsOnly"
                    dataPoint: settingQML.point_ChieuRongDuong
                    text: !isUpdateSequence ? "" : (currentBDSData.streetWidth === const_DEFAULT_INT_VALUE ? "" : currentBDSData.streetWidth)
                    onActiveFocusChanged: {
                        if (!activeFocus){
                            finishEditing()
                        }
                    }
                    Keys.onEnterPressed: {
                        finishEditing()
                        txtTenDuAn.forceActiveFocus()
                    }

                    function finishEditing() {
                        if(previousText !== text){
                            currentBDSData.streetWidth = parseFloat(text)
                            previousText = text
                        }
                        settingQML.pointRunning_ChieuRongDuong = settingQML.point_ChieuRongDuong
                    }

                }
                Materials_TextBox{
                    id:txtTenDuAn
                    placeholderText: qsTr("Tên dự án")
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlDiaChi.isDropDowned
                    dataPoint: settingQML.point_DuAn
                    text: !isUpdateSequence ? "" : currentBDSData.landProjectName
                    onActiveFocusChanged: {
                        if (!activeFocus){
                            finishEditing()
                        }
                    }
                    Keys.onEnterPressed: {
                        finishEditing()
                        cdlGia.forceActiveFocus()
                        cdlGia.isDropDowned = true
                    }

                    function finishEditing() {
                        if(previousText !== text){
                            currentBDSData.landProjectName = text
                            previousText = text
                        }
                        settingQML.pointRunning_DuAn = settingQML.point_DuAn
                    }
                }
            }
            CustomDropdownList{
                id:cdlGia
                currentTextValue: qsTr("Giá")
                width: parent.width - 20 * dpiToPixelValue
                x: 10 * dpiToPixelValue
                onIsDropDownedChanged: {
                    if(isDropDowned){
                        txtGia.forceActiveFocus()
                    }
                }
                Materials_TextBox{
                    id:txtGia
                    placeholderText: qsTr("Giá")
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlGia.isDropDowned
                    inputMethodHints: "ImhDigitsOnly"
                    dataPoint: settingQML.point_GiaBan
                    text: !isUpdateSequence ? "" : (currentBDSData.price === const_DEFAULT_INT_VALUE ? "" : currentBDSData.price)
                    onActiveFocusChanged: {
                        if (!activeFocus){
                            finishEditing()
                        }
                    }
                    Keys.onEnterPressed: {
                        finishEditing()
                        txtDiscussedPrice.forceActiveFocus()
                    }

                    function finishEditing() {
                        if(previousText !== text){
                            currentBDSData.price = parseFloat(text)
                            previousText = text
                            settingQML.pointRunning_GiaBan = settingQML.point_GiaBan
                        }
                        appManager.calculateCurrentPriceList()
                    }
                }
                Materials_TextBox{
                    id:txtDiscussedPrice
                    placeholderText: qsTr("Giá thương lượng")
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlGia.isDropDowned
                    inputMethodHints: "ImhDigitsOnly"
                    dataPoint: settingQML.point_DiscussedPrice
                    text: !isUpdateSequence ? "" : (currentBDSData.discussedPrice === const_DEFAULT_INT_VALUE ? "" : currentBDSData.discussedPrice)
                    onActiveFocusChanged: {
                        if (!activeFocus){
                            finishEditing()
                        }
                    }
                    Keys.onEnterPressed: {
                        finishEditing()
                        txtGiaDonVi.forceActiveFocus()
                    }

                    function finishEditing() {
                        if(previousText !== text){
                            currentBDSData.discussedPrice = parseFloat(text)
                            previousText = text
                            settingQML.pointRunning_DiscussedPrice = settingQML.point_DiscussedPrice
                        }
                        appManager.calculateCurrentPriceList()
                    }
                }
            }
            CustomDropdownList{
                id:cdlDat
                currentTextValue: qsTr("Thông tin của mảnh đất")
                width: parent.width - 20 * dpiToPixelValue
                x: 10 * dpiToPixelValue
                onIsDropDownedChanged: {
                    if(isDropDowned){
                        txtChieuNgangDat.forceActiveFocus()
                    }
                }

                Materials_TextBox{
                    id:txtChieuNgangDat
                    placeholderText: qsTr("Chiều ngang (m)")
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlDat.isDropDowned
                    inputMethodHints: "ImhDigitsOnly"
                    dataPoint: settingQML.point_ChieuNgang
                    text: !isUpdateSequence ? "" : (currentBDSData.landWide === const_DEFAULT_INT_VALUE ? "" : currentBDSData.landWide)
                    onActiveFocusChanged: {
                        if (!activeFocus){
                            finishEditing()
                        }
                    }
                    Keys.onEnterPressed: {
                        finishEditing()
                        txtChieudaiDat.forceActiveFocus()
                    }

                    function finishEditing() {
                        currentBDSData.landWide = parseFloat(text)
                        if(previousText !== text){
                            previousText = text
                        }
                        settingQML.pointRunning_ChieuNgang = settingQML.point_ChieuNgang
                    }
                }
                Materials_TextBox{
                    id:txtChieudaiDat
                    placeholderText: qsTr("Chiều dài (m)")
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlDat.isDropDowned
                    inputMethodHints: "ImhDigitsOnly"
                    dataPoint: settingQML.point_ChieuDai
                    text: !isUpdateSequence ? "" : (currentBDSData.landLong === const_DEFAULT_INT_VALUE ? "" : currentBDSData.landLong)
                    onActiveFocusChanged: {
                        if (!activeFocus){
                            finishEditing()
                        }
                    }
                    Keys.onEnterPressed: {
                        finishEditing()
                        txtDienTichCongNhan.forceActiveFocus()
                    }

                    function finishEditing() {
                        currentBDSData.landLong = parseFloat(text)
                        if(previousText !== text){
                            previousText = text
                        }
                        settingQML.pointRunning_ChieuDai = settingQML.point_ChieuDai
                    }
                }
                Materials_TextBox{
                    id:txtDienTichCongNhan
                    placeholderText: qsTr("Diện tích công nhận (m2)")
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlDat.isDropDowned
                    inputMethodHints: "ImhDigitsOnly"
                    dataPoint: settingQML.point_DienTichCongNhan
                    text: !isUpdateSequence ? "" : (currentBDSData.landDefaultSquare === const_DEFAULT_INT_VALUE ? "" : currentBDSData.landDefaultSquare)
                    onActiveFocusChanged: {
                        if (!activeFocus){
                            finishEditing()
                        }
                    }
                    Keys.onEnterPressed: {
                        finishEditing()
                        txtDienTichThucTe.forceActiveFocus()
                    }

                    function finishEditing() {
                        currentBDSData.landDefaultSquare = parseFloat(text)
                        if(previousText !== text){
                            previousText = text
                        }
                        settingQML.pointRunning_DienTichCongNhan = settingQML.point_DienTichCongNhan
                        appManager.calculateCurrentPriceList()
                    }
                }
                Materials_TextBox{
                    id:txtDienTichThucTe
                    placeholderText: qsTr("Diện tích thực tế (m2)")
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlDat.isDropDowned
                    inputMethodHints: "ImhDigitsOnly"
                    dataPoint: settingQML.point_DienTichThucTe
                    text: !isUpdateSequence ? "" : (currentBDSData.landRealitySquare === const_DEFAULT_INT_VALUE ? "" : currentBDSData.landRealitySquare)
                    onActiveFocusChanged: {
                        if (!activeFocus){
                            finishEditing()
                        }
                    }
                    Keys.onEnterPressed: {
                        finishEditing()
                        txtDienTichLoGioi.forceActiveFocus()
                    }

                    function finishEditing() {
                        currentBDSData.landRealitySquare = parseFloat(text)
                        if(previousText !== text){

                            previousText = text
                        }
                        settingQML.pointRunning_DienTichThucTe = settingQML.point_DienTichThucTe
                        appManager.calculateCurrentPriceList()
                    }
                }
                Materials_TextBox{
                    id:txtDienTichLoGioi
                    placeholderText: qsTr("Diện tích lộ giới (m2)")
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlDat.isDropDowned
                    inputMethodHints: "ImhDigitsOnly"
                    text: !isUpdateSequence ? "" : (currentBDSData.roadSquare === const_DEFAULT_INT_VALUE ? "" : currentBDSData.roadSquare)
                    dataPoint: settingQML.point_DienTichLoGioi
                    onActiveFocusChanged: {
                        if (!activeFocus){
                            finishEditing()
                        }
                    }
                    Keys.onEnterPressed: {
                        finishEditing()
                        txtDienTichDatNongNghiep.forceActiveFocus()
                    }


                    function finishEditing() {
                        if(previousText !== text){
                            currentBDSData.roadSquare = parseFloat(text)
                            previousText = text
                            settingQML.pointRunning_DienTichLoGioi = settingQML.point_DienTichLoGioi
                        }
                        appManager.calculateCurrentPriceList()
                    }
                }
                Materials_TextBox{
                    id:txtDienTichDatNongNghiep
                    placeholderText: qsTr("Diện tích đất nông nghiệp (m2)")
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlDat.isDropDowned
                    inputMethodHints: "ImhDigitsOnly"
                    dataPoint: settingQML.point_DienTichDatNongNghiep
                    text: !isUpdateSequence ? "" : (currentBDSData.landAgriculturalLandSquare === const_DEFAULT_INT_VALUE ? "" : currentBDSData.landAgriculturalLandSquare)
                    onActiveFocusChanged: {
                        if (!activeFocus){
                            finishEditing()
                        }
                    }
                    Keys.onEnterPressed: {
                        finishEditing()
                        cbbHinhDangDat.forceActiveFocus()
                    }

                    function finishEditing() {
                        if(previousText !== text){

                            previousText = text
                            currentBDSData.landAgriculturalLandSquare = parseFloat(text)
                            settingQML.pointRunning_DienTichDatNongNghiep = settingQML.point_DienTichDatNongNghiep
                        }
                    }
                }
                Materials_Combobox{
                    dataPoint: settingQML.point_HinhDang
                    //                    headerEnabled: true
                    headerText: qsTr("Hình dạng")
                    id:cbbHinhDangDat
                    currentTextValue: !isUpdateSequence ? "" : currentBDSData.landShape
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    model:appManager.landShapesList
                    visible: cdlDat.isDropDowned
                    onCurrentValueChanged: {
                        appManager.selectLandShape(currentTextValue)
                        cbbQuyHoachDat.forceActiveFocus()
                        settingQML.pointRunning_HinhDang = settingQML.point_HinhDang
                    }
                }
                Materials_Combobox{
                    dataPoint: settingQML.point_QuyHoachLoaiDat
                    //                    headerEnabled: true
                    headerText: qsTr("Quy hoạch loại đất")
                    id:cbbQuyHoachDat
                    currentTextValue: !isUpdateSequence ? "" : currentBDSData.landPlanningType
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    model:appManager.landPlanningList
                    visible: cdlDat.isDropDowned
                    onCurrentValueChanged: {
                        appManager.selectLandPlanning(currentTextValue)
                        cbbHuong.forceActiveFocus()
                        settingQML.pointRunning_QuyHoachLoaiDat = settingQML.point_QuyHoachLoaiDat
                    }
                }
                Materials_Combobox{
                    dataPoint: settingQML.point_Huong
                    //                    headerEnabled: true
                    headerText: qsTr("Hướng")
                    id:cbbHuong
                    currentTextValue: !isUpdateSequence ? "" : currentBDSData.landDirection
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    model:appManager.landDirectionsList
                    visible: cdlDat.isDropDowned
                    onCurrentValueChanged: {
                        appManager.selectLandDirection(currentTextValue)
                        if(focus){
                            cdlNha.isDropDowned = true
                        }
                        settingQML.pointRunning_Huong = settingQML.point_Huong
                    }
                }
            }
            CustomDropdownList{
                id:cdlNha
                currentTextValue: qsTr("Thông tin nhà trên đất")
                width: parent.width - 20 * dpiToPixelValue
                x: 10 * dpiToPixelValue
                isDropDowned: false
                onIsDropDownedChanged: {
                    if(isDropDowned){
                        txtDienTichXayDung.forceActiveFocus()
                    }
                }

                Materials_TextBox{
                    id:txtDienTichXayDung
                    placeholderText: qsTr("Diện tích xây dựng (m2)")
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlNha.isDropDowned
                    inputMethodHints: "ImhDigitsOnly"
                    dataPoint: settingQML.point_ConstructionSquare
                    text: !isUpdateSequence ? "" : (currentBDSData.constructionSquare === const_DEFAULT_INT_VALUE ? "" : currentBDSData.constructionSquare)
                    onActiveFocusChanged: {
                        if (!activeFocus){
                            finishEditing()
                        }
                    }
                    Keys.onEnterPressed: {
                        finishEditing()
                        txtFloorSquare.forceActiveFocus()
                    }

                    function finishEditing() {
                        currentBDSData.constructionSquare = parseFloat(text)
                        if(previousText !== text){

                            previousText = text
                        }
                        settingQML.pointRunning_ConstructionSquare = settingQML.point_ConstructionSquare
                        appManager.calculateCurrentPriceList()
                    }
                }
                Materials_TextBox{
                    id:txtFloorSquare
                    placeholderText: qsTr("Diện tích sàn (m2)")
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlNha.isDropDowned
                    inputMethodHints: "ImhDigitsOnly"
                    dataPoint: settingQML.point_FloorSquare
                    text: !isUpdateSequence ? "" : (currentBDSData.floorSquare === const_DEFAULT_INT_VALUE ? "" : currentBDSData.floorSquare)
                    onActiveFocusChanged: {
                        if (!activeFocus){
                            finishEditing()
                        }
                    }
                    Keys.onEnterPressed: {
                        finishEditing()
                        txtFloors.forceActiveFocus()


                    }

                    function finishEditing() {
                        currentBDSData.floorSquare = parseFloat(text)
                        if(previousText !== text){

                            previousText = text
                        }
                        settingQML.pointRunning_FloorSquare = settingQML.point_FloorSquare
                        appManager.calculateCurrentPriceList()
                    }
                }

                Materials_TextBox{
                    id:txtFloors
                    placeholderText: qsTr("Số tầng")
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlNha.isDropDowned
                    inputMethodHints: "ImhDigitsOnly"
                    dataPoint: settingQML.point_Floors
                    text: !isUpdateSequence ? "" : (currentBDSData.floors === const_DEFAULT_INT_VALUE ? "" : currentBDSData.floors)
                    onActiveFocusChanged: {
                        if (!activeFocus){
                            finishEditing()
                        }
                    }
                    Keys.onEnterPressed: {
                        finishEditing()
                        txtConstructionHeight.forceActiveFocus()
                    }

                    function finishEditing() {
                        currentBDSData.floors = text
                        if(previousText !== text){

                            previousText = text
                        }
                        settingQML.pointRunning_Floors = settingQML.point_Floors
                        appManager.calculateCurrentPriceList()
                    }
                }
                Materials_TextBox{
                    id:txtConstructionHeight
                    placeholderText: qsTr("Chiều cao công trình (m)")
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlNha.isDropDowned
                    inputMethodHints: "ImhDigitsOnly"
                    dataPoint: settingQML.point_ConstructionHeight
                    text: !isUpdateSequence ? "" : (currentBDSData.constructionHeight === const_DEFAULT_INT_VALUE ? "" : currentBDSData.constructionHeight)
                    onActiveFocusChanged: {
                        if (!activeFocus){
                            finishEditing()
                        }
                    }
                    Keys.onEnterPressed: {
                        finishEditing()
                        txtSoPhongNgu.forceActiveFocus()

                    }

                    function finishEditing() {
                        currentBDSData.constructionHeight = parseFloat(text)
                        settingQML.pointRunning_ConstructionHeight = settingQML.point_ConstructionHeight
                    }
                }
                Materials_TextBox{
                    id:txtSoPhongNgu
                    placeholderText: qsTr("Số phòng ngủ")
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlNha.isDropDowned
                    inputMethodHints: "ImhDigitsOnly"
                    dataPoint: settingQML.point_SoPhongNgu
                    text: !isUpdateSequence ? "" : (currentBDSData.bedRooms === const_DEFAULT_INT_VALUE ? "" : currentBDSData.bedRooms)
                    onActiveFocusChanged: {
                        if (!activeFocus){
                            finishEditing()
                        }
                    }
                    Keys.onEnterPressed: {
                        finishEditing()
                        txtSoPhongWC.forceActiveFocus()
                    }

                    function finishEditing() {
                        currentBDSData.bedRooms = parseInt(text)
                        settingQML.pointRunning_SoPhongNgu = settingQML.point_SoPhongNgu
                    }
                }

                Materials_TextBox{
                    id:txtSoPhongWC
                    placeholderText: qsTr("Số WC")
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlNha.isDropDowned
                    inputMethodHints: "ImhDigitsOnly"
                    dataPoint: settingQML.point_SoWC
                    text: !isUpdateSequence ? "" : (currentBDSData.toilets === const_DEFAULT_INT_VALUE ? "" : currentBDSData.toilets)
                    onActiveFocusChanged: {
                        if (!activeFocus){
                            finishEditing()
                        }
                    }
                    Keys.onEnterPressed: {
                        finishEditing()
                        cbbHoanThien.forceActiveFocus()
                    }

                    function finishEditing() {
                        currentBDSData.toilets = parseInt(text)
                        settingQML.pointRunning_SoWC = settingQML.point_SoWC
                    }
                }

                Materials_Combobox{
                    id:cbbHoanThien
                    dataPoint: settingQML.point_CompleteTypes
                    headerText: qsTr("Hoàn Thiện")
                    currentTextValue: !isUpdateSequence ? "" : currentBDSData.completeTypes
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlNha.isDropDowned
                    model:appManager.completeTypesList
                    onCurrentValueChanged: {
                        appManager.selectCompleteTypes(currentTextValue)
                        settingQML.pointRunning_CompleteTypes = settingQML.point_CompleteTypes
                        appManager.calculateCurrentPriceList()
                    }
                }
                CustomComboboxWithCheckbox{
                    ListModel{
                        id:lmTienich
                        ListElement{
                            displayText:"Sân thượng"
                            displayActive:false
                        }
                        ListElement{
                            displayText:"Sân Vườn"
                            displayActive:false
                        }
                        ListElement{
                            displayText:"Nhà xe"
                            displayActive:false
                        }
                    }
                    currentText: "Tiện ích xung quanh"
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlNha.isDropDowned
                    model:lmTienich
                    onItemCheckedChanged: {
                        if(itemChecked){
                            settingQML.pointRunning_TienIchTrongNha = settingQML.point_TienIchTrongNha
                        }
                        appManager.selectConvenientStuff(itemText, itemChecked)
                    }
                }

            }
            CustomDropdownList{
                id:cdlPhapLy
                currentTextValue: qsTr("Pháp lý")
                width: parent.width - 20 * dpiToPixelValue
                x: 10 * dpiToPixelValue
                Materials_Combobox{
                    dataPoint: settingQML.point_LoaiGiayTo
                    //                    headerEnabled: true
                    headerText: qsTr("Loại giấy tờ")
                    id:cbbLoaiGiayTo
                    currentTextValue: !isUpdateSequence ? "" : currentBDSData.landJuridical
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    visible: cdlPhapLy.isDropDowned
                    model:appManager.juridicalsList
                    onCurrentValueChanged: {
                        appManager.selectLandJuridical(currentTextValue)
                        settingQML.pointRunning_LoaiGiayTo = settingQML.point_LoaiGiayTo
                    }
                }
                //                Materials_Combobox{
                //                    dataPoint: 10
                //                    headerEnabled: true
                //                    headerText: qsTr("Tình trạng")
                //                    id:cbbTinhTrang
                //                    currentTextValue: qsTr("Tình trạng")
                //                    width: parent.width - 20 * dpiToPixelValue
                //                    x: 10 * dpiToPixelValue
                //                    model:appManager.landStatusesList
                //                    visible: cdlPhapLy.isDropDowned
                //                    onCurrentValueChanged: {
                //                        currentBDSData.tinhtrangthechap = currentTextValue
                //                    }
                //                }
            }
            CustomDropdownList{
                id:cdlTinhTrang
                currentTextValue: qsTr("Tình Trạng hiện tại")
                width: parent.width - 20 * dpiToPixelValue
                x: 10 * dpiToPixelValue
                Materials_Combobox{
                    dataPoint: settingQML.point_UsingStatus
                    //                    headerEnabled: true
                    headerText: qsTr("Tình trạng sử dụng")
                    currentTextValue: !isUpdateSequence ? "" : currentBDSData.usingStatus
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    model:appManager.landUsingStatuses
                    visible: cdlTinhTrang.isDropDowned
                    onCurrentValueChanged: {
                        appManager.selectUsingStatus(currentTextValue)
                        settingQML.pointRunning_UsingStatus = settingQML.point_UsingStatus
                    }
                }
                Materials_Combobox{
                    dataPoint: settingQML.point_TinhTrangChatLuong
                    //                    headerEnabled: true
                    headerText: qsTr("Tình trạng chất lượng")
                    currentTextValue: !isUpdateSequence ? "" : currentBDSData.houseQuality
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    model:appManager.houseQualitiesList
                    visible: cdlTinhTrang.isDropDowned
                    onCurrentValueChanged: {
                        appManager.selectHouseQuality(currentTextValue)
                        settingQML.pointRunning_TinhTrangChatLuong = settingQML.point_TinhTrangChatLuong
                    }
                }
            }
        }
    }
}

