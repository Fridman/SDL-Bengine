#pragma once
#include <stdio.h>
#include <SDL.h>
#include <string>

class Screen {
	virtual void input(void) = 0;
	virtual void update(void) = 0;
	virtual void render(void) = 0;
};