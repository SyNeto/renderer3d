#include "display.h"

bool is_running = false;

void setup(void) {
	// Alocate the required memory in bytes for the color_buffer used to create the renderer texture.
	color_buffer = (uint32_t*) malloc(sizeof (uint32_t) * window_width * window_height);
	color_buffer_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, window_width, window_height);
}

void process_input(void) {
	SDL_Event event;
	SDL_PollEvent(&event);
	
	switch (event.type) {
	case SDL_QUIT:
		is_running = false;
		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE) {
			is_running = false;
			break;
		}
	}
}

void update(void) {
	// update function
}

void render(void) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);
	draw_grid();
	draw_pixel(205, 205, 0xFFAF2A6E);
	draw_rect(100, 100, 100, 100, 0xFFD84242);
	render_color_buffer();
	clear_color_buffer(0xFFEAFF7B);
	SDL_RenderPresent(renderer);
}

int main(int argc, char* args) {
	is_running = initialize_window();
	setup();
	while (is_running) {
		process_input();
		update();
		render();
	}
	destroy_window();
	return 0;
}