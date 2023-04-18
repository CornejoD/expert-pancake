//Diego Cornejo
//COSC 1436
//Created April 28 2022

#include <iostream>
#include "Circle.h"
using namespace std;

Circle::Circle(int x, int y, double r, Color color)
{
	setCoordinates(x, y);
	setRadius(r);
	setColor(color);
}

void Circle::setX(int newX)
{
	if (newX >= 0 && newX <= 100)
		x = newX;
	else
		x = 0;
}

void Circle::setY(int y)
{
	if (y >= 0 && y <= 100)
		this->y = y;
	else 
		this->y = 0;
}

void Circle::setCoordinates(int x, int y)
{
	setX(x);
	setY(y);
}

void Circle::setRadius(double r)
{
	if (r >= 0 && r <= 50)

		if (x - r >= 0 && x + r <= 100 && y - r >= 0 && y + r <= 100)
		{
			radius = r;
		}
		else
			radius = 0;
	else
		radius = 0;
}

void Circle::setColor(Color c)
{
	if (c >= UNDEFINED && c <= YELLOW)
	{
		color = c;
	}
	else
	{
		color = UNDEFINED;
	}
}

int Circle::getX() const
{
	return x;
}

int Circle::getY() const
{
	return y;
}

double Circle::getRadius() const
{
	return radius;
}

double Circle::getArea() const
{
	double area;
	area = (radius * radius) * 3.14159;
	return area;
}

double Circle::getCircumference() const
{
	return (radius * 2) * 3.14159;
}

Circle::Color Circle::getColor() const
{
	return color;
}

string Circle::displayCircleColor() const
{

	switch (color)
	{
	case Circle::UNDEFINED:
		return "UNDEFINED";
	case Circle::BLACK:
		return "BLACK";
	case Circle::RED:
		return "RED";
	case Circle::BLUE:
		return "BLUE";
	case Circle::GREEN:
		return "GREEN";
	case Circle::YELLOW:
		return "YELLOW";
	default:
		return "UNDEFINED";
	}

	/*switch (color)
	{
	case UNDEFINED: return "UNDEFINED";

	case BLACK: return "BLACK";

	case RED: return "RED";

	case BLUE: return "BLUE";

	case GREEN: return "GREEN";

	default: return "UNDEFINED";
	}
	*/
}

void Circle::displayCircle() const
{
	cout << "x-coordinate:\t" << getX() << endl;
	cout << "y-coordinate:\t" << getY() << endl;
	cout << "Radius:\t\t" << getRadius() << endl;
	cout << "Color:\t\t" << displayCircleColor() << endl;
	cout << "Area:\t\t" << getArea() << endl;
	cout << "Circumference:\t" << getCircumference() << endl;
}

bool Circle::operator==(const Circle& aCircle) const
{
	if (x == aCircle.x && y == aCircle.y &&
			radius == aCircle.radius && color == aCircle.color)
		return true;
	else
		return false;
}
