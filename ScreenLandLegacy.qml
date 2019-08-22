import QtQuick 2.0

Rectangle {
    Flickable {
        clip: true
        width: parent.width
        height: parent.height
        contentHeight: colImagePhapLy.implicitHeight + txtHeader.height + 20 * dpiToPixelValue
        flickableDirection : Flickable.VerticalFlick
        boundsBehavior: Flickable.StopAtBounds
        Text {
            text: qsTr("Pháp lý")
            font.pixelSize: extraFontSize
            color:baseTextColor
            width: parent.width
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            id:txtHeader
        }
        Column{
            id:colImagePhapLy
            height: parent.height - txtHeader.height
            width: parent.width
            y: txtHeader.height
            spacing: 20 * dpiToPixelValue
            Materials_Combobox{
                dataPoint: 10
//                headerEnabled: true
                headerText: qsTr("Loại giấy tờ")
                id:cbbLoaiGiayTo
                currentTextValue: qsTr("Loại giấy tờ")
                width: parent.width - 20 * dpiToPixelValue
                x: 10 * dpiToPixelValue
                model:appManager.juridicalsList
                onCurrentValueChanged: {
                    currentBDSData.phaply = currentTextValue
                }
            }
            Materials_Combobox{
                dataPoint: 10
//                headerEnabled: true
                headerText: qsTr("Tình trạng")
                id:cbbTinhTrang
                currentTextValue: qsTr("Tình trạng")
                width: parent.width - 20 * dpiToPixelValue
                x: 10 * dpiToPixelValue
                model:["Bình thường","Đang thế chấp"]
                onCurrentValueChanged: {
                    currentBDSData.tinhtrangthechap = currentTextValue
                }
            }
        }
    }
}
