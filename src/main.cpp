#include <iostream>
#include "engine/src/window.h"
#include "l_shape.h"
#include "z_shape.h"
#include "staging_area.h"
#include "game.h"

int main()
{
	/*Window window(800, 600, "Tetris");
	StagingArea staging_area(Point(0.0f, 0.0f));

	int count = 1;
	while(window.open())
	{
		window.update();
		window.setBackGroundColor(Color(Shade::BLUE));

		staging_area.draw();

		if(count % 100 == 0)
		{
			staging_area.pop();
		}

		++count;
	}*/

	Game game;
	game.run();

	return 0;
}
