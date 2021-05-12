#include "Shape.h"
#ifndef DAU_H_
#define DAU_H_
class Dau: public Shape {
public:
	Dau();
	virtual void draw() = 0;
	virtual string getType() = 0;
	virtual Point getCenter() = 0;
	virtual void fillColor(int x, int y, int colr_id) = 0;
};

class DauCong : public Dau {
public:
	DauCong(Point c, Point btmRight);
	void draw();
	float width;
	string getType();
	Point getCenter();
	void fillColor(int x, int y, int colr_id);
};

class DauTru : public Dau {
	Point other;
public:
	DauTru(Point c, Point btmRight);
	void draw();
	float width;
	string getType();
	Point getCenter();
	void fillColor(int x, int y, int colr_id);
};

#endif // !DAU_H_
