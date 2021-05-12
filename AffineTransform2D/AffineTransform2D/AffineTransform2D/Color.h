#ifndef COLOR_H_
#define COLOR_H_
#include <iostream>
using namespace std;

class RGBColor {
public:
	float r;
	float g;
	float b;
public:
	RGBColor(float rr, float gg, float bb);
	void setColor(float rr, float gg, float bb);
	RGBColor();
};

const RGBColor mauXanh(0.4f, 0.8f, 0.9f);
const RGBColor mauDo(0.9f, 0.2f, 0.1f);
const RGBColor mauVang(0.9f, 0.9f,0.3f);

const RGBColor mauVien(0.1f, 0.3f,0.5f);


RGBColor GetPixel(int x, int y);
void PutPixel(int x, int y, RGBColor color);
bool IsSameColor(RGBColor x, RGBColor y);
void BoundaryFill(int x, int y, RGBColor F_Color, RGBColor B_Color);
//void floodFill(int x, int y, RGBColor oldColor, RGBColor newColor);

#endif // !COLOR_H_
