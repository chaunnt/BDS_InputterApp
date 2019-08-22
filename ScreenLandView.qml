import QtQuick 2.0

Rectangle{
    Flickable {
        width: parent.width
        height: parent.height
        contentHeight: colContent.implicitHeight + txtHeader.height + 20 * dpiToPixelValue
        clip: true
        flickableDirection: Flickable.VerticalFlick
        Text {
            text: qsTr("Hình ảnh thực tế")
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
            Repeater{
                model:appManager.imageTypesList
                delegate: CustomHorizontaImagelList{
                    id:recMatTien
                    width: parent.width - 20 * dpiToPixelValue
                    x: 10 * dpiToPixelValue
                    model: currentBDSData.houseImageList
                    listName: modelData.dataDisplayName
                    imageType: settingQML.imageType_mattien
                    visible: index == 2
                    onImageDeleted: {

                    }
                    onCaptureStarted: {
                        console.log("modelData.dataName: " + modelData.dataName)
                        scrCamera.imageType = modelData.dataName
                        scrCamera.visible = true
                    }
                }
            }

            Rectangle{
                width: parent.width - 20 * dpiToPixelValue
                x: 10 * dpiToPixelValue
                height: txtGoogleMapCoor.height
                Materials_TextBox{
                    id:txtGoogleMapCoor
                    width: parent.width
                    placeholderText: qsTr("Bản đồ")
//                    enabled: false
                    dataPoint: settingQML.point_ChieuRongDuong
                    text: !isUpdateSequence ? "" : currentBDSData.landLongitude

                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        scrMap.currentPosition = currentBDSData.landLongitude
                        scrMap.visible = true
                    }
                }
                Connections{
                    target: scrMap
                    onVisibleChanged:{
                        txtGoogleMapCoor.text = currentBDSData.landLongitude
                    }
                }
            }
        }
    }
}
