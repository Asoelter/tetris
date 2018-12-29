#include "game.h"

Game::Game()
	: window_(800, 600, "Tetris")
	, gameArea_(Point(-0.2f, 0.0f), 0.7f, 1.4f, Color(Shade::BLACK), Color(Shade::WHITE))
	, stagingArea_(Point(0.4f, 0.0f))
	, activeShape_(nullptr)
{

}

void Game::run()
{
	while(window_.open())
	{
		stagingArea_.draw();
		gameArea_.draw();

		if(!activeShape_)
		{
			activeShape_ = stagingArea_.pop();
			activeShape_->moveRight(-0.6f);
			activeShape_->moveUp(0.5f);
		}
		else
		{
			activeShape_->moveUp(-0.003f);
		}

		activeShape_->draw();

		window_.update();
		window_.setBackGroundColor(Color(Shade::BLUE));
	}
}

