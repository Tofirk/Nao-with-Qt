#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
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

private:
    Ui::MainWindow *ui;
    int  port  =  9559 ;
    QString ip  =  "127.0.0.1" ;
    ALTextToSpeechProxy *tts;
    //ALMotionProxy *motion;
    //const AL::ALValue jointName = "HeadYaw";

};
#endif // MAINWINDOW_H
