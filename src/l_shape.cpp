#include "l_shape.h"

LShape::LShape(Point position, Color color)
	: Shape(position)
{
	Point p1(position.x() - (Block::Dimension / 2.0f), position.y() + Block::Dimension);
	Point p2(position.x() - (Block::Dimension / 2.0f), position.y()				   );
	Point p3(position.x() - (Block::Dimension / 2.0f), position.y() - Block::Dimension);
	Point p4(position.x() + (Block::Dimension / 2.0f), position.y() - Block::Dimension);

	Shape::blocks_[0] = std::make_unique<Block>(p1, color);
	Shape::blocks_[1] = std::make_unique<Block>(p2, color);
	Shape::blocks_[2] = std::make_unique<Block>(p3, color);
	Shape::blocks_[3] = std::make_unique<Block>(p4, color);
}

void LShape::rotate()
{
	switch(Shape::orientation())
	{
		case Orientation::UP:
			Shape::blocks_[0]->moveUp   (-1 * Block::Dimension);
			Shape::blocks_[0]->moveRight( 2 * Block::Dimension);
			Shape::blocks_[1]->moveRight( 1 * Block::Dimension);
			Shape::blocks_[2]->moveUp   ( 1 * Block::Dimension);
			Shape::blocks_[3]->moveRight(-1 * Block::Dimension);
		break;

		case Orientation::RIGHT:
			Shape::blocks_[0]->moveRight(-1 * Block::Dimension);
			Shape::blocks_[0]->moveUp   (-2 * Block::Dimension);
			Shape::blocks_[1]->moveUp   (-1 * Block::Dimension);
			Shape::blocks_[2]->moveRight( 1 * Block::Dimension);
			Shape::blocks_[3]->moveUp   ( 1 * Block::Dimension);
		break;

		case Orientation::DOWN:
			Shape::blocks_[0]->moveUp   ( 2 * Block::Dimension);
			Shape::blocks_[0]->moveRight(-2 * Block::Dimension);
			Shape::blocks_[1]->moveUp   ( 1 * Block::Dimension);
			Shape::blocks_[1]->moveRight(-1 * Block::Dimension);
			Shape::blocks_[3]->moveRight( 1 * Block::Dimension);
			Shape::blocks_[3]->moveUp   ( 1 * Block::Dimension);
		break;

		case Orientation::LEFT:
			Shape::blocks_[0]->moveUp   ( 1 * Block::Dimension);
			Shape::blocks_[0]->moveRight( 1 * Block::Dimension);
			Shape::blocks_[2]->moveRight(-1 * Block::Dimension);
			Shape::blocks_[2]->moveUp   (-1 * Block::Dimension);
			Shape::blocks_[3]->moveUp   (-2 * Block::Dimension);
		break;
	}

	Shape::rotate();
}

float LShape::topBorderPosition() const
{
	return Shape::yPos() + (1.5f * Block::Dimension);
}

float LShape::rightBorderPosition()	const
{
	return Shape::xPos() + Block::Dimension;
}

float LShape::bottomBorderPosition() const
{
	return Shape::yPos() - (1.5f * Block::Dimension);
}

float LShape::leftBorderPosition() const
{
	return Shape::xPos() - Block::Dimension;
}
