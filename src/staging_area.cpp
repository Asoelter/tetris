#include "staging_area.h"

StagingArea::StagingArea(Point position)
	: area_(position, 0.7f, 1.4f, Color(Shade::BLACK), Color(Shade::WHITE))
{

}

void StagingArea::draw() const
{
	area_.draw();
	std::for_each(blocks_.begin(), blocks_.end(), [](const shapePtr& s){s->draw();});
}

std::unique_ptr<Block> StagingArea::pop()
{

}
