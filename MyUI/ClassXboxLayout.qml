import QtQuick 2.15
import QtQuick.Controls

Item {
    Rectangle {

        //when iamge use PreserveAspectCrop mode,the source image maybe be croped,the property is the length to crop
        property real   crop_length_h:                             0
        property real   crop_length_w:                             0
        property real   scale_ratio:                               1


        property int      everyRoundButtonSize:                    60
        property int      everyButtonSize:                         60

        // every component center location
        property point    sThumbL:                                 Qt.point(560,442)
        property point    sThumbR:                                 Qt.point(1437,785)
        property point    trigerLPos:                              Qt.point(20,10)
        property point    trigerRPos:                              Qt.point(rectangle.width-20-trigerW,10)
//        property point    wButtons:                                Qt.point(560,432)
        property point    xButton:                                 Qt.point(1566,444)
        property point    yButton:                                 Qt.point(1719,290)
        property point    bButton:                                 Qt.point(1876,444)
        property point    aButton:                                 Qt.point(1720,596)
        property point    viewButton:                              Qt.point(970,444)
        property point    menuButton:                              Qt.point(1301,444)
        property point    rightButton:                             Qt.point(952,803)
        property point    leftButton:                              Qt.point(728,804)
        property point    downButton:                              Qt.point(840,913)
        property point    upButton:                                Qt.point(840,695)

        //Triger location
        property int      trigerW:                                 40
        property int      trigerH:                                 250

        function calculateCroplength() {
            var hRatio = xbox_one_image.sourceSize.height / xbox_one_image.height;
            var wRatio = xbox_one_image.sourceSize.width / xbox_one_image.width;
            if(wRatio<hRatio)
            {
                scale_ratio = wRatio
                crop_length_h = (xbox_one_image.sourceSize.height - xbox_one_image.height * scale_ratio)/2
            }else
            {
                scale_ratio = hRatio
                crop_length_w = (xbox_one_image.sourceSize.width - xbox_one_image.width * scale_ratio)/2
            }

//            console.log("w_ratio:",wRatio,"h_ratio:",hRatio)
//            console.log("crop_length_w:",crop_length_w,"crop_length_h:",crop_length_h)
//            console.log("sourceSize.width:",xbox_one_image.sourceSize.width,"sourceSize.height:",xbox_one_image.sourceSize.height)
//            console.log("xbox_one_image_width:",xbox_one_image.width,"xbox_one_image_height:",xbox_one_image.height)
        }
        // calculate the x and y after crop and scale
        function calculateComponentCenterX(x_origin){
            return (x_origin - crop_length_w)/scale_ratio
        }
        function calculateComponentCenterY(y_origin){
            return (y_origin - crop_length_h)/scale_ratio
        }

        id: rectangle
        color: "green"
        anchors.fill: parent
        Image {
            id: xbox_one_image
             anchors.fill: parent
             anchors.centerIn: parent
             source: "images/xbox_img_crop.jpg"
             fillMode: Image.PreserveAspectCrop/**/

             Component.onCompleted: rectangle.calculateCroplength()
         }

         //ThumbPad
         JoystickThumbPad {
             id:                     thumbL
             width:                  200
             height:                 200
             x: rectangle.calculateComponentCenterX(rectangle.sThumbL.x) - width/2
             y: rectangle.calculateComponentCenterY(rectangle.sThumbL.y) - height/2
             onXValueChange:
             {
                 xBoxState.ChangeThumbLX(Math.floor(value*65535))
             }
             onYValueChange:
             {
                 xBoxState.ChangeThumbLY(Math.floor(value*65535))
             }
         }

         JoystickThumbPad {
             id:                     thumbR
             x: rectangle.calculateComponentCenterX(rectangle.sThumbR.x) - width/2
             y: rectangle.calculateComponentCenterY(rectangle.sThumbR.y) - height/2
             width:                  200
             height:                 200
             onXValueChange:
             {
                 xBoxState.ChangeThumbRX(Math.floor(value*65535))
             }
             onYValueChange:
             {
                 xBoxState.ChangeThumbRY(Math.floor(value*65535))
             }
         }

         // Round Button A B X Y View Menu
         RoundButton {
             id:                     yButtonComponent
             x:                      rectangle.calculateComponentCenterX(rectangle.yButton.x) - width/2
             y:                      rectangle.calculateComponentCenterY(rectangle.yButton.y) - height/2
             width:                  rectangle.everyRoundButtonSize
             height:                 rectangle.everyRoundButtonSize
             opacity:                0.5
             radius:                 width/2
             background: Rectangle {
                 anchors.centerIn:   parent
                 width:              parent.width
                 height:             parent.height
                 color:              "yellow"
                 radius:             width/2
             }
             onPressed:
             {
                 xBoxState.SetY()
//                 console.log("yButtonComponent press")
             }
             onReleased:
             {
                 xBoxState.ReleaseY()
//                 console.log("yButtonComponent release")
             }

         }

         RoundButton {
             id:                     bButtonComponent
             x:                      rectangle.calculateComponentCenterX(rectangle.bButton.x) - width/2
             y:                      rectangle.calculateComponentCenterY(rectangle.bButton.y) - height/2
             width:                  rectangle.everyRoundButtonSize
             height:                 rectangle.everyRoundButtonSize
             opacity:                0.5
             radius:                 width/2
             background: Rectangle {
                 anchors.centerIn:   parent
                 width:              parent.width
                 height:             parent.height
                 color:              "red"
                 radius:             width/2
             }
             onPressed:
             {
                 xBoxState.SetB()

//                 console.log("bButtonComponent press")
             }
             onReleased:
             {
                 xBoxState.ReleaseB()

//                 console.log("bButtonComponent release")
             }

         }

         RoundButton {
             id:                     aButtonComponent
             x:                      rectangle.calculateComponentCenterX(rectangle.aButton.x) - width/2
             y:                      rectangle.calculateComponentCenterY(rectangle.aButton.y) - height/2
             width:                  rectangle.everyRoundButtonSize
             height:                 rectangle.everyRoundButtonSize
             opacity:                0.5
             radius:                 width/2
             background: Rectangle {
                 anchors.centerIn:   parent
                 width:              parent.width
                 height:             parent.height
                 color:              "green"
                 radius:             width/2
             }
             onPressed:
             {
                 xBoxState.SetA()

//                 console.log("aButtonComponent press")
             }
             onReleased:
             {
                 xBoxState.ReleaseA()

//                 console.log("aButtonComponent release")
             }

         }
         RoundButton {
             id:                     xButtonComponent
             x:                      rectangle.calculateComponentCenterX(rectangle.xButton.x) - width/2
             y:                      rectangle.calculateComponentCenterY(rectangle.xButton.y) - height/2
             width:                  rectangle.everyRoundButtonSize
             height:                 rectangle.everyRoundButtonSize
             opacity:                0.5
             radius:                 width/2
             background: Rectangle {
                 anchors.centerIn:   parent
                 width:              parent.width
                 height:             parent.height
                 color:              "blue"
                 radius:             width/2
             }
             onPressed:
             {
                 xBoxState.SetX()

//                 console.log("xButtonComponent press")
             }
             onReleased:
             {
                 xBoxState.ReleaseX()

//                 console.log("xButtonComponent release")
             }

         }
         RoundButton {
             id:                     viewButtonComponent
             x:                      rectangle.calculateComponentCenterX(rectangle.viewButton.x) - width/2
             y:                      rectangle.calculateComponentCenterY(rectangle.viewButton.y) - height/2
             width:                  rectangle.everyRoundButtonSize
             height:                 rectangle.everyRoundButtonSize
             opacity:                0.5
             radius:                 width/2
             background: Rectangle {
                 anchors.centerIn:   parent
                 width:              parent.width
                 height:             parent.height
                 color:              "black"
                 radius:             width/2
             }
             onPressed:              xBoxState.SetView()
             onReleased:             xBoxState.ReleaseView()

         }
         RoundButton {
             id:                     menuButtonComponent
             x:                      rectangle.calculateComponentCenterX(rectangle.menuButton.x) - width/2
             y:                      rectangle.calculateComponentCenterY(rectangle.menuButton.y) - height/2
             width:                  rectangle.everyRoundButtonSize
             height:                 rectangle.everyRoundButtonSize
             opacity:                0.5
             radius:                 width/2
             background: Rectangle {
                 anchors.centerIn:   parent
                 width:              parent.width
                 height:             parent.height
                 color:              "black"
                 radius:             width/2
             }
             onPressed:              xBoxState.SetMenu()
             onReleased:             xBoxState.ReleaseMenu()

         }

         // RectButton UP DOWN LEFT RIGHT
         Button {
              id:                     upButtonComponent
              x:                      rectangle.calculateComponentCenterX(rectangle.upButton.x) - width/2
              y:                      rectangle.calculateComponentCenterY(rectangle.upButton.y) - height/2
              width:                  rectangle.everyRoundButtonSize
              height:                 rectangle.everyRoundButtonSize
              opacity:                0.5
              background: Rectangle {
                  anchors.centerIn:   parent
                  width:              parent.width
                  height:             parent.height
                  color:              "black"
                  radius:             parent.width/4
              }
              onPressed:              xBoxState.SetUp()
              onReleased:             xBoxState.ReleaseUp()

          }
         Button {
             id:                     downButtonComponent
             x:                      rectangle.calculateComponentCenterX(rectangle.downButton.x) - width/2
             y:                      rectangle.calculateComponentCenterY(rectangle.downButton.y) - height/2
             width:                  rectangle.everyRoundButtonSize
             height:                 rectangle.everyRoundButtonSize
             opacity:                0.5
             background: Rectangle {
                 anchors.centerIn:   parent
                 width:              parent.width
                 height:             parent.height
                 color:              "black"
                 radius:             parent.width/4
             }
             onPressed:              xBoxState.SetDown()
             onReleased:             xBoxState.ReleaseDown()

         }
         Button {
             id:                     leftButtonComponent
             x:                      rectangle.calculateComponentCenterX(rectangle.leftButton.x) - width/2
             y:                      rectangle.calculateComponentCenterY(rectangle.leftButton.y) - height/2
             width:                  rectangle.everyRoundButtonSize
             height:                 rectangle.everyRoundButtonSize
             opacity:                0.5
             background: Rectangle {
                 anchors.centerIn:   parent
                 width:              parent.width
                 height:             parent.height
                 color:              "black"
                 radius:             parent.width/4
             }
             onPressed:              xBoxState.SetLeft()
             onReleased:             xBoxState.ReleaseLeft()
         }
         Button {
             id:                     rightButtonComponent
             x:                      rectangle.calculateComponentCenterX(rectangle.rightButton.x) - width/2
             y:                      rectangle.calculateComponentCenterY(rectangle.rightButton.y) - height/2
             width:                  rectangle.everyRoundButtonSize
             height:                 rectangle.everyRoundButtonSize
             opacity:                0.5
             background: Rectangle {
                 anchors.centerIn:   parent
                 width:              parent.width
                 height:             parent.height
                 color:              "black"
                 radius:             parent.width/4
             }
             onPressed:              xBoxState.SetRight()
             onReleased:             xBoxState.ReleaseRight()

         }

         // left trigger and right trigger
         Trigger{
             x:                                      rectangle.trigerLPos.x
             y:                                      rectangle.trigerLPos.y
             height:                                 rectangle.trigerH
             width:                                  rectangle.trigerW
             opacity:                                0.3
             id:                                     left_trigher
             Text {
                 anchors.centerIn:                   parent
                 text:                               qsTr("TrigerL")
                 font.pixelSize: Qt.application.font.pixelSize
                 rotation:                           -90
                 font.bold:                          true
             }
             onValueChange:
             {
                 xBoxState.ChangeLeftTrigger(Math.floor(value*255))
//                 console.log("left triger value:",value)
             }
         }
         Trigger{
             x:                                      rectangle.trigerRPos.x
             y:                                      rectangle.trigerRPos.y
             height:                                 rectangle.trigerH
             width:                                  rectangle.trigerW
             opacity:                                0.3
             id:                                     right_trigher
             Text {
                 anchors.centerIn:                   parent
                 text:                               qsTr("TrigerR")
                 font.pixelSize: Qt.application.font.pixelSize
                 rotation:                           -90
                 font.bold:                          true
             }
             onValueChange:
             {
                 xBoxState.ChangeRightTrigger(Math.floor(value*255))
//                 console.log("right triger value:",value)
             }
         }

         //Lb and Rb
         function releaseButton(buttonName)
         {
            buttonName.color = "black"
//            console.log("lBButtonComponent release")
         }


         //leftThumbButtonComponent and rightThumbButtonComponent
         RoundButton {
             property bool           press_flag:              false
             id:                     leftThumbButtonComponent
             width:                  rectangle.everyRoundButtonSize
             height:                 rectangle.everyRoundButtonSize
             anchors.horizontalCenter:thumbL.horizontalCenter
             anchors.top:          thumbL.bottom
             opacity:                0.5
             radius:                 width/2
             background: Rectangle {
                 id:leftThumbButtonComponentBackground
                 anchors.centerIn:   parent
                 width:              parent.width
                 height:             parent.height
                 color:              "black"
                 radius:             width/2
                 Text {
                     color: "black"
                     anchors.centerIn: parent
                     text: qsTr("L")
                 }
             }
             onPressed:
             {
                 press_flag = true
                 xBoxState.SetThumbL()
//                 console.log("leftThumbButtonComponent press")
                 leftThumbButtonComponentBackground.color = "white"
             }
             onReleased:
             {
                 if(press_flag)
                 {
                     press_flag = false
                     xBoxState.ReleaseThumbL()
                     parent.releaseButton(leftThumbButtonComponentBackground)
                 }
             }
             onPressedChanged:
             {
                 if(press_flag)
                 {
                     press_flag = false
                     xBoxState.ReleaseThumbL()
//                     console.log("leftThumbButtonComponent onPressedChanged")
                     parent.releaseButton(leftThumbButtonComponentBackground)
                 }
             }

         }
         RoundButton {
             property bool           press_flag:              false
             id:                     rightThumbButtonComponent
             width:                  rectangle.everyRoundButtonSize
             height:                 rectangle.everyRoundButtonSize
             anchors.verticalCenter: thumbR.verticalCenter
             anchors.left:          thumbR.right
             opacity:                0.5
             radius:                 width/2
             background:Rectangle {
                 id:rightThumbButtonComponentBackground
                 anchors.centerIn:   parent
                 width:              parent.width
                 height:             parent.height
                 color:              "black"
                 radius:             width/2
                 Text {
                     color: "black"
                     anchors.centerIn: parent
                     text: qsTr("R")
                 }
             }
             onPressed:
             {
                 press_flag = true
                 xBoxState.SetThumbR()
//                 console.log("rightThumbButtonComponent press")
                 rightThumbButtonComponentBackground.color = "white"
             }
             onReleased:
             {
                 if(press_flag)
                 {
                     press_flag = false
                     xBoxState.ReleaseThumbR()
                     parent.releaseButton(rightThumbButtonComponentBackground)
                 }
             }
             onPressedChanged:
             {
                 if(press_flag)
                 {
                     press_flag = false
                     xBoxState.ReleaseThumbR()
//                     console.log("rightThumbButtonComponent onPressedChanged")
                     parent.releaseButton(rightThumbButtonComponentBackground)
                 }
             }

         }


         Button {
             property bool           press_flag:              false
             id:                     lButtonComponent
             width:                  rectangle.everyRoundButtonSize
             height:                 rectangle.everyRoundButtonSize
             opacity:                0.5
             anchors.horizontalCenter: left_trigher.horizontalCenter
             anchors.top:              left_trigher.bottom
             anchors.topMargin:      5
             text:                   qsTr("LB")
             background: Rectangle {
                      id:lButtonComponentBackGround
                      color: "black"
                      radius: rectangle.everyRoundButtonSize/4
                  }

             onPressed:
             {
                 press_flag = true
                 xBoxState.SetLB()
//                 console.log("lBButtonComponent press")
                 lButtonComponentBackGround.color = "white"
             }
             onReleased:
             {
                 if(press_flag)
                 {
                     press_flag = false
                     xBoxState.ReleaseLB()
                     parent.releaseButton(lButtonComponentBackGround)
                 }
             }
             onPressedChanged:
             {
                 if(press_flag)
                 {
                     press_flag = false
                     xBoxState.ReleaseLB()
//                     console.log("lB onPressedChanged")
                     parent.releaseButton(lButtonComponentBackGround)
                 }
             }
         }

         Button {
             property bool           press_flag:              false
             id:                     rButtonComponent
             width:                  rectangle.everyRoundButtonSize
             height:                 rectangle.everyRoundButtonSize
             opacity:                0.5
             anchors.horizontalCenter: right_trigher.horizontalCenter
             anchors.top:              right_trigher.bottom
             anchors.topMargin:      5
             text:                   qsTr("RB")
             background: Rectangle {
                      id:rButtonComponentBackGround
                      color: "black"
                      radius: rectangle.everyRoundButtonSize/4
                  }

             onPressed:
             {
                 press_flag = true
                 xBoxState.SetRB()
//                 console.log("rBButtonComponent press")
                 rButtonComponentBackGround.color = "white"
             }
             onReleased:
             {
                 if(press_flag)
                 {
                     press_flag = false
                     xBoxState.ReleaseRB()
                     parent.releaseButton(rButtonComponentBackGround)
                 }
             }
             onPressedChanged:
             {
                 if(press_flag)
                 {
                     press_flag = false
                     xBoxState.ReleaseRB()
//                     console.log("rB onPressedChanged")
                     parent.releaseButton(rButtonComponentBackGround)
                 }
             }
         }
    }

    ///--You can also use signals
//    Timer {
//        interval:   1000          // 1Hz
//        running:    true
//        repeat:     true
//        onTriggered: {
//            console.log("sourceSize:h:",xbox_one_image.sourceSize.height,",w:",xbox_one_image.sourceSize.width)
//            console.log("Image:h:",xbox_one_image.height,",w:",xbox_one_image.width)
//        }
//    }


}

/*##^##
Designer {
    D{i:0;autoSize:true;height:342;width:842}
}
##^##*/




