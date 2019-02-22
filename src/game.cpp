#include "game.h"

static auto calculateBlockIndices(const std::unique_ptr<Block>& block)
{
	auto firstBlockXPos = Game::gameAreaXPos - (Game::gameAreaWidth  / 2.0f) + (0.5f * Block::Dimension);
	auto firstBlockYPos = Game::gameAreaYPos - (Game::gameAreaHeight / 2.0f) + (0.5f * Block::Dimension);

	std::pair<std::size_t, std::size_t> indices;

	//Added 0.01 to account for precision loss 
	indices.first  = static_cast<std::size_t>((block->xPos() - firstBlockXPos + 0.01) / Block::Dimension);
	indices.second = static_cast<std::size_t>((block->yPos() - firstBlockYPos + 0.01) / Block::Dimension);

	return indices;
}

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
			auto blocks = activeShape_->releaseBlocks();

			for(auto& block : blocks)
			{
				auto position = calculateBlockIndices(block);
				std::swap(fallenBlocks_[position.first][position.second], block);
			}

			activeShape_ = nullptr;
		}

		drawFallenBlocks();

		if(!activeShape_)
		{
			activeShape_ = stagingArea_.pop();
			centerShape(activeShape_);
		}

		activeShape_->draw();
		manager.manage(activeShape_);

		window_.update();
		window_.setBackGroundColor(Color(Shade::BLUE));
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

		auto topOfGameArea = gameAreaYPos + (gameAreaHeight / 2.0f);
		shape->moveUp(topOfGameArea - shape->yPos() + (0.5 * Block::Dimension));
	}
	else
	{
		shape->moveRight(gameArea_.xPos() - stagingArea_.xPos() -(0.5f * Block::Dimension));

		auto topOfGameArea = gameAreaYPos + (gameAreaHeight / 2.0f);
		shape->moveUp(topOfGameArea - shape->yPos());
	}

}

void Game::drawFallenBlocks() const
{
	for(const auto& blocks : fallenBlocks_)
	{
		for(const auto& block : blocks)
		{
			if(block)
			{
				block->draw();
			}
		}
	}
}
