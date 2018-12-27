#include <iostream>
#include "engine/src/square.h"
#include "engine/src/window.h"
#include "engine/src/color.h"
#include "engine/src/bordered_square.h"
#include "engine/src/rectangle.h"
#include "block.h"
#include "l_shape.h"

int main()
{
	Window window(800, 600, "Tetris");
	Block block(Point(0.4f, -0.21f), Color(Shade::GREEN));
	LShape lshape(Point(0.0f, 0.0f), Color(Shade::RED));

	int count = 1;
	while(window.open())
	{
		block.draw();
		lshape.draw();
		//lshape.moveRight(0.01f);
		window.update();
		window.setBackGroundColor(Color(Shade::BLUE));

		if(count % 100 == 0)
		{
			lshape.rotate();
		}

		++count;
	}

	return 0;
}
