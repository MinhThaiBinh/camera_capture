#include "../../JHCap2/JHCap.h"
#include "bmpfile.h"
#include <stdio.h>
#include <stdlib.h>

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


int save_gray_bmp(const char * filename, unsigned char * inBuf, int width, int height)
{
  bmpfile_t *bmp;
  rgb_pixel_t pixel = {0, 0, 0, 255};

  bmp = bmp_create(width, height, 24);
  // write image data
  int i=0, j=0;  
  for(i = 0; i < width; i++)  {  
    for( j = 0; j < height; j++)  {  
      int seq = j*width+i; 
      pixel.red = *(inBuf+seq); 
      pixel.green = *(inBuf+seq); 
      pixel.blue = *(inBuf+seq); 
      bmp_set_pixel(bmp, i, j, pixel);
    } 
  } 
  bmp_save(bmp, filename);
  bmp_destroy(bmp);

  return 0;
}


int main(int argc, char *argv[])
{
    if(argc<2) 
    {
	printf("Init a virtual camera to convert raw data to color image.\n");
	printf("Usage: virtual <camid> <seq>\n");
	printf("\tcamid is a integer, ex. 0x3C80 for JHUM800s\n");
	printf("\tseq is a save file sequence number, default 0\n");
	return -1;
    }

    int camid = strtol(argv[1], 0, 16);

    CameraInit(0);

    int width, height, len;
    CameraGetImageSize(0,&width, &height);
    CameraGetImageBufferSize(0,&len, CAMERA_IMAGE_RAW8);

    unsigned char *buffer = new unsigned char[len];
    if(!CameraQueryImage(0,buffer, &len, CAMERA_IMAGE_RAW8)==API_OK)
    {
        printf("CameraQueryImage error!");
    }
    save_gray_bmp("raw.bmp", buffer, width, height);

    CameraFree(0);

    //////////////////////////////////////////////////////////

    struct ISPParam param;
    param.gamma = 1.3;
    param.contrast = 1.0;
    param.saturation = 1.0;
    param.black = 14;
    param.red_gain = 1.81;
    param.green_gain = 1;
    param.blue_gain = 1.7;
    param.mirror_x = false;
    param.mirror_y = false;
    param.enhancement = false;

    int ret = CameraInitVirtual(5, camid, &param);
    printf("CameraInitVirtual %d\n", ret);
    int size;
    ret = CameraGetISPImageBufferSize(5,&size,width,height,CAMERA_IMAGE_BMP);
    printf("CameraGetISPImageBufferSize %d\n", ret);
    unsigned char *ISPbuf = new unsigned char[size];
    ret = CameraISP(5, buffer, ISPbuf, width, height, CAMERA_IMAGE_BMP);
    int err = 0;
    if(ret == API_ERROR)
    {
        CameraGetLastError(&err);
    }
    printf("CameraISP %d %d %d %d\n", ret, err, width, height);


    char filename[255];
    int seq = 0;
    if(argc>2) seq = atoi(argv[2]);
    sprintf(filename, "color%d.bmp", seq);
    save_bmp(filename, ISPbuf, width, height);

    delete[] ISPbuf;
    delete[] buffer;
}
