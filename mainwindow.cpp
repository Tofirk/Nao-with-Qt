#include "mainwindow.h"
#include "./ui_mainwindow.h"

using namespace AL;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const QString phraseToSay = "Hello world";
    ip = ui->lineEdit_IP->text();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    Talk();

}


void MainWindow::on_pushButton_2_clicked()
{
    MoveHead();
}

qi::Future<int> MainWindow::Talk()
{
    qi::Promise<int> promise;
      qi::async(boost::bind(&MainWindow::doTalk, this, promise));
      return promise.future();
}

qi::Future<int> MainWindow::MoveHead()
{
    qi::Promise<int> promise;
      qi::async(boost::bind(&MainWindow::doMoveHead, this, promise));
      return promise.future();
}

void MainWindow::doTalk(qi::Promise<int> promise)
{
    try {

        tts = new ALTextToSpeechProxy(ip.toStdString().c_str(), port);
        tts->say(ui->lineEdit->text().toStdString().c_str());
        promise.setValue(1);
    }  catch (ALError e) {
        promise.setValue(0);
    }

}

void MainWindow::doMoveHead(qi::Promise<int> promise)
{
    try {

        motion = new ALMotionProxy(ip.toStdString().c_str(), port);
        ALValue stiffness = 1.0f;
            /** Time (in seconds) to reach the target. */
        ALValue time = 1.0f;
            /** Call the stiffness interpolation method. */
        motion->stiffnessInterpolation(jointName, stiffness, time);

            /** Set the target angle list, in radians. */
        ALValue targetAngles = AL::ALValue::array(-1.5f, 1.5f, 0.0f);
            /** Set the corresponding time lists, in seconds. */
        ALValue targetTimes = AL::ALValue::array(3.0f, 6.0f, 9.0f);
            /** Specify that the desired angles are absolute. */
        bool isAbsolute = true;

            /** Call the angle interpolation method. The joint will reach the
            * desired angles at the desired times.
            */
        motion->angleInterpolation(jointName, targetAngles, targetTimes, isAbsolute);

            /** Remove the stiffness on the head. */
            stiffness = 0.0f;
            time = 1.0f;
        motion->stiffnessInterpolation(jointName, stiffness, time);
        promise.setValue(1);
    }  catch (ALError e) {
        promise.setValue(0);
    }
}

