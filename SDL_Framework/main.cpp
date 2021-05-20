#include <iostream>
#include "Game.h"


int main(int argc, char* argv[])
{
	Game myGame;
	int result = myGame.Init("Hakan's first attempt", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	if (result == 0)
	{
		while (myGame.IsRunning())
		{
			myGame.HandleEvents();
			myGame.Update();
			myGame.Render();

		}
		myGame.Clean();

	}
	
	return result;
}