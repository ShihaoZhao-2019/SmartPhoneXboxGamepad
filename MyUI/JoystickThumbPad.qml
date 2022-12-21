import QtQuick.Window
import QtQuick
import QtQuick.Controls

Item {

    signal                                  xValueChange(real value)
    signal                                  yValueChange(real value)

    id:                         _joyRoot

    ///--Output：xAxis、yAxis、xPositionDelta、yPositionDelta
    property real   xAxis:                  0                   ///< Value range [-1,1], negative values left stick, positive values right stick
    property real   yAxis:                  0                   ///< Value range [-1,1], negative values down stick, positive values up stick
    property real   xPositionDelta:         0                   ///< Amount to move the control on x axis    ( [-50,50] )
    property real   yPositionDelta:         0                   ///< Amount to move the control on y axis    ( [-50,50] )

    property real   _centerXY:              width / 2
    property bool   _processTouchPoints:    false
    property color  _fgColor:               "black"
    property real   _hatWidth:              100
    property real   _hatWidthHalf:          _hatWidth / 2

    property real   stickPositionX:         _centerXY           //Value range [0,width]
    property real   stickPositionY:         _centerXY           //Value range [0,height]

    onWidthChanged:                     calculateXAxis()
    onStickPositionXChanged:            calculateXAxis()

    onHeightChanged:                    calculateYAxis()
    onStickPositionYChanged:            calculateYAxis()

    function calculateXAxis() {
        //xAxis =  ((stickPositionX / width) * 2 - 1)
        xAxis = stickPositionX / width
    }

    function calculateYAxis() {
        //yAxis =  (1 - (stickPositionY / height) * 2)
        yAxis = stickPositionY / height
    }

    ///--Release the thumb and return to the center position
    function reCenter() {
        //松开_processTouchPoints标志为置为0
        _processTouchPoints = false

        // Move control back to original position
        xPositionDelta = 0
        yPositionDelta = 0

        // Re-Center sticks as needed
        stickPositionX = _centerXY
        stickPositionY = _centerXY

        xValueChange(xPositionDelta/width)
        yValueChange(yPositionDelta/width)
    }

    ///--Where the thumb is pressed, it is the center of the joystick
    function thumbDown(touchPoints) {
        // Position the control around the initial thumb position
//        console.log("touchPoints[0].y",touchPoints[0].y)
//        console.log("touchPoints[0].x",touchPoints[0].x)

        xPositionDelta = touchPoints[0].x - _centerXY    //[-50，50]
        yPositionDelta = touchPoints[0].y - _centerXY    //[-50，50]
        // We need to wait until we move the control to the right position before we process touch points
        _processTouchPoints = true //按下_processTouchPoints标志为置为1
    }

    ///--stickPositionX = touchPoint.x ; stickPositionY = touchPoint.y
    Connections {
        target: touchPoint
        onXChanged: {
            if (_processTouchPoints) {
                _joyRoot.stickPositionX = Math.max(Math.min(touchPoint.x, _joyRoot.width), 0)//将触摸点限制在内部
                xPositionDelta = _joyRoot.stickPositionX - _centerXY
//                console.log("x:",_joyRoot.xPositionDelta,"y:",_joyRoot.yPositionDelta)
                xValueChange(xPositionDelta/width)

            }
        }
        onYChanged: {
            if (_processTouchPoints) {
                _joyRoot.stickPositionY = Math.max(Math.min(touchPoint.y, _joyRoot.height), 0)
                yPositionDelta = -(_joyRoot.stickPositionY - _centerXY)
//                console.log("x:",_joyRoot.xPositionDelta,"y:",_joyRoot.yPositionDelta)
                yValueChange(yPositionDelta/width)
            }
        }
    }

    ///--Multiple Point Touch Area,  core:  touchPoints
    MultiPointTouchArea {
        anchors.fill:           parent
        minimumTouchPoints:     1                   //only one
        maximumTouchPoints:     1                   //only one
        touchPoints:            [ TouchPoint { id: touchPoint } ]
        onPressed:              _joyRoot.thumbDown(touchPoints)
        onReleased:             _joyRoot.reCenter()//松开的情况下回到中心点
    }

    ///--UI： inside circle + outer circle
    Rectangle {
        anchors.fill:       parent
        radius:             width / 2
        color:              "white"
        opacity:            0.5

        ///--UI: touch points
        Rectangle {
            width:          _hatWidth
            height:         _hatWidth
            radius:         _hatWidthHalf
            border.color:   _fgColor
            border.width:   1
            color:          Qt.rgba(_fgColor.r, _fgColor.g, _fgColor.b, 0.5)
            //stickPositionX为基准点,是这个组件的正中间
            x:              stickPositionX - _hatWidthHalf                  //By default the middle //这个小点长度为15,x和y是左上角的点，这里设置其左上角的坐标=中心点坐标-自身宽高除2
            y:              stickPositionY - _hatWidthHalf                  //By default the middle
       }
    }
}

