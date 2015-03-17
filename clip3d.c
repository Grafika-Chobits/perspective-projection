#include "clip3d.h"

//xmin = sisi kiri dari clip
//ymin = sisi atas dari clip
//xmax = sisi kanan dari clip
//ymax = sisi bawah dari clip

//TOP = 	1000
//BOTTOM = 	0100
//LEFT = 	0001
//RIGHT = 	0010
//outcode compute(int x, int y , int xmin1, int ymin1, int xmax1, int ymin2, int xmax2, int ymax2, int xmin2, int ymax1)
outcode compute(int x, int y , Coord kiriAtas, Coord kananAtas, Coord kiriBawah, Coord kananBawah)
{
	float m;
	outcode oc=0;
	int xmin, ymin, xmax, ymax;
	// printf("kiriAtas.x = %d\n", kiriAtas.x);
	// printf("kiriBawah.x = %d\n", kiriBawah.x);
	if(kiriAtas.x == kiriBawah.x && kananAtas.x == kananBawah.x){
		printf("masuk checking x biasa\n");
		xmin = kiriAtas.x;
		xmax = kananAtas.x;
		if(x<xmin)
			oc|=LEFT;
		else if(x>xmax)
			oc|=RIGHT;
	}
	else
	{
		printf("masuk else x\n");
		xmin = kiriAtas.x > kiriBawah.x? kiriAtas.x:kiriBawah.x;
		ymin = kiriAtas.x > kiriBawah.x? kiriAtas.y:kiriBawah.y;
		xmax = kananAtas.x < kananBawah.x? kananAtas.x:kananBawah.x;
		ymax = kananAtas.x < kananBawah.x? kananAtas.y:kananBawah.y;
		if(x < xmin)
		{
			m = (kiriBawah.y - kiriAtas.y) / (kiriBawah.x - kiriAtas.x);
			// printf("m dengan x < xmin = %f\n", m);
			// cari xPotong
			int xPotong = round(m * (y - ymin) + xmin);
			if(x < xPotong)
				oc|=LEFT;
		}
		else if(x > xmax)
		{
			m = (kananBawah.y - kananAtas.y) / (kananBawah.x - kananAtas.x);
			printf("m dengan x > xmax = %f\n", m);
			// int xPotong = round(m * (y - ymax) + xmax);
			int xPotong = round( ((y - ymax) / m) + xmax );
			printf("y = %d\n", y);
			printf("ymax = %d\n", ymax);
			printf("xmax = %d\n", xmax);
			printf("xPotong = %d\n", xPotong);
			if(x > xPotong) // xPotong = 1200, x = 700
			{
				oc|=RIGHT;
			}
		}
	}
	
	if(kiriAtas.y == kananAtas.y && kiriBawah.y == kananBawah.y)
	{
		// printf("masuk checking y biasa\n");
		ymin = kiriAtas.y;
		ymax = kiriBawah.y;
		if(y<ymin)
			oc|=TOP;
		else if(y>ymax)
			oc|=BOTTOM;
	}
	else
	{
		// printf("masuk else y\n");
		ymin = kiriAtas.y > kananAtas.y? kiriAtas.y:kananAtas.y;
		xmin = kiriAtas.y > kananAtas.y? kiriAtas.x:kananAtas.x;
		ymax = kiriBawah.y < kananBawah.y? kiriBawah.y:kananBawah.y;
		xmax = kiriBawah.y < kananBawah.y? kiriBawah.x:kananBawah.x;
		if(y < ymin) 
		{
			m = (kananAtas.y - kiriAtas.y) / (kananAtas.x - kiriAtas.x);
			//cari titik potong
			int yPotong = round(m * (x - xmin) + ymin);

			//Cek ada dimana y dilihat dari titik potong.
			//Apakah ada di atas yPotong
			if(y < yPotong)
				oc|=TOP;
		}
		else if(y > ymax)
		{
			m = (kananBawah.y - kiriBawah.y) / (kananBawah.x - kiriBawah.x);
			//Cari titik potong
			int yPotong = round(m * (x - xmax) + ymax);

			//Cek ada dimana y dilihat dari titik potong y.
			//Apakah y ada di bawah yPotong
			if(y > yPotong)
				oc|=BOTTOM;
		}
		
	}
	printf("oc = %d\n", oc);
	return oc;
}

