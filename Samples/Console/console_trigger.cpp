// Console.cpp : Console demo for linux

#include "../../JHCap2/JHCap.h"
#include "bmpfile.h"

#include <stdio.h>
#include <unistd.h>


int save_bmp(char * filename, unsigned char * inBuf, int width, int height)
{
  bmpfile_t *bmp;
  rgb_pixel_t pixel = {0, 0, 0, 255};

  bmp = bmp_create(width, height, 24);
  // write image data
  int i=0, j=0;  
  for(i = 0; i < width; i++)  {  
    for( j = 0; j < height; j++)  {  
      int seq = j*width+i;
      pixel.red = *(inBuf+3*seq+2);  
      pixel.green = *(inBuf+3*seq+1);  
      pixel.blue = *(inBuf+3*seq);  
      bmp_set_pixel(bmp, i, j, pixel);
    } 
  } 
  bmp_save(bmp, filename);
  bmp_destroy(bmp);

  return 0;
}

int main(void)
{
	char filename[255];

	int count=0;

	CameraGetCount(&count);
	printf("Camera count: %d\n", count);

        if(count<1) return 0;

	CameraInit(0);
	CameraSetGain(0, 32);
	CameraSetExposure(0, 1000);

	CameraSetSnapMode(0, CAMERA_SNAP_CONTINUATION);
	CameraSetSnapMode(0, CAMERA_SNAP_TRIGGER);


	int width=0, height=0, len=0;
	CameraGetImageSize(0,&width, &height);
	CameraGetImageBufferSize(0,&len, CAMERA_IMAGE_BMP);
	unsigned char *imageBuf = new unsigned char[len];

	int i=0;
	while(true)
	{
		CameraTriggerShot(0);
		if(CameraQueryImage(0,imageBuf, &len,
			CAMERA_IMAGE_BMP)==API_OK)
		{
			sprintf(filename, "a%d.bmp", i);
			save_bmp(filename, imageBuf, width, height);
			printf("GRABING DONE %s\n", filename);
			i++;
			if(i==100) break;
		}
		else
		{
			int error = 0;

			CameraGetLastError(&error);

			printf("GRABING ERROR %d\n", error);

			usleep(100);
		}
	}
	CameraFree(0);

	return 0;
}

