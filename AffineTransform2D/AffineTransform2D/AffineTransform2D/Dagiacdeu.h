#include "Shape.h"
#ifndef DAGIACDEU_H_
#define DAGIACDEU_H_

class DaGiacDeu : public Shape {
public:
	DaGiacDeu();
	virtual void draw() = 0;
	virtual string getType() = 0;
	virtual void fillColor(int x, int y, int colr_id) = 0;
};

class NguGiacDeu : public DaGiacDeu {
private: 
	float al = 72;
public: 
	NguGiacDeu(Point c, Point btmRight);
	void draw();
	string getType();
	Point getCenter();
	void fillColor(int x, int y, int colr_id);

};

class LucGiacDeu : public DaGiacDeu {
private:
	float al = 60;
public:
	LucGiacDeu(Point c, Point btmRight);
	void draw();
	string getType();
	Point getCenter();
	void fillColor(int x, int y, int colr_id);
};

#endif // !DaGiacDeu_H_
