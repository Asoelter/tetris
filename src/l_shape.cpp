#include "l_shape.h"

LShape::LShape(Point position, Color color)
	: Shape(position)
{
	Point p1(position.x() - (Block::Dimension / 2), position.y() + Block::Dimension);
	Point p2(position.x() - (Block::Dimension / 2), position.y()					);
	Point p3(position.x() - (Block::Dimension / 2), position.y() - Block::Dimension);
	Point p4(position.x() + (Block::Dimension / 2), position.y() - Block::Dimension);

	Shape::blocks_[0] = std::make_unique<Block>(p1, color);
	Shape::blocks_[1] = std::make_unique<Block>(p2, color);
	Shape::blocks_[2] = std::make_unique<Block>(p3, color);
	Shape::blocks_[3] = std::make_unique<Block>(p4, color);
}

void LShape::rotate()
{
	//TODO: Implement rotation
	switch(Shape::orientation())
	{
		case Orientation::UP:
			std::cout << "UP" << std::endl;
			Shape::blocks_[0]->moveUp   (-1 * Block::Dimension);
			Shape::blocks_[0]->moveRight( 2 * Block::Dimension);
			Shape::blocks_[1]->moveRight( 1 * Block::Dimension);
			Shape::blocks_[2]->moveUp   ( 1 * Block::Dimension);
			Shape::blocks_[3]->moveRight(-1 * Block::Dimension);
		break;

		case Orientation::RIGHT:
			std::cout << "RIGHT" << std::endl;
			Shape::blocks_[0]->moveRight(-1 * Block::Dimension);
			Shape::blocks_[0]->moveUp   (-2 * Block::Dimension);
			Shape::blocks_[1]->moveUp   (-1 * Block::Dimension);
			Shape::blocks_[2]->moveRight( 1 * Block::Dimension);
			Shape::blocks_[3]->moveUp   ( 1 * Block::Dimension);
		break;

		case Orientation::DOWN:
			std::cout << "DOWN" << std::endl;
			Shape::blocks_[0]->moveUp   ( 2 * Block::Dimension);
			Shape::blocks_[0]->moveRight(-2 * Block::Dimension);
			Shape::blocks_[1]->moveUp   ( 1 * Block::Dimension);
			Shape::blocks_[1]->moveRight(-1 * Block::Dimension);
			Shape::blocks_[2]->moveRight( 1 * Block::Dimension);
		break;

		case Orientation::LEFT:
			std::cout << "LEFT" << std::endl;
			Shape::blocks_[0]->moveUp   ( 1 * Block::Dimension);
			Shape::blocks_[0]->moveRight( 1 * Block::Dimension);
			Shape::blocks_[2]->moveRight(-1 * Block::Dimension);
			Shape::blocks_[2]->moveUp   (-1 * Block::Dimension);
			Shape::blocks_[3]->moveUp   (-2 * Block::Dimension);
		break;
	}

	Shape::rotate();
}

