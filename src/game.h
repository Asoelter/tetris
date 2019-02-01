#ifndef GAME_H
#define GAME_H

#include "engine/src/bordered_rectangle.h"
#include "engine/src/window.h"
#include "staging_area.h"
#include "shape_manager.h"

#define persistant static

class Game
{
	using shapePtr = std::unique_ptr<Shape>;

	public:
		Game();

		void run();

	private:
		void manageShape(shapePtr& shape);

	private:
		Window					window_;
		BorderedRectangle		gameArea_;
		StagingArea				stagingArea_;
		shapePtr				activeShape_;
};

#endif //GAME_H
