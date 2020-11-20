#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMediaPlayer * music = new QMediaPlayer(this); //初始化音乐
    QMediaPlaylist * list = new QMediaPlaylist(this); //初始化音乐列表
    list->setPlaybackMode(QMediaPlaylist::Loop);//设置播放模式(顺序播放，单曲循环，随机播放等)
    //list->addMedia();//添加歌曲
    list->addMedia(QUrl("qrc:/songs/Music/K歌之王"));
    music->setVolume(200);
    music->setPlaylist(list);  //设置播放列表
    music->play();//播放歌曲


}

MainWindow::~MainWindow()
{
    delete ui;
}
