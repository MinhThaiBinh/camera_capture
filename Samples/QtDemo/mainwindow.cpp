#include "JHCap.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iocontrol.h"

#include <QDebug>
#include <QImage>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),  m_scene(0), m_image_item(0)
{
    ui->setupUi(this);
    m_scene = new QGraphicsScene(this);
    ui->gvMain->setScene(m_scene);
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateFps()));
    m_timer->start(1000);
    m_index=0;
    for(int i=0; i<TN; i++)
    {
        m_thread[i] = new CaptureThread(this);
        //start task thread
        connect(m_thread[i], SIGNAL(captured(QImage, unsigned char *)),
                this, SLOT(process(QImage, unsigned char *)));
        m_thread[i]->start();
    }
    m_LabelFps = new QLabel(this);
    m_LabelFps->setAlignment(Qt::AlignHCenter);
    ui->statusBar->addWidget(m_LabelFps);
    m_totalFrame = 0;
    m_fps = 0;

    int count;
    CameraGetCount(&count);
    for(int i=0; i<count; i++)
    {
        char name[255], model[255];
        CameraGetName(i, name, model);
        ui->cmbDevice->addItem(QString("%1").arg(model));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent * e)
{
    for(int i=0; i<TN; i++)
    {
        m_thread[i]->stop();
    }

    CameraFree(m_index);

    for(int i=0; i<TN; i++)
    {
        m_thread[i]->wait();
    }

    QMainWindow::closeEvent(e);
}

void MainWindow::updateFps()
{
    if(m_fps == 0) m_fps = m_totalFrame;
    else m_fps = 0.4*m_fps + 0.6*m_totalFrame;

    m_totalFrame = 0;

    m_LabelFps->setText(QString("fps: %1").arg(QString::number(m_fps, 'f', 2)));
}

void MainWindow::process(QImage img, unsigned char *buffer)
{
    if(m_image_item)
    {
        m_image_item->setPixmap(QPixmap::fromImage(img));
    }
    else
    {
        m_image_item = m_scene->addPixmap(QPixmap::fromImage(img));
    }

    m_scene->setSceneRect(0, 0, img.width(), img.height());
  //  QTime time;
   // qDebug()<<time.currentTime();

    delete buffer;
    m_totalFrame++;
}

//////////////////////////////////////////
//// UI
/////////////////////////
void MainWindow::zoomIn()
{
    ui->gvMain->scale(1.2, 1.2);
}

void MainWindow::zoomOut()
{
    ui->gvMain->scale(1/1.2, 1/1.2);
}

