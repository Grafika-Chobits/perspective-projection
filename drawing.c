#include "drawing.h"

void drawSquare (Frame *frm, Coord kiriAtas, Coord kananBawah, RGB color)
{
	//atas
	plotLine(frm, kiriAtas.x, kiriAtas.y, kananBawah.x, kiriAtas.y, color);
	//kanan
	plotLine(frm, kananBawah.x, kiriAtas.y, kananBawah.x, kananBawah.y, color);
	//kiri
	plotLine(frm, kiriAtas.x, kiriAtas.y, kiriAtas.x, kananBawah.y, color);
	//bawah
	plotLine(frm, kiriAtas.x, kananBawah.y, kananBawah.x, kananBawah.y, color);
}

void drawFreeSquare(Frame *frm, Coord kiriAtas, Coord kananAtas, Coord kiriBawah, Coord kananBawah, RGB color)
{
	plotLine(frm, kiriAtas.x, kiriAtas.y, kananAtas.x, kananAtas.y, color);
	plotLine(frm, kananAtas.x, kananAtas.y, kananBawah.x, kananBawah.y, color);
	plotLine(frm, kananBawah.x, kananBawah.y, kiriBawah.x, kiriBawah.y, color);
	plotLine(frm, kiriAtas.x, kiriAtas.y, kiriBawah.x, kiriBawah.y, color);
}

std::vector<Line> drawKapal(Frame *frm, Coord loc, RGB color){
	plotLine(frm,loc.x-15,loc.y-10,loc.x+15,loc.y-10,color);
	plotLine(frm,loc.x-15,loc.y+10,loc.x+15,loc.y+10,color);
	plotLine(frm,loc.x-15,loc.y-10,loc.x-20,loc.y,color);
	plotLine(frm,loc.x+15,loc.y-10,loc.x+20,loc.y,color); 	
	plotLine(frm,loc.x-15,loc.y+10,loc.x-20,loc.y,color);
	plotLine(frm,loc.x+15,loc.y+10,loc.x+20,loc.y,color);
	std::vector<Line> kapalLine;
	kapalLine.push_back(line(coord(loc.x-15,loc.y-10),coord(loc.x+15,loc.y-10)));
	kapalLine.push_back(line(coord(loc.x-15,loc.y+10),coord(loc.x+15,loc.y+10)));
	kapalLine.push_back(line(coord(loc.x-15,loc.y-10),coord(loc.x-20,loc.y)));
	kapalLine.push_back(line(coord(loc.x+15,loc.y-10),coord(loc.x+20,loc.y)));
	kapalLine.push_back(line(coord(loc.x-15,loc.y+10),coord(loc.x-20,loc.y)));
	kapalLine.push_back(line(coord(loc.x+15,loc.y+10),coord(loc.x+20,loc.y)));
	return kapalLine;
	}
	
std::vector<Line> drawKapalVertikal (Frame *frm, Coord loc, RGB color){
	plotLine(frm,loc.x-10,loc.y-15,loc.x-10,loc.y+15,color);
	plotLine(frm,loc.x+10,loc.y-15,loc.x+10,loc.y+15,color);
	plotLine(frm,loc.x,loc.y-20,loc.x-10,loc.y-15,color);
	plotLine(frm,loc.x,loc.y-20,loc.x+10,loc.y-15,color); 	
	plotLine(frm,loc.x,loc.y+20,loc.x-10,loc.y+15,color);
	plotLine(frm,loc.x,loc.y+20,loc.x+10,loc.y+15,color);
	std::vector<Line> kapalLine;
	kapalLine.push_back(line(coord(loc.x-10,loc.y-15),coord(loc.x-10,loc.y+15)));
	kapalLine.push_back(line(coord(loc.x+10,loc.y-15),coord(loc.x+10,loc.y+15)));
	kapalLine.push_back(line(coord(loc.x,loc.y-20),coord(loc.x-10,loc.y-15)));
	kapalLine.push_back(line(coord(loc.x,loc.y-20),coord(loc.x+10,loc.y-15)));
	kapalLine.push_back(line(coord(loc.x,loc.y+20),coord(loc.x-10,loc.y+15)));
	kapalLine.push_back(line(coord(loc.x,loc.y+20),coord(loc.x+10,loc.y+15)));
	return kapalLine;	
	}
	
