#ifndef GAME_H
#define GAME_H

#include <utility>

#include "engine/src/bordered_rectangle.h"
#include "engine/src/window.h"
#include "staging_area.h"
#include "shape_manager.h"

class Game
{
	using shapePtr = std::unique_ptr<Shape>;
	using blockPtr = std::unique_ptr<Block>;

	public:
		Game();

		void run();

		static constexpr auto gameAreaXPos		= -0.2f;
		static constexpr auto gameAreaYPos		=  0.0f;
		static constexpr auto gameAreaWidth		=  10.0f * Block::Dimension;
		static constexpr auto gameAreaHeight	=  20.0f * Block::Dimension;

	private:
		void centerShape(const shapePtr& shape);
		void drawFallenBlocks() const;

	private:
		Window										window_;
		BorderedRectangle							gameArea_;
		StagingArea									stagingArea_;
		shapePtr									activeShape_;
		std::array<std::array<blockPtr, 20>, 10>	fallenBlocks_;

};

#endif //GAME_H
