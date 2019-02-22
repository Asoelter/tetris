#ifndef SHAPE_H
#define SHAPE_H

#include <array>
#include <memory>
#include <algorithm>

#include "block.h"

enum class Orientation
{
	UP,
	RIGHT,
	DOWN,
	LEFT
};

class Shape
{
	using blockPtr = std::unique_ptr<Block>;
	using shapePtr = std::unique_ptr<Shape>;

	public:
		virtual ~Shape(){}
		virtual void moveUp(float increment);
		virtual void moveRight(float increment);
		virtual void moveDown(float increment);
		virtual void moveLeft(float increment);
		virtual void rotate();
		virtual void draw() const;

		virtual float xPos() const;
		virtual float yPos() const;

		virtual float topBorderPosition()		const = 0;
		virtual float rightBorderPosition()		const = 0;
		virtual float bottomBorderPosition()	const = 0;
		virtual float leftBorderPosition()		const = 0;

		virtual std::array<blockPtr, 4> releaseBlocks();

	protected:
		Shape(Point position);
		Shape(const Shape&)			 {}
		void operator=(const Shape&) {}

		Orientation orientation() const;

		std::array<blockPtr, 4> blocks_;

	private:
		static std::array<Orientation, 4>	orientations_;
		unsigned							orientationIndex_;
		Orientation							currentOrientation_;
		float								xPos_;
		float								yPos_;
};

#endif //SHAPE_H
