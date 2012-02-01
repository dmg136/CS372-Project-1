#include <stdlib.h>
#include <math.h>

#include "point.h"

void point_translate(Point *p, double x, double y)
{
	point_set(p, x, y);
}

double point_distance(const Point *p1, const Point *p2)
{
	//d = sqrt( (x2 - x1)^2 + (y2 - y1)^2 )
	return sqrt( (point_getX(p2) -  point_getX(p1)) * (point_getX(p2) - point_getX(p1)) + (point_getY(p2) - point_getY(p1)) * (point_getY(p2) - point_getY(p1)) );
}
