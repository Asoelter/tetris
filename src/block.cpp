#include "block.h"

const float Block::Dimension = 0.05f;

Block::Block(Point position, Color color)
	: BorderedSquare(position, Block::Dimension, color, Color(Shade::BLACK))
{

}

