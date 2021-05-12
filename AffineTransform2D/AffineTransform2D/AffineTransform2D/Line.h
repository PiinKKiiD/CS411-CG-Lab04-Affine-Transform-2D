#include "Shape.h"
#ifndef LINE_H_
#define LINE_H_
class Line : public Shape {
public:
	Line(Point s, Point e);
	string getType();
	void draw();
	Point getCenter();
	void fillColor(int x, int y, int colr_id);
};
#endif