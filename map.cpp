#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <stack>
#include "allstruct.h"
#include "video.h"
#include "plotting.h"
#include "rotasi.h"
#include "drawing.h"
#include "clip.h"
#include <pthread.h>

using namespace std;

/* FUNCTIONS FOR SCANLINE ALGORITHM ---------------------------------------------------- */

bool isSlopeEqualsZero(int y0, int y1){
	if(y0 == y1){
		return true;
	}else{
		return false;
	}
}

bool isInBetween(int y0, int y1, int yTest){
	if((yTest >= y0 && yTest <= y1 || yTest >= y1 && yTest <= y0) && !isSlopeEqualsZero(y0, y1)){
		return true;
	}else{
		return false;
	}
}

/* Function to calculate intersection between line (a,b) and line with slope 0 */
Coord intersection(Coord a, Coord b, int y){
	int x;
	double slope;
	
	if(b.x == a.x){
		x = a.x;
	}else{
		slope = (double)(b.y - a.y) / (double)(b.x - a.x);
		x = round(((double)(y - a.y) / slope) + (double)a.x);
	}
	
	return coord(x, y);
}

bool compareByAxis(const s_coord &a, const s_coord &b){
	return a.x <= b.x;
}

bool compareSameAxis(const s_coord &a, const s_coord &b){
	return a.x == b.x;
}

bool operator==(const Coord& lhs, const Coord& rhs) {
	if(lhs.x==rhs.x && lhs.y==rhs.y)
		return true;
	return false;
}

bool isLocalMaxima(const Coord& a, const Coord& b, const Coord& titikPotong) {
	return ((titikPotong.y<a.y && titikPotong.y<b.y) || (titikPotong.y>a.y && titikPotong.y>b.y));
}

vector<Coord> intersectionGenerator(int y, vector<Coord> polygon){
	vector<Coord> intersectionPoint;
	Coord prevTipot = coord(-9999,-9999);
	for(int i = 0; i < polygon.size(); i++){
		if(i == polygon.size() - 1){
			if(isInBetween(polygon.at(i).y, polygon.at(0).y, y)){				
				Coord a = coord(polygon.at(i).x, polygon.at(i).y);
				Coord b = coord(polygon.at(0).x, polygon.at(0).y);
						
				Coord titikPotong = intersection(a, b, y);

				if(titikPotong==b){
					if(isLocalMaxima(polygon.at(i), polygon.at(1), titikPotong))
						intersectionPoint.push_back(titikPotong);
				}
				else {
					if(prevTipot==titikPotong){
						if(isLocalMaxima(polygon.at(i-1), polygon.at(0), titikPotong))
							intersectionPoint.push_back(titikPotong);
					}
					else
						intersectionPoint.push_back(titikPotong);
				}
			}
		}else{
			if(isInBetween(polygon.at(i).y, polygon.at(i + 1).y, y)){
				Coord a = coord(polygon.at(i).x, polygon.at(i).y);
				Coord b = coord(polygon.at(i + 1).x, polygon.at(i + 1).y);
				
				Coord titikPotong = intersection(a, b, y);

				// Jika sama dgn tipot sebelumnya, cek apakah local minima/maxima
				if(titikPotong==prevTipot) {
					Coord z = coord(polygon.at(i-1).x, polygon.at(i-1).y);
					if(isLocalMaxima(z, b, titikPotong)) {
						intersectionPoint.push_back(titikPotong);
					}
				}
				else {
					intersectionPoint.push_back(titikPotong);
				}
				prevTipot = intersectionPoint.back();
			}
		}
	}
	
	sort(intersectionPoint.begin(), intersectionPoint.end(), compareByAxis);
	
	return intersectionPoint;
}
vector<Coord> combineIntersection(vector<Coord> a, vector<Coord> b){
	for(int i = 0; i < b.size(); i++){
		a.push_back(b.at(i));
	}
	
	sort(a.begin(), a.end(), compareByAxis);
	
	return a;
}

void fillShape(Frame *frame, int xOffset, int yOffset, int startY, int shapeHeight, std::vector<Coord> shapeCoord, RGB color) {
	for(int i = startY; i <= shapeHeight; i++){
		vector<Coord> shapeIntersectionPoint = intersectionGenerator(i, shapeCoord);	
		for(int j = 0; j < shapeIntersectionPoint.size() - 1; j++){
			if(j % 2 == 0){
				int x0 = shapeIntersectionPoint.at(j).x + xOffset;
				int y0 = shapeIntersectionPoint.at(j).y + yOffset;
				int x1 = shapeIntersectionPoint.at(j + 1).x + xOffset;
				int y1 = shapeIntersectionPoint.at(j + 1).y + yOffset;
				
				plotLine(frame, x0, y0, x1, y1, color);
			}
		}		
	}
}

