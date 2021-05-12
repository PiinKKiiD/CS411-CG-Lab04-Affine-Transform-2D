#pragma once
#ifndef POINT_H_
#define POINT_H_
#include <glm/glm.hpp>

class MyVect;
class Point {
private:
	float x;
	float y;
public:
	Point(float xx, float yy);
	Point();
	float distanceTo(Point B);
	void setCoor(float xx, float yy);
	void setEqual(Point B);
	float getX();
	float getY();
	void operator=(Point b);
	Point midMointTo(Point b);
	glm::vec3 getVec3();
	glm::vec3 translate(float xx, float yy, float zz);
	glm::vec3 scale(float xx, float yy, float zz);
	glm::vec3 rotate(float degree, float xx, float yy, float zz);
	void moveFollow(MyVect tt);
};

#endif // !POINT_H_
