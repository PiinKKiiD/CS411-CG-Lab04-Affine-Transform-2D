#include "Shape.h"
#ifndef  TUGIAC_H_
#define TUGIAC_H_
class TuGiac: public Shape {
public:
	TuGiac();
	virtual void draw() = 0;
	virtual string getType() = 0;
	virtual Point getCenter() = 0;
	void fillColor(int x, int y, int colr_id);
};

class HinhChuNhat : public TuGiac {
public:
	HinhChuNhat(Point c, Point btmRight);
	void draw();
	string getType();
	Point getCenter();
};

class HinhVuong : public TuGiac {
public:
	HinhVuong(Point c, Point btmRight);
	void draw();
	string getType();
	Point getCenter();
};

#endif // ! TUGIAC_H_

