#include "staging_area.h"

constexpr StagingArea::shapeType StagingArea::shapeTypes_[];
constexpr Shade StagingArea::colors_[];

StagingArea::StagingArea(const Point& position)
	: area_(position, 0.3f, 0.7f, Color(Shade::BLACK), Color(Shade::WHITE))
	, shapes_()
	, xPos_(position.x())
	, yPos_(position.y())
	, shapeIndex_(0)
{
	Point p0(position.x(), position.y() + distanceBetweenShapes);
	Point p1(position.x(), position.y() - distanceBetweenShapes);

	shapes_[0] = std::make_unique<LShape>(p0,		Color(Shade::RED));
	shapes_[1] = std::make_unique<ZShape>(position, Color(Shade::BLUE));
	shapes_[2] = std::make_unique<LShape>(p1,		Color(Shade::GREEN));
}

void StagingArea::draw() const
{
	area_.draw();
	std::for_each(shapes_.begin(), shapes_.end(), [](const shapePtr& s){s->draw();});
}

std::unique_ptr<Shape> StagingArea::pop()
{
	std::swap(shapes_[0], shapes_[1]);
	std::swap(shapes_[1], shapes_[2]);

	Point newShapePosition(xPos_, yPos_ - distanceBetweenShapes);
	shapePtr newShape = generateShapeAt(newShapePosition);

	std::swap(shapes_[2], newShape);

	shapes_[0]->moveUp(distanceBetweenShapes);
	shapes_[1]->moveUp(distanceBetweenShapes);

	return newShape;
}

float StagingArea::xPos() const
{
	return area_.xPos();
}

float StagingArea::yPos() const
{
	return area_.yPos();
}

std::unique_ptr<Shape> StagingArea::generateShapeAt(Point position)
{
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::mt19937 shapeIndexGenerator(seed);
	std::mt19937 colorIndexGenerator(seed);

	auto shapeIndex = shapeIndexGenerator() % 2;
	auto colorIndex = colorIndexGenerator() % 3;

	auto type = shapeTypes_[shapeIndex];
	auto color(StagingArea::colors_[colorIndex]);

	std::unique_ptr<Shape> rval;

	switch(type)
	{
		case LSHAPE:
			rval = std::make_unique<LShape>(position, color);
		break;
		case ZSHAPE:
			rval = std::make_unique<ZShape>(position, color);
		break;
	}

	return rval;
}

