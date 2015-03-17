#ifndef PLOTTING_H
#define PLOTTING_H

//Segala hal tentang plotting

#include <cmath>
#include <stdio.h>
#include "allstruct.h"
#include "video.h"

using namespace std;
void plotCircle(Frame* frm,int xm, int ym, int r,RGB col);

void plotHalfCircle(Frame *frm,int xm, int ym, int r,RGB col);

/* Fungsi membuat garis */
void plotLine(Frame* frm, int x0, int y0, int x1, int y1, RGB lineColor);
void plotLine(Frame *frm, Line line, RGB lineColor);
void plotLineWidth(Frame* frm, int x0, int y0, int x1, int y1, float wd, RGB lineColor);

#endif
