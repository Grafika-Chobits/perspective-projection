#include "rotasi.h"

int rotasiX(int xAwal,int yAwal,Coord loc,int sudut){
	return ((xAwal-loc.x)*cos(sudut)-(yAwal-loc.y)*sin(sudut)+loc.x);
}

int rotasiY(int xAwal,int yAwal,Coord loc,int sudut){
	return ((xAwal-loc.x)*sin(sudut)+(yAwal-loc.y)*cos(sudut)+loc.y);
}
