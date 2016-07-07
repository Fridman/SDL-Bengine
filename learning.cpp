//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "engine/player.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be renderning to
SDL_Window* window = NULL;

//The surface contained by the window
SDL_Surface* screenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* helloWorld = NULL;


int main( int argc, char* args[] )
{
	Player player1;
	//Start up SDL and create window
	if( !init() ) {
		printf( "Failed to initialize!\n" );
	} else {
		//Load media
		if( !loadMedia() ) {
			printf( "Failed to load media!\n" );
		} else {
			printf( "loaded media!\n" );
		}
	}

	//Mail loop flag
	bool quit = false;

	//Event handler

	while( !quit ) {
		//Handle events on queue
		
		//Apply the image
		SDL_BlitSurface( helloWorld, NULL, screenSurface, NULL );

		//Update the surface
		SDL_UpdateWindowSurface( window );

		if (player1.getInput() == "quit") {
			quit = true;
		}
	}

	
	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}

bool init()
{

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {

		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;

	} else {
		//Create Window
		window = SDL_CreateWindow( "Learning", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if (window == NULL ) {
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		} else {
			//Get window surface
			screenSurface = SDL_GetWindowSurface( window );

			//Fill the surface white
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

			//UPdate the surface
			SDL_UpdateWindowSurface( window );

			//Wait two seconds

		}
	}
	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	helloWorld = SDL_LoadBMP( "assets/hello_world.bmp" );
	if( helloWorld == NULL ) {
		printf( "Unable to load image %s! SDL Error: %s\n", "assets/hello_world.bmp", SDL_GetError() );
		success = false;
	}
	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface( helloWorld );
	helloWorld = NULL;

	//Destroy Window
	SDL_DestroyWindow( window );
	window = NULL;

	//Quite SDL subsystems
	SDL_Quit();
}