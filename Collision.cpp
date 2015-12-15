#include "Collision.h"

Point operator-(Point lhs, Point rhs) { return Point{ lhs.X - rhs.X, lhs.Y - rhs.Y }; }



struct Rectangle
{
	Point a, b, c, d;

	Rectangle(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy)
	{
		a.X = ax;
		a.Y = ay;
		b.X = bx;
		b.Y = by;
		c.X = cx;
		c.Y = cy;
		d.X = dx;
		d.Y = dy;
	}

	Rectangle(float startPosX, float startPosY, float width, float height)
	{
		a.X = startPosX;
		a.Y = startPosY;
		b.X = width;
		b.Y = a.Y;
		c.X = width;
		c.Y = height;
		d.X = a.X;
		d.Y = height;
	}

};

struct Line2D
{
	Vector2 P;
	Vector2 V;

	//Creates a 2D line segment
	Line2D() {}
	Line2D(float pX, float pY, float vX, float vY)
	{
		P.X = pX;
		P.Y = pY;
		V.X = vX;
		V.Y = vY;
	}

	float yInt()
	{
		return{ (-V.Y * P.X + V.X * P.Y) / V.X };
	}
	float Slope()
	{
		return{ V.Y / V.X };

	}
};



struct MapSegment
{
	Point p1;
	Point p2;
	MapSegment(Point a, Point b)
	{
		p1 = a;
		p2 = b;
	}
	MapSegment(Line2D line)
	{
		p1.X = line.P.X;
		p1.Y = line.P.Y;
		p2.X = line.V.X;
		p2.Y = line.V.Y;
	}
	Vector2 GetVector()
	{
		return Vector2{ p2.X - p1.X, p2.Y - p1.Y };
	}
	Rectangle CollisionRect()
	{
		//return{ Rectangle(std::fmin(p1.X, p2.X), std::fmin(p1.Y, p2.Y), std::abs(p1.X - p2.X), std::abs(p1.Y - p2.Y)) };
		return{ Rectangle(p1.X,p1.Y, std::abs(p1.X - p2.X), std::abs(p1.Y - p2.Y)) };
	}
};

Vector2 operator-(Vector2 lhs, Vector2 rhs) { return Vector2{ lhs.X - rhs.X, lhs.Y - rhs.Y }; }

float Collision::Magnitude(Vector2 v) { return{ (float)std::sqrt(v.X * v.X + v.Y * v.Y) }; };

Vector2 Collision::VectorNormal(Vector2 v)
{
	return{ Vector2(-v.Y, v.X) };
}

Vector2 Collision::UnitVector(Vector2 v)
{
	return{ Vector2(v.X / Magnitude(v), v.Y / Magnitude(v)) };
}

float Collision::DotProduct(Vector2 u, Vector2 v)
{
	return{ u.X * v.X + u.Y * v.Y };
}

Vector2 Collision::ReflectedVector(Vector2 v, Vector2 a)
{
	Vector2 n = VectorNormal(a);
	float co = -2 * (DotProduct(v, n) / (Magnitude(n) * Magnitude(n)));
	Vector2 r;
	r.X = v.X + co * n.X;
	r.Y = v.Y + co * n.Y;
	return r;
}

