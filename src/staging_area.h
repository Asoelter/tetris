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
		StagingArea(Point position);

		void draw() const;
		std::unique_ptr<Shape> pop();

	private:
		BorderedRectangle						area_;
		std::array<std::unique_ptr<Shape>, 3>	shapes_;
		float									xPos_;
		float									yPos_;
};

#endif //STAGING_AREA_H
