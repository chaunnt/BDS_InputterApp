import QtQuick 2.0
import QtMultimedia 5.8

Rectangle {
    width: parent.width
    height: parent.height
    color: "black"
    property string imageFile: ""
    property string imageType: ""
    onVisibleChanged: {
        if(imageType === settingQML.imageType_nha){
            lvImageList.model = currentBDSData.houseImageList
        }else if(imageType === settingQML.imageType_giaytonha){
            lvImageList.model = currentBDSData.legacyImageList
        }else if(imageType === settingQML.imageType_quyhoachlogioi){
            lvImageList.model = currentBDSData.landPlanningImageList
        }
    }

    Camera {
        id: camera

        imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceFlash

        exposure {
            exposureCompensation: -1.0
            exposureMode: Camera.ExposurePortrait
        }
        captureMode: Camera.CaptureStillImage
        flash.mode: Camera.FlashRedEyeReduction
        focus {
            focusMode: CameraFocus.FocusContinuous
            focusPointMode: CameraFocus.FocusPointAuto
        }
        imageCapture {
            onImageCaptured: {
                appManager.addPreviewImage(imageType, requestId, preview)
                if(imageType === settingQML.imageType_nha){
                    lvImageList.model = currentBDSData.houseImageList
                }else if(imageType === settingQML.imageType_giaytonha){
                    lvImageList.model = currentBDSData.legacyImageList
                }else if(imageType === settingQML.imageType_quyhoachlogioi){
                    lvImageList.model = currentBDSData.landPlanningImageList
                }
            }
            onImageSaved: {
                appManager.captureImage(imageType, requestId, path)
            }
        }
    }

    VideoOutput {
        source: camera
        anchors.fill: parent
        focus : visible // to receive focus and capture key events when visible
        autoOrientation: true
        fillMode: VideoOutput.Stretch
        MouseArea {
            anchors.fill: parent
            onClicked: {
                camera.focus.customFocusPoint = Qt.point(mouse.x / width,  mouse.y / height);
                camera.focus.focusMode = CameraFocus.FocusMacro;
                camera.focus.focusPointMode = CameraFocus.FocusPointCustom;
            }
        }
    }
    ListView{
        id:lvImageList
        orientation: ListView.Horizontal
        width: parent.width - 10 * dpiToPixelValue
        x: 5 * dpiToPixelValue
        height: baseButtonHeight * 2
        clip: true
        spacing: 5 * dpiToPixelValue
        anchors.bottom: btnCaptureImage.top
        anchors.bottomMargin: 10 * dpiToPixelValue
        delegate: Rectangle{
            height: parent.height
            width: height
            radius: 5 * dpiToPixelValue
            color: "black"
            Image {
                source: modelData
                anchors.fill: parent
                fillMode: Image.Stretch
            }
        }
    }
    Rectangle{
        id:btnCaptureImage
        height: baseButtonHeight
        width: height
        x: parent.width / 2 - width / 2
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20 * dpiToPixelValue
        color: "red"
        radius: height / 2
        MouseArea{
            anchors.fill: parent
            onClicked: {
                camera.imageCapture.capture();
            }
        }
    }
    Rectangle{
        id:btnBack
        height: baseButtonHeight
        width: height
        anchors.top: parent.top
        anchors.topMargin: 5 * dpiToPixelValue
        anchors.left: parent.left
        anchors.leftMargin: 5 * dpiToPixelValue
        color: "transparent"
        Image {
            id:imgBack
            height: parent.height / 2
            y: parent.height / 2 - height / 2
            source: "qrc:/resource/back.png"
            fillMode: Image.PreserveAspectFit
        }
        Text {
            id:txtBack
            text: qsTr("Quay lại")
            font.pixelSize: normalFontSize
            height: parent.height
            verticalAlignment: Image.AlignVCenter
            anchors.left: imgBack.right
            anchors.leftMargin: 5 * dpiToPixelValue
            color: baseTextColor
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                scrCamera.visible = false
            }
        }
    }

    Keys.onPressed: {
        if (event.key === Qt.Key_Back) {
            scrCamera.visible = false
        }
    }
}
