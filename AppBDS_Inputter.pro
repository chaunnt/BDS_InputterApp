QT += quick network sql multimedia webview
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
android: {

    QT += androidextras
    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

    OTHER_FILES += \
        android/src/com/batdongsan/nhadatvn/AndroidClient.java \
        android/AndroidManifest.xml

    ANDROID_EXTRA_LIBS += \
        $$PWD/android/libs/libcrypto.so \
        $$PWD/android/libs/libssl.so
    SOURCES += \
        jni_android.cpp
}

SOURCES += main.cpp \
    appmanager.cpp \
    RealEstateModel/bdsdata.cpp \
    notification.cpp \
    RealEstateModel/provincedata.cpp \
    RealEstateModel/districtdata.cpp \
    ServerCommunication/servercommunicator.cpp \
    globaldefine.cpp \
    RealEstateModel/retype.cpp \
    RealEstateModel/simpledata.cpp \
    RealEstateModel/relocationtype.cpp \
    RealEstateModel/redirection.cpp \
    RealEstateModel/reshape.cpp \
    DBCommunication/dbcommunicator.cpp \
    RealEstateModel/warddata.cpp \
    imageprovider.cpp \
    RealEstateModel/imagedata.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    appmanager.h \
    RealEstateModel/bdsdata.h \
    notification.h \
    RealEstateModel/provincedata.h \
    RealEstateModel/districtdata.h \
    ServerCommunication/servercommunicator.h \
    globaldefine.h \
    RealEstateModel/retype.h \
    RealEstateModel/simpledata.h \
    RealEstateModel/relocationtype.h \
    RealEstateModel/redirection.h \
    RealEstateModel/reshape.h \
    DBCommunication/dbcommunicator.h \
    RealEstateModel/warddata.h \
    imageprovider.h \
    RealEstateModel/imagedata.h

DISTFILES += \
    android/AndroidManifest.xml \
    android/res/values/strings.xml \
    ios/Project-Info.plist \
    android/res/drawable-hdpi/ic_launcher.png \
    android/res/drawable-mdpi/ic_launcher.png \
    android/res/drawable-xhdpi/ic_launcher.png \
    android/res/drawable-xxhdpi/ic_launcher.png \
    ios/Def-568h@2x.png \
    ios/Def-667h@2x.png \
    ios/Def-Portrait-736h@3x.png \
    ios/Def-Portrait.png \
    ios/Def-Portrait@2x.png \
    ios/Def.png \
    ios/Def@2x.png \
    ios/Icon-60.png \
    ios/Icon-60@2x.png \
    ios/Icon-60@3x.png \
    ios/Icon-72.png \
    ios/Icon-72@2x.png \
    ios/Icon-76.png \
    ios/Icon-76@2x.png \
    ios/Icon-Small-40.png \
    ios/Icon-Small-40@2x.png \
    ios/Icon-Small-50.png \
    ios/Icon-Small-50@2x.png \
    android/AndroidManifest.xml \
    android/libs/QtAndroidWebView-bundled.jar \
    android/res/values/strings.xml \
    android/res/drawable-hdpi/ic_launcher.png \
    android/res/drawable-hdpi/icon.png \
    android/res/drawable-ldpi/icon.png \
    android/res/drawable-mdpi/ic_launcher.png \
    android/res/drawable-mdpi/icon.png \
    android/res/drawable-xhdpi/ic_launcher.png \
    android/res/drawable-xxhdpi/ic_launcher.png \
    android/src/com/batdongsan/nhadatvn/AndroidClient.java
