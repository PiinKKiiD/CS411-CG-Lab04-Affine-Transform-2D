#ifndef DAGIACKHAC_H_
#define DAGIACKHAC_H_
#include "Shape.h"
#include <vector>

class DaGiacKhac : public Shape {

public:
	DaGiacKhac(vector<Point*> verts);
	void draw();
	string getType();
	Point getCenter();
	void fillColor(int x, int y, int colr_id);

};

#endif // !DAGIACKHAC_H_
