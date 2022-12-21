#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <Transfer/TaskControl.h>
#include <iostream>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/SmartPhoneXboxGamepad_client/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    TaskControl *main_task = new TaskControl();
    engine.load(url);
    engine.rootContext()->setContextProperty("xBoxState",main_task->GetTcpXboxDevice().get());
//    Xbox *p = Xbox::getInstance();
//    p->SetY();


//    auto t = new TransTCP();
//    auto p = new TransUDP();
//    p->SetTCPPort(LOCAL_TCP_PORT);
//    qDebug() << p->GetLocalHostInt() << Qt::endl;
//    qDebug() << p->GetTCPPort()<< Qt::endl ;
//    qDebug() << "my address have send by udp,send len is" << p->Send() <<"ip:" << p->GetLocalHostInt() << "port" << p->GetTCPPort() << Qt::endl;


    return app.exec();


//    qDebug()<<ip_address;
//       return ip_address'

}
