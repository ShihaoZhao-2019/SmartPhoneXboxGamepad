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
    // 公有静态成员函数，返回唯一实例
    static Xbox* getInstance();

    XINPUT_STATE &GetXboxState();
    PXINPUT_STATE &GetPXboxState();
    //press
    Q_INVOKABLE void SetY();
    Q_INVOKABLE void SetX();
    Q_INVOKABLE void SetB();
    Q_INVOKABLE void SetA();
    Q_INVOKABLE void SetRB();
    Q_INVOKABLE void SetLB();
    Q_INVOKABLE void SetThumbR();
    Q_INVOKABLE void SetThumbL();
    Q_INVOKABLE void SetView();
    Q_INVOKABLE void SetMenu();
    Q_INVOKABLE void SetRight();
    Q_INVOKABLE void SetLeft();
    Q_INVOKABLE void SetDown();
    Q_INVOKABLE void SetUp();

    //release
    Q_INVOKABLE void ReleaseY();
    Q_INVOKABLE void ReleaseX();
    Q_INVOKABLE void ReleaseB();
    Q_INVOKABLE void ReleaseA();
    Q_INVOKABLE void ReleaseRB();
    Q_INVOKABLE void ReleaseLB();
    Q_INVOKABLE void ReleaseThumbR();
    Q_INVOKABLE void ReleaseThumbL();
    Q_INVOKABLE void ReleaseView();
    Q_INVOKABLE void ReleaseMenu();
    Q_INVOKABLE void ReleaseRight();
    Q_INVOKABLE void ReleaseLeft();
    Q_INVOKABLE void ReleaseDown();
    Q_INVOKABLE void ReleaseUp();

    //Change Analog value
    Q_INVOKABLE void ChangeThumbLY(short value);
    Q_INVOKABLE void ChangeThumbLX(short value);
    Q_INVOKABLE void ChangeThumbRX(short value);
    Q_INVOKABLE void ChangeThumbRY(short value);
    Q_INVOKABLE void ChangeLeftTrigger(unsigned char value);
    Q_INVOKABLE void ChangeRightTrigger(unsigned char value);

private:
    // 私有构造函数，保证外界无法直接实例化
    explicit Xbox(QObject *parent = nullptr);
private:
    // 私有静态变量，保存唯一实例
    static Xbox *instance;
    XINPUT_STATE xbox_state;
    PXINPUT_STATE p_xbox_state;


    std::mutex data_mutex;


};

#endif // XBOX_H
