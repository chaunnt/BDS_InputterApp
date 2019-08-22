import QtQuick 2.0
import QtQuick.Controls 2.0
SwipeView {
    id: view
    currentIndex: mainswipeIndex
    interactive: false

    onVisibleChanged: {
        console.log("onVisibleChanged")
        if(visible){
            mainswipeIndex = 0
            currentBDSData = appManager.currentBDSData
        }
    }
    Component.onCompleted: {
        console.log("Component.onCompleted")
        console.log(isUpdateSequence)
        mainswipeIndex = 0
        currentBDSData = appManager.currentBDSData
    }

    ScreenLandArea{
        id: recScreenLandArea
        visible: mainswipeIndex === 0
    }

    ScreenLandDetail {
        id: recScreenLandDetail
        visible: mainswipeIndex === 1
    }

    ScreenLandContact {
        id: recScreenLandContact
        visible: mainswipeIndex === 2
    }

    ScreenLandOwner {
        id: recScreenLandOwner
        visible: mainswipeIndex === 3
    }

    ScreenLandView {
        id: recScreenLandView
        visible: mainswipeIndex === 4
    }

    ScreenLandLegacyImage{
        id:recScreenLandLegacyImage
        visible: mainswipeIndex === 5
    }
}
