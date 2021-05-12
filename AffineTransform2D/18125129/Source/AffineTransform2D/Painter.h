
#include <iostream>
#include <vector>
#include "glut.h"
#include "Shape.h"

const int h = 500; //the height of window

const int id_Oval = 1;
const int id_HinhTron = 11;
const int id_Ellipse = 12;

const int id_TamGiac = 2;
const int id_TgVuongCan = 21;
const int id_TgDeu = 22;

const int id_TuGiac = 3;
const int id_HinhChuNhat = 31;
const int id_HinhVuong = 32;

const int id_Line = 4;

const int id_DaGiacDeu = 5;
const int id_NguGiacDeu = 51;
const int id_LucGiacDeu = 52;

const int id_HinhKhac = 6;
const int id_NgoiSao = 61;
const int id_MuiTen = 62;

const int id_Dau = 7;
const int id_DauCong = 71;
const int id_DauTru = 72;
const int id_DauNhan = 73;
const int id_DauChia = 74;

const int id_Dagiackhac = 9;

#define mauVang_id  81
#define mauDo_id  82
#define mauXanh_id  83

#define Floodfill 101
#define Boundary 100





using namespace std;
//Class Painter creates only 1 obj
class Painter {
private:
	
	static Painter* instance;
	int selected;
	vector<Shape*> listOfShape;
public:
	Painter();
	~Painter();
	Painter(Painter const&) = delete;
	void operator=(Painter const&) = delete;
	Shape* getSelected();
	void setSelected(int i);
	vector<Shape*> getList();
	static Painter* getInstance();
	void addShape(Shape* a);
	void showList();
	void fillColor(int x, int y, int color_id);
	void translateSelected(string state); //up, down, left, right
	void scaleSelected(string state); // up, down
	void rotateSelected(string state); //left, right
};

