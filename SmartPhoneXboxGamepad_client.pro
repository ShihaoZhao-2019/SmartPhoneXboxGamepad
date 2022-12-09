QT += quick network

SOURCES += \
        Communication/TransCOM.cpp \
        Communication/TransTCP.cpp \
        Communication/TransUDP.cpp \
        Transfer/TaskControl.cpp \
        Xbox/Xbox.cpp \
        main.cpp

resources.files = main.qml 
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