//Urutan kotaknya: kiriAtas, kananAtas, kiriBawah, kananBawah
std::vector<Line> cohen_sutherland(Frame *canvas, std::vector<Line> lines, Coord kiriAtas, Coord kananAtas, 
																			Coord kiriBawah, Coord kananBawah, RGB color)
{
	int xmin1 = kiriAtas.x;
	int xmin2 = kiriBawah.x;
	int ymin1 = kiriAtas.y;
	int ymin2 = kananAtas.y;
	int xmax1 = kananAtas.x;
	int xmax2 = kananBawah.x;
	int ymax1 = kiriBawah.y;
	int ymax2 = kananBawah.y;
	
	int x1, y1, x2, y2;

	std::vector<Line> clippedLines;
	for (int i = 0; i < lines.size(); i++)
	{
		x1 = StartX(lines.at(i));
		y1 = StartY(lines.at(i));
		x2 = EndX(lines.at(i));
		y2 = EndY(lines.at(i));
		bool accept = false, done=false;double m;
		outcode o1,o2,ot;
		o1=compute(x1,y1, kiriAtas, kananAtas, kiriBawah, kananBawah);
		o2=compute(x2,y2, kiriAtas, kananAtas, kiriBawah, kananBawah);
		do{

			if(!(o1 | o2))
			{
				done=true;
				accept=true;
			}
			else if(o1&o2)
			{
				done=true;
			}
			else
			{
				int x,y;
				ot=o1?o1:o2; //Nyari point mana yang ada di luar kotak, kemudian masukin ke ot
				if(ot & TOP)			// point is above the clip rectangle
				{
					y=ymin1;
					x = x1 + (ymin1 - y1) * (x2-x1) / (y2-y1);
				} 
				else if(ot & BOTTOM) 	// point is below the clip rectangle
				{
					y=ymax1;
					x = x1 + (ymax1 - y1) * (x2 - x1) / (y2-y1);
				}
				else if(ot & RIGHT)		// point is to the right of clip rectangle
				{
					if(kiriAtas.x == kiriBawah.x && kananAtas.x == kananBawah.x)
						x=xmax1;
					else
					{
						float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
						float m2 = ((float)kananBawah.y - (float)kananAtas.y) / ((float)kananBawah.x - (float)kananAtas.x);
						x = round( (m1*(float)x1 - (float)y1 - m2 * (float)kananAtas.x + (float)kananAtas.y) / (m1 - m2) ); 
						printf("x = %d\n", x);
					}
					y = y1 + (x - x1) * (y2 - y1) / (x2 - x1);
				}
				else if(ot & LEFT)		// point is to the left of clip rectangle
				{
					x=xmin1;
					//x = x1 + (ymin1 - y1) * (x2 - x1) / (y2 - y1);
					y = y1 + (xmin1 - x1) * (y2 - y1) / (x2 - x1);
				}
				if(ot==o1)
				{
					x1=x;
					y1=y;
					o1=compute(x1,y1,kiriAtas, kananAtas, kiriBawah, kananBawah);
				}
				else
				{
					x2=x;
					y2=y;
					o2=compute(x2,y2,kiriAtas, kananAtas, kiriBawah, kananBawah);
				}
			}
		}while(done==false);

		if(accept==true)
		{
			clippedLines.push_back(line(coord(x1, y1),coord(x2,y2)));
		}
		drawFreeSquare(canvas, kiriAtas, kananAtas, kiriBawah, kananBawah, rgb(255,255,0));
	}
	return clippedLines;
}


//Fungsi cohen di bawah ini cuma menggambar line yang masuk ke dia, tergantung di accept atau gak
//~ void cohen_sutherland(Frame *frm, int x1,int y1,int x2,int y2, int xmin,int ymin, int xmax, int ymax, RGB color)
//~ {
	//~ bool accept = false, done=false;double m;
	//~ outcode o1,o2,ot;
	//~ o1=compute(x1,y1,xmax,ymax,xmin,ymin);
	//~ o2=compute(x2,y2,xmax,ymax,xmin,ymin);
	//~ do{
