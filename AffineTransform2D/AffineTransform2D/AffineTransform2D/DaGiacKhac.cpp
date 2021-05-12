#include "DaGiacKhac.h"

DaGiacKhac::DaGiacKhac(vector<Point*> verts)
{
	float x = 0, y = 0;
	listOfPoint = verts;
	//for (int i = 0; i < listOfPoint.size(); i++) {
	//	x += listOfPoint[i]->getX();
	//	y += listOfPoint[i]->getY();
	//}
	//x /= listOfPoint.size();
	//y /= listOfPoint.size();
	//this->center.setCoor(x, y);
	updateCenter();
}

void DaGiacKhac::draw()
{
	setLibColor();
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < listOfPoint.size(); i++) {
		glVertex2f(this->listOfPoint[i]->getX(), this->listOfPoint[i]->getY());
	}
	glEnd();
}

string DaGiacKhac::getType()
{
	return "Da Giac Khac";
}

Point DaGiacKhac::getCenter()
{
	return this->center;
}

void DaGiacKhac::fillColor(int x, int y, int colr_id)
{
}
