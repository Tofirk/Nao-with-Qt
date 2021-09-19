#include "mainwindow.h"
#include "./ui_mainwindow.h"

using namespace AL;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const QString phraseToSay = "Hello world";
    ui->lineEdit->setText(phraseToSay.toStdString().c_str());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    const std::string phraseToSay = "It's Ok now.... !";
    ui->lineEdit->setText(phraseToSay.c_str());
    //motion = new ALMotionProxy("127.0.0.1", 9559);
    //tts = new ALTextToSpeechProxy("127.0.0.1",port);
    try {
        tts = new ALTextToSpeechProxy(ip.toStdString().c_str(),port);
        tts->say(phraseToSay);
    }  catch (ALError e) {

    }

}

