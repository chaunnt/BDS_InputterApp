import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle{
    Rectangle{
        anchors.centerIn: parent
        width:parent.width - 20 * dpiToPixelValue
        height: clItems.implicitHeight
        color: "transparent"
        Column{
            id:clItems
            width: parent.width
            spacing: 20 * dpiToPixelValue * dpiToPixelValue
            Materials_TextBox{
                id:txtPhoneNumber
                placeholderText: "Phone Number"
                width: parent.width
                textBoxRadius:height / 2
                onTextChanged:{
                    if(txtPhoneNumber.text.trim() === ""){
                        btnForgot.enabled = false
                    }else{
                        btnForgot.enabled = true
                    }
                }
            }
            CustomButton{
                id:btnForgot
                buttonText: qsTr("Restore")
                width: parent.width
                buttonColor: enabled ? baseColor : "gray"
                enabled: false
                onClicked: {
                    forceActiveFocus()
                    if(txtPhoneNumber.text.trim() === ""){
                        messageDialog.show("Please input phone number")
                    }else{
                        waitingDialog.show("Please wait")
                        if(appManager.forgotPassword(txtPhoneNumber.text)){
                            messageDialog.show("Please check your inbox")
                            txtPhoneNumber.text = ""
                        }

                        waitingDialog.close()
                    }

                }
            }
            CustomButton{
                id:btnBack
                buttonText: qsTr("Back")
                width: parent.width
                onClicked: {
                    enabled = false
                    mainStackView.pop()
                    enabled = true
                }
            }
        }

    }
}

