#include<stdio.h>
	#include<graphics.h>
//http://2k8618.blogspot.com/2012/01/line-clipping-cohen-sutherland-line.html

const int TOP=8,BOTTOM=4,RIGHT=2,LEFT=1;

typedef int outcode;

outcode compute(int x, int y , int xmax, int ymax, int xmin, int ymin)
{
	outcode oc=0;
	if(x<xmin)
		oc|=LEFT;
	else if(x>xmax)
		oc|=RIGHT;
	
	if(y>ymax)
		oc|=TOP;
	else if(y<ymin)
		oc|=BOTTOM;
	printf("oc = %d\n", oc);
	return oc;
}

void coh(int x1,int y1,int x2,int y2, int xmin,int ymin, int xmax, int ymax)
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
			ot=o1?o1:o2;
			if(ot & TOP)
			{
				printf("masuk top\n");
				y=ymax;
				x = x1 + (x2-x1)*(ymax-y1)/(y2-y1);
			} 
			else if(ot & BOTTOM)
			{
				printf("masuk bottom\n");
				y=ymin;
				x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
			}
			else if(ot & RIGHT)
			{
				printf("masuk right\n");
				x=xmax;
				y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
			}
			else if(ot & LEFT)
			{
				printf("masuk left\n");
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
		line(x1,y1,x2,y2);
		//printf("Point 1 = (%d, %d)\n",x1, y1);
		//printf("Point 2 = (%d, %d)\n",x2, y2);
	}

}

int main()
{
	 int gd=DETECT,gm,x,y,j,i;
	 initgraph(&gd,&gm,NULL);
	 
	 outtextxy(150,15, "Cohen Sutherland");

	 int xmx=200,ymx=200,xmn=100,ymn=100;
	 
	 
	 //~ int ax1=50,ay1=75,bx1=50,by1=325;
	 //~ 
	 //~ int ax2=150,ay2=75,bx2=150,by2=325;
	 
	 int ax1=110,ay1=110,bx1=180,by1=180;
	 
	 int ax2=160,ay2=50,bx2=150,by2=150;
	 
	 int ax3=250,ay3=75,bx3=250,by3=325;
	 
	 int ax4=50,ay4=75,bx4=250,by4=75;
	 
	 int ax5=50,ay5=175,bx5=250,by5=175; 
	 
	 int ax6=50,ay6=275,bx6=250,by6=275;
	 int ax7=50,ay7=75,bx7=275,by7=275;
	 int ax8=250,ay8=75,bx8=75,by8=275;

	 //~ line(ax1,ay1,bx1,by1);
	 line(ax2,ay2,bx2,by2);
	 //~ line(ax3,ay3,bx3,by3);
	 //~ line(ax4,ay4,bx4,by4);
	 //~ line(ax5,ay5,bx5,by5);
	 //~ line(ax6,ay6,bx6,by6);
	 //~ line(ax7,ay7,bx7,by7);
	 //~ line(ax8,ay8,bx8,by8);
	 setcolor(4);
	 rectangle(xmn,ymn,xmx,ymx);
	 delay(2000);
	 
	 cleardevice(); 
	 
	 setcolor(4);
	 rectangle(xmn,ymn,xmx,ymx);
	 
	 setcolor(15);
	 //printf("xmin = %d\n", xmn);
	 //printf("ymin = %d\n", ymn);
	 //printf("xmax = %d\n", xmx);
	 //printf("ymax = %d\n", ymx);
	 
	 //~ printf("Sebelum\n");
	 //~ printf("Point 1 = (%d, %d)\n",ax1, ay1);
	 //~ printf("Point 2 = (%d, %d)\n",bx1, by1);
	 //~ printf("Sesudah\n");
	 //~ coh(ax1,ay1,bx1,by1,xmn,ymn,xmx,ymx);
	 
	 //~ printf("Sebelum\n");
	 //~ printf("Point 1 = (%d, %d)\n",ax2, ay2);
	 //~ printf("Point 2 = (%d, %d)\n",bx2, by2);
	 //~ printf("Sesudah\n");
	 coh(ax2,ay2,bx2,by2,xmn,ymn,xmx,ymx);
	 
	 //~ printf("Sebelum\n");
	 //~ printf("Point 1 = (%d, %d)\n",ax3, ay3);
	 //~ printf("Point 2 = (%d, %d)\n",bx3, by3);
	 //~ printf("Sesudah\n");
	 //~ coh(ax3,ay3,bx3,by3,xmn,ymn,xmx,ymx);
	 
	 //~ printf("Sebelum\n");
	 //~ printf("Point 1 = (%d, %d)\n",ax4, ay4);
	 //~ printf("Point 2 = (%d, %d)\n",bx4, by4);
	 //~ printf("Sesudah\n");
	 //~ coh(ax4,ay4,bx4,by4,xmn,ymn,xmx,ymx);
	 
	 //~ printf("Sebelum\n");
	 //~ printf("Point 1 = (%d, %d)\n",ax5, ay5);
	 //~ printf("Point 2 = (%d, %d)\n",bx5, by5);
	 //~ printf("Sesudah\n");
	 //~ coh(ax5,ay5,bx5,by5,xmn,ymn,xmx,ymx);
	 
	 //~ printf("Sebelum\n");
	 //~ printf("Point 1 = (%d, %d)\n",ax6, ay6);
	 //~ printf("Point 2 = (%d, %d)\n",bx6, by6);
	 //~ printf("Sesudah\n");
	 //~ coh(ax6,ay6,bx6,by6,xmn,ymn,xmx,ymx);
	 
	 //~ printf("Sebelum\n");
	 //~ printf("Point 1 = (%d, %d)\n",ax7, ay7);
	 //~ printf("Point 2 = (%d, %d)\n",bx7, by7);
	 //~ printf("Sesudah\n");
	 //~ coh(ax7,ay7,bx7,by7,xmn,ymn,xmx,ymx);
	 
	 //~ printf("Sebelum\n");
	 //~ printf("Point 1 = (%d, %d)\n",ax8, ay8);
	 //~ printf("Point 2 = (%d, %d)\n",bx8, by8);
	 //~ printf("Sesudah\n");
	 //~ coh(ax8,ay8,bx8,by8,xmn,ymn,xmx,ymx);
	 delay(1000);
	 
	 
	 getch();
	 closegraph();
	 return 0;
}
