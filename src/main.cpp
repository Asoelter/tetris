#include <iostream>
#include "engine/src/square.h"
#include "engine/src/window.h"
#include "engine/src/color.h"
#include "engine/src/bordered_square.h"
#include "engine/src/rectangle.h"
#include "block.h"
#include "l_shape.h"
#include "z_shape.h"

int main()
{
	Window window(800, 600, "Tetris");
	ZShape zshape(Point(0.0f, 0.0f), Color(Shade::RED));

	int count = 1;
	while(window.open())
	{
		window.update();
		window.setBackGroundColor(Color(Shade::BLUE));

		zshape.draw();

		if(count % 100 == 0)
		{
			zshape.rotate();
		}

		++count;
	}

	return 0;
}
