import QtQuick 2.9
import QtQuick.Controls 2.2


Rectangle{
    id: cbbMain
    property var model
    property string currentTextValue: ""
    property int currentValue: -1
    // Option
    property int cbbPopupItemHeight: baseButtonHeight
    property int fontSizeCbb: normalFontSize
    property int dataPoint: 0
    property bool headerEnabled: currentValue === -1 && (currentTextValue === headerText || currentTextValue === "")
    property string headerText: ""
    onActiveFocusChanged: {
        if(activeFocus){
            recDisplay.border.color = baseColor
        }else{
            recDisplay.border.color = baseSelectingColor
        }
    }
    onCurrentTextValueChanged: {

    }

    height: baseButtonHeight
    Rectangle {
        id: recDisplay
        width: parent.width
        height: parent.height
        radius: 5 * dpiToPixelValue
        y: parent.height / 2 - height / 2
        border.color: baseSelectingColor
        border.width: 1
        Text{
            id: txtDisplay
            text: headerEnabled ? headerText : currentTextValue
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            height: parent.height
            width: parent.width - parent.height / 2
            x:(parent.width - parent.height / 2) / 2 - width / 2
            color: baseSelectingColor
            font.pixelSize: fontSizeCbb
            elide: Text.ElideRight
        }
        MouseArea {
            anchors.fill: txtDisplay
            onClicked: {
                cbbMain.forceActiveFocus()
                menuCombobox.open()
            }
        }
    }
    Rectangle{
        width: txtHeaderText.width + 10 * dpiToPixelValue
        height: txtHeaderText.height + 6 * dpiToPixelValue
        color: recDisplay.border.color
        visible: !headerEnabled
        y: recDisplay.y - height / 2
        x: recDisplay.radius
        radius: height / 2
        Text {
            id:txtHeaderText
            text: headerText
            font.pixelSize: 9 * dpiToPixelValue
            anchors.centerIn: parent
            color: recDisplay.border.color === baseColor ? baseTextColor : baseColor
        }
    }

    Image {
        id: imgCbbLeftIcon
        width: height
        height: parent.height / 2
        source: "qrc:/resource/SortDownIcon_Unselected.png"
        anchors.right: parent.right
        anchors.rightMargin: 5 * dpiToPixelValue
        y:parent.height / 2 - height / 2
        MouseArea {
            anchors.fill: parent
            onClicked: {
                cbbMain.forceActiveFocus()
                menuCombobox.open()
            }
        }
    }
    Rectangle{
        width: txtPoint.width + imgStar.width + 5 * dpiToPixelValue
        height: txtPoint.height
        color: "white"
        x: txtPoint.x
        y: txtPoint.y
        visible: dataPoint > 0
    }
    Text {
        id:txtPoint
        text: "+ " + dataPoint
        color: recDisplay.border.color
        font.pixelSize: fontSizeCbb
        y:parent.height / 2 - height / 2
        anchors.right: imgStar.left
        anchors.rightMargin: 5 * dpiToPixelValue
        visible: dataPoint > 0
    }
    Image {
        id: imgStar
        source: "qrc:/resource/Star_Yellow.png"
        height: parent.height / 2
        width: height
        y:parent.height / 2 - height / 2
        anchors.right: imgCbbLeftIcon.left
        anchors.rightMargin: 3 * dpiToPixelValue
        visible: dataPoint > 0
    }

    Menu {
        id: menuCombobox
        y: cbbMain.height
        height: recComboboxPopup.height
        width: cbbMain.width
        background: Rectangle{
            color: "transparent"
        }
        onOpened: {
            recDisplay.border.color = baseColor
        }
        onClosed: {
            recDisplay.border.color = baseSelectingColor
        }

        onVisibleChanged: {
            if(visible) {
                lvComboboxPopup.model = cbbMain.model
            }
        }

        contentItem: Rectangle {
            id: recComboboxPopup
            width: lvComboboxPopup.width
            height: lvComboboxPopup.height + (recBackGround.radius * 2)
            clip: true

            Rectangle {
                id: recBackGround
                border.color: baseColor
                radius: 5 * dpiToPixelValue
                anchors.fill: parent
            }

            ListView {
                id: lvComboboxPopup
                width: cbbMain.width
                height: lvComboboxPopup.count > 10 ? cbbPopupItemHeight * 10 : cbbPopupItemHeight * lvComboboxPopup.count
                y: recBackGround.radius
                snapMode: ListView.SnapToItem
                delegate: Rectangle {
                    width: cbbMain.width
                    height: cbbPopupItemHeight
                    color: "transparent"
                    Text{
                        id: txtComboboxNameItem
                        text: modelData.dataDisplayName
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        x: 5 * dpiToPixelValue
                        height: parent.height
                        width: parent.width - 10 * dpiToPixelValue
                        color: baseSelectingColor
                        font.pixelSize: fontSizeCbb
                        elide: Text.ElideRight
                    }
                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onClicked: {
                            cbbMain.currentTextValue = txtComboboxNameItem.text
                            cbbMain.currentValue = modelData.dataId
                            menuCombobox.close()
                        }
                        onEntered: {
                            parent.color = "#d3e0ee"
                        }
                        onExited: {
                            parent.color = "transparent"
                        }
                    }
                }
            }
        }
    }
}

