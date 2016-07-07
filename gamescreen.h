#pragma once 

#include <stdio.h>
#include <SDL.h>
#include <string>

class gameScreen : public screen
{

	void gameScreen(void);
	void input(void);
	void update(void);
	void render(void);
}