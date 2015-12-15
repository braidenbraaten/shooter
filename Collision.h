#ifndef Collision_H
#define Collision_H

#include <cmath>
#include <math.h>
struct Point { float X, Y; };
Point operator-(Point lhs, Point rhs);


struct Rectangle;

struct Line2D;

struct Vector2
{
	float X, Y;
	Vector2() {}
	Vector2(float a, float b)
	{
		X = a;
		Y = b;
	}
};

struct Circle
{
	Vector2 P;
	double R = 0;

	Circle(Vector2 p, double r)
	{
		P = p;
		R = r;
	}
};



struct MapSegment;

Vector2 operator-(Vector2 lhs, Vector2 rhs);
class Collision
{
public:










	float Magnitude(Vector2 v);
	Vector2 VectorNormal(Vector2 v);

	Vector2 UnitVector(Vector2 v);

	float DotProduct(Vector2 u, Vector2 v);

	Vector2 ReflectedVector(Vector2 v, Vector2 a);



	bool CheckSegmentSegmentCollision(MapSegment s1, MapSegment s2);

	bool CheckRectangleCollision(Rectangle a, Rectangle b);

	bool CheckCircleSegmentCollision(Circle C, MapSegment S);

	bool CheckCircleCircleCollision(Circle C, Circle D);
};


#endif