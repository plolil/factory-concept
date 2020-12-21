int main(int argc, char ** argv)
{
	bool quit = false;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO); TTF_Init();

	TTF_Font * font = TTF_OpenFont("assets/font.ttf", 32);
	SDL_Window * screen = SDL_CreateWindow("Factory Game",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(screen, -1, 0);
	while (!quit){
		Uint32 start = SDL_GetTicks();
		while (SDL_PollEvent(&event)) {
			switch (event.type){
				case SDL_QUIT:
					quit = true;
					break;
			}
		}
		SDL_RenderClear(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(screen);
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
	return 0;
}
