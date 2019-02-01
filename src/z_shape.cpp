#include "z_shape.h"


ZShape::ZShape(Point position, Color color)
	: Shape(position)
{
	Point p1(position.x() - Block::Dimension, position.y() + (Block::Dimension / 2));
	Point p2(position.x()					, position.y() + (Block::Dimension / 2));
	Point p3(position.x()					, position.y() - (Block::Dimension / 2));
	Point p4(position.x() + Block::Dimension, position.y() - (Block::Dimension / 2));
	
	Shape::blocks_[0] = std::make_unique<Block>(p1, color);
	Shape::blocks_[1] = std::make_unique<Block>(p2, color);
	Shape::blocks_[2] = std::make_unique<Block>(p3, color);
	Shape::blocks_[3] = std::make_unique<Block>(p4, color);
}

void ZShape::rotate()
{
	auto& block1 = Shape::blocks_[0];
	auto& block3 = Shape::blocks_[2];
	auto& block4 = Shape::blocks_[3];

	switch(Shape::orientation())
	{
		case Orientation::UP:
		case Orientation::DOWN:
			block1->moveUp	 ( 1 * Block::Dimension);
			block1->moveRight( 1 * Block::Dimension);
			block3->moveUp   ( 1 * Block::Dimension);
			block3->moveRight(-1 * Block::Dimension);
			block4->moveRight(-2 * Block::Dimension);
		break;

		case Orientation::RIGHT:
		case Orientation::LEFT:
			block1->moveUp	 (-1 * Block::Dimension);
			block1->moveRight(-1 * Block::Dimension);
			block3->moveUp   (-1 * Block::Dimension);
			block3->moveRight( 1 * Block::Dimension);
			block4->moveRight( 2 * Block::Dimension);
		break;
	}

	Shape::rotate();
}

float ZShape::topBorderPosition() const
{
	return Shape::yPos() + Block::Dimension;
}

float ZShape::rightBorderPosition()	const
{
	return Shape::xPos() + (1.5f * Block::Dimension);
}

float ZShape::bottomBorderPosition() const
{
	return Shape::yPos() - Block::Dimension;
}

float ZShape::leftBorderPosition() const
{
	return Shape::xPos() - (1.5f * Block::Dimension);
}
