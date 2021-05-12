#include "Shape.h"
#ifndef OVAL_H_
#define OVAL_H_
class Oval :public Shape {

public:
	Oval();
	virtual Point getCenter() = 0;
	virtual void draw() = 0;
	virtual string getType() = 0;
	virtual void fillColor(int x, int y, int colr_id) = 0;
};


class HinhTron : public Oval {
private:
	float radius;
public:
	HinhTron(Point, Point);
	void operator=(Oval const& a);
	void draw();
	string getType();
	Point getCenter();
	void fillColor(int x, int y, int colr_id);
};

class HinhElip : public Oval {
private:
	float biRa;
	float smRa;
public:
	HinhElip(Point, Point);
	void draw();
	string getType();
	Point getCenter();
	void fillColor(int x, int y, int colr_id);
};
#endif // !OVAL_H_

