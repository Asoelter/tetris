#include "shape_manager.h"

ShapeManager::ShapeManager(Window* inputSource, const BorderedRectangle& borderSource)
	: shapeHasFallen_		(false)
	, spacePressedRecently_	(false)
	, translationCounter_	(0)
	, rotationCounter_		(0)
	, rightLimit_			(borderSource.xPos() + (borderSource.width()  / 2.0f))
	, lowerLimit_			(borderSource.yPos() - (borderSource.height() / 2.0f))
	, leftLimit_			(borderSource.xPos()  - (borderSource.width()  / 2.0f))
	, window_				(inputSource)
{

}

void ShapeManager::manage(std::unique_ptr<Shape>& shape)
{
	shapeHasFallen_ = false;
	translationCounter_ = (translationCounter_ + 1) % 11;

	if(window_->keyIsPressed(Key::RIGHT_ARROW))
	{
		moveShapeRight(shape);
	}
	if(window_->keyIsPressed(Key::LEFT_ARROW))
	{
		moveShapeLeft(shape);
	}
	if(window_->keyIsPressed(Key::SPACEBAR))
	{
		rotateShape(shape);
	}

	if((int)rotationCounter_ == 10)
	{
		spacePressedRecently_ = false;
		rotationCounter_ = (rotationCounter_ + 1) % 11;
	}
	if(spacePressedRecently_)
	{
		++rotationCounter_;
	}

	moveShapeDown(shape, shapeHasFallen_);
}

bool ShapeManager::shapeHasFallen()
{
	return shapeHasFallen_;
}

void ShapeManager::moveShapeRight(shapePtr& shape) const
{
	if(shape->rightBorderPosition() + Block::Dimension <= rightLimit_)
	{
		shape->moveRight(Block::Dimension);
	}
}

void ShapeManager::moveShapeLeft(shapePtr& shape) const
{
	if(shape->leftBorderPosition() - Block::Dimension >= leftLimit_)
	{
		shape->moveRight(-1 * Block::Dimension);
	}
}

void ShapeManager::moveShapeDown(shapePtr& shape, bool& statusFlag) const
{
	if(shape->bottomBorderPosition() > lowerLimit_) 
	{
		if(translationCounter_ % 10 == 0)
		{
			shape->moveUp(-1 * Block::Dimension);
		}
	}
	else
	{
		statusFlag = true;
	}
}

void ShapeManager::rotateShape(shapePtr& shape)	 
{
	if(!spacePressedRecently_)
	{
		shape->rotate();
		spacePressedRecently_ = true;
	}
}
