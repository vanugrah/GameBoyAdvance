#include "myLib.h"
#include "font.h"

unsigned short *videoBuffer = (unsigned short *)0x6000000;


void setPixel(int row, int col, u16 color)
{
	videoBuffer[OFFSET(row, col, 240)] = color;
}

void drawRect(int row, int col, int height, int width, u16 color)
{
	for(int r=0; r<height; r++)
	{
		for(int c=0; c<width; c++)
		{
			setPixel(row+r, col+c, color);
		}
	}
}


int boundsCheck(int *var, int bound, int *delta, int size)
{
		if(*var < 0)
		{
			*var = 0;
			*delta = -*delta;
			return 1;
		}
		if(*var > bound-size+1)
		{
			*var = bound-size+1;
			*delta = -*delta;
		}
		return 0;

}

void WaitForVblank()
{
	while(SCANLINECOUNTER > 160);
	while(SCANLINECOUNTER < 160);
}

void drawImage3(int r, int c, int height, int width, const u16* image)
{
	for (int x = 0; x < height; x++) {
		DMA[3].src = &image[OFFSET(x, 0, width)];
		DMA[3].dst = &videoBuffer[OFFSET(r + x, c, 240)];
		DMA[3].cnt = (width) | DMA_ON;
	}
}

void drawRect3(int r, int c, int width, int height, u16 color) {
	for (int x = 0; x < height; x++) {
		DMA[3].src = &color;
		DMA[3].dst = &videoBuffer[OFFSET(r + x, c, 240)];
		DMA[3].cnt = (width) | DMA_SOURCE_FIXED | DMA_ON;
	}
}

void waitForOneSecond()
{
	int counter = 0;

	while (counter < 1) {
		WaitForVblank();
		counter++;
	}

}

void wait(int seconds)
{
	for (int i = 0; i < seconds; ++i)
	{
		waitForOneSecond();
	}
}




