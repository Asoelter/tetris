#ifndef BLOCK_H
#define BLOCK_H

#include "engine/src/bordered_square.h"
#include "engine/src/point.h"
#include "engine/src/color.h"

class Block : public BorderedSquare
{
	public:
		Block(Point position, Color color);

		static const float Dimension;
	private:
};

#endif //BLOCK_H
