#include "Shape.h"
#include "MyVect.h"
#ifndef HINHKHAC_H_
#define HINHKHAC_H_
class HinhKhac : public Shape {
public:
	HinhKhac();
	virtual void draw() = 0;
	virtual string getType() = 0;
	virtual Point getCenter() = 0;
	virtual void fillColor(int x, int y, int colr_id) = 0;
};

class MuiTen : public HinhKhac {
private:
	float fullEdge;
	float tri;
	float rect;
	MyVect ar_Vect;
	Point center;
	Point cross;
public:
	MuiTen(Point c, Point btmRight);
	void draw();
	string getType();
	Point getCenter();
	void fillColor(int x, int y, int colr_id);
	void updateCenter();
};

class NgoiSao : public HinhKhac {
private:
	float al = 72;
	float minEdge;
public:
	NgoiSao(Point c, Point btmRight);
	void draw();
	string getType();
	Point getCenter();
	void fillColor(int x, int y, int colr_id);

};
#endif // !HINHKHAC
