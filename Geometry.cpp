#include <local.h>

const long double eps = 1e-9;
const long double PI = acos(-1);
inline int sign(long double x) { return (x > eps) - (x < -eps); }

struct Point {
    long double x = 0, y = 0;
    Point() {}
    Point(long double x, long double y = 0) : x(x), y(y) {}

    void read() { cin >> x >> y; }
	void show() { cout << x << ' ' << y << '\n'; }

    Point operator+ (const Point &a) { return Point(x + a.x, y + a.y); }
    Point operator- (const Point &a) { return Point(x - a.x, y - a.y); }
	Point operator* (long double a) { return Point(x * a, y * a); }
	Point operator/ (long double a) { return Point(x / a, y / a); }
    bool operator== (Point a) { return sign(x - a.x) == 0 && sign(y - a.y) == 0; }
    bool operator!= (Point a) { return !(*this == a); }
    bool operator< (Point a) { return sign(x - a.x) == 0 ? y < a.y : x < a.x; }
    bool operator> (Point a) { return sign(x - a.x) == 0 ? y > a.y : x > a.x; }

	long double mdist() { return abs(x) + abs(y); } // manhattan distance
    long double sqdist() { return x * x + y * y; } // square distance
    long double dist() { return sqrt(mdist()); } // euclidean distance
};

inline long double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
inline long double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }


//*  checks if a shape can be fromed using some point
struct Shape {
	//Finds squared euclidean distance between two points
	int dist(Point &a, Point &b) {
		return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	}

	//Checks if angle ABC is a right angle
	bool isOrthogonal(Point &a, Point &b, Point &c) {
		return (b.x - a.x) * (b.x - c.x) + (b.y - a.y) * (b.y - c.y) == 0;
	}

	//Checks if ABCD form a rectangle (in that order)
	bool isRectangle(Point &a, Point &b, Point &c, Point &d) {
		return isOrthogonal(a, b, c) && isOrthogonal(b, c, d) && isOrthogonal(c, d, a);
	}

	//Checks if ABCD form a rectangle, in any orientation
	bool isRectangleAnyOrder(Point &a, Point &b, Point &c, Point &d) {
		return isRectangle(a, b, c, d) || isRectangle(b, c, a, d) || isRectangle(c, a, b, d);
	}

	//Checks if ABCD form a square (in that order)
	bool isSquare(Point &a, Point &b, Point &c, Point &d) {
		return isRectangle(a, b, c, d) && dist(a, b) == dist(b, c);
	}

	//Checks if ABCD form a square, in any orientation
	bool isSquareAnyOrder(Point &a, Point &b, Point &c, Point &d) {
		return isSquare(a, b, c, d) || isSquare(b, c, a, d) || isSquare(c, a, b, d);
	}
} shape;