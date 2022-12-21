import QtQuick.Window
import QtQuick
import QtQuick.Controls 6.3
import "MyUI"

Window {
    id: main
    width: Screen.width
    height: Screen.height

    visible: true
    title: qsTr("Hello,World")


    ClassXboxLayout{
        id:class_xbox_one
        width:parent.width
        height:parent.height

    }
}
