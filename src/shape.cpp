#include "shape.h"

std::array<Orientation, 4> Shape::orientations_ = {
	Orientation::UP,
	Orientation::RIGHT,
	Orientation::DOWN,
	Orientation::LEFT
};

void Shape::moveUp(float increment)
{
	std::for_each(blocks_.begin(), blocks_.end(), [increment](blockPtr& b){b->moveUp(increment);});
	yPos_ += increment;
}

void Shape::moveRight(float increment)
{
	std::for_each(blocks_.begin(), blocks_.end(), [increment](blockPtr& b){b->moveRight(increment);});
	xPos_ += increment;
}

void Shape::rotate()
{
	orientationIndex_   = (orientationIndex_ + 1) % 4;
	currentOrientation_ = orientations_[orientationIndex_];
}

void Shape::draw() const
{
	std::for_each(blocks_.begin(), blocks_.end(), [](const blockPtr& b){b->draw();});
}

Shape::Shape(Point position)
	: blocks_()
	, orientationIndex_(0)
	, currentOrientation_(Orientation::UP)
	, xPos_(position.x())
	, yPos_(position.y())
{

}

Orientation Shape::orientation() const
{
	return currentOrientation_;
}

float Shape::xPos() const
{
	return xPos_;
}

float Shape::yPos() const
{
	return yPos_;
}
