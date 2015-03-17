#ifndef ADDEDSTRUCT_H
#define ADDEDSTRUCT_H

#include <vector>
#include <math.h>
#include <cmath>
#include <stdio.h>

#define min(X,Y) (((X) < (Y)) ? (X) : (Y))
#define max(X,Y) (((X) > (Y)) ? (X) : (Y))
#define End(Line) Line.end
#define EndX(Line) Line.end.x
#define EndY(Line) Line.end.y
#define StartX(Line) Line.start.x
#define StartY(Line) Line.start.y

#define PI 3.14159265

#define degreesToRadians(angleDegrees) (angleDegrees * M_PI / 180.0)

/* SETTINGS ------------------------------------------------------------ */
#define screenXstart 250
#define screenX 1366
#define screenY 768
#define mouseSensitivity 3

/* TYPEDEFS ------------------------------------------------------------ */
//RGB color
typedef struct s_rgb {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} RGB;

//Frame of RGBs
typedef struct s_frame {
	RGB px[screenX][screenY];
} Frame;

//Coordinate System
typedef struct s_coord {
	int x;
	int y;
} Coord;

//3D Coordinate System
typedef struct s_coord3d {
	int x;
	int y;
	int z;
} Coord3d;

//Line System
typedef struct s_line {
	Coord start;
	Coord end;
} Line;

//The integrated frame buffer plus info struct.
typedef struct s_frameBuffer {
	char* ptr;
	int smemLen;
	int lineLen;
	int bpp;
} FrameBuffer;

//Tipe data kubus
typedef struct s_block{
	Coord3d origin;
	int length;
	int width;
	int height;
}Block;
	
Coord coord(int x, int y);

Coord3d coord3d(int x, int y, int z);

Line line(Coord start, Coord end);

Block block(Coord3d _origin, int _length, int _width, int _height);

std::vector<Coord3d> createBlockCoordinates(Block block);

std::vector<Line> perspectiveProjection(Block block, Coord3d cameraPosition, int angleX, int angleY);

std::vector<Coord3d> perspectiveTransformation(std::vector<Coord3d> threeDimensionalCoordinates, Coord3d cameraPosition, int angleX, int angleY);

std::vector<Coord> worldToScreenCoordinates(std::vector<Coord3d> threeDimensionalCoordinates, Coord3d cameraPosition);

std::vector<Line> createBlockLines(std::vector<Coord> twoDimensionalCoordinates);

unsigned char isInBound(Coord position, Coord corner1, Coord corner2);

#endif
