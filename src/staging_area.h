#ifndef STAGING_AREA_H
#define STAGING_AREA_H

#include <array>
#include <memory>

#include "engine/src/bordered_rectangle.h"
#include "block.h"
#include "shape.h"
#include "l_shape.h"
#include "z_shape.h"

class StagingArea
{
	using shapePtr = std::unique_ptr<Shape>;

	public:
		StagingArea(const Point& position);

		void draw() const;

		shapePtr pop();
		
		float xPos() const;
		float yPos() const;

	private:
		BorderedRectangle			area_;
		std::array<shapePtr, 3>		shapes_;
		float						xPos_;
		float						yPos_;
};

#endif //STAGING_AREA_H