Coord lengthEndPoint(Coord startingPoint, int angle, int length){
	Coord endPoint;
	
	endPoint.x = int((double)length * cos((double)angle * PI / (double)180)) + startingPoint.x;
	endPoint.y = int((double)length * sin((double)angle * PI / (double)180)) + startingPoint.y;
	
	return endPoint;
}

//origin, pojok kiri atas viewPort
void viewPort(Frame *frame, Coord origin, int viewportSize, int windowSize, std::vector<Line> originalLines){
	// viewport frame
	plotLine(frame, origin.x, origin.y, origin.x + viewportSize, origin.y, rgb(255,255,255));
	plotLine(frame, origin.x, origin.y, origin.x, origin.y + viewportSize, rgb(255,255,255));
	plotLine(frame, origin.x, origin.y + viewportSize, origin.x + viewportSize, origin.y + viewportSize, rgb(255,255,255));
	plotLine(frame, origin.x + viewportSize, origin.y, origin.x + viewportSize, origin.y + viewportSize, rgb(255,255,255));
	
	// transform line, then draw
	std::vector<Line> transformedLines;
	for(int i = 0; i < originalLines.size(); i++){
		int startX = int((double)originalLines.at(i).start.x * (double)viewportSize / (double)windowSize) + origin.x;
		int startY = int((double)originalLines.at(i).start.y * (double)viewportSize / (double)windowSize) + origin.y;
		int endX = int((double)originalLines.at(i).end.x * (double)viewportSize / (double)windowSize) + origin.x;
		int endY = int((double)originalLines.at(i).end.y * (double)viewportSize / (double)windowSize) + origin.y;
		transformedLines.push_back(line(coord(startX, startY), coord(endX, endY)));
		plotLine(frame, transformedLines.at(i), rgb(50, 150, 0));
	}
}

void drawExplosion(Frame *frame, Coord loc, int mult, RGB color){	
	plotLine(frame,loc.x+10*mult,loc.y +10*mult,loc.x+20*mult,loc.y+20*mult,color);
	plotLine(frame,loc.x-10*mult,loc.y -10*mult,loc.x-20*mult,loc.y-20*mult,color);
	plotLine(frame,loc.x+10*mult,loc.y -10*mult,loc.x+20*mult,loc.y-20*mult,color);
	plotLine(frame,loc.x-10*mult,loc.y +10*mult,loc.x-20*mult,loc.y+20*mult,color);
	plotLine(frame,loc.x,loc.y -10*mult,loc.x,loc.y-20*mult,color);
	plotLine(frame,loc.x-10*mult,loc.y,loc.x-20*mult,loc.y,color);
	plotLine(frame,loc.x+10*mult,loc.y ,loc.x+20*mult,loc.y,color);
	plotLine(frame,loc.x,loc.y +10*mult,loc.x,loc.y+20*mult,color);
}

void animateExplosion(Frame* frame, int explosionMul, Coord loc){
	int explosionR, explosionG, explosionB;
	explosionR = explosionG = explosionB = 255-explosionMul*12;	
	if(explosionR <= 0 || explosionG <= 0 || explosionB <= 0){
		explosionR = explosionG = explosionB = 0;
	}
	drawExplosion(frame, loc, explosionMul, rgb(explosionR, 0, 0));
}

static struct termios old, new1;
void initTermios(int echo) {
    tcgetattr(0, &old); /* grab old terminal i/o settings */
    new1 = old; /* make new settings same as old settings */
    new1.c_lflag &= ~ICANON; /* disable buffered i/o */
    new1.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
    tcsetattr(0, TCSANOW, &new1); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) {
    tcsetattr(0, TCSANOW, &old);
}

/* GLOBALVAR DECLARATIONS ----------------------------------------------- */

int cameraX = 0;
int cameraY = 0;

int angleX = 0;
int angleY = 0;

int running = 1;

int leftClick = 0;

