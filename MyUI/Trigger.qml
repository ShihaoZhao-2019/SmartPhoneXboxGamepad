import QtQuick 2.15
import QtQuick.Controls


Item {
        property bool press_flag:           true
        signal valueChange(real value);
        function setBarValue(value){
            control.value = value
            valueChange(control.value)
        }

        function thumbDown(){
            press_flag = true
            control.value = (_triggerBar.height - Math.max(Math.min(touchPoint.y, _triggerBar.height), 0)) / _triggerBar.height
            valueChange(control.value)
//            console.log("press x:",touchPoints[0].x,"y:",touchPoints[0].y)
        }
        function thumbUp(){
            press_flag = false
            control.value = 0
            valueChange(control.value)
//            console.log("release x:",touchPoints[0].x,"y:",touchPoints[0].y)
        }

        id:                                 _triggerBar
        ProgressBar {
            id: control
            value: 0
            anchors.centerIn: parent
            anchors.fill: parent
            background: Rectangle {
                implicitWidth: control.width
                implicitHeight: control.height
                color: "black"
                radius: 10
            }
            contentItem: Item {
                Rectangle {
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    width: control.width
                    height: control.height * control.value
                    radius: 10
                    color: "white"
                }
            }
        }

        MultiPointTouchArea {
            anchors.fill:           parent
            minimumTouchPoints:     1                   //only one
            maximumTouchPoints:     1                   //only one
            touchPoints:            [ TouchPoint { id: touchPoint } ]
            onPressed:              _triggerBar.thumbDown()
            onReleased:             _triggerBar.thumbUp()
        }
        Connections {
            target: touchPoint
            onYChanged: {
                if (press_flag) {
//                    console.log("y:",touchPoint.y)
                    control.value = (_triggerBar.height - Math.max(Math.min(touchPoint.y, _triggerBar.height), 0)) / _triggerBar.height
                    valueChange(control.value)
                }

            }
        }
}



