#ifndef XBOX_H
#define XBOX_H

#include <QObject>
#include <mutex>
#define BITE(n)         (1<<(15-n))

#define BITY                BITE(0)
#define BITX                BITE(1)
#define BITB                BITE(2)
#define BITA                BITE(3)
#define BITRB               BITE(6)
#define BITLB               BITE(7)
#define BITThumbR           BITE(8)
#define BITThumbL           BITE(9)
#define BITView             BITE(10)
#define BITMenu             BITE(11)
#define BITRight            BITE(12)
#define BITLeft             BITE(13)
#define BITDown             BITE(14)
#define BITUp               BITE(15)



typedef struct _XINPUT_GAMEPAD
{
    quint16                         wButtons;
    quint8                          bLeftTrigger;
    quint8                          bRightTrigger;
    qint16                          sThumbLX;
    qint16                          sThumbLY;
    qint16                          sThumbRX;
    qint16                          sThumbRY;
} XINPUT_GAMEPAD, *PXINPUT_GAMEPAD;

typedef struct _XINPUT_STATE
{
    quint32                       dwPacketNumber;
    XINPUT_GAMEPAD                      Gamepad;
} XINPUT_STATE, *PXINPUT_STATE;

class Xbox : public QObject
{
    Q_OBJECT
public:
    explicit Xbox(QObject *parent = nullptr);
    XINPUT_GAMEPAD &GetXboxState();
    PXINPUT_GAMEPAD &GetPXboxState();
    //press
    void SetY();
    void SetX();
    void SetB();
    void SetA();
    void SetRB();
    void SetLB();
    void SetThumbR();
    void SetThumbL();
    void SetView();
    void SetMenu();
    void SetRight();
    void SetLeft();
    void SetDown();
    void SetUp();

    //release
    void ReleaseY();
    void ReleaseX();
    void ReleaseB();
    void ReleaseA();
    void ReleaseRB();
    void ReleaseLB();
    void ReleaseThumbR();
    void ReleaseThumbL();
    void ReleaseView();
    void ReleaseMenu();
    void ReleaseRight();
    void ReleaseLeft();
    void ReleaseDown();
    void ReleaseUp();

    //Change Analog value
    void ChangeThumbLY(short value);
    void ChangeThumbLX(short value);
    void ChangeThumbRX(short value);
    void ChangeThumbRY(short value);
    void ChangeLeftTrigger(short value);
    void ChangeRightTrigger(short value);

private:
    XINPUT_GAMEPAD xbox_state;
    PXINPUT_GAMEPAD p_xbox_state;
    std::mutex data_mutex;

signals:

};

#endif // XBOX_H
