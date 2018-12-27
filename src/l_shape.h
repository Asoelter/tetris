#ifndef L_SHAPE_H
#define L_SHAPE_H

#include <array>
#include <algorithm>

#include "shape.h"

struct LShape : public Shape
{
	LShape(Point position, Color color);

	virtual void rotate();
};

#endif //L_SHAPE_H
