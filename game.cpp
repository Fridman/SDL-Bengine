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

void game::game() {
	screen = Screen();
}