std::vector<Line> drawPeta(Frame *frame, Coord center, RGB color) {
	std::vector<Line> sumatera;
	Coord offset = coord(30, 10);
	sumatera.push_back(line(offset, coord(offset.x+20, offset.y+20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())+10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+15, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+10, EndY(sumatera.back())+20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+5, EndY(sumatera.back())+20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+5, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())+10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+15, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+5, EndY(sumatera.back())+30)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+45, EndY(sumatera.back())+20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+35, EndY(sumatera.back())+30)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back()), EndY(sumatera.back())+5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+3, EndY(sumatera.back())+8)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+5, EndY(sumatera.back())+5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+10, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+10, EndY(sumatera.back())+5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+10, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())+20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-3, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())+5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-20, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())-5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-15, EndY(sumatera.back())-5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())-5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-20, EndY(sumatera.back())-5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-15, EndY(sumatera.back())-8)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+5, EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+3, EndY(sumatera.back())-20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-25)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back()), EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back()), EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-15, EndY(sumatera.back())-20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-15, EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+10, EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back()), EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+8, EndY(sumatera.back())-20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back()), EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+3, EndY(sumatera.back())-7)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back()), EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), offset));

	std::vector<Line> jawa;
	Coord offsetJawa = coord(offset.x+180, offset.y+350);
	jawa.push_back(line(offsetJawa, coord(offsetJawa.x+15, offsetJawa.y-10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+15, EndY(jawa.back())+10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+25, EndY(jawa.back())+5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back()))));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+15, EndY(jawa.back())+10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+20, EndY(jawa.back())+8)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+8, EndY(jawa.back())-2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+15, EndY(jawa.back())+7)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+15, EndY(jawa.back()))));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())-3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+15, EndY(jawa.back())-5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())-1)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())+3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+8, EndY(jawa.back())+6)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())+3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())+8)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+20, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())+3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+30, EndY(jawa.back())-3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())-5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())-7)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())-4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+3, EndY(jawa.back()))));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+15, EndY(jawa.back())+4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())+10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+3, EndY(jawa.back())+15)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+2, EndY(jawa.back())+10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-5, EndY(jawa.back())+15)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+3, EndY(jawa.back())+4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+6, EndY(jawa.back())+5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+4, EndY(jawa.back())+4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())+4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-5, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-25, EndY(jawa.back())+4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-15, EndY(jawa.back())-3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-10, EndY(jawa.back())-6)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-15, EndY(jawa.back())+5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-25, EndY(jawa.back())-10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-45, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-35, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-40, EndY(jawa.back())-3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-20, EndY(jawa.back())-5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-15, EndY(jawa.back())-3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-25, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-20, EndY(jawa.back())-10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-15, EndY(jawa.back())-15)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-10, EndY(jawa.back())+3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-8, EndY(jawa.back())-5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-25, EndY(jawa.back())-15)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-20, EndY(jawa.back())-10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-5, EndY(jawa.back()))));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-15, EndY(jawa.back())-8)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-3, EndY(jawa.back())-5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())-4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())-3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back()), EndY(jawa.back())-2)));
	jawa.push_back(line(End(jawa.back()), offsetJawa));

	std::vector<Line> kalimantan;
	Coord offsetKalimantan = coord(offset.x+230, offset.y+150);
	kalimantan.push_back(line(offsetKalimantan, coord(offsetKalimantan.x+5, offsetKalimantan.y-5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())+8)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())+5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())+8)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())-1)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+5, EndY(kalimantan.back())+3)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())-5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())-3)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())-2)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())-6)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())-3)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())+1)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())+2)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+8, EndY(kalimantan.back())-15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())-15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())-20)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+5, EndY(kalimantan.back())-15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+5, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+6, EndY(kalimantan.back())-3)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+6, EndY(kalimantan.back())-5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+4, EndY(kalimantan.back())-5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+4, EndY(kalimantan.back())+3)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+3, EndY(kalimantan.back())+8)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+5, EndY(kalimantan.back())+35)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-4, EndY(kalimantan.back())+20)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-2, EndY(kalimantan.back())+20)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-8, EndY(kalimantan.back())+10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-1, EndY(kalimantan.back())+5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+3, EndY(kalimantan.back())+5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-1, EndY(kalimantan.back())+5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-5, EndY(kalimantan.back())+15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-10, EndY(kalimantan.back())+8)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-+2, EndY(kalimantan.back())+5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-5, EndY(kalimantan.back())+15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-10, EndY(kalimantan.back())+25)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+3, EndY(kalimantan.back())+25)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-1, EndY(kalimantan.back())+15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-3, EndY(kalimantan.back())+15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-20, EndY(kalimantan.back())+15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-15, EndY(kalimantan.back())+10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-25, EndY(kalimantan.back())+3)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-10, EndY(kalimantan.back())-2)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-7, EndY(kalimantan.back())-5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-5, EndY(kalimantan.back())+1)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-5, EndY(kalimantan.back())+2)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-25, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-30, EndY(kalimantan.back())-25)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-15, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-5, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-5, EndY(kalimantan.back())-5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-7, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-10, EndY(kalimantan.back())-15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+2, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-3, EndY(kalimantan.back())-25)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-10, EndY(kalimantan.back())-15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-10, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+7, EndY(kalimantan.back())-7)));
	kalimantan.push_back(line(End(kalimantan.back()), offsetKalimantan));


	std::vector<Line> sulawesi;
	Coord offsetSulawesi = coord(offset.x+520, offset.y+170);
	sulawesi.push_back(line(offsetSulawesi, coord(offsetSulawesi.x+2, offsetSulawesi.y-15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+4, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+8, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+10, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+15, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+15, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+20, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+30, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+25, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+10, EndY(sulawesi.back())-5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-6)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+4, EndY(sulawesi.back())-5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+7, EndY(sulawesi.back())-8)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+7, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+7, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-9, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-9, EndY(sulawesi.back())+15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())+4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-15, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-15, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-15, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-25, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-8, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-15, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-6, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-2, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+1, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-2, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+10, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+8, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+15, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+10, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+8, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+9, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+8, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+7, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+15, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+7, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+10, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+3, EndY(sulawesi.back())+4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+6, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+3, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-4, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-4, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-6, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-7, EndY(sulawesi.back())+4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-4, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-4, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-11, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-6, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-4, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())+8)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-4, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-7, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+3, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+18, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+8, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+15, EndY(sulawesi.back())+20)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-2, EndY(sulawesi.back())+7)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+1, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+8, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+20, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+1, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-20, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-25, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())-5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-6, EndY(sulawesi.back())-8)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-7, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-2, EndY(sulawesi.back())+15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+20)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+3, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+4, EndY(sulawesi.back())+15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-2, EndY(sulawesi.back())+20)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())+4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())-7)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+2, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-20)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())-15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-8, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())-8)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+1, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+2, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-1, EndY(sulawesi.back())-15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-2, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+4, EndY(sulawesi.back())-15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+3, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+2, EndY(sulawesi.back())-7)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-8)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+2, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), offsetSulawesi));

	std::vector<Line> papua;
	Coord offsetPapua = coord(offset.x+900, offset.y+170);
	papua.push_back(line(offsetPapua, coord(offsetPapua.x+5, offsetPapua.y-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())+2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())-6)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+5, EndY(papua.back())+2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+8, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())+7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+3, EndY(papua.back())+5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+3, EndY(papua.back())+7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+1, EndY(papua.back())+7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-3, EndY(papua.back())+7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+1, EndY(papua.back())+5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+5, EndY(papua.back())+11)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())+10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+5, EndY(papua.back())+7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+7, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+4, EndY(papua.back())+8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+8, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())+2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+7, EndY(papua.back())-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+8, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+6, EndY(papua.back())-11)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+7, EndY(papua.back())-14)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+7, EndY(papua.back())-14)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())-2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())+6)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())+10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())+3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())+2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+8, EndY(papua.back())-1)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())-2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())+3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back()), EndY(papua.back())+150)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-5, EndY(papua.back())-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())+1)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())+8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-4, EndY(papua.back())+5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-7, EndY(papua.back())+2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-8, EndY(papua.back())+3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+2, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-12, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+2, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-6)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-9)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-12, EndY(papua.back())+1)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-6)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-12, EndY(papua.back())+1)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-13)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-18, EndY(papua.back())-8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-20, EndY(papua.back())-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-5, EndY(papua.back())+5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())+3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-1)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-3, EndY(papua.back())-8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+5, EndY(papua.back())-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+9, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())-8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())-8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+4, EndY(papua.back())-6)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+6, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-5, EndY(papua.back())-2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-4, EndY(papua.back())-8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-6, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-7, EndY(papua.back())+1)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-8, EndY(papua.back())-2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-9, EndY(papua.back())-4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-8, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-6)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-8, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+1, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), offsetPapua));
	//papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-6)));
	
	std::vector<Line> petaLines;
	for(int i=0;i<sumatera.size();++i)  
	{
		petaLines.push_back(sumatera.at(i));
		//cohen_sutherland(frame, StartX(sumatera.at(i)), StartY(sumatera.at(i)), EndX(sumatera.at(i)), EndY(sumatera.at(i)), 400, 300, 800, 600, color);
		plotLine(frame, sumatera.at(i), color);
	}
	
	for(int i=0;i<jawa.size();++i)
	{
		petaLines.push_back(jawa.at(i));
		plotLine(frame, jawa.at(i), color);
		//cohen_sutherland(frame, StartX(jawa.at(i)), StartY(jawa.at(i)), EndX(jawa.at(i)), EndY(jawa.at(i)), 400, 300, 800, 600, rgb(100,100,100));
	}
	for(int i=0;i<kalimantan.size();++i)
	{
		petaLines.push_back(kalimantan.at(i));
		//cohen_sutherland(frame, StartX(kalimantan.at(i)), StartY(kalimantan.at(i)), EndX(kalimantan.at(i)), EndY(kalimantan.at(i)), 400, 300, 800, 600, color);
		plotLine(frame, kalimantan.at(i), color);
	}
	for(int i=0;i<sulawesi.size();++i)
	{
		petaLines.push_back(sulawesi.at(i));
		//cohen_sutherland(frame, StartX(sulawesi.at(i)), StartY(sulawesi.at(i)), EndX(sulawesi.at(i)), EndY(sulawesi.at(i)), 400, 300, 800, 600, color);
		plotLine(frame, sulawesi.at(i), color);
	}
	for(int i=0;i<papua.size();++i)
	{
		petaLines.push_back(papua.at(i));
		plotLine(frame, papua.at(i), color);
	}
	
	//~ printf("Ukuran Sumatera = %d\n", sumatera.size());
	//~ printf("Ukuran jawa = %d\n", jawa.size());
	//~ printf("Ukuran kalimantan = %d\n", kalimantan.size());
	//~ printf("Ukuran sulawesi = %d\n", sulawesi.size());
	//~ printf("Ukuran papua = %d\n", papua.size());
	return petaLines;
}

