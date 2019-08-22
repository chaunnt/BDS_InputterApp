import QtQuick 2.0
import QtWebView 1.1
import QtQml 2.2

Item {
    id:itemLandLegacySearch
    property var locale: Qt.locale()
    property string timeString
    onVisibleChanged: {
        if(visible){
            wvLegacy.url = "https://thongtinquyhoach.hochiminhcity.gov.vn/"
        }
    }

    Text {
        text: qsTr("Đang tải dữ liệu bản đồ...")
        font.pixelSize: normalFontSize
        anchors.centerIn: parent
    }
    WebView{
        id:wvLegacy
        width: parent.width
        height: parent.height - recFooterMap.height - 10 * dpiToPixelValue
        url: "https://thongtinquyhoach.hochiminhcity.gov.vn/"
        onUrlChanged: {
            console.log(wvLegacy.childrenRect)
            if(url !== "https://thongtinquyhoach.hochiminhcity.gov.vn/"){
                url = "https://thongtinquyhoach.hochiminhcity.gov.vn/"
            }
        }
    }

    Rectangle{
        id:recFooterMap
        width: parent.width
        height: baseButtonHeight
        color: baseColor
        anchors.bottom: parent.bottom
        Rectangle{
            width: height
            height: baseButtonHeight + 10 * dpiToPixelValue
            radius: height / 2
            x: parent.width / 4 - width / 2
            y: - 10 * dpiToPixelValue
            CustomButton{
                id:btnCaptureMap
                width: height
                anchors.centerIn: parent
                buttonText: qsTr("Lưu")
                buttonColor: baseColor
                onClicked: {
                    var currentTime = new Date()
                    var timeString = currentTime.toLocaleString(locale, "yyyyMMddhhmmss");
                    var nameDateString = appManager.getImageStorageLocation() + "thongtinquyhoach" + timeString + ".jpg"
                    if (Qt.platform.os === "android") {
                        var captureshot = appManager.captureScreenShot(appManager.getImageStorageLocation() + "thongtinquyhoach" + timeString + ".jpg")
                        if(captureshot !== ""){
                            appManager.captureImage(settingQML.imageType_quyhoachlogioi, "image://imageprovider/" + "thongtinquyhoach" + timeString + ".jpg", true)
                        }
                    }else{
                        wvLegacy.grabToImage(function(result) {
                            var resultSave = result.saveToFile(nameDateString);
                            console.log("nameDateString: " + nameDateString)
                            if(resultSave === true){
                                recSaveMessage.message = qsTr("Đã lưu thành công")
                                recSaveMessage.show()
                                appManager.addPreviewImage(settingQML.imageType_quyhoachlogioi, timeString, "file:/" + nameDateString)
                                appManager.captureImage(settingQML.imageType_quyhoachlogioi, timeString, nameDateString, true)
                            }else{
                                recSaveMessage.message = qsTr("Lưu thông tin thất bại")
                                recSaveMessage.show()
                            }
                        })
                    }
                }
            }
        }
        Rectangle{
            width: height
            height: baseButtonHeight + 10 * dpiToPixelValue
            radius: height / 2
            x: parent.width * 3 / 4 - width / 2
            y: - 10 * dpiToPixelValue
            CustomButton{
                id:btnDone
                width: height
                anchors.centerIn: parent
                buttonText: qsTr("Xong")
                buttonColor: baseColor
                onClicked: {
                    itemLandLegacySearch.visible = false
                }
            }
        }
    }

    Rectangle{
        id:recSaveMessage
        color: "#404040"
        property string message: qsTr("Đã lưu thành công")
        width: txtSaveMessage.width + 20 * dpiToPixelValue
        height: baseButtonHeight
        radius: height / 2
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5 * dpiToPixelValue
        x: parent.width / 2 - width / 2
        visible: false
        Text {
            id: txtSaveMessage
            text: recSaveMessage.message
            font.pixelSize: normalFontSize
            color: "white"
            height: baseButtonHeight
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.centerIn: parent
        }
        PropertyAnimation{
            id:aniSaveMessage
            target: recSaveMessage
            property: "opacity"
            to: 0
            duration: 500
            onStopped: {
                recSaveMessage.visible = false
                recSaveMessage.opacity = 1
            }
        }

        Timer{
            id:tmShow
            repeat: false
            running: false
            interval: 1000
            onTriggered: {
                aniSaveMessage.start()
            }
        }

        function show(){
            recSaveMessage.visible = true
            tmShow.start()
        }
    }

}
