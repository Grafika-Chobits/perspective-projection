#ifndef DRAWING_H
#define DRAWING_H

#include "rotasi.h"
#include "plotting.h"
#include "allstruct.h"
#include "clip3d.h"
#include <vector>
#include <unistd.h>
#include <stdio.h>

std::vector<Line> drawPeta(Frame *frame, Coord center, RGB color);
std::vector<Line> drawKapal(Frame *frm, Coord loc, RGB color);
std::vector<Line> drawKapalVertikal(Frame *frm,Coord loc,RGB color);
std::vector<Line> drawBaling(Frame *frm , Coord loc,int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4 ,RGB color);
std::vector<Line> rotateBaling(Frame *frm,Coord loc, RGB col ,int counter );

void drawSquare (Frame *frm, Coord kiriAtas, Coord KananBawah, RGB color);
void drawFreeSquare(Frame *frm, Coord kiriAtas, Coord kananAtas, Coord kiriBawah, Coord kananBawah, RGB color);

void drawSquare(Frame *frm, Coord kiriAtas, Coord KananBawah, RGB color);
void drawBlock(Frame *frm, Block block, Coord3d cameraPosition, int angleX, int angleY, int screenWidth, int screenHeight, RGB color);

void drawITB(Frame *frm, Coord3d cameraPosition, int angleX, int angleY, int screenWidth, int screenHeight, RGB color);

#endif
