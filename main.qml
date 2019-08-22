import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    id:mainWindow
    visible: true
    width: 360
    height: 567
    property int baseButtonHeight: 40 * dpiToPixelValue
    property int normalFontSize: 15 * dpiToPixelValue
    property int bigFontSize: 20 * dpiToPixelValue
    property int extraFontSize: 24 * dpiToPixelValue
    property int smallFontSize: 12 * dpiToPixelValue
    property color baseColor: "#E5CA05"
    property color baseSelectingColor: "#0B132D"
    property color baseTextColor: "#0B132D"
    property bool isLoggedIn: false
    onIsLoggedInChanged: {
        drawer.close()
        drawer.activeIndex = 0
    }

    property int mainswipeIndex: 0
    property bool isStartSequence: false
    property int currentHeaderItem: 1
    property bool isUpdateSequence: false

    readonly property string const_DEFAULT_TEXT : appManager.get_const_DEFAULT_TEXT()
    readonly property int const_DEFAULT_SELECTED_ID : appManager.get_const_DEFAULT_SELECTED_ID()
    readonly property int const_DEFAULT_INT_VALUE : appManager.get_const_DEFAULT_INT_VALUE()
    property QtObject currentBDSData: appManager.currentBDSData
    Setting {
        id: settingQML
        point_TinhThanh : appManager.getpoint_TinhThanh()
        point_QuanHuyen : appManager.getpoint_QuanHuyen()
        point_PhuongXa : appManager.getpoint_PhuongXa()
        point_LoaiBDS : appManager.getpoint_LoaiBDS()
        point_DiaChiNha : appManager.getpoint_DiaChiNha()
        point_TenDuong : appManager.getpoint_TenDuong()
        point_ViTri : appManager.getpoint_ViTri()
        point_ChieuRongDuong : appManager.getpoint_ChieuRongDuong()
        point_DuAn : appManager.getpoint_DuAn()
        point_ChieuNgang : appManager.getpoint_ChieuNgang()
        point_ChieuDai : appManager.getpoint_ChieuDai()
        point_DienTichCongNhan : appManager.getpoint_DienTichCongNhan()
        point_DienTichThucTe : appManager.getpoint_DienTichThucTe()
        point_DienTichLoGioi : appManager.getpoint_DienTichLoGioi()
        point_HinhDang : appManager.getpoint_HinhDang()
        point_QuyHoachLoaiDat : appManager.getpoint_QuyHoachLoaiDat()
        point_DienTichDatNongNghiep : appManager.getpoint_DienTichDatNongNghiep()
        point_Huong : appManager.getpoint_Huong()
        point_ConstructionSquare : appManager.getpoint_ConstructionSquare()
        point_FloorSquare : appManager.getpoint_FloorSquare()
        point_Floors: appManager.getpoint_Floors()
        point_ConstructionHeight : appManager.getpoint_ConstructionHeight()
        point_VatLieuHoanThien : appManager.getpoint_VatLieuHoanThien()
        point_TienIchNha : appManager.getpoint_TienIchNha()
        point_UsingStatus : appManager.getpoint_UsingStatus()
        point_TinhTrangChatLuong : appManager.getpoint_TinhTrangChatLuong()
        point_GiaBan : appManager.getpoint_GiaBan()
        point_DonViGia : appManager.getpoint_DonViGia()
        point_DiscussedPrice : appManager.getpoint_DiscussedPrice()
        point_LoaiGiayTo : appManager.getpoint_LoaiGiayTo()
        point_TinhTrangPhapLy : appManager.getpoint_TinhTrangPhapLy()
        point_CompleteTypes: appManager.getpoint_CompleteTypes()
        point_OwnerName : appManager.getpoint_OwnerName()
        point_OwnerAge : appManager.getpoint_OwnerAge()
        point_OwnerGender : appManager.getpoint_OwnerGender()
        point_OwnerPhone : appManager.getpoint_OwnerPhone()
        point_OwnerAddress : appManager.getpoint_OwnerAddress()
        point_ImageMatTien : appManager.getpoint_ImageMatTien()
        point_ImageLeft : appManager.getpoint_ImageLeft()
        point_ImageRight : appManager.getpoint_ImageRight()
        point_ImageOpposite : appManager.getpoint_ImageOpposite()
        point_ImagePhongKhach : appManager.getpoint_ImagePhongKhach()
        point_ImagePhongBep : appManager.getpoint_ImagePhongBep()
        point_ImagePhongNgu : appManager.getpoint_ImagePhongNgu()
        point_ImagePhongTam : appManager.getpoint_ImagePhongTam()
        point_ImageSanThuong : appManager.getpoint_ImageSanThuong()
        point_ImageNhaXe : appManager.getpoint_ImageNhaXe()
        point_TienIchTrongNha : appManager.getpoint_TienIchTrongNha()
        point_VideoNha : appManager.getpoint_VideoNha()
        point_Image360Degree : appManager.getpoint_Image360Degree()
        point_Position : appManager.getpoint_Position()
        point_ImageGiayToNha : appManager.getpoint_ImageGiayToNha()
        point_ImageQuyHoachLoGioi : appManager.getpoint_ImageQuyHoachLoGioi()
        point_ImageQuyHoachSuDungDat : appManager.getpoint_ImageQuyHoachSuDungDat()
        point_ContactType : appManager.getpoint_ContactType()
        point_ContactName : appManager.getpoint_ContactName()
        point_ContactAge : appManager.getpoint_ContactAge()
        point_ContactGender : appManager.getpoint_ContactGender()
        point_ContactPhone : appManager.getpoint_ContactPhone()
        point_ContactAddress : appManager.getpoint_ContactAddress()
        point_ContactCompany : appManager.getpoint_ContactCompany()

        imageType_nha: appManager.getImageType_nha()
        imageType_mattien : appManager.getImageType_mattien()
        imageType_viewtraiphai : appManager.getImageType_viewtraiphai()
        imageType_phongkhach : appManager.getImageType_phongkhach()
        imageType_phongbep : appManager.getImageType_phongbep()
        imageType_phongngu : appManager.getImageType_phongngu()
        imageType_phongtam : appManager.getImageType_phongtam()
        imageType_santhuong : appManager.getImageType_santhuong()
        imageType_nhaxe : appManager.getImageType_nhaxe()
        imageType_giaytonha : appManager.getImageType_giaytonha()
        imageType_quyhoachlogioi : appManager.getImageType_quyhoachlogioi()
        imageType_quyhoachsudungdat : appManager.getImageType_quyhoachsudungdat()
    }
    ListModel{
        id:lmFunction
        ListElement{
            fucIcon:"qrc:/resource/Home_White.png"
            fucText:"Trang chủ"
            fucActive:0
        }
        ListElement{
            fucIcon:"qrc:/resource/Round_Plus_Dark_Blue.png"
            fucText:"Nhập BĐS"
            fucActive:1
        }
        ListElement{
            fucIcon:"qrc:/resource/List_White.png"
            fucText:"Danh sách BĐS"
            fucActive:2
        }
        ListElement{
            fucIcon:"qrc:/resource/History_DarkBlue.png"
            fucText:"Lịch sử"
            fucActive:3
        }
        ListElement{
            fucIcon:"qrc:/resource/QuestionMark_White.png"
            fucText:"Thông tin ứng dụng"
            fucActive:4
        }
        ListElement{
            fucIcon:"qrc:/resource/LogOut_DarkBlue.png"
            fucText:qsTr("Đăng xuất")
            fucActive:5
        }
    }

    Drawer {
        id: drawer
        width: 0.5 * mainWindow.width
        height: mainWindow.height
        property int activeIndex: 0
        ListView{
            id:lvFucList
            anchors.fill: parent
            model: lmFunction

            delegate: Rectangle{
                width: parent.width
                height: baseButtonHeight
                color: drawer.activeIndex === index ? baseColor : "white"
                Image {
                    id:imgFucIcon
                    source: fucIcon
                    height: parent.height / 2
                    fillMode: Image.PreserveAspectFit
                    x: 5 * dpiToPixelValue
                    y: parent.height / 2 - height / 2
                }
                Text {
                    id: txtLogout
                    text: fucText
                    font.pixelSize: normalFontSize
                    anchors.left: imgFucIcon.right
                    anchors.leftMargin: 5 * dpiToPixelValue
                    width: parent.width - imgFucIcon.width - 10 * dpiToPixelValue
                    clip: true
                    y: parent.height / 2 - height / 2
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        var currIdx = drawer.activeIndex
                        if(currIdx !== index){
                            drawer.activeIndex = index
                            currIdx = drawer.activeIndex
                            if(isStartSequence){
                                isStartSequence = false
                            }
                            if(currIdx === 0){
                                mainStackView.replace("qrc:/ScreenHome.qml")
                            }else if(currIdx === 1){
                                appManager.startInputSequence()
                                isStartSequence = true
                                mainswipeIndex = 0
                                settingQML.initPoint()
                                mainStackView.push("qrc:/ScreenLandInputSequence.qml")
                            }else if(currIdx === 2){
                                isStartSequence = false
                                mainStackView.replace("qrc:/ScreenLandList.qml")
                            }else if(currIdx === 3){
                                mainStackView.replace("qrc:/ScreenHistory.qml")
                            }else if(currIdx === 4){
                                mainStackView.replace("qrc:/ScreenAppInfo.qml")
                            }else if(currIdx === 5){
                                mainStackView.replace("qrc:/ScreenLogin.qml")
                                appManager.logout()
                                isLoggedIn = false
                            }else{
                                mainStackView.replace("qrc:/ScreenHome.qml")
                            }
                        }
                        drawer.close()
                    }
                }
                Rectangle{
                    width: parent.width
                    height: 1
                    color: "lightgray"
                    anchors.bottom: parent.bottom
                    visible: drawer.activeIndex === index ? baseColor : "white"
                }
            }
        }
    }

    Rectangle{
        id:recHeader
        height: baseButtonHeight
        width: parent.width
        anchors.top: parent.top
        visible: isLoggedIn
        color: baseColor
        Row{
            width: parent.width
            height: parent.height
            Rectangle{
                id:recDrawerButton
                width: parent.height
                height: parent.height
                color: "transparent"
                Image {
                    source: "qrc:/resource/Drawer_White.png"
                    height: parent.height / 2
                    fillMode: Image.PreserveAspectFit
                    anchors.centerIn: parent
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        drawer.open()
                    }
                }
            }
        }
    }
    Rectangle{
        id:recFooter
        height: baseButtonHeight
        width: parent.width
        anchors.bottom: parent.bottom
        visible: isLoggedIn && isStartSequence
        color: baseColor
        Rectangle{
            id:recBack
            height: parent.height
            visible: mainswipeIndex > 0
            width: imgQuayLai.width + 10 * dpiToPixelValue + txtQuayLai.width
            color: "transparent"
            Image {
                id: imgQuayLai
                source: "qrc:/resource/RightArrow_Gray.png"
                rotation: 180
                height: parent.height / 2
                width: height
                y: parent.height / 2 - height / 2
                x: 5 * dpiToPixelValue
            }
            Text{
                id:txtQuayLai
                text: "Quay lại"
                height: parent.height
                font.pixelSize: normalFontSize
                color:baseTextColor
                verticalAlignment: Text.AlignVCenter
                anchors.left: imgQuayLai.right
                anchors.leftMargin: 5 * dpiToPixelValue
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    mainswipeIndex--
                }
            }
        }
        Rectangle{
            id:recNext
            height: parent.height
            anchors.right: parent.right
            width: imgTiepTuc.width + 10 * dpiToPixelValue + txtTiepTuc.width
            color: "transparent"
            Image {
                id: imgTiepTuc
                source: "qrc:/resource/RightArrow_Gray.png"
                height: parent.height / 2
                width: height
                y: parent.height / 2 - height / 2
                x: 5 * dpiToPixelValue
                anchors.right: parent.right
                anchors.rightMargin: 5 * dpiToPixelValue
            }
            Text{
                id:txtTiepTuc
                text:mainswipeIndex === 5 ? "Hoàn tất" : "Tiếp tục"
                height: parent.height
                font.pixelSize: normalFontSize
                color:baseTextColor
                verticalAlignment: Text.AlignVCenter
                anchors.right: imgTiepTuc.left
                anchors.rightMargin: 5 * dpiToPixelValue
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    console.log("mainswipeIndex: " + mainswipeIndex)
                    if(mainswipeIndex < 5)
                        mainswipeIndex++
                    else{
                        waitingDialog.show("Submit to server")
                        settingQML.calculateRunningPoint()
                        if(settingQML.totalRunningPoint !== 0){
                            currentBDSData.bdsPoint = settingQML.totalRunningPoint
                        }
                        console.log(isUpdateSequence)
                        if(isUpdateSequence){
                            if(appManager.updateBDSData() === true){
                                isStartSequence = false
                                mainStackView.replace("qrc:/ScreenLandSubmit.qml")
                            }
                        }else{
                            if(appManager.submitData() === true){
                                isStartSequence = false
                                mainStackView.replace("qrc:/ScreenLandSubmit.qml")
                            }
                        }
                        waitingDialog.close()
                    }
                }
            }
        }
    }
    Rectangle{
        id:recSplash
        anchors.fill: parent
        color: "white"
        Component.onCompleted: {
            firstFading.start()
        }

        Image {
            id:imgFirstIcon
            source: "qrc:/resource/logo_hobe.png"
            fillMode: Image.PreserveAspectFit
            anchors.centerIn: parent
            width: parent.width * 8 / 10
        }
        PropertyAnimation{
            id: firstFading
            target: imgFirstIcon
            property: "opacity";
            to: 0;
            duration: 2500
            onStopped: {
                imgSecondIcon.visible = true
                imgFirstIcon.visible = false
                secondFading.start()
            }
        }
        Image {
            id:imgSecondIcon
            source: "qrc:/resource/logo_nhadat.png"
            fillMode: Image.PreserveAspectFit
            anchors.centerIn: parent
            width: parent.width * 8 / 10
            visible: false
        }
        PropertyAnimation{
            id: secondFading
            target: imgFirstIcon
            property: "opacity";
            to: 0;
            duration: 2000
        }
    }
    StackView {
        id: mainStackView
        width: parent.width
        height: isLoggedIn ? parent.height - recHeader.height  - (isStartSequence ? recFooter.height : 0): parent.height
        y: isLoggedIn ? recHeader.height : 0
        visible: false

    }
    ScreenCamera{
        id:scrCamera
        anchors.fill: parent
        width: parent.width
        height: parent.height
        visible: false
    }
    ScreenMap{
        id:scrMap
        anchors.fill: parent
        visible: false
    }
    ScreenLegacySearch{
        id:scrLegacySearch
        anchors.fill: parent
        visible: false
    }
    Timer{
        id: tmSplashTimer
        interval: 5000
        running: false
        repeat: false
        onTriggered: {
            waitingDialog.show("Khởi động ứng dụng")
            if(appManager.autoLogin() === true){
                if(appManager.startupApplication() === true){
                    mainStackView.visible = true
                    mainStackView.push("qrc:/ScreenHome.qml")
                    isLoggedIn = true
                }
            }else{
                mainStackView.visible = true
                mainStackView.push("qrc:/ScreenLogin.qml")
            }
            recSplash.visible = false
            waitingDialog.close()
        }
    }

    Component.onCompleted: {
        tmSplashTimer.start()
    }
    Rectangle{
        id: bgMessageDialog
        anchors.fill: parent
        visible: waitingDialog.visible || messageDialog.visible
        color: "black"
        opacity: 0.5
        MouseArea{
            enabled: parent.visible
            anchors.fill: parent
            onClicked: {
                console.log("Screen Locked")
            }
        }
    }
    Connections{
        target: appManager
        onServerError:{
            messageDialog.show(errorMessage)
        }
    }

    Rectangle{
        id:waitingDialog
        function show(string){
            txtWaitingMessage.text=string
            visible = true
        }

        function close(){
            waitingDialog.visible = false
        }
        anchors.centerIn: parent
        radius: 2
        width: Math.max(txtWaitingMessage.width + 20 * dpiToPixelValue, 100 * dpiToPixelValue)
        color: "white"
        visible: false

        Text {
            id: txtWaitingMessage
            padding: 6
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            x:parent.width / 2 - width / 2
            anchors.top :imgWaitingIndicator.bottom
            font.pixelSize: normalFontSize
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        }
        Image {
            id: imgWaitingIndicator
            source: "qrc:/resource/spinner.png"
            width: 40 * dpiToPixelValue
            height: width
            fillMode: Image.PreserveAspectFit
            x:parent.width / 2 - width / 2
            anchors.centerIn: parent
        }
        RotationAnimator {
            target: imgWaitingIndicator;
            from: 0;
            to: 360;
            duration: 1000
            running: waitingDialog.visible
            direction: RotationAnimator.Clockwise
            loops: Animation.Infinite
        }
        height: txtWaitingMessage.height + rectLoginMessageRow.height + 20 * dpiToPixelValue + imgWaitingIndicator.height
    }

    Rectangle{
        id: messageDialog
        signal closed

        function show(string){
            txtLoginMessageContent.text=string
            visible = true
        }

        function close(){
            messageDialog.visible = false
            closed()
        }
        anchors.centerIn: parent
        radius: 10 * dpiToPixelValue
        width: parent.width - 20 * dpiToPixelValue
        color: "white"
        visible: false
        Text {
            id: txtLoginMessageContent
            padding: 6
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            x:parent.width / 2 - width / 2
            anchors.top :parent.top
            font.pixelSize: normalFontSize
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            width: parent.width
        }
        Rectangle{
            id:rectLoginMessageRow
            anchors.top:txtLoginMessageContent.bottom
            anchors.topMargin: 5
            color: "lightgray"
            width: parent.width
            height: 1
        }
        Button{
            id:btnOK
            text:"OK"
            font.pixelSize: normalFontSize
            width: parent.width / 2
            height: baseButtonHeight
            padding: 0
            x: parent.width / 2 - width / 2
            anchors.top:rectLoginMessageRow.bottom
            background: Rectangle{
                anchors.fill: parent
                color: "transparent"
            }
            onClicked: {
                messageDialog.close()
            }
        }
        height: txtLoginMessageContent.height + btnOK.height + rectLoginMessageRow.height
    }

}
