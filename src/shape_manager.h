#ifndef SHAPE_MANAGER_H
#define SHAPE_MANAGER_H

#include "shape.h"
#include "engine/src/bordered_rectangle.h"
#include "engine/src/window.h"

class ShapeManager
{
	using shapePtr = std::unique_ptr<Shape>;
	public:
		ShapeManager(Window* inputSource, const BorderedRectangle& borderSource);

		void manage(std::unique_ptr<Shape>& shape);

		bool shapeHasFallen();

	private:
		void moveShapeRight(shapePtr& shape) const;
		void moveShapeLeft(shapePtr&  shape) const;
		void moveShapeDown(shapePtr&  shape, bool& statusFlag) const;
		void rotateShape(shapePtr& shape);

		bool shapeHasFallen_;
		bool spacePressedRecently_;

		unsigned char translationCounter_;
		unsigned char rotationCounter_;

		float rightLimit_;
		float lowerLimit_;
		float leftLimit_;

		Window* window_;
};

#endif //SHAPE_MANAGER_H
