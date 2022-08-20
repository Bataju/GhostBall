#pragma once

#include "SDL.h"
#include"SDL_image.h"
#include <iostream>
#include "vector"

class ColliderComponent;

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();


	static void addTile(int srcX,int srcY, int xpos, int yos);
	static SDL_Renderer* renderer;
	static SDL_Event event;
	static std::vector<ColliderComponent*>colliders;
	static int updateCounter;
	static bool isRunning;
	static bool ballMoving;
	static bool isComplete;

private:
	int cnt = 0;
	SDL_Window *window;
};