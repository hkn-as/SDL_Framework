#pragma once
#include <SDL.h>
class Game
{
private:
	bool m_running;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

private:
	static const int kWidth = 1024;
	static const int kHeight = 768;

public:
	Game();
	int Init(const char* title, int x, int y);
	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	
	bool IsRunning() { return m_running; }

	SDL_Window* GetWindow() { return m_pWindow; }
	SDL_Renderer* GetRenderer() { return m_pRenderer; }
};

