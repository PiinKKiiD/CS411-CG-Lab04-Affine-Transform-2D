#include "Dagiacdeu.h"
#include "Painter.h"
NguGiacDeu::NguGiacDeu(Point c, Point btmRight)
{
	this->center = c;
	this->end = btmRight;
	float alpha = al;
	//1st
	Point* temp = new Point(this->end.getX(), this->end.getY());
	this->listOfPoint.push_back(temp);
	//2nd
	temp = new Point((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	this->listOfPoint.push_back(temp);
	//3rd
	alpha += al;
	temp = new Point((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	this->listOfPoint.push_back(temp);
	//4rd
	alpha += al;
	temp = new Point((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	this->listOfPoint.push_back(temp);
	//5rd
	alpha += al;
	temp = new Point((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	this->listOfPoint.push_back(temp);

	updateCenter();
}

void NguGiacDeu::draw()
{
	setLibColor();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < this->listOfPoint.size(); i++) {
		glVertex2f(listOfPoint[i]->getX(), listOfPoint[i]->getY());
	}
	glEnd();
	if (this->fill > 0)
		fillColor(this->center.getX(), this->center.getY(), fill);
}

string NguGiacDeu::getType()
{
	return "Ngu Giac Deu";
}

Point NguGiacDeu::getCenter()
{
	return this->center;
}

void NguGiacDeu::fillColor(int x, int y, int colr_id)
{
	if (colr_id == mauDo_id) {
		BoundaryFill(x, y, mauDo, mauVien);
	}
	else if (colr_id == mauVang_id) {
		BoundaryFill(x, y, mauVang, mauVien);
	}
	else if (colr_id == mauXanh_id) {
		BoundaryFill(x, y, mauXanh, mauVien);
	}
}

DaGiacDeu::DaGiacDeu()
{
}

LucGiacDeu::LucGiacDeu(Point c, Point btmRight)
{
	this->center = c;
	this->end = btmRight;
	float alpha = al;
	//1st
	Point* temp = new Point(this->end.getX(), this->end.getY());
	this->listOfPoint.push_back(temp);
	//2nd=
	temp = new Point((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	this->listOfPoint.push_back(temp);

	//3rd
	alpha += al;
	temp = new Point((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	this->listOfPoint.push_back(temp);

	//4rd
	alpha += al;
	temp = new Point((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	this->listOfPoint.push_back(temp);

	//5rd
	alpha += al;
	temp = new Point((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	this->listOfPoint.push_back(temp);

	//6rd
	alpha += al;
	temp = new Point((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	this->listOfPoint.push_back(temp);
	updateCenter();


}

void LucGiacDeu::draw()
{
	setLibColor();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < this->listOfPoint.size(); i++) {
		glVertex2f(listOfPoint[i]->getX(), listOfPoint[i]->getY());
	}
	glEnd();
	if (this->fill > 0)
		fillColor(this->center.getX(), this->center.getY(), fill);
}

string LucGiacDeu::getType()
{
	return "Luc Giac Deu";
}

Point LucGiacDeu::getCenter()
{
	return this->center;
}

void LucGiacDeu::fillColor(int x, int y, int colr_id)
{
	if (colr_id == mauDo_id) {
		BoundaryFill(x, y, mauDo, mauVien);
	}
	else if (colr_id == mauVang_id) {
		BoundaryFill(x, y, mauVang, mauVien);
	}
	else if (colr_id == mauXanh_id) {
		BoundaryFill(x, y, mauXanh, mauVien);
	}
}
