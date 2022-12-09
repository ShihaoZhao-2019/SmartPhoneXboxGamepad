#include "Xbox.h"

Xbox::Xbox(QObject *parent)
    : QObject{parent}
{

}

XINPUT_GAMEPAD &Xbox::GetXboxState()
{
    return xbox_state;
}

PXINPUT_GAMEPAD &Xbox::GetPXboxState()
{
    return p_xbox_state;
}

// Set Key
void Xbox::SetY()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons |= BITY;
}
void Xbox::SetX()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons |= BITX;
}
void Xbox::SetB()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons |= BITB;
}
void Xbox::SetA()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons |= BITA;
}
void Xbox::SetRB()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons |= BITRB;
}
void Xbox::SetLB()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons |= BITLB;
}
void Xbox::SetThumbR()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons |= BITThumbR;
}
void Xbox::SetThumbL()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons |= BITThumbL;
}
void Xbox::SetView()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons |= BITView;
}
void Xbox::SetMenu()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons |= BITMenu;
}
void Xbox::SetRight()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons |= BITRight;
}
void Xbox::SetLeft()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons |= BITLeft;
}

// Release Key

void Xbox::ReleaseY()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons &= ~BITY;
}
void Xbox::ReleaseX()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons &= ~BITX;
}
void Xbox::ReleaseB()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons &= ~BITB;
}
void Xbox::ReleaseA()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons &= ~BITA;
}
void Xbox::ReleaseRB()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons &= ~BITRB;
}
void Xbox::ReleaseLB()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons &= ~BITLB;
}
void Xbox::ReleaseThumbR()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons &= ~BITThumbR;
}
void Xbox::ReleaseThumbL()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons &= ~BITThumbL;
}
void Xbox::ReleaseView()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons &= ~BITView;
}
void Xbox::ReleaseMenu()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons &= ~BITMenu;
}
void Xbox::ReleaseRight()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons &= ~BITRight;
}
void Xbox::ReleaseLeft()
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->wButtons &= ~BITLeft;
}


//Change Analog value
void Xbox::ChangeThumbLY(short value)
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->sThumbLY = value;
}
void Xbox::ChangeThumbLX(short value)
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->sThumbLX = value;
}
void Xbox::ChangeThumbRX(short value)
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->sThumbRX = value;
}
void Xbox::ChangeThumbRY(short value)
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->sThumbRY = value;
}
void Xbox::ChangeLeftTrigger(short value)
{
    std::lock_guard<std::mutex> lock(data_mutex);; //加锁
    p_xbox_state->bLeftTrigger = value;
}
void Xbox::ChangeRightTrigger(short value)
{
    p_xbox_state->bRightTrigger = value;
}


