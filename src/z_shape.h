#ifndef Z_SHAPE_H
#define Z_SHAPE_H

#include "shape.h"

struct ZShape : public Shape
{
	ZShape(Point position, Color color);

	virtual void rotate();

	virtual float topBorderPosition()		const;
	virtual float rightBorderPosition()		const;
	virtual float bottomBorderPosition()	const;
	virtual float leftBorderPosition()		const;
};

#endif //Z_SHAPE_H
