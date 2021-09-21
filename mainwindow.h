#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <qi/future.hpp>
#include <alcommon/alproxy.h>
#include <alerror/alerror.h>
#include <alproxies/altexttospeechproxy.h>
#include <alproxies/almotionproxy.h>

using namespace AL;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    int  port  =  9559 ;
    QString ip  =  "192.168.102.226" ;
    ALTextToSpeechProxy *tts;
    ALMotionProxy *motion;
    const AL::ALValue jointName = "HeadYaw";

public:
  qi::Future<int> Talk();
  qi::Future<int> MoveHead();

private:
  void doTalk(qi::Promise<int> promise);
  void doMoveHead(qi::Promise<int> promise);

};
#endif // MAINWINDOW_H
