#include "Game.h"
#include  <iostream>
using namespace std;

Game::Game() : m_running(false)
			 , m_pWindow(nullptr)
			 , m_pRenderer(nullptr)
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
void Game::Update()
{
	
	
	cout << "Inside Update ..." << endl;

	
}
void Game::Render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 0, 128, 255, 255);
	SDL_RenderClear(m_pRenderer);

	SDL_RenderPresent(m_pRenderer);
	
	cout << "Inside Render.. " << endl;
}
void Game::Clean()
{
	cout << "Inside Clean..." << endl;
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();
	
}