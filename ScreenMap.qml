import QtQuick 2.0
import QtQuick.Window 2.0
import QtLocation 5.6
import QtPositioning 5.8
import QtWebView 1.1
import QtQml 2.2

Rectangle {
    id: maprec
    property string currentPosition: ""
    property string newPosition: ""
    Text {
        id:txtLoadDuLieu
        text: qsTr("Đang tải dữ liệu bản đồ...")
        font.pixelSize: normalFontSize
        anchors.centerIn: parent
    }
    WebView{
        id:wvMap
        width: parent.width
        height: parent.height - recFooterMap.height - 10 * dpiToPixelValue
        visible: maprec.visible
        onVisibleChanged: {
            if(visible){
                if(currentPosition !== "" && currentPosition.indexOf("https://www.google.com/maps/@") > -1){
                    url = currentPosition
                }else{
                    url = "https://www.google.com/maps/@10.7644208,106.6900086,15z"
                }
            }
        }

        onUrlChanged: {
            console.log(url)
            newPosition = url;
            if(currentPosition !== "" && newPosition.indexOf("https://www.google.com/maps/@") < 0){
                url = "https://www.google.com/maps/@10.7644208,106.6900086,15z"
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
                    appManager.selectBDSLocation(wvMap.url, wvMap.url)
                    recSaveMessage.show()
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
                    maprec.visible = false
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
