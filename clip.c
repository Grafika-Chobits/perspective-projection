#include "clip.h"

//xmin = sisi kiri dari clip
//ymin = sisi atas dari clip
//xmax = sisi kanan dari clip
//ymax = sisi bawah dari clip

//TOP = 	1000
//BOTTOM = 	0100
//LEFT = 	0001
//RIGHT = 	0010
outcode compute(int x, int y , int xmax, int ymax, int xmin, int ymin)
{
	outcode oc=0;
	if(x<xmin)
		oc|=LEFT;
	else if(x>xmax)
		oc|=RIGHT;
	
	if(y<ymin)
		oc|=TOP;
	else if(y>ymax)
		oc|=BOTTOM;

	return oc;
}

std::vector<Line> cohen_sutherland(Frame *canvas, std::vector<Line> lines, Coord center, int size)
{
	int xmin = center.x - size;
	int ymin = center.y - size;
	int xmax = center.x + size;
	int ymax = center.y + size;
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
		o1=compute(x1,y1,xmax,ymax,xmin,ymin);
		o2=compute(x2,y2,xmax,ymax,xmin,ymin);
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
					y=ymin;
					x = x1 + (x2-x1) * (ymin - y1) / (y2-y1);
				} 
				else if(ot & BOTTOM) 	// point is below the clip rectangle
				{
					y=ymax;
					x = x1 + (x2 - x1) * (ymax - y1) / (y2-y1);
				}
				else if(ot & RIGHT)		// point is to the right of clip rectangle
				{
					x=xmax;
					y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
				}
				else if(ot & LEFT)		// point is to the left of clip rectangle
				{
					x=xmin;
					y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);

				}
				if(ot==o1)
				{
					x1=x;
					y1=y;
					o1=compute(x1,y1,xmax,ymax,xmin,ymin);
				}
				else
				{
					x2=x;
					y2=y;
					o2=compute(x2,y2,xmax,ymax,xmin,ymin);
				}
			}
		}while(done==false);

		if(accept==true)
		{
			clippedLines.push_back(line(coord(x1 - xmin, y1 - ymin),coord(x2 - xmin,y2 - ymin)));
		}
		drawSquare(canvas, coord(xmin, ymin), coord(xmax, ymax), rgb(255,255,0));
	}
	return clippedLines;
}


//Fungsi cohen di bawah ini cuma menggambar line yang masuk ke dia, tergantung di accept atau gak
void cohen_sutherland(Frame *frm, int x1,int y1,int x2,int y2, int xmin,int ymin, int xmax, int ymax, RGB color)
{
	bool accept = false, done=false;double m;
	outcode o1,o2,ot;
	o1=compute(x1,y1,xmax,ymax,xmin,ymin);
	o2=compute(x2,y2,xmax,ymax,xmin,ymin);
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
				y=ymin;
				x = x1 + (x2-x1) * (ymin - y1) / (y2-y1);
			} 
			else if(ot & BOTTOM) 	// point is below the clip rectangle
			{
				y=ymax;
				x = x1 + (x2 - x1) * (ymax - y1) / (y2-y1);
			}
			else if(ot & RIGHT)		// point is to the right of clip rectangle
			{
				x=xmax;
				y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
			}
			else if(ot & LEFT)		// point is to the left of clip rectangle
			{
				x=xmin;
				y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);

			}
			if(ot==o1)
			{
				x1=x;
				y1=y;
				o1=compute(x1,y1,xmax,ymax,xmin,ymin);
			}
			else
			{
				x2=x;
				y2=y;
				o2=compute(x2,y2,xmax,ymax,xmin,ymin);
			}
		}
	}while(done==false);

	if(accept==true)
	{
		plotLine(frm, line(coord(x1,y1),coord(x2,y2)), color);
	}
}


void cohen_sutherland(int x1,int y1,int x2,int y2, int xmin,int ymin, int xmax, int ymax)
{
	bool accept = false, done=false;double m;
	outcode o1,o2,ot;
	o1=compute(x1,y1,xmax,ymax,xmin,ymin);
	o2=compute(x2,y2,xmax,ymax,xmin,ymin);
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
				y=ymin;
				x = x1 + (x2-x1) * (ymin - y1) / (y2-y1);
			} 
			else if(ot & BOTTOM) 	// point is below the clip rectangle
			{
				y=ymax;
				x = x1 + (x2 - x1) * (ymax - y1) / (y2-y1);
			}
			else if(ot & RIGHT)		// point is to the right of clip rectangle
			{
				x=xmax;
				y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
			}
			else if(ot & LEFT)		// point is to the left of clip rectangle
			{
				x=xmin;
				y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);

			}
			if(ot==o1)
			{
				x1=x;
				y1=y;
				o1=compute(x1,y1,xmax,ymax,xmin,ymin);
			}
			else
			{
				x2=x;
				y2=y;
				o2=compute(x2,y2,xmax,ymax,xmin,ymin);
			}
		}
	}while(done==false);

	if(accept==true)
	{
		printf("Point 1 = (%d, %d)\n",x1, y1);
		printf("Point 2 = (%d, %d)\n",x2, y2);
	}
	else
	{
		printf("Not accepted\n");
		printf("Point 1 = (%d, %d)\n",x1, y1);
		printf("Point 2 = (%d, %d)\n",x2, y2);
	}
}
