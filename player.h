#pragma once
#include <stdio.h>
#include <SDL.h>
#include <string>

class Player {
	public:
		Player(void);
		int id;
		std::string getInput();
	private:
};