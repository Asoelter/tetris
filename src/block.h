#ifndef BLOCK_H
#define BLOCK_H

#include "engine/src/bordered_square.h"
#include "engine/src/point.h"
#include "engine/src/color.h"

struct Block : public BorderedSquare
{
	Block(Point position, Color color);

	static constexpr float Dimension = 0.08f;
};

#endif //BLOCK_H
