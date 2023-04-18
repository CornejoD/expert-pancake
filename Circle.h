//Diego Cornejo

//#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H


#include <string>

using namespace std;

class Circle
{
public:
	enum Color { UNDEFINED, BLACK, RED, BLUE, GREEN, YELLOW };

private:
	int x, y;		//coordinates for the circle center point
	double radius;	//radius of a cirlce
	Color color;	//The color of a Circle
	
public:

	Circle(int x = 0, int y = 0, double radius = 0.0, Color color = UNDEFINED); //calls the member mutator functions
	void setX(int newX); //Receives an int for x and validates that it is a valid position on a grid(0 - 100)
	void setY(int y); //Receives an int for y and validates that it is a valid position on a grid(0 - 100)
	void setCoordinates(int x, int y); //receives two in arguments for the x and y coordinates
	void setRadius(double r); //Receives a double for the radius and validates that it is valid
	void setColor(Color color); // receives a Color object and validates that it is in the enumerator list range

	int getX() const;				//returns the private member x as an int
	int getY() const;				//returns the private meber y as an int
	double getRadius() const;		//returns the private member radius
	double getArea() const;			//returns the calculated area: Area = PIr2
	double getCircumference() const; //returns the calculated value: 2PIr
	Circle::Color getColor() const;		//returns the private member color as a Color object
	string displayCircleColor() const;	//returns the orivate member color name as a string
	void displayCircle() const;			 //Display Circle Attributes
	bool operator==(const Circle& aCircle) const;

};

#endif // !CIRCLE_H




