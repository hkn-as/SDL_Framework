#include "Game.h"
#include  <iostream>

using namespace std;

Game::Game() : m_running(false)
			 , m_pWindow(nullptr)
			 , m_pRenderer(nullptr)
			 , m_rectangleTransform{kWidth/2, kHeight/2, 100, 100}
			 , m_pKeyStates(nullptr)
			 , m_timePassed(0)
			 , m_speedMultiplier(1)
{
	cout << "Inside the constructor" << endl;
}

int Game::Init(const char* title, int x, int y)
{
	cout << "Initialising Game ..." << endl;
	
	int errorCode = SDL_Init(SDL_INIT_EVERYTHING);
	if(errorCode == 0)
	{ 
		cout << "SDL_INIT successful. " << endl;
	}
	else
	{
		cout << "SDL_INIT failed..errorCode:" << errorCode << "  " << SDL_GetError() << endl;
		system("pause");
		return errorCode;
	}
	m_pWindow = SDL_CreateWindow(title, x, y, kWidth, kHeight, 0);
	if(m_pWindow != nullptr)
	{
		cout << "SDL_CreateWindow succeeded." << endl;
	}
	else
	{
		cout << "SDL_CreateWindow() failed.." <<  SDL_GetError() << endl;
		SDL_Quit();
		system("pause");
		return errorCode;
	}
	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);
	if (m_pRenderer != nullptr)
	{
		cout << "SDL_CreateRenderer() succeeded." << endl;
	}
	else
	{
		cout << "SDL_CreateRenderer() failed.." << SDL_GetError() << endl;
		SDL_DestroyWindow(m_pWindow);
		SDL_Quit();
		system("pause");
		return -1;
	}

	cout << "Initialization successful!" << endl;

	m_pKeyStates = SDL_GetKeyboardState((nullptr));
	
	m_running = true;
	return 0;
}

void Game::HandleEvents()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			m_running = false;
			break;
		}
	}

}

bool Game::IsKeyDown(SDL_Scancode key)
{
	if(m_pKeyStates)
	{
		return m_pKeyStates[key] == 1;
	}
	return false;
}


void Game::Update(float deltaTime)
{
	/*m_timePassed += deltaTime;
	if(m_timePassed > 2)
	{
		m_speedMultiplier = 2;
		m_timePassed = 0;
	}*/
	
	if (IsKeyDown(SDL_SCANCODE_W))
		m_rectangleTransform.y -= kRectangleSpeed * deltaTime;
	if (IsKeyDown(SDL_SCANCODE_S))
		m_rectangleTransform.y += kRectangleSpeed * deltaTime;
	if (IsKeyDown(SDL_SCANCODE_A))
		m_rectangleTransform.x -= kRectangleSpeed * deltaTime;
	if (IsKeyDown(SDL_SCANCODE_D))
		m_rectangleTransform.x += kRectangleSpeed * deltaTime;
	//if (IsKeyDown(SDL_SCANCODE_SPACE))
		//m_rectangleTransform.y -= 5;

	
}
void Game::Render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 0, 128, 255, 255);
	SDL_RenderClear(m_pRenderer);

	SDL_SetRenderDrawColor(m_pRenderer, 255, 128, 64, 255);
	SDL_RenderFillRectF(m_pRenderer, &m_rectangleTransform);
	
	SDL_RenderPresent(m_pRenderer);
	
	
}
void Game::Clean()
{
	cout << "Inside Clean..." << endl;
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();
	
}