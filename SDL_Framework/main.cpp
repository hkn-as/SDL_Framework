#include <iostream>
#include <chrono>
#include "Game.h"


int main(int argc, char* argv[])
{
	Game& myGameInstance = Game::getInstance();
	int result = myGameInstance.Init("Hakan's first attempt", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	if (result == 0)
	{
		auto lastFrameTime = std::chrono::high_resolution_clock::now();
		
		while (myGameInstance.IsRunning())
		{
			auto thisFrameTime = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float> lastFrameDuration = thisFrameTime - lastFrameTime;
			
			float deltaTime = lastFrameDuration.count();

			lastFrameTime = thisFrameTime;
			
			myGameInstance.HandleEvents();
			myGameInstance.Update(deltaTime);
			myGameInstance.Render();

		}
		myGameInstance.Clean();

	}
	
	return result;
}