#include "Color.h"
#include "glut.h"
#include "Painter.h"
RGBColor GetPixel(int x, int y)
{
	float* ptr = new float[3];
	ptr[0] = 1.0f;
	ptr[1] = 1.0f;
	ptr[2] = 1.0f;

	glReadPixels(x, h- y, 1, 1, GL_RGB, GL_FLOAT, ptr);

	RGBColor color;
	color.setColor(ptr[0], ptr[1], ptr[2]);

	//if(!(x<0 || x> h || y< 0 || y>h))
	//	cout << color.r << " co vo day k " << color.g << " co vo day k " << color.b << endl;
	return color;
}

void PutPixel(int x, int y, RGBColor color) {
	float* ptr = new float[3];
	ptr[0] = color.r;
	ptr[1] = color.g;
	ptr[2] = color.b;

	glRasterPos2i(x, y);
	glPointSize(2);
	glDrawPixels(1, 1, GL_RGB, GL_FLOAT, ptr);

	glFlush();
}

bool IsSameColor(RGBColor x, RGBColor y) {
	if (abs(x.r - y.r)< 0.01 && abs(x.b - y.b) < 0.01 && abs(x.g - y.g) <0.01) {
		/*cout << "is same color true" << endl;*/
		return true;
	}
	else {
		//cout << "is same color false" << endl;
		return false;
	}
}

void BoundaryFill(int x, int y, RGBColor F_Color, RGBColor B_Color) {
	RGBColor currentColor;
	//cout << x << " " << y << "in BoFi" << endl;
	currentColor = GetPixel(x, y);
	//cout << currentColor.r << " g: " << currentColor.g << " b: " << currentColor.b << endl;
	//cout << x << "y: " << y << " h: " << h << endl;
	if (!IsSameColor(currentColor, B_Color) && !IsSameColor(currentColor, F_Color)&& x<h && y<h && x>0 && y>0) {

		//cout << F_Color.r << " FIllColor: " << F_Color.g << " b: " << F_Color.b << endl;
		//cout << B_Color.r << " BouColor: " << B_Color.g << " b: " << B_Color.b << endl;
		PutPixel(x, y, F_Color);
		BoundaryFill(x -1, y, F_Color, B_Color);
		BoundaryFill(x, y + 1, F_Color, B_Color);
		BoundaryFill(x + 1, y, F_Color, B_Color);
		BoundaryFill(x, y - 1, F_Color, B_Color);
	}
}

//void floodFill(int x, int y, RGBColor oldColor, RGBColor newColor) {
//	RGBColor color;
//	color = GetPixel(x, y);
//
//	if (!IsSameColor(oldColor,newColor))
//	{
//		PutPixel(x, y, newColor);
//		floodFill(x + 1, y, oldColor, newColor);
//		floodFill(x, y + 1, oldColor, newColor);
//		floodFill(x - 1, y, oldColor, newColor);
//		floodFill(x, y - 1, oldColor, newColor);
//	}
//	return;
//}

RGBColor::RGBColor(float rr, float gg, float bb)
{
	r = rr;
	g = gg;
	b = bb;
}

void RGBColor::setColor(float rr, float gg, float bb)
{
	r = rr;
	g = gg;
	b = bb;
}

RGBColor::RGBColor()
{
}
