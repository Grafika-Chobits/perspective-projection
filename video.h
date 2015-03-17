#ifndef VIDEO_H
#define VIDEO_H

#include "allstruct.h"

// construct RGB
RGB rgb(unsigned char r, unsigned char g, unsigned char b);

// insert pixel to composition frame, with bounds filter
void insertPixel(Frame* frm, Coord loc, RGB col);

// delete contents of composition frame
void flushFrame (Frame* frm, RGB color);

// copy composition Frame to FrameBuffer
void showFrame (Frame* frm, FrameBuffer* fb);

void showCanvas(Frame* frm, Frame* cnvs, int canvasWidth, int canvasHeight, Coord loc, RGB borderColor, int isBorder);

#endif
