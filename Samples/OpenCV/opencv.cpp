// opencv.cpp : OpenCV demo for linux
//

#include "../../JHCap2/JHCap.h"

#include <opencv2/opencv.hpp>

#include <stdio.h>
#include <unistd.h>

#include <time.h>


int main(void)
{
    int count=0;

    CameraGetCount(&count);
    printf("Camera count: %d\n", count);

    if(count<1) return 0;

    CameraInit(0);
    CameraSetGain(0, 32);
    CameraSetExposure(0, 1000);

    CameraSetSnapMode(0, CAMERA_SNAP_CONTINUATION);
    //CameraSetSnapMode(0, CAMERA_SNAP_TRIGGER);

    int width=376, height=240, len=0;
    CameraSetResolution(0, 0, 0, 0);
    CameraGetResolution(0, 0, &width, &height);
    //CameraSetROI(0, 0, 0, width, height);
    CameraGetImageBufferSize(0, &len, CAMERA_IMAGE_BMP);

    IplImage *image = cvCreateImage(cvSize(width, height), 8, 3);
    cvNamedWindow("Hello OpenCV");

    while(true)
    {
        if(CameraQueryImage(0,(unsigned char*)image->imageData, &len,
                            CAMERA_IMAGE_BMP/* |CAMERA_IMAGE_TRIG*/)==API_OK)
        {
            struct timespec *t;
            t = (struct timespec *)malloc(sizeof(t));
            clock_gettime(CLOCK_MONOTONIC, t);
            printf("%ld\n", t->tv_nsec);
            free(t);


            //cvErode(image, image, 0, 2);

            cvShowImage("Hello OpenCV", image);
        }
        else
        {
            usleep(100);
        }

        unsigned char key = cvWaitKey(1);
        if(key==27) break;
    }
    cvReleaseImage(&image);
    cvDestroyWindow("Hello OpenCV");
    CameraFree(0);

    return 0;
}

