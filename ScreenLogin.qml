import QtQuick 2.0

Rectangle {
    Image {
        id: bgLogin
        source: "qrc:/resource/background_LandMark.jpg"
        height: parent.height
        anchors.centerIn: parent
        fillMode: Image.PreserveAspectFit
    }

    Rectangle {
        anchors.centerIn: parent
        width: parent.width - 60 * dpiToPixelValue
        height: clItems.implicitHeight + 40 * dpiToPixelValue
        color: "#ccffffff"
        radius: 10 * dpiToPixelValue
        Column{
            id:clItems
            width: parent.width - 20 * dpiToPixelValue
            spacing: 20 * dpiToPixelValue * dpiToPixelValue
            x: 10 * dpiToPixelValue
            y: 10 * dpiToPixelValue
            Rectangle{
                width: parent.width
                height: baseButtonHeight * 2
                color: "transparent"
                Image {
                    source: "qrc:/resource/logo_hobe.png"
                    height: baseButtonHeight * 2
                    fillMode: Image.PreserveAspectFit
                    anchors.centerIn: parent
                }
            }

            Materials_TextBox{
                id:txtUserName
                placeholderText: qsTr("Tên đăng nhập")
                width: parent.width
                textBoxRadius:height / 2
//                text:"chauinput"
                onTextChanged:{
                    if(txtUserName.text.trim() === "" || txtPassword.text.trim() === ""){
                        btnSignIn.enabled = false
                    }else{
                        btnSignIn.enabled = true
                    }
                }
            }
            Materials_TextBox{
                id:txtPassword
                placeholderText: qsTr("Mật khẩu")
                width: parent.width
                textBoxRadius:height / 2
                echoMode: TextInput.Password
                onTextChanged:{
                    if(txtUserName.text.trim() === "" || txtPassword.text.trim() === ""){
                        btnSignIn.enabled = false
                    }else{
                        btnSignIn.enabled = true
                    }
                }
//                text:"chauinput"
            }
            CustomButton{
                id:btnSignIn
                buttonText: qsTr("Đăng nhập")
                buttonColor: enabled ? baseColor : "gray"
                enabled: true
                width: parent.width
                onClicked: {
                    forceActiveFocus()
                    if(txtUserName.text.trim() === ""){
                        messageDialog.show("Please input Phone Number")
                    }else if(txtPassword.text.trim() === ""){
                        messageDialog.show("Please input password")
                    }else{
                        waitingDialog.show("Please wait")
                        if(appManager.loginUser(txtUserName.text, txtPassword.text) === true){
                            if(appManager.startupApplication() === true){
                                mainStackView.push("qrc:/ScreenHome.qml")
                                isLoggedIn = true
                            }
                        }
                        waitingDialog.close()
                        enabled = true
                    }
                }
            }
        }
    }
}
