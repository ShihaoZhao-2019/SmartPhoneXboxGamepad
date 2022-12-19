QT += quick network

SOURCES += \
        Communication/TransCOM.cpp \
        Communication/TransTCP.cpp \
        Communication/TransUDP.cpp \
        Transfer/TaskControl.cpp \
        Xbox/Xbox.cpp \
        main.cpp

resources.files = main.qml  \
                  MyUI/ClassXboxLayout.qml\
                  MyUI/JoystickThumbPad.qml\
                  MyUI/Trigger.qml\
                  MyUI/images/xbox_img.jpg\
                  MyUI/images/xbox_img_crop.jpg\
                  MyUI/images/Up.svg\
                  MyUI/images/Down.svg\
                  MyUI/images/Left.svg\
                  MyUI/images/Right.svg


resources.prefix = /$${TARGET}
RESOURCES += resources

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Communication/TransCOM.h \
    Communication/TransTCP.h \
    Communication/TransUDP.h \
    Transfer/TaskControl.h \
    Xbox/Xbox.h

INCLUDEPATH +=\
    ./