std::vector<Line> drawBaling(Frame *frm , Coord loc,int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4 ,RGB color){
	int xOffset = loc.x-x1;
	int yOffset = loc.y-y1;

	std::vector<Line> balingLine;
	balingLine.push_back(line(coord(x1,y1),coord(x2,y2)));
	balingLine.push_back(line(coord(x2,y2),coord(x3,y3)));
	balingLine.push_back(line(coord(x3,y3),coord(x4,y4)));
	balingLine.push_back(line(coord(x4,y4),coord(x1,y1)));
	
	plotCircle(frm,loc.x,loc.y,2,color);
	plotLine(frm,loc.x-5,loc.y-3,loc.x+15,loc.y-3,color);
	plotLine(frm,loc.x+15,loc.y-3,loc.x+15,loc.y+3,color);
	plotLine(frm,loc.x+15,loc.y+3,loc.x-5,loc.y+3,color);
	plotLine(frm,loc.x-5,loc.y+3,loc.x-5,loc.y-3,color);
	
	balingLine.push_back(line(coord(loc.x-5,loc.y-3),coord(loc.x+15,loc.y-3)));
	balingLine.push_back(line(coord(loc.x+15,loc.y-3),coord(loc.x+15,loc.y+3)));
	balingLine.push_back(line(coord(loc.x-5,loc.y+3),coord(loc.x-5,loc.y-3)));
	balingLine.push_back(line(coord(loc.x+15,loc.y+3),coord(loc.x-5,loc.y+3)));
	
	std::vector<Coord> balingCoordinates;
	balingCoordinates.push_back(loc);
	balingCoordinates.push_back(coord(x1, y1));
	balingCoordinates.push_back(coord(x2, y2));
	balingCoordinates.push_back(coord(x3,y3));
	balingCoordinates.push_back(coord(x4,y4));

	// Gambar baling-baling
	for(int i = 0; i < balingCoordinates.size(); i++){
		int x0, y0, x1, y1;
		if(i < balingCoordinates.size() - 1){
			x0 = balingCoordinates.at(i).x;
			y0 = balingCoordinates.at(i).y;
			x1 = balingCoordinates.at(i + 1).x;
			y1 = balingCoordinates.at(i + 1).y;
		}else{
			x0 = balingCoordinates.at(balingCoordinates.size() - 1).x;
			y0 = balingCoordinates.at(balingCoordinates.size() - 1).y;
			x1 = balingCoordinates.at(0).x;
			y1 = balingCoordinates.at(0).y;
		}
		plotLine(frm, x0, y0, x1, y1, color);
	}

	int balingHeight = 80;
	return balingLine;
}

