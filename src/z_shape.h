#ifndef Z_SHAPE_H
#define Z_SHAPE_H

#include "shape.h"

struct ZShape : public Shape
{
	ZShape(Point position, Color color);

	virtual void rotate();
};

#endif //Z_SHAPE_H
