#include "JHCap.h"
#include "capturethread.h"
#include "imageutil.h"

#include <QDebug>
#include <QtWidgets>

CaptureThread::CaptureThread(QObject *parent) :
    QThread(parent)
{
    work = false;
    term = false;
    index=0;

    for(int i = 0; i < 256; i++)
    {
       grayColourTable.append(qRgb(i, i, i));
    }
}

void CaptureThread::run()
{
    forever
    {
        int width, height, len;

        if(work)
        {

            CameraGetImageSize(index,&width, &height);
            CameraGetImageBufferSize(index,&len, CAMERA_IMAGE_RGB24);

            unsigned char *buffer = new unsigned char[len];
            if(CameraQueryImage(index,buffer, &len, CAMERA_IMAGE_RGB24)==API_OK)
            {
                if(term) break;

                //qDebug() << "got" <<QThread::currentThreadId();
               // QImage img(buffer, width, height, QImage::Format_Indexed8);
               // img.setColorTable(grayColourTable);

                QImage img(buffer, width, height, QImage::Format_RGB888);
                emit captured(img, buffer);
            }
            else
            {
                int error = 0;
                CameraGetLastError(&error);
                qDebug() << "error" << error<<QThread::currentThreadId();
                delete[] buffer;
                usleep(1000);

            }
        } else usleep(1000);
        if(term) break;
    }
}

void CaptureThread::stream()
{
    work = true;
}
void CaptureThread::setIndex(int index)
{
    this->index=index;
}

void CaptureThread::pause()
{
    work = false;
}

void CaptureThread::stop()
{
    work = false;
    term = true;
}
