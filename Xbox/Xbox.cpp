#include "Xbox.h"

Xbox::Xbox(QObject *parent)
    : QObject{parent}
{
    p_xbox_state = &xbox_state;
}

Xbox *Xbox::getInstance()
{
    if (instance == nullptr)
        instance = new Xbox();
    return instance;
}

XINPUT_STATE &Xbox::GetXboxState()
{
    return xbox_state;
}

PXINPUT_STATE &Xbox::GetPXboxState()
{
    return p_xbox_state;
}

void OutputwButtons()
{
//    for (int i = 15; i >= 0; i--) {
//            qDebug("%d", p_xbox_state->Gamepad.wButtons & 1 << i ? 1 : 0);
//    }
}


// Set Key
void Xbox::SetY()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons |= BITY;
}
void Xbox::SetX()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons |= BITX;
}
void Xbox::SetB()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons |= BITB;
}
void Xbox::SetA()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons |= BITA;
}
void Xbox::SetRB()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons |= BITRB;
}
void Xbox::SetLB()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons |= BITLB;
}
void Xbox::SetThumbR()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons |= BITThumbR;
}
void Xbox::SetThumbL()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons |= BITThumbL;
}
void Xbox::SetView()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons |= BITView;
}
void Xbox::SetMenu()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons |= BITMenu;
}
void Xbox::SetRight()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons |= BITRight;
}
void Xbox::SetLeft()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons |= BITLeft;
}

void Xbox::SetDown()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons |= BITDown;
}

void Xbox::SetUp()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons |= BITUp;
}

// Release Key

void Xbox::ReleaseY()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons &= ~BITY;
}
void Xbox::ReleaseX()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons &= ~BITX;
}
void Xbox::ReleaseB()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons &= ~BITB;
}
void Xbox::ReleaseA()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons &= ~BITA;
}
void Xbox::ReleaseRB()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons &= ~BITRB;
}
void Xbox::ReleaseLB()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons &= ~BITLB;
}
void Xbox::ReleaseThumbR()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons &= ~BITThumbR;
}
void Xbox::ReleaseThumbL()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons &= ~BITThumbL;
}
void Xbox::ReleaseView()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons &= ~BITView;
}
void Xbox::ReleaseMenu()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons &= ~BITMenu;
}
void Xbox::ReleaseRight()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons &= ~BITRight;
}
void Xbox::ReleaseLeft()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons &= ~BITLeft;
}

void Xbox::ReleaseDown()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons &= ~BITDown;
}

void Xbox::ReleaseUp()
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.wButtons &= ~BITUp;
}

void MyPrint(PXINPUT_GAMEPAD p)
{
//    qDebug("Lx:%d",p->sThumbLX);
//    qDebug("Ly:%d",p->sThumbLY);
//    qDebug("Rx:%d",p->sThumbRX);
//    qDebug("Ry:%d",p->sThumbRY);
}
//Change Analog value
void Xbox::ChangeThumbLY(short value)
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.sThumbLY = value;
    MyPrint(&p_xbox_state->Gamepad);
}
void Xbox::ChangeThumbLX(short value)
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.sThumbLX = value;
    MyPrint(&p_xbox_state->Gamepad);
}
void Xbox::ChangeThumbRX(short value)
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.sThumbRX = value;
    MyPrint(&p_xbox_state->Gamepad);
}
void Xbox::ChangeThumbRY(short value)
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.sThumbRY = value;
    MyPrint(&p_xbox_state->Gamepad);
}
void Xbox::ChangeLeftTrigger(unsigned char value)
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.bLeftTrigger = value;
}
void Xbox::ChangeRightTrigger(unsigned char value)
{
    std::lock_guard<std::mutex> lock(data_mutex); //加锁
    p_xbox_state->Gamepad.bRightTrigger = value;
}


Xbox* Xbox::instance = nullptr;