void MainWindow::resetView()
{
    ui->gvMain->resetTransform ();
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_btnZoomIn_clicked()
{
    zoomIn();
}

void MainWindow::on_btnZoomOut_clicked()
{
    zoomOut();
}

void MainWindow::on_btnResetView_clicked()
{
    resetView();
}


void MainWindow::on_btnStart_clicked()
{
    for(int i=0; i<TN; i++)
        m_thread[i]->stream();
}

void MainWindow::on_btnStop_clicked()
{
    for(int i=0; i<TN; i++)
        m_thread[i]->pause();
}

void MainWindow::initParam()
{
    double gamma;
    CameraGetGamma(m_index,&gamma);
    ui->lblGamm->setText(QString("%1").arg(gamma));
    ui->hsGamma->setValue(gamma*100);

    double contrast;
    CameraGetContrast(m_index,&contrast);
    ui->lblContrast->setText(QString("%1").arg(contrast));
    ui->hsContrast->setValue(contrast*100);

    bool aec,agc;
    CameraGetAGC(m_index,&agc);
    CameraGetAEC(m_index,&aec);

    if(agc)
    {
        ui->hsGain->setEnabled(false);
        ui->cbGain->setChecked(true);
    }
    else
    {
        int gain;
        CameraGetGain(m_index,&gain);
        ui->lblGain->setText(QString("%1").arg(gain));
        ui->hsGain->setValue(gain);
        ui->hsGain->setEnabled(true);
        ui->cbExposure->setChecked(true);
        ui->cbGain->setChecked(false);
    }


    if(aec)
    {
        ui->hsExposure->setEnabled(false);
        ui->cbExposure->setChecked(true);
    }
    else
    {
        int exposure;
        CameraGetExposure(m_index,&exposure);
        ui->lblExposure->setText(QString("%1").arg(exposure));
        ui->hsExposure->setValue(exposure);
        ui->hsExposure->setEnabled(true);
        ui->cbExposure->setChecked(false);
    }
}

void MainWindow::on_cmbDevice_currentIndexChanged(int index)
{
    m_index=index;
    for(int i=0; i<TN; i++)
        m_thread[i]->pause();
    CameraFree(m_index);
    CameraInit(index);
    for(int i=0; i<TN; i++)
        m_thread[i]->setIndex(m_index);
    initParam();

    int c = ui->cmbResolution->count();

    for(int i=0; i<c; i++)
    {
        ui->cmbResolution->removeItem(0);
    }

    int count;
    CameraGetResolutionCount(m_index,&count);

    for(int i=0; i<count; i++)
    {
        int width, height;
        CameraGetResolution(m_index,i, &width, &height);

        ui->cmbResolution->addItem(QString("%1x%2").arg(width).arg(height));
    }
}

void MainWindow::on_cmbResolution_currentIndexChanged(int index)
{
    for(int i=0; i<TN; i++)
        m_thread[i]->pause();
    CameraSetResolution(m_index,index, 0, 0);
    for(int i=0; i<TN; i++)
        m_thread[i]->stream();
}


void MainWindow::on_hsGamma_valueChanged(int value)
{
    double gamma = value / 100.0;
    CameraSetGamma(m_index,gamma);

    ui->lblGamm->setText(QString("%1").arg(gamma));
}

void MainWindow::on_hsContrast_valueChanged(int value)
{
    double contrast = value / 100.0;
    CameraSetContrast(m_index,contrast);

    ui->lblContrast->setText(QString("%1").arg(contrast));
}


void MainWindow::on_hsGain_valueChanged(int value)
{
    CameraSetGain(m_index,value);
    ui->lblGain->setText(QString("%1").arg(value));
}

void MainWindow::on_hsExposure_valueChanged(int value)
{
    CameraSetExposure(m_index,value);
    ui->lblExposure->setText(QString("%1").arg(value));
}

void MainWindow::on_btnROI_clicked()
{
    int height_offset = ui->leRowStart->text().toInt();
    int width_offset = ui->leColumnStart->text().toInt();
    int width = ui->leWidth->text().toInt();
    int height = ui->leHeight->text().toInt();
    CameraSetROI(m_index,width_offset, height_offset, width, height);
//    char i[255],j[255];
//    CameraGetName(0,i,j);
//    qDebug()<<"i="<<i;
//    qDebug()<<"j="<<j;
}

void MainWindow::on_cbGain_toggled(bool checked)
{
    CameraSetAGC(m_index,checked);
    initParam();
}

void MainWindow::on_cbHFlip_clicked()
{
    if(ui->cbHFlip->checkState())
        CameraSetMirrorX(m_index,true);
    else
        CameraSetMirrorX(m_index,false);
}

void MainWindow::on_cbVFlip_clicked()
{
    if(ui->cbVFlip->checkState())
        CameraSetMirrorY(m_index,true);
    else
        CameraSetMirrorY(m_index,false);

}

void MainWindow::on_rbGroup0_clicked()
{
    CameraLoadParameter(m_index,0);
    initParam();
}

void MainWindow::on_rbGroup1_clicked()
{
    CameraLoadParameter(m_index,1);
    initParam();
}

void MainWindow::on_btnSaveParameter_clicked()
{
     CameraSaveParameter(m_index,ui->rbGroup0->isChecked()?0:1);
}



void MainWindow::on_btnWB_clicked()
{
    CameraOnePushWB(m_index);
}

void MainWindow::on_actionIO_Controller_triggered()
{
    IOControl *iocontrol = new IOControl(this);
    iocontrol->show();
}

void MainWindow::on_btnIOControl_clicked()
{
    IOControl *iocontrol = new IOControl(this);
    iocontrol->show();
}

void MainWindow::on_cbExposure_clicked(bool checked)
{
    CameraSetAEC(m_index,checked);
    initParam();
}
