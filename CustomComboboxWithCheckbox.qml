import QtQuick 2.9
import QtQuick.Controls 2.2


Rectangle{
    id: cbbMain
    property var model
    // Option
    property int cbbPopupItemHeight: baseButtonHeight
    property int fontSizeCbb: normalFontSize
    property int marginCbbItem: 5 * dpiToPixelValue
    signal itemCheckedChanged(var itemIndex, var itemText, var itemChecked)
    property string currentText: "Loại bất động sản"
    height: baseButtonHeight
    width: parent.width
    onActiveFocusChanged: {
        console.log("onActiveFocusChangedonActiveFocusChangedonActiveFocusChanged")
        console.log(activeFocus)
        if(activeFocus){
            recDisplay.border.color = baseColor
        }else{
            recDisplay.border.color = baseSelectingColor
        }
    }
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
            text: currentText
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

    Image {
        id: imgCbbLeftIcon
        width: height
        height: parent.height / 2
        source: "qrc:/resource/DownArrow_Black.png"
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
                    id:cbbItem
                    width: cbbMain.width
                    height: cbbPopupItemHeight
                    color: "transparent"
                    Text{
                        id: txtComboboxNameItem
                        text: displayText
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        x: 5 * dpiToPixelValue
                        height: parent.height
                        width: parent.width - 10 * dpiToPixelValue
                        color: baseTextColor
                        font.pixelSize: fontSizeCbb
                        elide: Text.ElideRight
                    }
                    Rectangle{
                        height: parent.height / 2
                        width: height
                        y:parent.height / 2 - height / 2
                        anchors.right: parent.right
                        anchors.rightMargin: 5 * dpiToPixelValue
                        border.color: "lightgray"
                        border.width: 1
                        radius: 3 * dpiToPixelValue
                        Image {
                            source: "qrc:/resource/Check_Green.png"
                            anchors.fill: parent
                            fillMode: Image.PreserveAspectFit
                            visible: displayActive
                        }
                    }

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onClicked: {
                            console.log("onclicked")
                            displayActive = !displayActive
                            itemCheckedChanged(index,txtComboboxNameItem.text,displayActive)
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

