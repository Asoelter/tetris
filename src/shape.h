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

	public:
		virtual ~Shape(){}
		virtual void moveUp(float increment);
		virtual void moveRight(float increment);
		virtual void rotate();
		virtual void draw() const;

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
