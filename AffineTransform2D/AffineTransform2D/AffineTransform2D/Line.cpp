#include "Line.h"

Line::Line(Point s, Point e)
{
	this->center = s.midMointTo(e);
	this->start = s;
	this->end = e;

	Point* temp = new Point(this->start.getX(), this->start.getY());
	this->listOfPoint.push_back(temp);
	temp = new Point(this->end.getX(), this->end.getY());
	this->listOfPoint.push_back(temp);
	updateCenter();

}

string Line::getType()
{
	return "Line";
}

void Line::draw()
{
	setLibColor();
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < listOfPoint.size(); i++){
		glVertex2f(listOfPoint[i]->getX(), listOfPoint[i]->getY());
	}
	glEnd();
}

Point Line::getCenter()
{
	return this->center;
}

void Line::fillColor(int x, int y, int colr_id)
{
	this->fill = colr_id;
}