//bool Collision::CheckSegmentSegmentCollision(MapSegment s1, MapSegment s2)
//{
//	Line2D L1, L2;
//	L1.P = Vector2(s1.p1.X, s1.p1.Y);
//	L2.P = Vector2(s2.p1.X, s2.p1.Y);
//	L1.V.X = s1.p2.X - s1.p1.X;
//	L1.V.Y = s1.p2.Y - s1.p1.Y;
//	L2.V.X = s1.p2.X - s1.p1.X;
//	L2.V.Y = s1.p2.Y - s1.p1.Y;
//	Vector2 CollisionPoint;
//	CollisionPoint.X = (L2.yInt() - L1.yInt()) / (L1.Slope() - L2.Slope());
//	CollisionPoint.Y = L1.Slope() * CollisionPoint.X + L1.yInt();
//
//	bool cond1 = (std::fmin(s1.p1.X, s1.p2.X) <= CollisionPoint.X && CollisionPoint.X <= std::fmax(s1.p1.X, s1.p2.X));
//
//	bool cond2 = (std::fmin(s2.p1.X, s2.p2.X) <= CollisionPoint.X && CollisionPoint.X <= std::fmax(s2.p1.X, s2.p2.X));
//
//	bool cond3 = (std::fmin(s1.p1.Y, s1.p2.Y) <= CollisionPoint.Y && CollisionPoint.Y <= std::fmax(s1.p1.Y, s1.p2.Y));
//
//	bool cond4 = (std::fmin(s2.p1.Y, s2.p2.Y) <= CollisionPoint.Y && CollisionPoint.Y <= std::fmax(s2.p1.Y, s2.p2.Y));
//
//	return cond1 && cond2 && cond3 && cond4;
//}
//
//bool Collision::CheckRectangleCollision(Rectangle a, Rectangle b)
//{
//
//	//How the line naming system works
//	// Lhs,point to start, point to end
//	//Lab =  Lhs, Point a, Point b      dont forget about Vector normals!!
//	Line2D Lab;
//	Lab.P.X = a.a.X;
//	Lab.P.Y = a.a.Y;
//	Lab.V.X = a.b.X;
//	Lab.V.Y = a.b.Y;
//	Line2D Lbc;
//	Lbc.P.X = a.b.X;
//	Lbc.P.Y = a.b.Y;
//	Lbc.V.X = a.c.X;
//	Lbc.V.Y = a.c.Y;
//	Line2D Lcd;
//	Lcd.P.X = a.c.X;
//	Lcd.P.Y = a.c.Y;
//	Lcd.V.X = a.d.X;
//	Lcd.V.Y = a.d.Y;
//	Line2D Lda;
//	Lda.P.X = a.d.X;
//	Lda.P.Y = a.d.Y;
//	Lda.V.X = a.a.X;
//	Lda.V.Y = a.a.Y;
//
//	/*
//	/////////////////////// Rectangle B \\\\\\\\\\\\\\\\\\\\\\\\
//	*/
//
//	Line2D rab;
//	rab.P.X = b.a.X;
//	rab.P.Y = b.a.Y;
//	rab.V.X = b.b.X;
//	rab.V.Y = b.b.Y;
//	Line2D rbc;
//	rbc.P.X = b.b.X;
//	rbc.P.Y = b.b.Y;
//	rbc.V.X = b.c.X;
//	rbc.V.Y = b.c.Y;
//	Line2D rcd;
//	rcd.P.X = b.c.X;
//	rcd.P.Y = b.c.Y;
//	rcd.V.X = b.d.X;
//	rcd.V.Y = b.d.Y;
//	Line2D rda;
//	rda.P.X = b.d.X;
//	rda.P.Y = b.d.Y;
//	rda.V.X = b.a.X;
//	rda.V.Y = b.a.Y;
//
//	return CheckSegmentSegmentCollision(Lab, rab);
//	
//}

//bool Collision::CheckCircleSegmentCollision(Circle C, MapSegment S)
//{
//
//	Line2D L;
//	L.P.X = S.p1.X;
//	L.P.Y = S.p1.Y;
//	L.V.X = S.p2.X - S.p1.X;
//	L.V.Y = S.p2.Y - S.p1.Y;
//
//
//	double OH = std::abs(((L.V.X * (C.P.Y)) - (L.V.Y * (C.P.X - L.P.X))) / (std::sqrt(L.V.X * L.V.X + L.V.Y * L.V.Y)));
//
//	if (OH <= C.R)
//	{
//		Vector2 CollisionPoint1;
//		Vector2 CollisionPoint2;
//
//		if (L.V.X != 0)
//		{
//			double Dv = L.V.Y / L.V.X;
//			double E = (L.V.X * L.P.Y - L.V.Y * L.P.X) / L.V.X - C.P.Y;
//
//			double a = 1 + Dv * Dv;
//			double b = -2 * C.P.X + 2 * E * Dv;
//			double c = C.P.X * C.P.X + E * E - C.R * C.R;
//
//			CollisionPoint1.X = (float)((-b + std::sqrt(b * b - 4 * a * c)) / (2 * a));
//			CollisionPoint2.X = (float)((-b - std::sqrt(b * b - 4 * a * c)) / (2 * a));
//			CollisionPoint1.Y = L.Slope() * CollisionPoint1.X + L.yInt();
//			CollisionPoint2.Y = L.Slope() * CollisionPoint1.X + L.yInt();
//
//			bool cond1 = (std::fmin(S.p1.X, S.p2.X) <= CollisionPoint1.X && CollisionPoint1.X <= std::fmax(S.p1.X, S.p2.X));
//
//			bool cond2 = (std::fmin(S.p1.Y, S.p2.Y) <= CollisionPoint1.Y && CollisionPoint1.Y <= std::fmax(S.p1.Y, S.p2.Y));
//
//			bool cond3 = (std::fmin(S.p1.X, S.p2.X) <= CollisionPoint2.X && CollisionPoint2.X <= std::fmax(S.p1.X, S.p2.X));
//
//			bool cond4 = (std::fmin(S.p1.Y, S.p2.Y) <= CollisionPoint2.Y && CollisionPoint2.Y <= std::fmax(S.p1.Y, S.p2.Y));
//
//			return (cond1 && cond2) || (cond3 && cond4);
//		}
//	}
//
//	return false;
//}

bool Collision::CheckCircleCircleCollision(Circle C, Circle D)
{
	if (C.R + D.R >= Magnitude(D.P - C.P))
	{
		return true;
	}
	return false;
}

