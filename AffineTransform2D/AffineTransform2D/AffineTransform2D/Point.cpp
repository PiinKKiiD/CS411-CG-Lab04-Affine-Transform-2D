#include <math.h>
#include "Point.h"
#include "MyVect.h"

Point::Point(float xx, float yy)
{
	this->x = xx;
	this->y = yy;
}

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

float Point::distanceTo(Point B)
{
	float dx = this->x - B.x;
	float dy = this->y - B.y;
	float ret = dx * dx + dy * dy;
	return sqrt(ret);
}

void Point::setCoor(float xx, float yy)
{
	this->x = xx;
	this->y = yy;
	return;
}

void Point::setEqual(Point B)
{
	this->x = B.x;
	this->y = B.y;
}

float Point::getX()
{
	return this->x;
}

float Point::getY()
{
	return this->y;
}

void Point::operator=(Point b)
{
	this->x = b.x;
	this->y = b.y;
}

Point Point::midMointTo(Point b)
{
	return Point((this->x + b.x) / 2, (this->y + b.y) / 2);
}

glm::vec3 Point::getVec3()
{
	return glm::vec3(this->x,this->y,0.0f);
}

glm::vec3 Point::translate(float xx, float yy, float zz)
{
	glm::vec4 translateVertex = glm::vec4(this->getVec3(), 1.0);
	translateVertex = translateVertex * glm::mat4(1.0f, 0.0f, 0.0f, xx,
												  0.0f, 1.0f, 0.0f, yy,
												  0.0f, 0.0f, 1.0f, zz,
												  0.0f, 0.0f, 0.0f, 1.0f);
	return glm::vec3(translateVertex[0], translateVertex[1], translateVertex[2]);
}

glm::vec3 Point::scale(float xx, float yy, float zz)
{
	glm::vec4 scaleVertex = glm::vec4(this->getVec3(), 1.0);
	scaleVertex = scaleVertex * glm::mat4(xx, 0.0f, 0.0f, 0.0f,
										  0.0f, yy, 0.0f, 0.0f,
										  0.0f, 0.0f, zz, 0.0f,
										  0.0f, 0.0f, 0.0f, 1.0f);
	return glm::vec3(scaleVertex[0], scaleVertex[1], scaleVertex[2]);
}

glm::vec3 Point::rotate(float degree, float xx, float yy, float zz)
{
	float radians = glm::radians(degree);
	glm::mat4 rotateX = glm::mat4(1.0f, 0.0f, 0.0f, 0.0f,
								  0.0f, cos(radians), -sin(radians), 0.0f,
								  0.0f, sin(radians), cos(radians), 0.0f,
								  0.0f, 0.0f, 0.0f, 1.0f);
	glm::mat4 rotateY = glm::mat4(cos(radians), 0.0f, sin(radians), 0.0f,
								  0.0f, 1.0f, 0.0f, 0.0f,
								  -sin(radians), 0.0f, cos(radians), 0.0f,
								  0.0f, 0.0f, 0.0f, 1.0f);
	glm::mat4 rotateZ = glm::mat4(cos(radians), -sin(radians), 0.0f, 0.0f,
								  sin(radians), cos(radians), 0.0f, 0.0f,
								  0.0f, 0.0f, 1.0f, 0.0f,
								  0.0f, 0.0f, 0.0f, 1.0f);

	glm::vec4 rotateVertex = glm::vec4(this->getVec3(), 1.0f);
	if (xx == 1.0f)
		rotateVertex = rotateVertex * rotateX;
	if (yy == 1.0f)
		rotateVertex = rotateVertex * rotateY;
	if (zz == 1.0f)
		rotateVertex = rotateVertex * rotateZ;
	return glm::vec3(rotateVertex[0], rotateVertex[1], rotateVertex[2]);
}

void Point::moveFollow(MyVect tt)
{
	x += tt.getX();
	y += tt.getY();
}
