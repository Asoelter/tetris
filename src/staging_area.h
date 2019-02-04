#ifndef STAGING_AREA_H
#define STAGING_AREA_H

#include <array>
#include <memory>
#include <random>
#include <chrono>

#include "engine/src/bordered_rectangle.h"
#include "block.h"
#include "shape.h"
#include "l_shape.h"
#include "z_shape.h"

class StagingArea
{
	//using declarations
	using shapePtr = std::unique_ptr<Shape>;

	public: //public member functions
		StagingArea(const Point& position);

		void draw() const;

		shapePtr pop();
		
		float xPos() const;
		float yPos() const;

	private: //private member functions
		std::unique_ptr<Shape> generateShapeAt(Point position);

	private: //private member enums
		enum shapeType{LSHAPE, ZSHAPE};

	private: //private member variables

		BorderedRectangle			area_;
		std::array<shapePtr, 3>		shapes_;
		float						xPos_;
		float						yPos_;
		unsigned char				shapeIndex_;

		static constexpr float		distanceBetweenShapes	=	0.2f;
		static constexpr shapeType	shapeTypes_[2]			=	{LSHAPE, ZSHAPE};

		static constexpr Shade		colors_[3]				=	{Shade::RED, 
																Shade::GREEN, 
																Shade::BLUE};
};

#endif //STAGING_AREA_H
