#include "game.h"

Game::Game()
	: window_(800, 600, "Tetris")
	, gameArea_(Point(-0.2f, 0.0f), ( 10.0f * Block::Dimension + 2.0 * BorderedRectangle::borderWidth), 
			(20.0f * Block::Dimension + 2.0f * BorderedRectangle::borderWidth), 
			Color(Shade::BLACK), Color(Shade::WHITE))
	, stagingArea_(Point(0.4f, 0.0f))
	, activeShape_(nullptr)
{

}

void Game::run()
{
	ShapeManager manager(&window_, gameArea_);

	while(window_.open())
	{
		stagingArea_.draw();
		gameArea_.draw();

		if(manager.shapeHasFallen())
		{
			activeShape_ = nullptr;
		}

		if(!activeShape_)
		{
			activeShape_ = stagingArea_.pop();
			//activeShape_->moveRight(gameArea_.xPos() - stagingArea_.xPos());
			//activeShape_->moveUp(0.5f);
			centerShape(activeShape_);
		}

		activeShape_->draw();
		manager.manage(activeShape_);

		window_.update();
		window_.setBackGroundColor(Color(Shade::BLUE));
	}
}

void Game::manageShape(shapePtr& shape)
{
	persistant int count					= 0;
	persistant bool spacePressedRecently	= false;

	if(window_.keyIsPressed(Key::RIGHT_ARROW))
	{
		shape->moveRight(Block::Dimension);
	}
	if(window_.keyIsPressed(Key::DOWN_ARROW))
	{
		shape->moveUp(-0.01f);
	}
	if(window_.keyIsPressed(Key::LEFT_ARROW))
	{
		shape->moveRight(-1 * Block::Dimension);
	}
	if(window_.keyIsPressed(Key::SPACEBAR) && count == 0)
	{
		shape->rotate();
		spacePressedRecently = true;
	}

	if(spacePressedRecently)
	{
		count = (count + 1) % 11;
	}
	if(count == 0)
	{
		spacePressedRecently = false;
	}
}

void Game::centerShape(const shapePtr& shape)
{
	//TODO: If possible, implement without a 
	//		call to dynamic cast 

	//TODO: Add extra cases as new shape 
	//		types get added

	if(dynamic_cast<LShape*>(shape.get()))
	{
		shape->moveRight(gameArea_.xPos() - stagingArea_.xPos());
	}
	else
	{
		shape->moveRight(gameArea_.xPos() - stagingArea_.xPos() -(0.5f * Block::Dimension));
	}

	shape->moveUp(0.5f);
}
