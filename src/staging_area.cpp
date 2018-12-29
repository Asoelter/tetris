#include "staging_area.h"

StagingArea::StagingArea(Point position)
	: area_(position, 0.3f, 0.7f, Color(Shade::BLACK), Color(Shade::WHITE))
	, shapes_()
	, xPos_(position.x())
	, yPos_(position.y())
{
	shapes_[0] = std::make_unique<LShape>(Point(position.x(), position.y() + 0.2f), Color(Shade::RED));
	shapes_[1] = std::make_unique<ZShape>(position, Color(Shade::BLUE));
	shapes_[2] = std::make_unique<LShape>(Point(position.x(), position.y() - 0.2f), Color(Shade::GREEN));
}

void StagingArea::draw() const
{
	area_.draw();
	std::for_each(shapes_.begin(), shapes_.end(), [](const shapePtr& s){s->draw();});
}

std::unique_ptr<Shape> StagingArea::pop()
{
	//TODO: Implement random shape type and color generation 

	shapes_[0].swap(shapes_[1]);
	shapes_[1].swap(shapes_[2]);

	std::unique_ptr<Shape> newShape = std::make_unique<ZShape>(Point(xPos_, yPos_ - 0.2f), Color(Shade::GREEN));
	shapes_[2].swap(newShape);

	shapes_[0]->moveUp(0.2f);
	shapes_[1]->moveUp(0.2f);

	return newShape;
}