std::vector<Line> rotateBaling(Frame *frm,Coord loc, RGB col ,int counter ){
	int x1=loc.x+10; int y1=loc.y+2;
	int x2=loc.x+10; int y2=loc.y-2;
	int x3=loc.x-10; int y3=loc.y+2;
	int x4=loc.x-10; int y4=loc.y-2;
	
	std::vector<Line> balingLine;
	int temp;
	temp=rotasiX(x1,y1,loc,counter*10);
	y1=rotasiY(x1,y1,loc,counter*10);
	x1=temp;
	temp=rotasiX(x2,y2,loc,counter*10);
	y2=rotasiY(x2,y2,loc,counter*10);
	x2=temp;
	temp=rotasiX(x3,y3,loc,counter*10);	
	y3=rotasiY(x3,y3,loc,counter*10);
	x3=temp;
	temp=rotasiX(x4,y4,loc,counter*10);
	y4=rotasiY(x4,y4,loc,counter*10);
	x4=temp;
	balingLine=drawBaling(frm,loc,x1,x2,x3,x4,y1,y2,y3,y4,col);
	return balingLine;
}

void drawBlock(Frame *frm, Block block, Coord3d cameraPosition, int angleX, int angleY, int screenWidth, int screenHeight, RGB color){
	std::vector<Line> lines = perspectiveProjection(block, cameraPosition, angleX, angleY);
	int halfScreenWidth = screenWidth / 2;
	int halfScreenHeight = screenHeight / 2;
	
	for(int i = 0; i < lines.size(); i++){
		int startX = lines.at(i).start.x + halfScreenWidth;
		int startY = lines.at(i).start.y + halfScreenHeight;
		int endX = lines.at(i).end.x + halfScreenWidth;
		int endY = lines.at(i).end.y + halfScreenHeight;
		
		plotLine(frm, startX, startY, endX, endY, color);
	}
}