/* VIEW CONTROLLER: MOUSE AND KEYBOARD----------------------------------- */
void *threadFuncMouse(void *arg)
{
	FILE *fmouse;
    char b[3];
	fmouse = fopen("/dev/input/mice","r");
	
    while(1){
		fread(b,sizeof(char),3,fmouse);
		leftClick = (b[0]&1)>0;
	
		if(leftClick == 1){
			angleX = angleX - b[2] / mouseSensitivity;
			angleY = angleY + b[1] / mouseSensitivity;
		}else{
			cameraX = cameraX + b[1] / mouseSensitivity;
			cameraY = cameraY + b[2] / mouseSensitivity;
		}
    }
    fclose(fmouse);

	return NULL;
}

void *threadFuncKeyboard(void *arg)
{
	char c;
    initTermios(0);    
	
    while(1){
		read(0, &c, 1); 
		if(c == 97){
			angleY--;
		}
		
		if(c == 100){
			angleY++;
		}
		
		if(c == 119){
			angleX--;
		}
		
		if(c == 115){
			angleX++;
		}
		
    }

    resetTermios();
    
	return NULL;
}


/* MAIN FUNCTION ------------------------------------------------------- */
int main() {	
	/* Preparations ---------------------------------------------------- */
	
	// get fb and screenInfos
	struct fb_var_screeninfo vInfo; // variable screen info
	struct fb_fix_screeninfo sInfo; // static screen info
	int fbFile;	 // frame buffer file descriptor
	fbFile = open("/dev/fb0",O_RDWR);
	if (!fbFile) {
		printf("Error: cannot open framebuffer device.\n");
		exit(1);
	}
	if (ioctl (fbFile, FBIOGET_FSCREENINFO, &sInfo)) {
		printf("Error reading fixed information.\n");
		exit(2);
	}
	if (ioctl (fbFile, FBIOGET_VSCREENINFO, &vInfo)) {
		printf("Error reading variable information.\n");
		exit(3);
	}
	
	// create the FrameBuffer struct with its important infos.
	FrameBuffer fb;
	fb.smemLen = sInfo.smem_len;
	fb.lineLen = sInfo.line_length;
	fb.bpp = vInfo.bits_per_pixel;
	
	// and map the framebuffer to the FB struct.
	fb.ptr = (char*)mmap(0, sInfo.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, fbFile, 0);
	if ((long int)fb.ptr == -1) {
		printf ("Error: failed to map framebuffer device to memory.\n");
		exit(4);
	}
		
	// prepare environment controller
	unsigned char loop = 1; // frame loop controller
	Frame cFrame; // composition frame (Video RAM)
		
	pthread_t pth_mouse;
	pthread_create(&pth_mouse,NULL,threadFuncMouse,NULL);
	
	pthread_t pth_keyboard;
	pthread_create(&pth_keyboard,NULL,threadFuncKeyboard,NULL);
	
	int zoom = 400;
	
	while (loop) {
		
								
		// clean canvas
		flushFrame(&cFrame, rgb(0,0,0));
		
		// draw ITB's map
		//drawITB(&cFrame, coord3d(cameraX, cameraY, zoom), angleX, angleY, screenX, screenY, rgb(99,99,99));
		
		// create 3d block
		drawBlock(&cFrame, block(coord3d(50,50,50), 100, 100, 100), coord3d(cameraX, cameraY, zoom), angleX, angleY, screenX, screenY, rgb(99,99,99));
		drawBlock(&cFrame, block(coord3d(50,50,160), 100, 100, 100), coord3d(cameraX, cameraY, zoom), angleX, angleY, screenX, screenY, rgb(99,99,99));
		drawBlock(&cFrame, block(coord3d(160,50,50), 100, 100, 100), coord3d(cameraX, cameraY, zoom), angleX, angleY, screenX, screenY, rgb(99,99,99));
		
		drawBlock(&cFrame, block(coord3d(-150,50,50), 100, 100, 100), coord3d(cameraX, cameraY, zoom), angleX, angleY, screenX, screenY, rgb(99,99,99));
		drawBlock(&cFrame, block(coord3d(-150,50,160), 100, 100, 100), coord3d(cameraX, cameraY, zoom), angleX, angleY, screenX, screenY, rgb(99,99,99));
		drawBlock(&cFrame, block(coord3d(-260,50,50), 100, 100, 100), coord3d(cameraX, cameraY, zoom), angleX, angleY, screenX, screenY, rgb(99,99,99));
		
		//show frame
		showFrame(&cFrame,&fb);	
	}

	/* Cleanup --------------------------------------------------------- */
	int running= 0;
	
	pthread_join(pth_mouse,NULL);
	pthread_join(pth_keyboard,NULL);
	
	munmap(fb.ptr, sInfo.smem_len);
	close(fbFile);
	
	return 0;
}
