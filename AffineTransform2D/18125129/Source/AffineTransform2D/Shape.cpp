#include "Shape.h"
#include "Painter.h"
#include "MyVect.h"
Shape::Shape()
{
	fill = 0;
}

void Shape::updateCenter()
{
	float x = 0, y = 0;
	for (int i = 0; i < listOfPoint.size(); i++) {
		x += listOfPoint[i]->getX();
		y += listOfPoint[i]->getY();
	}
	x /= listOfPoint.size();
	y /= listOfPoint.size();
	this->center.setCoor(x, y);
}

void Shape::setLibColor()
{
	
		glLineWidth(3);
		if (fill == 0)
			glColor3f(mauVien.r, mauVien.g, mauVien.b);
		else if (fill == mauXanh_id)
			glColor3f(mauXanh.r, mauXanh.g, mauXanh.b);
		else if (fill == mauDo_id)
			glColor3f(mauDo.r, mauDo.g, mauDo.b);
		else if (fill == mauVang_id)
			glColor3f(mauVang.r, mauVang.g, mauVang.b);
		if(this->selected == true)
			glColor3f(mauXanh.r, mauXanh.g, mauXanh.b);
		else
			glColor3f(mauVien.r, mauVien.g, mauVien.b);

		//glColor3f(0.8f, 0.5f, 0.6f);
	
}

void Shape::setSelected(bool state)
{
	selected = state;
}

void Shape::moveFollow(MyVect tt)
{
	for (int i = 0; i < this->listOfPoint.size(); i++)
		listOfPoint[i]->moveFollow(tt);
	updateCenter();
}
