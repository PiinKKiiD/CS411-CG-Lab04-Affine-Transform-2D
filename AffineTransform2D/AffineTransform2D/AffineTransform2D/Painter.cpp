#include "Painter.h"
#include "MyVect.h"
#include <glm/glm.hpp>
#include <vector>
Painter* Painter::instance = NULL;

Painter::~Painter()
{
	if (instance)
	{
		instance = NULL;
		listOfShape.clear();
	}
}

Painter::Painter()
{
	cout << "Create 1" << endl;
	selected = -1;
}

Shape* Painter::getSelected()
{
	if (listOfShape.size() > 0 && selected > -1) {
		return listOfShape[selected];
	}
	return NULL;
}

void Painter::setSelected(int i)
{
	selected = i;
	for (int j = 0; j < listOfShape.size(); j++) {
		listOfShape[j]->setSelected(false);
	}
	listOfShape[i]->setSelected(true);
}

vector<Shape*> Painter::getList()
{
	return listOfShape;
}

Painter* Painter::getInstance() {
	if (instance == NULL) {
		instance = new Painter();
	}
	return instance;
}

void Painter::addShape(Shape* a)
{
	listOfShape.push_back(a);
}

void Painter::showList()
{
	cout << &listOfShape << endl;
}

void Painter::fillColor(int x, int y, int color_id)
{
	if (listOfShape.size() == 0)
		return;
	Point pickedPoint(x, y);
	Shape* pickedShape = listOfShape[0];
	float minDis = pickedPoint.distanceTo(listOfShape[0]->getCenter());
	for (int i = 1; i < listOfShape.size(); i++) {
		if(pickedPoint.distanceTo(listOfShape[i]->getCenter())<minDis){
			minDis = pickedPoint.distanceTo(listOfShape[i]->getCenter());
			pickedShape = listOfShape[i];
		}
	}
	//if (pickedShape->getType() == "Line" || pickedShape->getType()=="Mui Ten") {

	//	return;
	//}
	//if (color_id == mauDo_id) {
	//	BoundaryFill(x,y, mauDo, mauVien);
	//}
	//else if (color_id == mauVang_id) {
	//	BoundaryFill(x,y, mauVang, mauVien);
	//}
	//else if (color_id == mauXanh_id) {
	//	BoundaryFill(x,y, mauXanh, mauVien);
	//}
	//cout << "int painter filco" << endl;
	pickedShape->fill = color_id;
}

void Painter::translateSelected(string state)
{
	if (selected == -1)
		return;
	Shape* selectedOj = listOfShape[selected];
	glm::vec3 translated;
	if (state == "DOWN") {
		for (int i = 0; i < selectedOj->listOfPoint.size(); i++) {
			translated = selectedOj->listOfPoint[i]->translate(0, 1, 0);
			selectedOj->listOfPoint[i]->setCoor(translated[0], translated[1]);
		}
	}
	else if (state == "UP") {
		for (int i = 0; i < selectedOj->listOfPoint.size(); i++) {
			translated = selectedOj->listOfPoint[i]->translate(0, -1, 0);
			selectedOj->listOfPoint[i]->setCoor(translated[0], translated[1]);

		}
	}
	else if (state == "LEFT") {
		for (int i = 0; i < selectedOj->listOfPoint.size(); i++) {
			translated = selectedOj->listOfPoint[i]->translate(-1, 0, 0);
			selectedOj->listOfPoint[i]->setCoor(translated[0], translated[1]);

		}
	}
	else if (state == "RIGHT") {
		for (int i = 0; i < selectedOj->listOfPoint.size(); i++) {
			translated = selectedOj->listOfPoint[i]->translate(1, 0, 0);
			selectedOj->listOfPoint[i]->setCoor(translated[0], translated[1]);

		}
	}
	selectedOj->updateCenter();
}

void Painter::scaleSelected(string state)
{
	if (selected == -1)
		return;
	Shape* selectedOj = listOfShape[selected];
	glm::vec3 scaled;
	if (state == "UP") {
		Point oldCenter = selectedOj->getCenter();
		for (int i = 0; i < selectedOj->listOfPoint.size(); i++) {
			scaled = selectedOj->listOfPoint[i]->scale(1.1, 1.1, 1.1);//Lat viet tiep
			selectedOj->listOfPoint[i]->setCoor(scaled[0], scaled[1]);
		}
		selectedOj->updateCenter();
		Point newCen = selectedOj->getCenter();
		MyVect ttVect= MyVect(newCen, oldCenter);
		selectedOj->moveFollow(ttVect);
	}
	else if (state == "DOWN") {
		Point oldCenter = selectedOj->getCenter();
		for (int i = 0; i < selectedOj->listOfPoint.size(); i++) {
			scaled = selectedOj->listOfPoint[i]->scale(0.9, 0.9,0.9);//Lat viet tiep
			selectedOj->listOfPoint[i]->setCoor(scaled[0], scaled[1]);
		}
		selectedOj->updateCenter();
		Point newCen = selectedOj->getCenter();
		MyVect ttVect = MyVect(newCen, oldCenter);
		selectedOj->moveFollow(ttVect);
	}
}

void Painter::rotateSelected(string state)
{
	if (selected == -1)
		return;
	Shape* selectedOj = listOfShape[selected];
	glm::vec3 rotated;
	Point oldCenter = selectedOj->getCenter();
	Point o(0, 0);
	MyVect moveToO(oldCenter, o);
	selectedOj->moveFollow(moveToO);
	selectedOj->updateCenter();
	if (state == "LEFT") {
		
		for (int i = 0; i < selectedOj->listOfPoint.size(); i++) {
			rotated = selectedOj->listOfPoint[i]->rotate(10 , 0.0f, 0.0f, 1.0f);//Lat viet tiep
			selectedOj->listOfPoint[i]->setCoor(rotated[0], rotated[1]);
		}
		
	}
	else if (state == "RIGHT") {
		for (int i = 0; i < selectedOj->listOfPoint.size(); i++) {
			rotated = selectedOj->listOfPoint[i]->rotate(-10.0, 0.0f, 0.0f, 1.0f);//Lat viet tiep
			selectedOj->listOfPoint[i]->setCoor(rotated[0], rotated[1]);
		}
	}
	selectedOj->moveFollow(moveToO.multiBy(-1));
	selectedOj->updateCenter();
}

