#ifndef L_SHAPE_H
#define L_SHAPE_H

#include "shape.h"

struct LShape : public Shape
{
	LShape(Point position, Color color);

	virtual void rotate();

	virtual float topBorderPosition()		const;
	virtual float rightBorderPosition()		const;
	virtual float bottomBorderPosition()	const;
	virtual float leftBorderPosition()		const;
};

#endif //L_SHAPE_H
