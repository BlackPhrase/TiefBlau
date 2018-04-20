/// @file

#include <cstdlib>
#include <iostream>

#include <SDL.h>

#include "SDLSound.hpp"
#include "SoundController.hpp"

constexpr auto WINDOW_WIDTH{1280};
constexpr auto WINDOW_HEIGHT{600};

SDL_Window *gpWindow{nullptr};
SDL_Renderer *gpRenderer{nullptr};

cSoundController *gpSoundController{nullptr};

bool IBFInitGraphics()
{
	gpWindow = SDL_CreateWindow("IBF Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	
	if(!gpWindow)
	{
		std::cout << "SDL2 window creation failed! (" << SDL_GetError() << ")" << std::endl; 
		SDL_Quit();
		return false;
	};
	
	gpRenderer = SDL_CreateRenderer(gpWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	if(!gpRenderer)
	{
		SDL_DestroyWindow(gpWindow);
		std::cout << "SDL2 renderer creation failed! (" << SDL_GetError() << ")" << std::endl; 
		SDL_Quit();
		return false;
	};
	
	return true;
};

bool IBFInitSound()
{
	cSoundSDL *pSoundImpl = new cSoundSDL();
	gpSoundController = new cSoundController(pSoundImpl);
	
	//22050
	if(!pSoundImpl->Init(44100, 2, 4096))
		return false;
	
	//delete pSoundImpl;
	//delete gpSoundController;
	
	return true;
};

bool IBFInit()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "SDL2 initialization failed! (" << SDL_GetError() << ")" << std::endl; 
		return false;
	};
	
	if(!IBFInitGraphics())
		return false;
	
	if(!IBFInitSound())
		return false;
	
	SDL_Event SDLEvent;
	
	bool bQuit{false};
	
	gpSoundController->StartMusic("Zweitestock.mp3");
	
	while(!bQuit)
	{
		while(SDL_PollEvent(&SDLEvent))
		{
			switch(SDLEvent.type)
			{
			case SDL_QUIT:
				bQuit = true;
				break;
			case SDL_KEYDOWN:
				switch(SDLEvent.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					bQuit = true;
					break;
				default:
					break;
				};
			case SDL_MOUSEBUTTONDOWN:
				break;
			default:
				break;
			};
		};
		
		SDL_RenderClear(gpRenderer);
		//rendertexture(image, gpRenderer, x, y);
		SDL_RenderPresent(gpRenderer);
	};
	
	return true;
};

void SDLCleanup()
{
	SDL_DestroyRenderer(gpRenderer);
	SDL_DestroyWindow(gpWindow);
	SDL_Quit();
};

void IBFShutdown()
{
	SDLCleanup();
};