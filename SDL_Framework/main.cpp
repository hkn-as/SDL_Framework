#include <iostream>
#include <chrono>
#include "Game.h"


int main(int argc, char* argv[])
{
	Game myGame;
	int result = myGame.Init("Hakan's first attempt", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	if (result == 0)
	{
		auto lastFrameTime = std::chrono::high_resolution_clock::now();
		
		while (myGame.IsRunning())
		{
			auto thisFrameTime = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float> lastFrameDuration = thisFrameTime - lastFrameTime;
			
			float deltaTime = lastFrameDuration.count();

			lastFrameTime = thisFrameTime;
			
			myGame.HandleEvents();
			myGame.Update(deltaTime);
			myGame.Render();

		}
		myGame.Clean();

	}
	
	return result;
}