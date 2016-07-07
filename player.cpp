#include "player.h"




Player::Player(void) {
	id = 0;
}

std::string Player::getInput() {
	std::string ret;
	if (id == 0) {
		SDL_Event e;
		while ( SDL_PollEvent( &e ) != 0 ) {
				//User requests quit
				if (e.type == SDL_QUIT ) {
					ret = "quit";
				}
				if ( e.type == SDL_KEYDOWN ) {
					switch ( e.key.keysym.sym ) {
						case SDLK_ESCAPE:
							ret = "quit";
							break;
						case SDLK_a:
							ret = "left";
							break;
						case SDLK_d:
							ret = "right";
							break;
				}
			}
		}
	} else {
		
	}
	return ret;
}