//~ 
		//~ if(!(o1 | o2))
		//~ {
			//~ done=true;
			//~ accept=true;
		//~ }
		//~ else if(o1&o2)
		//~ {
			//~ done=true;
		//~ }
		//~ else
		//~ {
			//~ int x,y;
			//~ ot=o1?o1:o2; //Nyari point mana yang ada di luar kotak, kemudian masukin ke ot
			//~ if(ot & TOP)			// point is above the clip rectangle
			//~ {
				//~ y=ymin;
				//~ x = x1 + (x2-x1) * (ymin - y1) / (y2-y1);
			//~ } 
			//~ else if(ot & BOTTOM) 	// point is below the clip rectangle
			//~ {
				//~ y=ymax;
				//~ x = x1 + (x2 - x1) * (ymax - y1) / (y2-y1);
			//~ }
			//~ else if(ot & RIGHT)		// point is to the right of clip rectangle
			//~ {
				//~ x=xmax;
				//~ y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
			//~ }
			//~ else if(ot & LEFT)		// point is to the left of clip rectangle
			//~ {
				//~ x=xmin;
				//~ y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
//~ 
			//~ }
			//~ if(ot==o1)
			//~ {
				//~ x1=x;
				//~ y1=y;
				//~ o1=compute(x1,y1,xmax,ymax,xmin,ymin);
			//~ }
			//~ else
			//~ {
				//~ x2=x;
				//~ y2=y;
				//~ o2=compute(x2,y2,xmax,ymax,xmin,ymin);
			//~ }
		//~ }
	//~ }while(done==false);
//~ 
	//~ if(accept==true)
	//~ {
		//~ plotLine(frm, line(coord(x1,y1),coord(x2,y2)), color);
	//~ }
//~ }
//~ 
//~ 
//~ void cohen_sutherland(int x1,int y1,int x2,int y2, int xmin,int ymin, int xmax, int ymax)
//~ {
	//~ bool accept = false, done=false;double m;
	//~ outcode o1,o2,ot;
	//~ o1=compute(x1,y1,xmax,ymax,xmin,ymin);
	//~ o2=compute(x2,y2,xmax,ymax,xmin,ymin);
	//~ do{
//~ 
		//~ if(!(o1 | o2))
		//~ {
			//~ done=true;
			//~ accept=true;
		//~ }
		//~ else if(o1&o2)
		//~ {
			//~ done=true;
		//~ }
		//~ else
		//~ {
			//~ int x,y;
			//~ ot=o1?o1:o2; //Nyari point mana yang ada di luar kotak, kemudian masukin ke ot
			//~ if(ot & TOP)			// point is above the clip rectangle
			//~ {
				//~ y=ymin;
				//~ x = x1 + (x2-x1) * (ymin - y1) / (y2-y1);
			//~ } 
			//~ else if(ot & BOTTOM) 	// point is below the clip rectangle
			//~ {
				//~ y=ymax;
				//~ x = x1 + (x2 - x1) * (ymax - y1) / (y2-y1);
			//~ }
			//~ else if(ot & RIGHT)		// point is to the right of clip rectangle
			//~ {
				//~ x=xmax;
				//~ y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
			//~ }
			//~ else if(ot & LEFT)		// point is to the left of clip rectangle
			//~ {
				//~ x=xmin;
				//~ y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
//~ 
			//~ }
			//~ if(ot==o1)
			//~ {
				//~ x1=x;
				//~ y1=y;
				//~ o1=compute(x1,y1,xmax,ymax,xmin,ymin);
			//~ }
			//~ else
			//~ {
				//~ x2=x;
				//~ y2=y;
				//~ o2=compute(x2,y2,xmax,ymax,xmin,ymin);
			//~ }
		//~ }
	//~ }while(done==false);
//~ 
	//~ if(accept==true)
	//~ {
		//~ printf("Point 1 = (%d, %d)\n",x1, y1);
		//~ printf("Point 2 = (%d, %d)\n",x2, y2);
	//~ }
	//~ else
	//~ {
		//~ printf("Not accepted\n");
		//~ printf("Point 1 = (%d, %d)\n",x1, y1);
		//~ printf("Point 2 = (%d, %d)\n",x2, y2);
	//~ }
//~ }
