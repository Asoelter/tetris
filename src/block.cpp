#include "block.h"

Block::Block(Point position, Color color)
	: BorderedSquare(position, Block::Dimension, color, Color(Shade::BLACK))
{

}

