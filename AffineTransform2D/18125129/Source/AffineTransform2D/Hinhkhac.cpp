#include "Hinhkhac.h"
#include "Painter.h"

HinhKhac::HinhKhac()
{
}
NgoiSao::NgoiSao(Point c, Point btmRight)
{
	this->center = c;
	this->end = btmRight;
	minEdge = c.distanceTo(btmRight) / 2;

	float alpha = al;
	//ve diem dau: dinh1
	Point* tempPoint = new Point(this->end.getX(), this->end.getY());
	this->listOfPoint.push_back(tempPoint);
	alpha = al / 2;
	Point temp;
	//	Quay goc al/2;
	temp.setCoor((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	MyVect ttVect(temp, center);
	// tinh tien 1/2 Temp-Center
	temp.setCoor(temp.getX() + ttVect.getX() / 2, temp.getY() + ttVect.getY() / 2);
	//Ve Temp1:
	tempPoint = new Point(temp.getX(), temp.getY());
	this->listOfPoint.push_back(tempPoint);
	//Tra alpha ve = al

	alpha = al;
	// Ve dinh2 lon: quay end alpha do.
	tempPoint = new Point((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	this->listOfPoint.push_back(tempPoint);
	//Quay temp : alpha tim temp2:
	alpha = al;
	temp.setCoor((temp.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((temp.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((temp.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (temp.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	tempPoint = new Point(temp.getX(), temp.getY());
	this->listOfPoint.push_back(tempPoint);

	//Ve dinh3 lon: Quay end 2alpha
	alpha = 2 * al;

	tempPoint = new Point((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	this->listOfPoint.push_back(tempPoint);
	//Quay temp: alpha tim temp3:
	alpha = al;
	temp.setCoor((temp.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((temp.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((temp.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (temp.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	tempPoint = new Point(temp.getX(), temp.getY());
	this->listOfPoint.push_back(tempPoint);

	//Ve dinh4 lon: Quay end 3alpha
	alpha = 3 * al;

	tempPoint = new Point((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	this->listOfPoint.push_back(tempPoint);
	//Quay temp: alpha tim temp4:
	alpha = al;
	temp.setCoor((temp.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((temp.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((temp.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (temp.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	tempPoint = new Point(temp.getX(), temp.getY());
	this->listOfPoint.push_back(tempPoint);

	//Ve dinh5 lon: Quay end 4alpha
	alpha = 4 * al;
	tempPoint = new Point((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	this->listOfPoint.push_back(tempPoint);
	//Quay temp: alpha tim temp5:
	alpha = al;
	temp.setCoor((temp.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((temp.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((temp.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (temp.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	tempPoint = new Point(temp.getX(), temp.getY());
	this->listOfPoint.push_back(tempPoint);
	updateCenter();
}

void NgoiSao::draw()
{
	setLibColor();
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < this->listOfPoint.size(); i++)
		glVertex2f(this->listOfPoint[i]->getX(), this->listOfPoint[i]->getY());
	glEnd();

	if (this->fill > 0)
		fillColor(this->center.getX(), this->center.getY(), fill);
}

string NgoiSao::getType()
{
	return "Ngoi Sao";
}

Point NgoiSao::getCenter()
{
	return this->center;
}

void NgoiSao::fillColor(int x, int y, int colr_id)
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

MuiTen::MuiTen(Point c, Point btmRight)
{
	this->start = c;
	this->end = btmRight;
	this->center = c.midMointTo(btmRight);
	
	fullEdge = c.distanceTo(btmRight);
	tri = fullEdge / 5;
	rect = fullEdge - tri;

	Point cr;
	MyVect ar(c, btmRight);
	ar_Vect = ar;

	MyVect tempCr(btmRight, c);
	tempCr = tempCr.multiBy(0.2);
	cr.setCoor(tempCr.getX() + btmRight.getX(), tempCr.getY() + btmRight.getY());
	this->cross = cr;

	MyVect nor = ar_Vect.getNormal();
	nor = nor.multiBy(0.2);
	
	Point* temp = new Point(this->start.getX(), this->start.getY());
	this->listOfPoint.push_back(temp); //Start
	temp = new Point(this->end.getX(), this->end.getY());
	this->listOfPoint.push_back(temp); //End

	temp = new Point(this->end.getX(), this->end.getY());
	this->listOfPoint.push_back(temp); //End
	temp = new Point(this->cross.getX() + nor.getX(), this->cross.getY() + nor.getY());
	this->listOfPoint.push_back(temp);//tren

	temp = new Point(this->end.getX(), this->end.getY());
	this->listOfPoint.push_back(temp);//end
	nor = nor.multiBy(-1);
	temp = new Point(this->cross.getX() + nor.getX(), this->cross.getY() + nor.getY());
	this->listOfPoint.push_back(temp);//duoi
	updateCenter();
}

void MuiTen::draw()
{
	setLibColor();
	
	glLineWidth(2);
	glBegin(GL_LINES);
	for (int i = 0; i < this->listOfPoint.size(); i++) {
		glVertex2f(this->listOfPoint[i]->getX(), this->listOfPoint[i]->getY());
	}
	glEnd();

}

string MuiTen::getType()
{
	return "Mui Ten";
}

Point MuiTen::getCenter()
{
	return this->center;
}

void MuiTen::fillColor(int x, int y, int colr_id)
{

}

void MuiTen::updateCenter()
{
	Point temp = this->listOfPoint[0]->midMointTo(*this->listOfPoint[1]);
	center.setCoor(temp.getX(), temp.getY());
}
