#pragma once
#include <SDL.h>
class Game
{
private:
	Game();
	bool m_running;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_FRect m_rectangleTransform;
	const Uint8* m_pKeyStates;
	float m_timePassed;
	float m_speedMultiplier;
private:
	static const int kWidth = 1024;
	static const int kHeight = 768;
	static const int kRectangleSpeed = 700;
	
public:
	static Game& getInstance();
	int Init(const char* title, int x, int y);
	void HandleEvents();
	bool IsKeyDown(SDL_Scancode key);
	void Update(float deltaTiime);
	void Render();
	void Clean();
	
	bool IsRunning() { return m_running; }

	SDL_Window* GetWindow() { return m_pWindow; }
	SDL_Renderer* GetRenderer() { return m_pRenderer; }
};