void drawITB(Frame *frm, Coord3d cameraPosition, int angleX, int angleY, int screenWidth, int screenHeight, RGB color){
	vector<Block> buildings;
	
	// SBM
	buildings.push_back(block(coord3d(-170, 0, -170), 70, 10, 40));
	buildings.push_back(block(coord3d(-125, 0, -185), 20, 15, 10));
	buildings.push_back(block(coord3d(-180, 0, -150), 70, 10, 40));
	
	// Matematika
	buildings.push_back(block(coord3d(-185, 0, -125), 65, 15, 40));
	buildings.push_back(block(coord3d(-190, 0, -100), 30, 20, 40));
	buildings.push_back(block(coord3d(-160, 0, -100), 30, 20, 40));
	
	// Mesin
	buildings.push_back(block(coord3d(-200, 0, -30), 70, 40, 40));
	buildings.push_back(block(coord3d(-200, 0, 0), 40, 20, 40));
	buildings.push_back(block(coord3d(-200, 0, 20), 70, 20, 40));
	
	// GKU Barat
	buildings.push_back(block(coord3d(-165, 0, 75), 45, 45, 40));
	buildings.push_back(block(coord3d(-200, 0, 80), 30, 15, 20));
	buildings.push_back(block(coord3d(-150, 0, 110), 50, 20, 20));
	
	// labtek
	buildings.push_back(block(coord3d(-95, 0, 90), 95, 30, 50));
	buildings.push_back(block(coord3d(-100, 0, 40), 95, 30, 50));
	buildings.push_back(block(coord3d(20, 0, 90), 95, 30, 50));
	buildings.push_back(block(coord3d(25, 0, 40), 95, 30, 50));
	
	// Oktagon, TVST
	buildings.push_back(block(coord3d(-40, 0, -10), 40, 40, 40));
	buildings.push_back(block(coord3d(-40, 0, -60), 40, 40, 40));
	
	// Labtek Biru
	buildings.push_back(block(coord3d(-120, 0, -20), 70, 25, 40));
	buildings.push_back(block(coord3d(-120, 0, -70), 70, 30, 40));
	buildings.push_back(block(coord3d(-100, 0, -50), 40, 15, 20));
	
	// Comlabs, PLN
	buildings.push_back(block(coord3d(20, 0, -10), 40, 30, 40));
	buildings.push_back(block(coord3d(20, 0, -70), 40, 30, 40));
	
	// Mektan
	buildings.push_back(block(coord3d(80, 0, 0), 30, 100, 40));
	
	// PAU
	buildings.push_back(block(coord3d(-40, 0, -120), 40, 70, 80));
	
	// Perpus
	buildings.push_back(block(coord3d(30, 0, -130), 40, 60, 40));
	
	// Tambang
	buildings.push_back(block(coord3d(130, 0, -140), 110, 20, 40));
	buildings.push_back(block(coord3d(170, 0, -90), 20, 40, 20));
	buildings.push_back(block(coord3d(140, 0, -70), 80, 15, 10));
	buildings.push_back(block(coord3d(220, 0, -70), 10, 45, 10));
	
	// Kimia
	buildings.push_back(block(coord3d(140, 0, -40), 70, 20, 30));
	buildings.push_back(block(coord3d(140, 0, -10), 75, 20, 30));
	
	// Lab gelombang
	buildings.push_back(block(coord3d(140, 0, 35), 60, 25, 15));
	
	// GKU Timur
	buildings.push_back(block(coord3d(155, 0, 65), 55, 25, 50));
	buildings.push_back(block(coord3d(190, 0, 85), 20, 20, 20));
	
	// Doping
	buildings.push_back(block(coord3d(140, 0, 110), 40, 25, 40));
	
	// CC
	buildings.push_back(block(coord3d(-50, 0, 150), 50, 20, 30));
	buildings.push_back(block(coord3d(25, 0, 150), 50, 20, 30));
	
	// Lingkungan
	buildings.push_back(block(coord3d(85, 0, 150), 95, 25, 15));
	buildings.push_back(block(coord3d(85, 0, 150), 50, 20, 30));
	buildings.push_back(block(coord3d(140, 0, 180), 50, 25, 30));
	
	// Plano, Arsi
	buildings.push_back(block(coord3d(90, 0, 210), 45, 15, 30));
	buildings.push_back(block(coord3d(140, 0, 210), 50, 15, 30));
	
	// SR
	buildings.push_back(block(coord3d(110, 0, 250), 30, 30, 35));
	buildings.push_back(block(coord3d(140, 0, 260), 20, 40, 10));
	
	// Aula
	buildings.push_back(block(coord3d(50, 0, 270), 60, 30, 20));
	buildings.push_back(block(coord3d(-80, 0, 270), 60, 30, 20));
	
	// Sipil
	buildings.push_back(block(coord3d(-140, 0, 240), 80, 20, 25));
	buildings.push_back(block(coord3d(-150, 0, 220), 90, 15, 25));
	
	// Fisika
	buildings.push_back(block(coord3d(-150, 0, 190), 90, 60, 20));
	
	for(int i = 0; i < buildings.size(); i++){
		drawBlock(frm, buildings.at(i), cameraPosition, angleX, angleY, screenWidth, screenHeight, color);
	}
}


